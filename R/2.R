A <- matrix(nrow = 3, ncol = 3, data = c(1, 3, 2, -3, 1, 5, -8, 0, 6), byrow = F) # nolint
print(A)
B <- solve(A) # nolint
print(B)
C <- matrix(nrow = 3, ncol = 1, data = c(-10, 4, 13), byrow = F)    # nolint
print(C)
D <- B %*% C    # nolint
print(D)
