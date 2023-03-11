#21BCE2067
#Kshitiz Bhargava
X <- c(30, 40, 20, 50, 60, 40, 20, 60)
Y <- c(110, 80, 70, 120, 150, 90, 70, 120)
Z <- c(11, 10, 7, 15, 19, 12, 8, 14)
model <- lm(Y ~ X + Z)
summary(model)
plot(model, main="------Kshitiz Bhargava 21BCE2067------")
