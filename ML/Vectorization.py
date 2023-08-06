# Vectorization 
import numpy as np

w = np.array([1,2,3])
b = 4
x = np.array([10,20,30])

f = np.dot(w,x) + b

print(f)