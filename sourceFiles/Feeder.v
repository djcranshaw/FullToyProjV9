`timescale 1ns / 1ps

module Feeder(
  input clk,
  input en_proc,
  output[5:0] memmaster_address0,
  input[31:0] memmaster_q0,
  output[4:0] mem_address0,
  output[31:0] mem_d0
);

reg[5:0] mm_a0;
reg[4:0] m_a0;

always @(posedge en_proc) begin
  mm_a0 <= 0;
  m_a0 <= 0;
end

always @(posedge clk) begin
  mm_a0 <= mm_a0 + 1'b1;
  m_a0 <= mm_a0 - 1'b1;
end
  assign memmaster_address0 = mm_a0;
  assign mem_address0 = m_a0;
  assign mem_d0 = memmaster_q0;
endmodule
