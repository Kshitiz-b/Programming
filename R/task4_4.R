# 21BCE2067
# Kshitiz Bhargava
men_n <- 400
men_favor <- 200
women_n <- 600
women_favor <- 325
alpha <- 0.05

p1_hat <- men_favor / men_n
p2_hat <- women_favor / women_n
p_hat <- (men_favor + women_favor) / (men_n + women_n)
z_score <- (p1_hat - p2_hat) / sqrt(p_hat * (1 - p_hat) * (1 / men_n + 1 / women_n))
z.alpha <- qnorm(1 - alpha / 2)

cat("z-score:", z_score, "\n")
cat("z-alpha:", z.alpha, "\n")
if (abs(z_score) > abs(z.alpha)) {
    cat("Reject Null Hypothesis\n")
} else {
    cat("Accept Null Hypothesis\n")
}
