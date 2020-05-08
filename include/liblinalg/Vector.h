//
// Created by olli on 04/05/20.
//

#ifndef SECONDASSIGNMENT_VECTOR_H
#define SECONDASSIGNMENT_VECTOR_H


#include "MatrixBase.h"
#include "Matrix.h"

class Matrix;

class Vector : public MatrixBase {

public:
    explicit Vector(int size, bool vertical = true);

    Vector(double *data, int rows, int cols);


    // Access using single index
    virtual double operator()(int i) const;

    // Modify using single infex
    virtual double &operator()(int i);

    // Multiplication
    Vector operator*(Matrix &other);

    Matrix operator*(Vector &other);


    // Mul and assign
    Vector &operator*=(MatrixBase &other);

    // Sum
    Vector operator+(MatrixBase &other);

    // Sum and assign
    Vector &operator+=(MatrixBase &other);

    // Subtraction
    Vector operator-(MatrixBase &other);

    // Sub and assign
    Vector &operator-=(MatrixBase &other);
};


#endif //SECONDASSIGNMENT_VECTOR_H
