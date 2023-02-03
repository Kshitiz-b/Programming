mid <- seq(132, 162, 5)
mid
f <- c(5, 15, 28, 24, 17, 10, 1)
fr.distr <- data.frame(mid, f)
fr.distr

mean <- (sum(mid * f)) / sum(f)
mean

midx <- seq(132, 162, 5)
frequency <- c(5, 15, 28, 24, 17, 10, 1)
fr.dist <- data.frame(midx, frequency)
fr.dist

cl <- cumsum(frequency)
cl
n <- sum(frequency)
n
ml <- min(which(cl >= n / 2))
ml
h <- ml
h
f <- frequency[ml]
f
c <- cl[ml - 1]
c
l <- mid[ml] - h / 2
l

median <- l + (((n / 2) - c) / f) * h
median
