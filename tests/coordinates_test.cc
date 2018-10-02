// Copyright snsinfu 2018.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstream>

#include "catch.hpp"
#include "../include/point.hpp"


TEST_CASE("coordinates - is default constructible as zero tuple")
{
    cxx::point_detail::coordinates coords;
    CHECK(coords.x == 0);
    CHECK(coords.y == 0);
    CHECK(coords.z == 0);
}

TEST_CASE("coordinates - is constructible from coordinate values")
{
    cxx::point_detail::coordinates coords = {1, 2, 3};
    CHECK(coords.x == 1);
    CHECK(coords.y == 2);
    CHECK(coords.z == 3);
}

TEST_CASE("coordinates - provide mutable element references")
{
    cxx::point_detail::coordinates coords = {1, 2, 3};
    CHECK(&coords[0] == &coords.x);
    CHECK(&coords[1] == &coords.y);
    CHECK(&coords[2] == &coords.z);
}

TEST_CASE("coordinates - provide const element references")
{
    cxx::point_detail::coordinates const coords = {1, 2, 3};
    CHECK(&coords[0] == &coords.x);
    CHECK(&coords[1] == &coords.y);
    CHECK(&coords[2] == &coords.z);
}

TEST_CASE("coordinates - is formattable")
{
    cxx::point_detail::coordinates const coords = {1.2, 3.4, 5.6};
    std::ostringstream str;
    str << '(' << coords << ')';
    CHECK(str.str() == "(1.2 3.4 5.6)");
}

TEST_CASE("coordinates - is parsable")
{
    cxx::point_detail::coordinates coords;
    std::istringstream str{"1.2 3.4 5.6"};
    str >> coords;
    CHECK(coords.x == Approx(1.2));
    CHECK(coords.y == Approx(3.4));
    CHECK(coords.z == Approx(5.6));
}
