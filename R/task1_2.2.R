regno <- "21BCE2067"
name <- "Kshitiz Bhargava"
mid <- seq(7.5, 42.5, 5)
mid
marks <- c(5, 6, 15, 10, 5, 4, 2, 2)
mean_marks <- sum(mid * marks) / sum(marks)
mean_marks
cl <- cumsum(marks)
cl
n <- sum(marks)
n
qc1 <- min(which(cl >= n / 4)) # The index of the Q1 class
qc1
qc3 <- min(which(cl >= ((3 * n) / 4)))  # The index of the Q3 class
h1 <- qc1
h1
h3 <- qc3
h3
f1 <- marks[qc1] # frequency of the Q1 class
f1
f3 <- marks[qc3] # frequency of the Q3 class
f3

c1 <- cl[qc1 - 1] # cumulative frequency of the preceding class of Q1
c1
c3 <- cl[qc3 - 1] # cumulative frequency of the preceding class of Q3
c3
l1 <- mid[qc1] - 2.5 + 0.1667
l1
l3 <- mid[qc3] - 2.5
l3
Q1 <- l1 + ((n / 4) - c1) * (h1/f1)
Q1
Q3 <- l3 + (((3 * n) / 4) - c3) * (h3/f3)
Q3
quartile_deviation <- (Q3 - Q1) / 2
quartile_deviation
mean_deviation <- sum(abs(mid - mean_marks) * marks) / sum(marks)
mean_deviation
