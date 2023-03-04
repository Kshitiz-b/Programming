#21BCE2067
#Kshitiz Bhargava
rank_A <- c(3, 5, 8, 4, 7, 10, 2)
rank_B <- c(6, 4, 9, 8, 1, 2, 1)
rank_correlation <- cor(rank_A, rank_B, method = "spearman")
print(rank_correlation)
