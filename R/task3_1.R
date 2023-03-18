#21BCE2067
#Kshitiz Bhargava
pbinom(4, 6, 0.95, lower.tail = FALSE)

pbinom(4, 6, 0.95) - pbinom(1, 6, 0.95)

x <- 0:6
pmf <- dbinom(x, 6, 0.95)
table <- data.frame(X = x, PMF = pmf)
print(table)
hist(x, breaks = seq(-0.5, 6.5, 1), freq = FALSE, main = "Binomial Distribution with n = 6, p = 0.95", xlab = "X", ylab = "PMF")
lines(x, pmf, type = "h")

mean(6, 0.95)
var(6, 0.95)

x <- 0:6
cdf <- pbinom(x, 6, 0.95)
plot(x, cdf, type = "s", main = "Binomial Distribution with n = 6, p = 0.95", xlab = "X", ylab = "CDF")
