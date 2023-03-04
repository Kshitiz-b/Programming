regno <- "21BCE2067"
name <- "Kshitiz Bhargava"
mid <- seq(7.5, 42.5, 5)
mid
marks <- c(5, 6, 15, 10, 5, 4, 2, 2)
mean_marks <- sum(mid * marks) / sum(marks)
mean_marks
quartiles <- quantile(mid, probs = c(0.25, 0.5, 0.75))
quartiles

cl <- cumsum(marks)
cl
n <- sum(marks)
n
qc1 <- min(which(cl >= n / 4)) # The serial number of the median class
qc1
qc3 <- min(which(cl >= ((3 * n) / 4)))
h1 <- qc1
h1
h3 <- qc3
h3
f1 <- marks[qc1] # frequency of the median class
f1
f3 <- marks[qc3] # frequency of the median class
f3

c1 <- cl[qc1 - 1] # cumulative frequency of the median class
c1
c3 <- cl[qc3 - 1] # cumulative frequency of the median class
c3
l1 <- mid[qc1] - h1 / 4
l1
l3 <- mid[qc3] - (3 * h3) / 4
l3
Q1 <- l1 + (((n / 4) - c1) / f1) * h1
Q1
Q3 <- l3 + ((((3 * n) / 4) - c3) / f3) * h3
Q3
Q <- (Q3 - Q1) / 2
Q
quartile_deviation <- (quartiles[3] - quartiles[1]) / 2
quartile_deviation
mean_deviation <- sum(abs(mid - mean_marks) * marks) / sum(marks)
mean_deviation
