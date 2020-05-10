//
// Created by olli on 10/05/20.
//

#include "libsimcon/Controller.h"

Controller::Controller(Matrix &K) : K(K) {
    loopCount = 0;
}


Vector Controller::control(const Vector &x) {
    loopCount++;
    return K * x;
}
