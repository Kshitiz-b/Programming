#21BCE2067
#Kshitiz Bhargava
boys_mean <- 72
boys_sd <- 8
boys_n <- 32
girls_mean <- 70
girls_sd <- 6
girls_n <- 36
alpha <- 0.01

numerator <- boys_mean - girls_mean
denominator <- sqrt((boys_sd^2 / boys_n) + (girls_sd^2 / girls_n))
z_stat <- numerator / denominator
z.alpha <- qnorm(1 - alpha)

cat("z-statistic:", z_stat, "\n")
cat("z-alpha:", z.alpha, "\n")
if (abs(z_stat) > abs(z.alpha)) {
    cat("Reject Null Hypothesis\n")
} else {
    cat("Accept Null Hypothesis\n")
}
