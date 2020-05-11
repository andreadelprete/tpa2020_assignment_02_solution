//
// Created by olli on 10/05/20.
//

#include "libsimcon/Simulator.h"

Simulator::Simulator(Matrix &A, Matrix &B, Vector &x0) :
        A(A), B(B), x(x0) {}


void Simulator::simulate(Vector &u) {
    x = (A * x) + (B * u);
}

const Vector &Simulator::getX() const {
    return x;
}

