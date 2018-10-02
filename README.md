point.hpp
=========

![C++11][cxx-badge]
[![Build Status][travis-badge]][travis-url]
[![Boost License][license-badge]][license-url]

Minimal single header-only library of three-dimensional vector and point.

```c++
#include <iostream>
#include "point.hpp"

int main()
{
    cxx::point pa = {2, 4, 8};
    cxx::point pb = {3, 5, 7};
    std::cout << (pa - pb).norm() << '\n';
}
```

[cxx-badge]: https://img.shields.io/badge/C%2B%2B-11-orange.svg
[license-badge]: https://img.shields.io/badge/license-Boost-blue.svg
[license-url]: https://raw.githubusercontent.com/snsinfu/cxx-point/master/LICENSE.txt
[travis-badge]: https://travis-ci.org/snsinfu/cxx-point.svg?branch=master
[travis-url]: https://travis-ci.org/snsinfu/cxx-point

- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [License](#license)

## Installation

point.hpp is single header-only and has zero dependency. Just download
[point.hpp][header] into your include directory and `#include` it.

```console
curl -LO https://raw.githubusercontent.com/snsinfu/cxx-point/master/include/point.hpp
```

Also, point.hpp comes with a very permissive license and can easily integrated
into your code base just by renaming include guard and namespace (if necessary).

[header]: https://raw.githubusercontent.com/snsinfu/cxx-point/master/include/point.hpp

## Usage

The header provides two classes: `cxx::vector` and `cxx::point`. `cxx::vector`
supports linear operations and norm calculation, whereas `cxx::point` supports
affine operations and distance calculation. [API docs][api].

[api]: https://github.com/snsinfu/cxx-point/blob/master/API.md

### Example

```c++
#include <iostream>
#include "point.hpp"

// Compute the potential energy and force acting on a point in a harmonic well.

int main()
{
    cxx::point center;
    cxx::point position = {1, 2, 3};

    double spring_constant = 10;
    double energy = spring_constant * position.squared_distance(center) / 2;
    cxx::vector force = -spring_constant * (position - center);

    std::cout << "Energy: " << energy << '\n';
    std::cout << "Force: " << force << '\n';
}
```

## Testing

Tests require g++ or clang++ supporting c++11.

```console
git clone https://github.com/snsinfu/cxx-point
cd cxx-point/tests
make
```

## License

Boost Software License, Version 1.0.
