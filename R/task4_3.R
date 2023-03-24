# 21BCE2067
# Kshitiz Bhargava
p1 <- 0.30
p2 <- 0.25
n1 <- 1200
n2 <- 900
alpha <- 0.05

p_hat <- (p1 * n1 + p2 * n2) / (n1 + n2)
z_score <- (p1 - p2) / sqrt(p_hat * (1 - p_hat) * (1 / n1 + 1 / n2))
z.alpha <- qnorm(1 - alpha / 2)

cat("z-score:", z_score, "\n")
cat("z-alpha:", z.alpha, "\n")

if (abs(z_score) > abs(z.alpha)) {
    cat("Reject Null Hypothesis\n")
} else {
    cat("Accept Null Hypothesis\n")
}
