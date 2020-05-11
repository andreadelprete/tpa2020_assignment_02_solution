//
// Created by olli on 10/05/20.
//

#include "catch2/catch2.hpp"
#include "liblinalg/Matrix.h"
#include "liblinalg/Vector.h"
#include "libsimcon/Simulator.h"
#include "libsimcon/Controller.h"
#include "ClosedLoop.h"

const double tol = 1e-2;

TEST_CASE("SimConTests", "[testSimCon]") {
    SECTION("MainSimulation") {
        Matrix A(2, 2);
        A <<= 0.5, 0.1, 0, -0.2;
        Matrix B(2, 3);
        B <<= 1, 0, 0.5, 0, 1, 0;
        Matrix K(3, 2);
        K <<= 0.1600, 0.0800,
                0, -0.4000,
                0.0800, 0.0400;
        Vector x0(2);
        x0.setAllValuesAt(10);

        Controller c(K);
        Simulator s(A, B, x0);

        ClosedLoop cl(s, c);
        cl.completeSimulation(10);

        Vector res = cl.getState();

        REQUIRE(res(0) == Approx(0.3166).epsilon(tol));
        REQUIRE(res(1) == Approx(0.06).epsilon(tol));
    }

    SECTION("controller") {
        Matrix K(3, 2);
        K <<= 1, 2, 3, 4, 5, 6;
        Vector X(2);
        X <<= 10, 11;

        Controller c(K);

        Vector U = c.control(X);

        REQUIRE((U.getCols() == 1 && U.getRows() == 3));
        REQUIRE(U(0) == 32);
        REQUIRE(U(1) == 74);
        REQUIRE(U(2) == 116);
    }

    SECTION("simulator") {
        Matrix A(2, 2);
        A <<= 1, 2, 3, 4;
        Vector X0(2);
        X0 <<= 10, 11;
        Matrix B(2, 3);
        B <<= 6, 7, 8, 9, 0, 1;
        Vector U(3);
        U <<= 13, 14, 15;

        Simulator s(A, B, X0);

        s.simulate(U);
        Vector X = s.getX();
        REQUIRE((X.getCols() == 1 && X.getRows() == 2));
        REQUIRE(X(0) == 328);
        REQUIRE(X(1) == 206);
    }
}