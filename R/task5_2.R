# 21BCE2067
# Kshitiz Bhargava
x <- 0:6
f <- c(275, 72, 80, 7, 5, 2, 1)
lambda <- (sum(f * x) / sum(f))
expf <- dpois(x, lambda) * sum(f)
f1 <- round(expf)
sum(f)
sum(f1)
obf <- c(275, 72, 30, 15)
exf <- c(242, 117, 28, 6)
chisq <- sum(((obf - exf)^2) / exf)
chisq
qchisq(0.95, 2)
