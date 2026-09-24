module top(input logic         clk, reset,
           output logic [31:0] WriteData, DataAdr,
           output logic        MemWrite);

endmodule

// Your memory should read the test code from the memory file at startup with:
// initial $readmemh("memfile.dat", RAM);
