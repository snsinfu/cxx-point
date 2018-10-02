// Copyright snsinfu 2018.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstream>

#include "catch.hpp"
#include "../include/point.hpp"


TEST_CASE("point - is default constructible as the origin")
{
    cxx::point pt;
    CHECK(pt.x == 0);
    CHECK(pt.y == 0);
    CHECK(pt.z == 0);
}

TEST_CASE("point - is constructible from coordinate values")
{
    cxx::point pt = {1, 2, 3};
    CHECK(pt.x == 1);
    CHECK(pt.y == 2);
    CHECK(pt.z == 3);
}

TEST_CASE("point - provides mutable element references")
{
    cxx::point pt = {1, 2, 3};
    CHECK(&pt[0] == &pt.x);
    CHECK(&pt[1] == &pt.y);
    CHECK(&pt[2] == &pt.z);
}

TEST_CASE("point - provides const element references")
{
    cxx::point const pt = {1, 2, 3};
    CHECK(&pt[0] == &pt.x);
    CHECK(&pt[1] == &pt.y);
    CHECK(&pt[2] == &pt.z);
}

TEST_CASE("point::vector - returns coordinate vector")
{
    cxx::point const pt = {1, 2, 3};
    cxx::vector const vec = pt.vector();
    CHECK(vec.x == pt.x);
    CHECK(vec.y == pt.y);
    CHECK(vec.z == pt.z);
}

TEST_CASE("point - may be translated by a vector")
{
    cxx::point pt = {2, 4, 6};
    pt += cxx::vector {5, 1, 3};
    CHECK(pt.x == 7);
    CHECK(pt.y == 5);
    CHECK(pt.z == 9);
}

TEST_CASE("point - may be translated by a negated vector")
{
    cxx::point pt = {2, 4, 6};
    pt -= cxx::vector {3, 1, 5};
    CHECK(pt.x == -1);
    CHECK(pt.y == 3);
    CHECK(pt.z == 1);
}

TEST_CASE("point - supports translation by vector addition")
{
    cxx::point const pt = {2, 4, 6};
    cxx::vector const vec = {5, 1, 3};
    cxx::point const dest = pt + vec;
    CHECK(dest.x == 7);
    CHECK(dest.y == 5);
    CHECK(dest.z == 9);
}

TEST_CASE("point - supports translation by vector subtraction")
{
    cxx::point const pt = {2, 4, 6};
    cxx::vector const vec = {3, 1, 5};
    cxx::point const dest = pt - vec;
    CHECK(dest.x == -1);
    CHECK(dest.y == 3);
    CHECK(dest.z == 1);
}

TEST_CASE("point - difference gives translation vector")
{
    cxx::point const pa = {2, 4, 6};
    cxx::point const pb = {7, 5, 3};
    cxx::vector const vec = pa - pb;
    CHECK(vec.x == -5);
    CHECK(vec.y == -1);
    CHECK(vec.z == 3);
}

TEST_CASE("point::squared_distance - returns squared Euclidean distance")
{
    cxx::point const pa = {2, 4, 6};
    cxx::point const pb = {7, 5, 3};
    CHECK(pa.squared_distance(pb) == 35);
}

TEST_CASE("point::distance - returns Euclidean distance")
{
    cxx::point const pa = {2, 4, 6};
    cxx::point const pb = {7, 5, 3};
    CHECK(pa.distance(pb) == Approx(5.916079783));
}

TEST_CASE("squared_distance - returns squared Euclidean distance between points")
{
    cxx::point const pa = {2, 4, 6};
    cxx::point const pb = {7, 5, 3};
    CHECK(cxx::squared_distance(pa, pb) == 35);
}

TEST_CASE("distance - returns Euclidean distance between points")
{
    cxx::point const pa = {2, 4, 6};
    cxx::point const pb = {7, 5, 3};
    CHECK(cxx::distance(pa, pb) == Approx(5.916079783));
}

TEST_CASE("point - is formattable")
{
    cxx::point const pt {1.2, 3.4, 5.6};
    std::ostringstream str;
    str << '(' << pt << ')';
    CHECK(str.str() == "(1.2 3.4 5.6)");
}

TEST_CASE("point - is parsable")
{
    cxx::point pt;
    std::istringstream str{"1.2 3.4 5.6"};
    str >> pt;
    CHECK(pt.x == Approx(1.2));
    CHECK(pt.y == Approx(3.4));
    CHECK(pt.z == Approx(5.6));
}
