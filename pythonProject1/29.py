# For Deletion

# remove(value) --> removes a value in the list
L = [1, 2, 3, 4, 5, 6, 7, 8, 9]
L.remove(3)
print(L)

# pop(index) --> removes the value given in the index
L.pop(4)
print(L)

# del
del(L[1])
print(L)

# clear()
L.clear()
print(L)

del L  # Deletes the whole list
