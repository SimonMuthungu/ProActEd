import joblib
import pandas as pd
import tensorflow as tf

#from tensorflow.keras.callbacks import EarlyStopping



dummy_data_path = r'C:\Users\Simon\proacted\ProActEd\AIacademia\python_scripts\trainwith_100000.xlsx'

# Load data from Excel into a DataFrame
training_data = pd.read_excel(dummy_data_path)

X = training_data[['Lessons_Attended', 'Aggregate points']]
y = training_data['passed']

# Convert pandas DataFrames to TensorFlow Datasets
X_dataset = tf.data.Dataset.from_tensor_slices(X.values)
y_dataset = tf.data.Dataset.from_tensor_slices(y.values)

# Combine features and labels into a single dataset
dataset = tf.data.Dataset.zip((X_dataset, y_dataset))

# Shuffle and split the dataset
dataset = dataset.shuffle(buffer_size=len(X))

# Split the dataset into training and testing sets
train_size = int(0.8 * len(X))
test_size = int(len(X) - train_size)

# Create separate iterators for training and testing
train_dataset = dataset.take(train_size).batch(batch_size=32)
test_dataset = dataset.skip(train_size).batch(batch_size=32)



# for x, y in dataset.take(5):  # Print the first 5 examples
#     print("Features:", x.numpy())
#     print("Labels:", y.numpy())

print(f"Train dataset size: {len(train_dataset)}")
print(f"Test dataset size: {len(test_dataset)}")


# Define a model using TensorFlow (a logistic regression model)
model = tf.keras.Sequential([
    tf.keras.layers.Dense(32, activation='relu', input_shape=(2,)),
    tf.keras.layers.Dense(1, activation='sigmoid')
])

# to auto-monitor when were overfitting
early_stopping = EarlyStopping(monitor='accuracy', 
                               patience=5, 
                               min_delta=0.001,
                               mode='max',
                               verbose=1) 

# Compile and train the model
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

history = model.fit(train_dataset,
                    epochs=30,
                    callbacks=[early_stopping])

# Evaluate the model on the test dataset
test_loss, test_accuracy = model.evaluate(test_dataset)
print(f'Test Accuracy: {test_accuracy}')

# Save the trained model using joblib
joblib.dump(model, r'C:\Users\Simon\proacted\ProActEd\AIacademia\trained_models\no_bias_trainedw_100000_10288genii.joblib')