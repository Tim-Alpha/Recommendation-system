<?php

// Define the filename
$filename = "post.csv";

// Define arrays to store the values
$ids = [];
$average_rating = [];
$view_counts = [];
$exit_count = [];

// Read data from the CSV file
$file = fopen($filename, 'r');
if ($file) {
    while (($row = fgetcsv($file)) !== false) {
        // Skip the header row
        if ($row[0] === 'id') {
            continue;
        }
        // Append values to the arrays
        $ids[] = intval($row[0]);
        $average_rating[] = intval($row[20]);
        $view_counts[] = intval($row[18]);
        $exit_count[] = intval($row[19]);
    }
    fclose($file);
}

// Create a 2D array from the arrays
$vector_data = array_map(null, $average_rating, $view_counts, $exit_count);

// Take input from the user
$ar = intval(readline("Enter average rating: "));
$vc = intval(readline("Enter view count: "));
$ec = intval(readline("Enter exit count: "));

// Convert inputs into an array
$input_vector = [$ar, $vc, $ec];

echo "Input vectors: " . implode(", ", $input_vector) . PHP_EOL;

// Calculate the Euclidean distance between the input vector and each vector in the dataset
$distances = [];
foreach ($vector_data as $vector) {
    $dist = 0;
    for ($i = 0; $i < count($vector); $i++) {
        $dist += pow($vector[$i] - $input_vector[$i], 2);
    }
    $distances[] = sqrt($dist);
}

// Sort the distances and preserve the original indices
asort($distances);

// Print the 5 nearest vectors along with their IDs
echo "5 Nearest Vectors Similar to the Given Input Vector:" . PHP_EOL;
$count = 0;
foreach ($distances as $index => $distance) {
    echo "ID: {$ids[$index]}, Vector: [" . implode(", ", $vector_data[$index]) . "], Distance: $distance" . PHP_EOL;
    $count++;
    if ($count >= 5) {
        break;
    }
}
