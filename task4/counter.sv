module counter (clk , rst , en , count);
    // interface signals
    input logic clk; //clk
    input logic rst; //reset
    input logic en;// enable
    output logic [7:0] count; //count output
// indicates that this is a clocked circuit
    always_ff @(posedge clk) 
    begin
    // {WIDTH{1’b0}} in line 12 uses the concatenation operator { } to form WIDTH bits of ‘0
        if(rst) begin
        count <= {8{1'b0}};
        end
        else begin
        count <= count + {{7{1'b0}},en};
        end 
    end

endmodule