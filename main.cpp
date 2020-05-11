//
// Created by olli on 07/05/20.
//

#include <iostream>
#include "liblinalg/Matrix.h"
#include "liblinalg/Vector.h"
#include "libsimcon/Simulator.h"
#include "libsimcon/Controller.h"
#include "ClosedLoop.h"

#define N 20

int main() {
    // Examples of liblinalg
    Matrix A(2, 2);
    A <<= 1, 2, 3, 4;
    std::cout << A.toString() << std::endl;

    Vector V(2);
    V <<= 10, 11;
    std::cout << V.toString() << std::endl;

    Vector R = V.transpose() * A;
    std::cout << R.toString() << std::endl
              << "------------------------------------" << std::endl;

//    // Examples of libsimcom
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
    std::cout << cl.getState().toString() << std::endl;
}
