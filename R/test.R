x <- seq(132, 162, 5)
f <- c(5,15,28,24,17,10,1)
mean <- sum(x*f)/sum(f)
mean
h=4
cf <- cumsum(f)
n <- sum(f)
ml <- min(which(cf >= n/2))
ml
freq <- f[ml]
c <- cf[ml-1]
l <- x[ml]-h/2
median <- l+(((n/2)-c)/freq)*h
median
mode <- 3*median - 2*mean
mode