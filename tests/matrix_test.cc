// Copyright snsinfu 2020.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstream>

#include "catch.hpp"
#include "../include/point.hpp"


TEST_CASE("matrix - is default constructible as the null matrix")
{
    cxx::matrix mat;
    CHECK(mat(0, 0) == 0);
    CHECK(mat(0, 1) == 0);
    CHECK(mat(0, 2) == 0);
    CHECK(mat(1, 0) == 0);
    CHECK(mat(1, 1) == 0);
    CHECK(mat(1, 2) == 0);
    CHECK(mat(2, 0) == 0);
    CHECK(mat(2, 1) == 0);
    CHECK(mat(2, 2) == 0);
}

TEST_CASE("matrix - is constructible from diagonal elements")
{
    cxx::matrix mat = {1, 2, 3};
    CHECK(mat(0, 0) == 1);
    CHECK(mat(0, 1) == 0);
    CHECK(mat(0, 2) == 0);
    CHECK(mat(1, 0) == 0);
    CHECK(mat(1, 1) == 2);
    CHECK(mat(1, 2) == 0);
    CHECK(mat(2, 0) == 0);
    CHECK(mat(2, 1) == 0);
    CHECK(mat(2, 2) == 3);
}

TEST_CASE("matrix - is constructible from full elements")
{
    cxx::matrix mat = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    CHECK(mat(0, 0) == 1);
    CHECK(mat(0, 1) == 2);
    CHECK(mat(0, 2) == 3);
    CHECK(mat(1, 0) == 4);
    CHECK(mat(1, 1) == 5);
    CHECK(mat(1, 2) == 6);
    CHECK(mat(2, 0) == 7);
    CHECK(mat(2, 1) == 8);
    CHECK(mat(2, 2) == 9);
}

TEST_CASE("matrix - provides mutable element references")
{
    cxx::matrix mat;
    mat(0, 1) = 4;
    mat(2, 0) = 5;
    mat(1, 2) = 6;
    CHECK(mat(0, 1) == 4);
    CHECK(mat(2, 0) == 5);
    CHECK(mat(1, 2) == 6);
}

TEST_CASE("matrix - supports element-wise in-place addition")
{
    cxx::matrix mat = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    mat += {
        3, 5, 7,
        6, 8, 1,
        9, 2, 4
    };
    CHECK(mat(0, 0) == 4);
    CHECK(mat(0, 1) == 7);
    CHECK(mat(0, 2) == 10);
    CHECK(mat(1, 0) == 10);
    CHECK(mat(1, 1) == 13);
    CHECK(mat(1, 2) == 7);
    CHECK(mat(2, 0) == 16);
    CHECK(mat(2, 1) == 10);
    CHECK(mat(2, 2) == 13);
}

TEST_CASE("matrix - supports element-wise in-place subtraction")
{
    cxx::matrix mat = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    mat -= {
        3, 5, 7,
        6, 8, 1,
        9, 2, 4
    };
    CHECK(mat(0, 0) == -2);
    CHECK(mat(0, 1) == -3);
    CHECK(mat(0, 2) == -4);
    CHECK(mat(1, 0) == -2);
    CHECK(mat(1, 1) == -3);
    CHECK(mat(1, 2) == 5);
    CHECK(mat(2, 0) == -2);
    CHECK(mat(2, 1) == 6);
    CHECK(mat(2, 2) == 5);
}

TEST_CASE("matrix - supports element-wise in-place scaling")
{
    cxx::matrix mat = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    mat *= 2;
    CHECK(mat(0, 0) == 2);
    CHECK(mat(0, 1) == 4);
    CHECK(mat(0, 2) == 6);
    CHECK(mat(1, 0) == 8);
    CHECK(mat(1, 1) == 10);
    CHECK(mat(1, 2) == 12);
    CHECK(mat(2, 0) == 14);
    CHECK(mat(2, 1) == 16);
    CHECK(mat(2, 2) == 18);
}

