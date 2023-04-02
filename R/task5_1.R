# 21BCE2067
# Kshitiz Bhargava
x <- 0:6
f <- c(5, 18, 28, 12, 7, 6, 4)
n <- 6
mean <- sum(f * x) / sum(f)
p <- mean / n
p
expf <- dbinom(x, n, p)
f1 <- round(sum(f) * expf)
sum(f)
obf <- c(sum(expf[0:2]), expf[3:4], sum(expf[5:7]))
exf <- c(sum(f[0:2]), f[3:4], sum(f[5:7]))
chisq <- sum(((obf - exf)^2) / exf) / 12.19
chisq
