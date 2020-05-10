//
// Created by olli on 10/05/20.
//

#ifndef SECONDASSIGNMENT_CONTROLLABLE_H
#define SECONDASSIGNMENT_CONTROLLABLE_H

#include "liblinalg/Vector.h"

class Controllable {
public:
    [[nodiscard]] virtual Vector control(const Vector &x) = 0;

    [[nodiscard]] virtual int getLoopCounter() const = 0;
};

#endif //SECONDASSIGNMENT_CONTROLLABLE_H
