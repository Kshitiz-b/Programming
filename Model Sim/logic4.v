module logic4(A, B, Y);
  input A, B;
  output Y;
  nand(Y, A, B);
endmodule
