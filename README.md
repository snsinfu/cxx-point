cxx-point
=========

![C++11][cxx-badge]
[![Build Status][travis-badge]][travis-url]
[![Boost License][license-badge]][license-url]

Minimal three-dimensional vector/point library for C++11 and later. No geometric
algorithm or linear algebra; just vectors and points. [API docs][docs].

```c++
#include <iostream>
#include "point.hpp"

int main()
{
    cxx::point pa = {2, 4, 8};
    cxx::point pb = {3, 5, 7};

    cxx::vector r1 = pa - pb;
    cxx::vector r2 = {1, 6, 9};

    std::cout << r1.cross(r2).normalize() << '\n';
}
```

[cxx-badge]: https://img.shields.io/badge/C%2B%2B-11-orange.svg
[license-badge]: https://img.shields.io/badge/license-Boost-blue.svg
[license-url]: https://raw.githubusercontent.com/snsinfu/cxx-point/master/LICENSE.txt
[travis-badge]: https://travis-ci.org/snsinfu/cxx-point.svg?branch=master
[travis-url]: https://travis-ci.org/snsinfu/cxx-point
[docs]: https://github.com/snsinfu/cxx-point/blob/master/API.md

- [Installation](#installation)
- [Testing](#testing)
- [License](#license)

## Installation

Just download [point.hpp][point.hpp] into your include directory. It is single
header-only and has zero dependency.

[point.hpp]: https://raw.githubusercontent.com/snsinfu/cxx-point/master/include/point.hpp

## Testing

Tests require a C++11 compiler with gcc-compatible command line options.

```console
git clone https://github.com/snsinfu/cxx-point
cd cxx-point/tests
make
```

## License

Boost Software License, Version 1.0.
