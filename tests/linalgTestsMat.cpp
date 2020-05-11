
/*
 * Tests for liblinalg
 */

#include "catch2/catch2.hpp"
#include "liblinalg/Matrix.h"
#include "liblinalg/Vector.h"


TEST_CASE("LinAlgTestsMat", "[testLinAlgMat]") {
    SECTION("transpose") {
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

        Matrix B = A.transpose();
        REQUIRE((B.getCols() == 3 && B.getRows() == 2));
        REQUIRE(B(0, 0) == 1);
        REQUIRE(B(0, 1) == 2);
        REQUIRE(B(0, 2) == 3);
        REQUIRE(B(1, 0) == 4);
        REQUIRE(B(1, 1) == 5);
        REQUIRE(B(1, 2) == 6);
    }

    SECTION("resize") {
        Matrix A(2, 3);

        A.resize(3, 2);
        REQUIRE((A.getCols() == 2 && A.getRows() == 3));
    }

    SECTION("OperatorAssign") {
        Matrix A(2, 3);
        A <<= 1, 2, 3, 4, 5, 6;

        Matrix B(2, 3);
        B = A;
        REQUIRE(B(0, 0) == 1);
        REQUIRE(B(0, 1) == 2);
        REQUIRE(B(0, 2) == 3);
        REQUIRE(B(1, 0) == 4);
        REQUIRE(B(1, 1) == 5);
        REQUIRE(B(1, 2) == 6);
    }

    SECTION("OperatorMul") {
        Matrix A(2, 3);
        A <<= 1, 2, 3, 4, 5, 6;
        Vector V(3);
        V <<= 10, 11, 13;

        Vector D = A * V;
        REQUIRE((D.getCols() == 1 && D.getRows() == 2));
        REQUIRE(D(0) == 71);
        REQUIRE(D(1) == 173);


        Matrix B(3, 2);
        B <<= 6, 7, 8, 9, 0, 1;
        Matrix E = A * B;
        REQUIRE((E.getCols() == 2 && E.getRows() == 2));
        REQUIRE(E(0, 0) == 22);
        REQUIRE(E(0, 1) == 28);
        REQUIRE(E(1, 0) == 64);
        REQUIRE(E(1, 1) == 79);
    }

    SECTION("OperatorSum") {
        Matrix A(2, 3);
        A <<= 1, 2, 3, 4, 5, 6;
        Matrix B(2, 3);
        B <<= 6, 7, 8, 9, 0, 1;

        Matrix R = A + B;

        REQUIRE(R(0, 0) == 7);
        REQUIRE(R(0, 1) == 9);
        REQUIRE(R(0, 2) == 11);
        REQUIRE(R(1, 0) == 13);
        REQUIRE(R(1, 1) == 5);
        REQUIRE(R(1, 2) == 7);
    }

    SECTION("OperatorSumAssign") {
        Matrix A(2, 3);
        A <<= 1, 2, 3, 4, 5, 6;
        Matrix B(2, 3);
        B <<= 6, 7, 8, 9, 0, 1;

        A += B;

        REQUIRE(A(0, 1) == 9);
        REQUIRE(A(0, 2) == 11);
        REQUIRE(A(1, 0) == 13);
        REQUIRE(A(1, 1) == 5);
        REQUIRE(A(0, 0) == 7);
        REQUIRE(A(1, 2) == 7);
    }

    SECTION("OperatorSub") {
        Matrix A(2, 3);
        A <<= 1, 2, 3, 4, 5, 6;
        Matrix B(2, 3);
        B <<= 6, 7, 8, 9, 0, 1;

        Matrix R = A - B;

        REQUIRE(R(0, 0) == -5);
        REQUIRE(R(0, 1) == -5);
        REQUIRE(R(0, 2) == -5);
        REQUIRE(R(1, 0) == -5);
        REQUIRE(R(1, 1) == 5);
        REQUIRE(R(1, 2) == 5);
    }

    SECTION("OperatorSubAssign") {
        Matrix A(2, 3);
        A <<= 1, 2, 3, 4, 5, 6;
        Matrix B(2, 3);
        B <<= 6, 7, 8, 9, 0, 1;

        A -= B;

        REQUIRE(A(0, 0) == -5);
        REQUIRE(A(0, 1) == -5);
        REQUIRE(A(0, 2) == -5);
        REQUIRE(A(1, 0) == -5);
        REQUIRE(A(1, 1) == 5);
        REQUIRE(A(1, 2) == 5);
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


