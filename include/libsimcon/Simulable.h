//
// Created by olli on 10/05/20.
//

#ifndef SECONDASSIGNMENT_SIMULABLE_H
#define SECONDASSIGNMENT_SIMULABLE_H

#include "liblinalg/Vector.h"

class Simulable {
public:
    virtual void simulate() = 0;

    virtual Vector *getX() const = 0;
};


#endif //SECONDASSIGNMENT_SIMULABLE_H
