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

public:

    Simulator(Matrix &A, Matrix &B, Vector &x0);

    /**
     * Simulate the discrete-time system
     *     x[n+1] = A*x[n] + B*u[n]
     */
    void simulate(Vector &u);

    /**
     * Get the system state
     * @return
     */
    const Vector &getX() const;
};


#endif //SECONDASSIGNMENT_SIMULATOR_H
