# Documentation

## cxx::vector

For `cxx::vector u, v`, `double x, y, z`, `std::istream in` and
`std::ostream out`:

| Expression             | Meaning                           |
| ---------------------- | --------------------------------- |
| cxx::vector{}          | zero vector                       |
| cxx::vector{x, y, z}   | vector with components (x, y, z)  |
| u.x, u[0]              | x-component of u                  |
| u.y, u[1]              | y-component of u                  |
| u.z, u[2]              | z-component of u                  |
| u += v                 | add v to u                        |
| u -= v                 | subtract v from u                 |
| u \*= x                | scale u by x                      |
| u /= x                 | scale u by 1/x                    |
| +u                     | copy of u                         |
| -u                     | negated copy of u                 |
| u + v                  | sum of u and v                    |
| u - v                  | difference of u and v             |
| u \* x                 | copy of u scaled by x             |
| x \* u                 | copy of u scaled by x             |
| u / x                  | copy of u scaled by 1/x           |
| u.dot(v)               | dot product of u and v            |
| u.cross(v)             | cross product of u and v          |
| u.norm()               | Euclidean norm of u               |
| u.squared\_norm()      | squared Euclidean norm of u       |
| u.normalize()          | u/norm(u)                         |
| cxx::dot(u, v)         | u.dot(v)                          |
| cxx::cross(u, v)       | u.cross(v)                        |
| cxx::norm(u)           | u.norm()                          |
| cxx::squared\_norm(u)  | u.squared\_norm()                 |
| cxx::normalize(u)      | u.normalize()                     |
| in >> u                | read "x y z" from in              |
| out << u               | write "x y z" to out              |

## cxx::point

For `cxx::point p, q` and `double x, y, z`, `std::istream in` and
`std::ostream out`:

| Expression                   | Meaning                                    |
| ---------------------------- | ------------------------------------------ |
| cxx::point{}                 | origin                                     |
| cxx::point{x, y, z}          | point with coordinates (x, y, z)           |
| p.x, p[0]                    | x-coordinate of p                          |
| p.y, p[1]                    | y-coordinate of p                          |
| p.z, p[2]                    | z-coordinate of p                          |
| p.vector()                   | coordinate vector as cxx::vector           |
| p += u                       | translate p by u                           |
| p -= u                       | translate p by -u                          |
| p + u                        | copy of p translated by u                  |
| p - u                        | copy of p translated by -u                 |
| p - q                        | displacement vector from q to p            |
| p.distance(q)                | Euclidean distance between p and q         |
| p.squared\_distance(q)       | squared Euclidean distance between p and q |
| cxx::distance(p, q)          | p.distance(q)                              |
| cxx::squared\_distance(p, q) | p.squared\_distance(q)                     |
| in >> q                      | read "x y z" from in                       |
| out << p                     | write "x y z" to out                       |
