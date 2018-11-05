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
