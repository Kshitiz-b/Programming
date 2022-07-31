module logic3(A, B, Y);
  input A, B;
  output Y;
  nor(Y, A, B);
endmodule
