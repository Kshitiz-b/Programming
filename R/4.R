mid <- seq(147.5, 182.5, 5)
print(mid)

f <- c(4, 6, 28, 58, 64, 30, 5, 5)
fr.distr <- data.frame(mid, f)
print(fr.distr)

mean <- (sum(mid * f)) / sum(f)
print(mean)

midx = seq(147.5, 182.5, 5)
fr.dist = data.frame(midx, f)
print(fr.dist)

cl = cumsum(f)


# x = c(18,19,19,19,19,20,20,20,20,20,21,21,21,21,22,23,24,27,30,36)
# y=mean(x)
# print(y)
