
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

    SECTION("transpose") {
        Vector V(2);
        V.transposeInPlace();

        REQUIRE((V.getCols() == 2 && V.getRows() == 1));

        Matrix A(2, 3);
        A <<= 1, 2, 3, 4, 5, 6;
        A.transposeInPlace();
        REQUIRE((A.getCols() == 2 && A.getRows() == 3));
        REQUIRE(A(0, 0) == 1);
        REQUIRE(A(0, 1) == 4);
        REQUIRE(A(1, 0) == 2);
        REQUIRE(A(1, 1) == 5);
        REQUIRE(A(2, 0) == 3);
        REQUIRE(A(2, 1) == 6);
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
        Vector V(2);
        V <<= 10, 11;

        Vector R = V.transpose() * A;

        REQUIRE(R(0) == 43.0);
        REQUIRE(R(1) == 64.0);

        Vector D = A * V;
        REQUIRE(D(0) == 32.0);
        REQUIRE(D(1) == 74.0);

        Matrix S = D.transpose() * D;
        REQUIRE((S.getRows() == 1 && S.getCols() == 1));
        REQUIRE(S(0, 0) == 6500);

        A = D * D.transpose();
        REQUIRE(A(0, 0) == 1024);
        REQUIRE(A(0, 1) == 2368);
        REQUIRE(A(1, 0) == 2368);
        REQUIRE(A(1, 1) == 5476);
    }

    SECTION("OperatorSumSub") {
        Matrix A1(2, 2);
        Matrix A2(2, 2);
        Matrix A3(2, 2);
        A1 <<= 1, 2, 3, 4;
        A2 <<= 1, 2, 3, 4;
        A3 <<= 4, 3, 2, 1;

        Matrix A4 = A1 - A2;
        for (int r = 0; r < A4.getRows(); ++r) {
            for (int c = 0; c < A4.getCols(); ++c) {
                REQUIRE(A4(r, c) == 0.0);
            }
        }

        Matrix A5 = A1 + A3;
        for (int r = 0; r < A5.getRows(); ++r) {
            for (int c = 0; c < A5.getCols(); ++c) {
                REQUIRE(A5(r, c) == 5.0);
            }
        }
    }
}