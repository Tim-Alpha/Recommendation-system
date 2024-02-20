import csv
import numpy as np

# Define the filename
filename = "post.csv"

# Define lists to store the values
ids = []
# categoryId = []
average_rating = []
view_counts = []
exit_count = []

# Read data from the CSV file
with open(filename, newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        # Append values to the lists
        ids.append(int(row['id']))
        # categoryId.append(int(row['category_id']))
        average_rating.append(int(row['average_rating']))
        view_counts.append(int(row['view_count']))
        exit_count.append(int(row['exit_count']))

# Create a vector from the lists
vector_data = list(zip(average_rating, view_counts, exit_count))
# vector_data = list(zip(average_rating, view_counts, exit_count, categoryId))

# Print the vector data
# print("Vector data:")
# print(vector_data)

# Take input from the user
# print("Enter a 3d vector have `average_rating`, `view_count`, `exit_count` & `title`:\n")
ar = int(input("Enter average rating: "))
vc = int(input("Enter view count: "))
ec = int(input("Enter exit count: "))
cId = int(input("Enter category_id: "))

# Convert inputs into a vector
input_vector = np.array([ar, vc, ec])
# input_vector = np.array([ar, vc, ec, cId])


print("Input vectors: ", input_vector)

# Calculate the Euclidean distance between the input vector and each vector in the dataset
distances = np.linalg.norm(vector_data - input_vector, axis=1)

# Sort the indices based on the distances
nearest_indices = np.argsort(distances)

# Print the 5 nearest vectors along with their IDs
print("5 Nearest Vectors Similar to the Given Input Vector:")
for i in range(5):
    index = nearest_indices[i]
    print("ID:", ids[index], "Vector:", vector_data[index], "Distance:", distances[index])
    # print("ID:", ids[index], "CategoryId:", categoryId[index], "Vector:", vector_data[index][:3], "Distance:", distances[index])