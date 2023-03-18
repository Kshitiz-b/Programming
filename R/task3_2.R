ppois(5, 4, lower.tail = FALSE)

ppois(100, 4) - ppois(9, 4)

x <- 0:100
pmf <- dpois(x, 4)
plot(x, pmf, type = "h", lwd = 2, main = "Poisson Distribution with λ = 4", xlab = "X", ylab = "PMF")
abline(v = 10, col = "blue", lwd = 2, lty = 2)
abline(v = 100, col = "blue", lwd = 2, lty = 2)
