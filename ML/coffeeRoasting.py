import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
import keras
from keras.layers import Dense

x = np.array([[200.0, 17.0]])   #1x2 matrix
layer_1 = Dense(units=3, activation = 'sigmoid')
a1 = layer_1(x)
print(a1)

layer_2 = Dense(units=1, activation = 'sigmoid')
a2 = layer_2(a1)

if a2 >= 0.5:
    yhat = 1
else:
    yhat = 0

print(f"yhat = {yhat}")
if yhat == 1:
    print("Beans are Roasted")
else:
    print("Beans are not Roasted")