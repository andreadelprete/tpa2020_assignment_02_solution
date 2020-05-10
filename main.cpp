//
// Created by olli on 07/05/20.
//

#include <iostream>
#include "liblinalg/Matrix.h"
#include "liblinalg/Vector.h"
#include "libsimcon/Simulator.h"
#include "libsimcon/Controller.h"
#include "batchSimultaion.h"

#define N 20

int main() {
    // Examples of liblinalg
    Matrix A(2, 2);
    A <<= 1, 2, 3, 4;
    std::cout << A.toString() << std::endl;

    Vector V(2, false);
    V <<= 10, 11;
    std::cout << V.toString() << std::endl;

    Vector R = V * A;
    std::cout << R.toString() << std::endl
              << "------------------------------------" << std::endl;

    // Examples of libsimcom
    A <<= -2, 1, 0, 1;
    Matrix B(2, 3);
    B <<= 1, -1, 0, 0, 1, -2;
    Matrix K(3, 2);
    K <<= 1, 2, 3, 4, 5, 6;
    Vector x0(2);
    x0.setAllValuesAt(0.01);

    Controller c(K);
    Simulator s(A, B, x0, c);
    auto simulators = new Simulable *[1];
    simulators[0] = &s;

    Vector ***res = batchSimulation(simulators, 1, N);
    deallocateSimData(res, 1, N);

    delete[] simulators;
}
