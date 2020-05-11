//
// Created by olli on 11/05/20.
//

#ifndef SECONDASSIGNMENT_CLOSEDLOOP_H
#define SECONDASSIGNMENT_CLOSEDLOOP_H

#include "liblinalg/Vector.h"
#include "libsimcon/Simulable.h"
#include "libsimcon/Controllable.h"


class ClosedLoop {
    Simulable *s;
    Controllable *c;

public:
    ClosedLoop(Simulable &s, Controllable &c) : s(&s), c(&c) {}

    void simulationStep() const;

    void completeSimulation(int nSteps) const;

    Vector getState();


};


#endif //SECONDASSIGNMENT_CLOSEDLOOP_H
