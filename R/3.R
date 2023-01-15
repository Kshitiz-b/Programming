A <- matrix(nrow = 2, ncol = 2, data = c(1, 1, 2, 1)) # nolint
B <- matrix(nrow = 2, ncol = 2, data = c(0, 1, -1, 2)) # nolint

C <- A %*% B # nolint
D <- solve(C) # nolint
print(D)

AT <- solve(A) # nolint
BT <- solve(B) # nolint

DT <- BT %*% AT # nolint
print(DT)
