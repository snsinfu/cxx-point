// Copyright snsinfu 2018.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstream>

#include "catch.hpp"
#include "../include/point.hpp"


TEST_CASE("vector - is default constructible as the null vector")
{
    cxx::vector vec;
    CHECK(vec.x == 0);
    CHECK(vec.y == 0);
    CHECK(vec.z == 0);
}

TEST_CASE("vector - is constructible from components")
{
    cxx::vector vec = {1, 2, 3};
    CHECK(vec.x == 1);
    CHECK(vec.y == 2);
    CHECK(vec.z == 3);
}

TEST_CASE("vector - provides mutable element references")
{
    cxx::vector vec = {1, 2, 3};
    CHECK(&vec[0] == &vec.x);
    CHECK(&vec[1] == &vec.y);
    CHECK(&vec[2] == &vec.z);
}

TEST_CASE("vector - provides const element references")
{
    cxx::vector const vec = {1, 2, 3};
    CHECK(&vec[0] == &vec.x);
    CHECK(&vec[1] == &vec.y);
    CHECK(&vec[2] == &vec.z);
}

TEST_CASE("vector - in-place addition works component-wise")
{
    cxx::vector vec = {2, 4, 6};
    vec += cxx::vector {5, 1, 3};
    CHECK(vec.x == 7);
    CHECK(vec.y == 5);
    CHECK(vec.z == 9);
}

TEST_CASE("vector - in-place subtraction works component-wise")
{
    cxx::vector vec = {2, 4, 6};
    vec -= cxx::vector {3, 1, 5};
    CHECK(vec.x == -1);
    CHECK(vec.y == 3);
    CHECK(vec.z == 1);
}

TEST_CASE("vector - in-place multiplication is broadcast")
{
    cxx::vector vec = {3, 5, 7};
    vec *= 2;
    CHECK(vec.x == 6);
    CHECK(vec.y == 10);
    CHECK(vec.z == 14);
}

TEST_CASE("vector - in-place division is broadcast")
{
    cxx::vector vec = {3, 5, 7};
    vec /= 2;
    CHECK(vec.x == Approx(1.5));
    CHECK(vec.y == Approx(2.5));
    CHECK(vec.z == Approx(3.5));
}

TEST_CASE("vector::dot - returns dot product")
{
    cxx::vector const va = {2, 4, 6};
    cxx::vector const vb = {7, 5, 3};
    CHECK(va.dot(vb) == 52);
}

TEST_CASE("vector::cross - returns cross product")
{
    cxx::vector const va = {2, 4, 6};
    cxx::vector const vb = {3, 1, 5};
    cxx::vector const vc = va.cross(vb);
    CHECK(vc.x == 14);
    CHECK(vc.y == 8);
    CHECK(vc.z == -10);
}

TEST_CASE("vector::squared_norm - returns squared Euclidean norm")
{
    cxx::vector const vec = {2, 3, 4};
    CHECK(vec.squared_norm() == 29);
}

TEST_CASE("vector::norm - returns Euclidean norm")
{
    cxx::vector const vec = {2, 3, 4};
    CHECK(vec.norm() == Approx(5.3851648));
}

TEST_CASE("vector::normalize - returns unit vector parallel to source")
{
    cxx::vector const vec = {2, 3, 4};
    cxx::vector const unit = vec.normalize();
    CHECK(unit.norm() == Approx(1));
    CHECK(unit.x == Approx(0.37139068));
}

TEST_CASE("vector::project - returns a projected vector")
{
    SECTION("projection onto a coordinate axis")
    {
        cxx::vector const vec = {2, 3, 5};
        cxx::vector const axis = {7, 0, 0};
        cxx::vector const proj = vec.project(axis);

        CHECK(proj.x == Approx(2));
        CHECK(proj.y == Approx(0));
        CHECK(proj.z == Approx(0));
    }

    SECTION("projection onto an arbitrary vector")
    {
        cxx::vector const vec = {2, 3, 5};
        cxx::vector const axis = {-3, 4, -5};
        cxx::vector const proj = vec.project(axis);

        CHECK(proj.x == Approx(1.14));
        CHECK(proj.y == Approx(-1.52));
        CHECK(proj.z == Approx(1.90));
    }
}

TEST_CASE("dot - returns dot product")
{
    cxx::vector const va = {2, 4, 6};
    cxx::vector const vb = {7, 5, 3};
    CHECK(cxx::dot(va, vb) == 52);
}

TEST_CASE("cross - returns cross product")
{
    cxx::vector const va = {2, 4, 6};
    cxx::vector const vb = {3, 1, 5};
    cxx::vector const vc = cxx::cross(va, vb);
    CHECK(vc.x == 14);
    CHECK(vc.y == 8);
    CHECK(vc.z == -10);
}

TEST_CASE("squared_norm - returns squared Euclidean norm")
{
    cxx::vector const vec = {2, 3, 4};
    CHECK(cxx::squared_norm(vec) == 29);
}

TEST_CASE("norm - returns Euclidean norm")
{
    cxx::vector const vec = {2, 3, 4};
    CHECK(cxx::norm(vec) == Approx(5.3851648));
}

TEST_CASE("normalize - returns unit vector parallel to source")
{
    cxx::vector const vec = {2, 3, 4};
    cxx::vector const unit = cxx::normalize(vec);
    CHECK(unit.norm() == Approx(1));
    CHECK(unit.x == Approx(0.37139068));
}

TEST_CASE("project - returns the first vector projected onto the second vector")
{
    SECTION("projection onto a coordinate axis")
    {
        cxx::vector const vec = {2, 3, 5};
        cxx::vector const axis = {7, 0, 0};
        cxx::vector const proj = cxx::project(vec, axis);

        CHECK(proj.x == Approx(2));
        CHECK(proj.y == Approx(0));
        CHECK(proj.z == Approx(0));
    }

    SECTION("projection onto an arbitrary vector")
    {
        cxx::vector const vec = {2, 3, 5};
        cxx::vector const axis = {-3, 4, -5};
        cxx::vector const proj = cxx::project(vec, axis);

        CHECK(proj.x == Approx(1.14));
        CHECK(proj.y == Approx(-1.52));
        CHECK(proj.z == Approx(1.90));
    }
}


TEST_CASE("vector - is formattable")
{
    cxx::vector const vec {1.2, 3.4, 5.6};
    std::ostringstream str;
    str << '(' << vec << ')';
    CHECK(str.str() == "(1.2 3.4 5.6)");
}

TEST_CASE("vector - is parsable")
{
    cxx::vector vec;
    std::istringstream str{"1.2 3.4 5.6"};
    str >> vec;
    CHECK(vec.x == Approx(1.2));
    CHECK(vec.y == Approx(3.4));
    CHECK(vec.z == Approx(5.6));
}
