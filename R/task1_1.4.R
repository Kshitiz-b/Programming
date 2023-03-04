#21BCE2067
#Kshitiz Bhargava
A <- matrix(nrow = 2, ncol = 2, data = c(1, 3, 2, 4)) 
B <- matrix(nrow = 2, ncol = 2, data = c(1, 2, 5, 3))
A
B
C <- A %*% B 
D <- solve(C)
print(D)

AT <- solve(A)
BT <- solve(B)

DT <- BT %*% AT
print(DT)
