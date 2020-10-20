# Documentation

## cxx::vector

`vector` is a three-dimensional vector with x, y and z components. It supports
linear operations, dot and cross products, norm calculation and iostream.

For `cxx::vector u, v`, `double x, y, z`, `std::istream in` and
`std::ostream out`:

| Expression                          | Meaning                           |
| ----------------------------------- | --------------------------------- |
| vector{}                            | zero vector                       |
| vector{x, y, z}                     | vector with components (x, y, z)  |
| u.x, u[0]                           | x-component of u                  |
| u.y, u[1]                           | y-component of u                  |
| u.z, u[2]                           | z-component of u                  |
| u += v                              | add v to u                        |
| u -= v                              | subtract v from u                 |
| u \*= x                             | scale u by x                      |
| u /= x                              | scale u by 1/x                    |
| +u                                  | copy of u                         |
| -u                                  | negated copy of u                 |
| u + v                               | sum of u and v                    |
| u - v                               | difference of u and v             |
| u \* x                              | copy of u scaled by x             |
| x \* u                              | copy of u scaled by x             |
| u / x                               | copy of u scaled by 1/x           |
| u.dot(v), dot(u, v)                 | dot product of u and v            |
| u.cross(v), cross(u, v)             | cross product of u and v          |
| u.hadamard(v), hadamard(u, v)       | Hadamard product of u and v       |
| u.norm(), norm(u)                   | Euclidean norm of u               |
| u.squared\_norm(), squared\_norm(u) | squared Euclidean norm of u       |
| u.normalize(), normalize(u)         | u/norm(u)                         |
| u.project(v), project(u, v)         | u projected onto v                |
| in >> u                             | read "x y z" from in              |
| out << u                            | write "x y z" to out              |

## cxx::point

`point` is a point in a three-dimensional Euclidean space with x, y and z
coordinates. Supports translation by vector, distance calculation and iostream.

For `cxx::point p, q` and `double x, y, z`, `std::istream in` and
`std::ostream out`:

| Expression                                      | Meaning                          |
| ----------------------------------------------- | -------------------------------- |
| point{}                                         | origin                           |
| point{x, y, z}                                  | point with coordinates (x, y, z) |
| p.x, p[0]                                       | x-coordinate of p                |
| p.y, p[1]                                       | y-coordinate of p                |
| p.z, p[2]                                       | z-coordinate of p                |
| p.vector()                                      | coordinate vector as cxx::vector |
| p += u                                          | translate p by u                 |
| p -= u                                          | translate p by -u                |
| p + u                                           | copy of p translated by u        |
| p - u                                           | copy of p translated by -u       |
| p - q                                           | displacement vector from q to p  |
| p.distance(q), distance(p, q)                   | distance between p and q         |
| p.squared\_distance(q), squared\_distance(p, q) | squared distance between p and q |
| in >> q                                         | read "x y z" from in             |
| out << p                                        | write "x y z" to out             |

## cxx::matrix

`matrix` is a three-dimensional square matrix. It supports linear operations,
matrix products, vector left-products and iostream.

For `cxx::matrix A, B`, `cxx::vector v`, `double a, b, c, r, s, t, x, y, z`,
`size_t i, j`, `std::istream in` and `std::ostream out`:

| Expression                          | Meaning                           |
| ----------------------------------- | --------------------------------- |
| matrix{}                            | zero matrix                       |
| matrix{a, b, c}                     | diagonal matrix                   |
| matrix{a, b, c, r, s, t, x, y, z}   | full 3-by-3 matrix                |
| A(i, j)                             | i,j-component of A                |
| A += B                              | add v to u                        |
| A -= B                              | subtract v from u                 |
| A \*= a                             | multiply all elements of A by a   |
| A /= a                              | divide all elements of A by a     |
| +A                                  | copy of A                         |
| -A                                  | negated copy of A                 |
| A + B                               | sum of A and B                    |
| A - B                               | difference of A and B             |
| A \* a                              | copy of A scaled by a             |
| a \* A                              | copy of A scaled by a             |
| A / a                               | copy of A scaled by 1/a           |
| A.dot(B), dot(A, B)                 | matrix product of A and B         |
| A.dot(v), dot(A, v)                 | matrix product of A and v         |
| A.transpose(), transpose(A)         | transposed copy of A              |
| in >> A                             | read "a b c r s t x y z" from in  |
| out << A                            | write "a b c r s t x y z" to out  |
