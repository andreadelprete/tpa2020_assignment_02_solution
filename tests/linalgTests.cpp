
/*
 * Tests for liblinalg
 */

#include "catch2/catch2.hpp"
#include "liblinalg/Matrix.h"
#include "liblinalg/Vector.h"


TEST_CASE("LinAlgTests", "[testLinAlg]") {

    SECTION("VectorConstructor") {
        Vector V1(3);
        REQUIRE((V1.getCols() == 1 && V1.getRows() == 3));

        Vector V2(3, false);
        REQUIRE((V2.getCols() == 3 && V2.getRows() == 1));
    }

    SECTION("OperatorBracketsVector") {
        Vector V(3);
        V(2) = 42.0;
        REQUIRE(V(2) == 42.0);
    }

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

    SECTION("OperatorMul") {
        Matrix A(2, 2);
        A <<= 1, 2, 3, 4;
        Vector V(2, false);
        V <<= 10, 11;

        Vector R = V * A;

        REQUIRE(R(0) == 43.0);
        REQUIRE(R(1) == 64.0);

    }

}