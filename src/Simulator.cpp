//
// Created by olli on 10/05/20.
//

#include "libsimcon/Simulator.h"

Simulator::Simulator(Matrix &A, Matrix &B, Vector &x0, Controllable &controller) :
        A(A), B(B), x(x0) {

    // Making a copy would be better but how
    this->controller = &controller;
}


void Simulator::simulate() {
    Vector u = controller->control(x);
    x = (A * x) + (B * u);
}

Vector *Simulator::getX() const {
    auto res = new Vector(x.getSize());

    res->operator=(x);

    return res;
}

