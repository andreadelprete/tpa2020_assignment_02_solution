//
// Created by olli on 07/05/20.
//

#include <iostream>
#include "liblinalg/Matrix.h"
#include "liblinalg/Vector.h"

int main() {
    Matrix A(2, 2);
    A <<= 1, 2, 3, 4;
    std::cout << A.toString() << std::endl;

    Vector V(2, false);
    V <<= 10, 11;
    std::cout << V.toString() << std::endl;

    Vector R = V * A;
    std::cout << R.toString() << std::endl;
}
