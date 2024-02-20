
# Vector Creation and Comparison using Euclidean Distance

## Vector Creation from Lists

The process involves creating 3-dimensional vectors (3D vectors) from lists of `average_rating`, `view_counts`, and `exit_count`. These vectors represent posts, with each dimension corresponding to an attribute of the post.

Example:
- Lists: `average_rating = [4, 3]`, `view_counts = [100, 200]`, `exit_count = [10, 20]`
- Resulting vectors: `vector_data = [(4, 100, 10), (3, 200, 20)]`

## Comparison Using Euclidean Distance

To compare an input vector to each vector in the dataset, we calculate the Euclidean distance. For two 3D vectors \(P = (p_1, p_2, p_3)\) and \(Q = (q_1, q_2, q_3)\), the distance \(d(P, Q)\) is calculated as:

\[
d(P, Q) = \sqrt{(p_1 - q_1)^2 + (p_2 - q_2)^2 + (p_3 - q_3)^2}
\]

This method finds the posts most similar to the user's input, using Euclidean distance as a similarity measure.
