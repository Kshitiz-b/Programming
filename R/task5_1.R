#21BCE2067
#Kshitiz Bhargava
x <- 0:6
f <- c(5, 18, 28, 12, 7, 6, 4)

n <- sum(x * f)
p <- sum(x * f) / sum(f)

y <- dbinom(x, size = n, prob = p)

chisq <- sum((f - n * y)^2 / (n * y))

df <- length(x) - 1 # degrees of freedom
pval <- 1 - pchisq(chisq, df)

plot(x, f,
    type = "h", lwd = 10, col = "blue",
    xlab = "x", ylab = "Frequency", ylim = c(0, 30)
)
points(x, n * y, type = "h", lwd = 5, col = "red")
legend("topright",
    legend = c("Observed", "Expected"),
    col = c("blue", "red"), lwd = 10, inset = 0.02
)

