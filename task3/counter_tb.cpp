#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int it;
    int clk;

    Verilated::commandArgs(argc,argv);
//  initialise top verilog instance
    Vcounter* top = new Vcounter;
// initialise trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("counter.vcd");

    // init Vbuddy
    if (vbdOpen()!=1) return (-1);
    vbdHeader("Lab1: Counter");
    vbdSetMode(1);


    // initialise simulation outputs
    top->clk =1;
    top->rst=0;
    top->en = 0;

    // run simulation for many clock cycles
    for(int i=0;i<300; i++){
        

        // dump variables into VCD file and toggle clock
        for(clk=0;clk<2;clk++){
            // in ps
            tfp->dump (2*i+clk);
            // falling edge
            top->clk = !top->clk;
            top->eval ();
        }

    // Send count value to Vbuddy
        vbdHex(4, (int(top->count) >> 16) & 0xF);
        vbdHex(3, (int(top->count) >> 8) & 0xF);
        vbdHex(2, (int(top->count) >> 4) & 0xF);
        vbdHex(1, int(top->count) & 0xF);
        vbdCycle(i+1);

    // Plot count on display
        // vbdPlot(int(top->count), 0, 255);
        // Change input stimuli
        // top->rst =(i<2) | (i==15);
        top->en = vbdFlag();
        // step 1
        // if(top->en == 1){
        //     top->count = vbdValue();
        // }
        if(Verilated::gotFinish()) exit(0);
    }
    vbdClose();
    tfp->close();
    exit(0);

}

