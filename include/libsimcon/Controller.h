//
// Created by olli on 10/05/20.
//

#ifndef SECONDASSIGNMENT_CONTROLLER_H
#define SECONDASSIGNMENT_CONTROLLER_H

#include "libsimcon/Controllable.h"
#include "liblinalg/Vector.h"
#include "liblinalg/Matrix.h"

class Controller : public Controllable {
    int loopCount = 0;
    Matrix K;
public:
    explicit Controller(Matrix &K);

    [[nodiscard]] Vector control(const Vector &x) override;

    [[nodiscard]] int getLoopCounter() const override { return loopCount; };
};


#endif //SECONDASSIGNMENT_CONTROLLER_H