TEST_CASE("matrix - supports element-wise in-place division")
{
    cxx::matrix mat = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    mat /= 2;
    CHECK(mat(0, 0) == Approx(0.5));
    CHECK(mat(0, 1) == Approx(1.0));
    CHECK(mat(0, 2) == Approx(1.5));
    CHECK(mat(1, 0) == Approx(2.0));
    CHECK(mat(1, 1) == Approx(2.5));
    CHECK(mat(1, 2) == Approx(3.0));
    CHECK(mat(2, 0) == Approx(3.5));
    CHECK(mat(2, 1) == Approx(4.0));
    CHECK(mat(2, 2) == Approx(4.5));
}

TEST_CASE("matrix::dot - computes matrix-matrix product")
{
    cxx::matrix const mat1 = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    cxx::matrix const mat2 = {
        3, 5, 7,
        6, 8, 1,
        9, 2, 4
    };
    cxx::matrix const expected = {
        42, 27, 21,
        96, 72, 57,
        150, 117, 93
    };
    cxx::matrix const actual = mat1.dot(mat2);
    CHECK(actual(0, 0) == Approx(expected(0, 0)));
    CHECK(actual(0, 1) == Approx(expected(0, 1)));
    CHECK(actual(0, 2) == Approx(expected(0, 2)));
    CHECK(actual(1, 0) == Approx(expected(1, 0)));
    CHECK(actual(1, 1) == Approx(expected(1, 1)));
    CHECK(actual(1, 2) == Approx(expected(1, 2)));
    CHECK(actual(2, 0) == Approx(expected(2, 0)));
    CHECK(actual(2, 1) == Approx(expected(2, 1)));
    CHECK(actual(2, 2) == Approx(expected(2, 2)));
}

TEST_CASE("matrix::dot - computes matrix-vector product")
{
    cxx::matrix const mat = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    cxx::vector const vec = {10, 11, 12};
    cxx::vector const expected = {68, 167, 266};
    cxx::vector const actual = mat.dot(vec);
    CHECK(actual.x == Approx(expected.x));
    CHECK(actual.y == Approx(expected.y));
    CHECK(actual.z == Approx(expected.z));
}

TEST_CASE("matrix::transpose - returns transposed copy")
{
    cxx::matrix const mat = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    cxx::matrix const tr = mat.transpose();
    CHECK(tr(0, 0) == mat(0, 0));
    CHECK(tr(0, 1) == mat(1, 0));
    CHECK(tr(0, 2) == mat(2, 0));
    CHECK(tr(1, 0) == mat(0, 1));
    CHECK(tr(1, 1) == mat(1, 1));
    CHECK(tr(1, 2) == mat(2, 1));
    CHECK(tr(2, 0) == mat(0, 2));
    CHECK(tr(2, 1) == mat(1, 2));
    CHECK(tr(2, 2) == mat(2, 2));
}

TEST_CASE("matrix - is formattable")
{
    cxx::matrix const mat = {
        1.2, 3.4, 5.6,
        7.8, 9.1, 2.3,
        4.5, 6.7, 8.9
    };
    std::ostringstream str;
    str << mat;
    CHECK(str.str() == "1.2 3.4 5.6\n7.8 9.1 2.3\n4.5 6.7 8.9");
}

TEST_CASE("matrix - is parsable")
{
    cxx::matrix mat;
    std::istringstream str("1.2 3.4 5.6\n7.8 9.1 2.3\n4.5 6.7 8.9");
    str >> mat;
    CHECK(mat(0, 0) == Approx(1.2));
    CHECK(mat(0, 1) == Approx(3.4));
    CHECK(mat(0, 2) == Approx(5.6));
    CHECK(mat(1, 0) == Approx(7.8));
    CHECK(mat(1, 1) == Approx(9.1));
    CHECK(mat(1, 2) == Approx(2.3));
    CHECK(mat(2, 0) == Approx(4.5));
    CHECK(mat(2, 1) == Approx(6.7));
    CHECK(mat(2, 2) == Approx(8.9));
}
