//
// Created by olli on 11/05/20.
//

#include "catch2/catch2.hpp"
#include "liblinalg/Matrix.h"
#include "liblinalg/Vector.h"

TEST_CASE("LinAlgTestsMatBase", "[testLinAlgMatBase]") {
    SECTION("OperatorBrackets") {
        Matrix A(2, 2);
        A(1, 1) = 42.0;
        REQUIRE(A(1, 1) == 42.0);
    }

    SECTION("setAllValuesAt") {
        Matrix A(2, 2);
        A.setAllValuesAt(42.0);

        for (int r = 0; r < A.getRows(); ++r) {
            for (int c = 0; c < A.getCols(); ++c) {
                REQUIRE(A(r, c) == 42.0);
            }
        }
    }

    SECTION("OperatorCommaAndShiftLeftAssign") {
        Matrix A(2, 2);
        A <<= 1, 2, 3, 4;
        REQUIRE(A(0, 0) == 1);
        REQUIRE(A(0, 1) == 2);
        REQUIRE(A(1, 0) == 3);
        REQUIRE(A(1, 1) == 4);
    }

    SECTION("toString") {
        Vector V(2, false);
        V <<= 10, 11;
        // Possible problems in Windows: replace \n with \r\n
        REQUIRE(V.toString() == "10.00 11.00 \n");
    }

    SECTION("CopyConstructor") {
        Vector V(2);
        V <<= 10, 11;

        Vector R = V;

        REQUIRE(R(0) == 10);
        REQUIRE(R(1) == 11);

        Matrix A(2, 3);
        A <<= 1, 2, 3, 4, 5, 6;

        Matrix B = A;
        REQUIRE(B(0, 0) == 1);
        REQUIRE(B(0, 1) == 2);
        REQUIRE(B(0, 2) == 3);
        REQUIRE(B(1, 0) == 4);
        REQUIRE(B(1, 1) == 5);
        REQUIRE(B(1, 2) == 6);
    }
}