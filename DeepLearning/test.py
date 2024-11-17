import tensorflow as tf 
from keras.datasets import mnist 
from keras.models import Sequential 
from keras.layers import Dense, Flatten 
from keras.utils import to_categorical 
import matplotlib.pyplot as plt

# Load the MNIST dataset
(x_train, y_train), (x_test, y_test) = mnist.load_data()

# Normalize the input data
x_train = x_train.astype('float32') / 255
x_test = x_test.astype('float32') / 255

# Convert labels to one-hot encoding
y_train = to_categorical(y_train, 10)  # Ensure labels are (num_samples, num_classes)
y_test = to_categorical(y_test, 10)

# Verify the shape of the one-hot encoded labels
print(f"Shape of y_train: {y_train.shape}")  # Should be (60000, 10)
print(f"Shape of y_test: {y_test.shape}")    # Should be (10000, 10)

# Build the feedforward neural network model
model = Sequential([
    Flatten(input_shape=(28, 28)),  # Flatten the input image
    Dense(128, activation='relu'),  # First hidden layer with 128 neurons
    Dense(64, activation='relu'),   # Second hidden layer with 64 neurons
    Dense(10, activation='softmax') # Output layer with 10 neurons for 10 classes
])

# Define the loss function and optimizer
loss_object = tf.keras.losses.CategoricalCrossentropy()
optimizer = tf.keras.optimizers.Adam()

# Prepare metrics
train_loss = tf.keras.metrics.Mean(name='train_loss')
train_accuracy = tf.keras.metrics.CategoricalAccuracy(name='train_accuracy')
val_accuracy = tf.keras.metrics.CategoricalAccuracy(name='val_accuracy')

# Training step function
@tf.function
def train_step(images, labels):
    with tf.GradientTape() as tape:
        predictions = model(images, training=True)
        loss = loss_object(labels, predictions)
    gradients = tape.gradient(loss, model.trainable_variables)
    optimizer.apply_gradients(zip(gradients, model.trainable_variables))
    train_loss(loss)
    train_accuracy(labels, predictions)

# Validation step function
@tf.function
def val_step(images, labels):
    predictions = model(images, training=False)
    val_accuracy(labels, predictions)

# Training loop
EPOCHS = 10
BATCH_SIZE = 32

# Create TensorFlow datasets from the data
train_dataset = tf.data.Dataset.from_tensor_slices((x_train, y_train)).shuffle(60000).batch(BATCH_SIZE)
val_dataset = tf.data.Dataset.from_tensor_slices((x_test, y_test)).batch(BATCH_SIZE)

# Initialize history to track metrics
history = {'accuracy': [], 'val_accuracy': []}

# Run training and validation
for epoch in range(EPOCHS):
    # Reset the metrics at the start of each epoch
    train_loss.reset_state()
    train_accuracy.reset_state()
    val_accuracy.reset_state()

    for images, labels in train_dataset:
        train_step(images, labels)

    for val_images, val_labels in val_dataset:
        val_step(val_images, val_labels)

    history['accuracy'].append(train_accuracy.result().numpy())
    history['val_accuracy'].append(val_accuracy.result().numpy())

    print(f'Epoch {epoch + 1}, '
          f'Loss: {train_loss.result()}, '
          f'Training Accuracy: {train_accuracy.result() * 100:.2f}, '
          f'Validation Accuracy: {val_accuracy.result() * 100:.2f}')

# Plotting accuracy history
plt.plot(history['accuracy'], label='Training Accuracy')
plt.plot(history['val_accuracy'], label='Validation Accuracy')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.legend()
plt.title('Model Accuracy')
plt.show()