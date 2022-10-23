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
always_ff@(posedge clk) 
// {WIDTH{1’b0}} in line 12 uses the concatenation operator { } to form WIDTH bits of ‘0
if(rst)begin
count <= {WIDTH{1'b0}};
end
// step 1
// else begin
//     if(en)
//     count <= count;
//     else
//     count <= count + 4'h0001;
// step 2 
// else
//     if(en)
//     count <=count+1;

endmodule 

