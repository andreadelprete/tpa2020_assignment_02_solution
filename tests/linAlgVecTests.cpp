//
// Created by olli on 11/05/20.
//

#include "catch2/catch2.hpp"
#include "liblinalg/Matrix.h"
#include "liblinalg/Vector.h"

TEST_CASE("LinAlgTestsVec", "[testLinAlgVec]") {
    SECTION("VectorConstructor") {
        Vector V1(3);
        REQUIRE((V1.getCols() == 1 && V1.getRows() == 3));

        Vector V2(3, false);
        REQUIRE((V2.getCols() == 3 && V2.getRows() == 1));

        Vector V3(nullptr, 3);
        REQUIRE((V3.getCols() == 1 && V3.getRows() == 3));

        Vector V4(nullptr, 3, false);
        REQUIRE((V4.getCols() == 3 && V4.getRows() == 1));
    }

    SECTION("OperatorBracketsVector") {
        Vector V(3);
        V(2) = 42.0;
        REQUIRE(V(2) == 42.0);
    }

    SECTION("OperatorMulVector") {
        Matrix A(3, 2);
        A <<= 1, 2, 3, 4, 5, 6;
        Vector V1(3);
        V1 <<= 10, 11, 12;
        Vector V2(3, false);
        V2 <<= 13, 14, 15;
        Vector V3(2, false);
        V3 <<= 16, 17;

        Vector R1 = V1.transpose() * A;
        REQUIRE((R1.getCols() == 2 && R1.getRows() == 1));
        REQUIRE(R1(0) == 103);
        REQUIRE(R1(1) == 136);

        Matrix R2 = V2 * V1;
        REQUIRE((R2.getCols() == 1 && R2.getRows() == 1));
        REQUIRE(R2(0, 0) == 464);


        Matrix R3 = V1 * V3;
        REQUIRE((R3.getCols() == 2 && R3.getRows() == 3));
        REQUIRE(R3(0, 0) == 160);
        REQUIRE(R3(0, 1) == 170);
        REQUIRE(R3(1, 0) == 176);
        REQUIRE(R3(1, 1) == 187);
        REQUIRE(R3(2, 0) == 192);
        REQUIRE(R3(2, 1) == 204);
    }

    SECTION("transpose") {
        Vector V(2);
        V <<= 10, 11;

        V.transposeInPlace();

        REQUIRE((V.getCols() == 2 && V.getRows() == 1));
        REQUIRE(V(0) == 10);
        REQUIRE(V(1) == 11);

        Vector R = V.transpose();

        REQUIRE((R.getCols() == 1 && R.getRows() == 2));
        REQUIRE(V(0) == 10);
        REQUIRE(V(1) == 11);
    }

    SECTION("resize") {
        Vector V(2);
        V <<= 10, 11;

        V.resize(3);
        REQUIRE(V.getSize() == 3);
        REQUIRE((V.getCols() == 1 && V.getRows() == 3));

        V.resize(3, false);
        REQUIRE(V.getSize() == 3);
        REQUIRE((V.getCols() == 3 && V.getRows() == 1));
    }

    SECTION("OperatorAssign") {
        Vector V(2);
        V <<= 10, 11;

        Vector R(2);
        R = V;

        REQUIRE(R(0) == 10);
        REQUIRE(R(1) == 11);
    }


    SECTION("OperatorSum") {
        Vector V1(2);
        V1 <<= 10, 11;

        Vector V2(2);
        V2 <<= 34, 9;

        Vector R = V1 + V2;

        REQUIRE(R(0) == 44);
        REQUIRE(R(1) == 20);
    }

    SECTION("OperatorSumAssign") {
        Vector V1(2);
        V1 <<= 10, 11;

        Vector V2(2);
        V2 <<= 34, 9;

        V1 += V2;

        REQUIRE(V1(0) == 44);
        REQUIRE(V1(1) == 20);
    }

    SECTION("OperatorSub") {
        Vector V1(2);
        V1 <<= 10, 11;

        Vector V2(2);
        V2 <<= 34, 9;

        Vector R = V1 - V2;

        REQUIRE(R(0) == -24);
        REQUIRE(R(1) == 2);
    }

    SECTION("OperatorSubAssign") {
        Vector V1(2);
        V1 <<= 10, 11;

        Vector V2(2);
        V2 <<= 34, 9;

        V1 -= V2;

        REQUIRE(V1(0) == -24);
        REQUIRE(V1(1) == 2);
    }
}
