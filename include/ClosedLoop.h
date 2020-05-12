//
// Created by olli on 11/05/20.
//

#ifndef SECONDASSIGNMENT_CLOSEDLOOP_H
#define SECONDASSIGNMENT_CLOSEDLOOP_H

#include "liblinalg/Vector.h"
#include "libsimcon/Simulable.h"
#include "libsimcon/Controllable.h"

/**
 * Class to simulate a closed-loop system composed of a simulator and a controller.
 */
class ClosedLoop {
    Simulable *s;
    Controllable *c;

public:
    ClosedLoop(Simulable &s, Controllable &c) : s(&s), c(&c) {}

    // Take a single simulation step
    void simulationStep();

    // Perform a complete simulation of nSteps time steps
    void completeSimulation(int nSteps);

    // Get the current state of the system
    Vector getState() const;
};


#endif //SECONDASSIGNMENT_CLOSEDLOOP_H
