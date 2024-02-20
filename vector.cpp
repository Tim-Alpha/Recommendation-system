#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../../../../../usr/include/c++/13/bits/stl_numeric.h"

using namespace std;

int main() {
    // FileName
    string fileName = "post.csv";

    // Vectors to store the values
    vector<int> ids, average_rating, view_counts, exit_count;

    // Read data from the CSV file
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        bool first_line = true;
        while (getline(file, line)) {
            if (first_line) {
                first_line = false;
                continue; // Skip the header row
            }

            stringstream ss(line);
            string token;
            vector<string> tokens;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            ids.push_back(stoi(tokens[0]));
            average_rating.push_back(stoi(tokens[20]));
            view_counts.push_back(stoi(tokens[18]));
            exit_count.push_back(stoi(tokens[19]));
        }
        file.close();
    } else {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Create a 2D vector from the arrays
    vector<vector<int>> vector_data;
    for (size_t i = 0; i < average_rating.size(); ++i) {
        vector<int> row = {average_rating[i], view_counts[i], exit_count[i]};
        vector_data.push_back(row);
    }

    // Take input from the user
    int ar, vc, ec;
    cout << "Enter average rating: ";
    cin >> ar;
    cout << "Enter view count: ";
    cin >> vc;
    cout << "Enter exit count: ";
    cin >> ec;

    cout << "Input vectors: " << ar << ", " << vc << ", " << ec << endl;

    // Calculate the Euclidean distance between the input vector and each vector in the dataset
    vector<double> distances;
    for (const auto& vec : vector_data) {
        double dist = 0.0;
        for (size_t i = 0; i < vec.size(); ++i) {
            dist += pow(vec[i] - ar, 2);
        }
        distances.push_back(sqrt(dist));
    }

    // Sort the distances and preserve the original indices
    vector<size_t> indices(distances.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&distances](size_t a, size_t b) { return distances[a] < distances[b]; });

    // Print the 5 nearest vectors along with their IDs
    cout << "5 Nearest Vectors Similar to the Given Input Vector:" << endl;
    for (size_t i = 0; i < min<size_t>(5, indices.size()); ++i) {
        size_t index = indices[i];
        cout << "ID: " << ids[index] << ", Vector: [" << vector_data[index][0] << ", " << vector_data[index][1] << ", " << vector_data[index][2] << "], Distance: " << distances[index] << endl;
    }

    return 0;
}
