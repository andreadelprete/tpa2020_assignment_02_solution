//
// Created by olli on 10/05/20.
//

#ifndef SECONDASSIGNMENT_SIMULATOR_H
#define SECONDASSIGNMENT_SIMULATOR_H

#include "libsimcon/Simulable.h"
#include "libsimcon/Controllable.h"
#include "liblinalg/Vector.h"
#include "liblinalg/Matrix.h"

class Simulator : public Simulable {
    Matrix A;
    Matrix B;
    Vector x;

    Controllable *controller;

public:

    Simulator(Matrix &A, Matrix &B, Vector &x0, Controllable &controller);

    void simulate() override;

    Vector *getX() const override;
};


#endif //SECONDASSIGNMENT_SIMULATOR_H
