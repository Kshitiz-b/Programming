import numpy as np
import matplotlib.pyplot as plt

x_train = np.array([1.0, 2.0])
y_train = np.array([300.0, 500.0])
print(f"x_train = {x_train}")
print(f"y_train = {y_train}")

m = len(x_train)
print(f"m = {m}")

plt.scatter(x_train, y_train, marker='o', c='r')
plt.title("Training Data")
plt.xlabel("x_train")
plt.ylabel("y_train")
plt.show()

def compute_model_output(x, w, b):
    m = len(x)
    f_wb = np.zeros(m)
    for i in range(m):
        f_wb[i] = w*x[i] + b
    
    return f_wb


w = 200
b = 100
tmp_fwb = compute_model_output(x_train, w, b)

plt.plot(x_train, tmp_fwb, c='b', label='Prediction')
plt.scatter(x_train, y_train, marker='o', c='r', label='Training Data')
plt.title("Training Data")
plt.xlabel("x_train")
plt.ylabel("y_train")
plt.legend()
plt.show()

x_i = 1.2
cost = w*x_i + b
print(f"cost = {cost}")
