//
// Created by olli on 04/05/20.
//

#include "Vector.h"


Vector::Vector(int size, bool vertical) : MatrixBase(size, 1) {
    if (!vertical) {
        rows = 1;
        cols = size;
    }
}




