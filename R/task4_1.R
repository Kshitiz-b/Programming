# 21BCE2067
# Kshitiz Bhargava
n <- 100
sample_mean <- 160
pop_mean <- 165
pop_sd <- 10
alpha <- 0.05

z.alpha <- qnorm(1 - alpha)

z_stat <- (sample_mean - pop_mean) / (pop_sd / sqrt(n))

cat("z-statistic:", z_stat, "\n")
cat("z-alpha:", z.alpha, "\n")
range <- c(-z.alpha, z.alpha)

if (abs(z_stat) > abs(z.alpha)) {
    cat("Reject Null Hypothesis\n")
} else {
    cat("Accept Null Hypothesis\n")
}
