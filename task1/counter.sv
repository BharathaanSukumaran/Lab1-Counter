module counter #(
    // bits in counter set to 8 bits
    parameter WIDTH = 8
)(
    // interface signals
    input logic clk, //clk
    input logic rst, //reset
    input logic en, // enable
    output logic [WIDTH-1:0] count //count output
);
// indicates that this is a clocked circuit
always_ff @(posedge clk) 
// {WIDTH{1’b0}} in line 12 uses the concatenation operator { } to form WIDTH bits of ‘0
if(rst)
count <= {WIDTH{1'b0}};
else 
count <= count + {{WIDTH-1{1'b0}},en};

endmodule 

