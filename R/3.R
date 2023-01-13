A <- matrix(nrow = 2, ncol = 2, data = c(1, 1, 2, 1))
B <- matrix(nrow = 2, ncol = 2, data = c(0, 1, -1, 2))

C <- A %*% B
D <- solve(C)
print(D)

AT <- solve(A)
BT <- solve(B)

DT <- BT %*% AT
print(DT)

