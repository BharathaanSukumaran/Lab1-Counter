#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

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

    // initialise simulation outputs
    top->clk =1;
    top->rst=1;
    top->en = 0;

    // run simulation for many clock cycles
    int tick = 0;
    for(int i=0;i< 300; i++){
        // Add to readme, remember to compelete part 2 of challenge
        // dump variables into VCD file and toggle clock
        for(clk=0;clk<2;clk++){
            // in ps
            tfp->dump (2*i+clk);
            // falling edge
            top->clk = !top->clk;
            top->eval ();
        }
        if(top-> count == 9){
            tick = tick+1;
            if(tick < 3){
                top->en = 0;
                top->rst = 0;
            }
            else{
                top->rst = 1;
                top->en = 0;
                tick = 0;
            }
        }
        else{
            top->rst=0;
            top->en=1;
        }
        if(Verilated::gotFinish()) exit(0);
        
    }
    tfp->close();
    exit(0);

}

