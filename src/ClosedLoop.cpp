//
// Created by olli on 11/05/20.
//

#include "ClosedLoop.h"


void ClosedLoop::simulationStep() const {
    Vector u = c->control(s->getX());
    s->simulate(u);
}

void ClosedLoop::completeSimulation(int nSteps) const {
    for (int i = 0; i < nSteps; ++i) {
        simulationStep();
    }
}

Vector ClosedLoop::getState() {
    auto a = s->getX();
    auto data = new double[a.getSize()];
    for (int i = 0; i < a.getSize(); ++i) {
        data[i] = a.getData()[i];
    }
    return Vector(data, a.getSize());
}


