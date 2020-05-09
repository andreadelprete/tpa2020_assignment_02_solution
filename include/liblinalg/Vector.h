//
// Created by olli on 04/05/20.
//

#ifndef SECONDASSIGNMENT_VECTOR_H
#define SECONDASSIGNMENT_VECTOR_H


#include "MatrixBase.h"

class Matrix;

class Vector : public MatrixBase {

public:
    explicit Vector(int size, bool vertical = true);

    Vector(double *data, int rows, int cols);

    int getSize() { return size; }

    Vector &transposeInPlace();

    Vector transpose();

    Vector &operator=(const Vector &other);

    // Access using single index
    virtual double operator()(int i) const;

    // Modify using single infex
    virtual double &operator()(int i);

    // Multiplication
    Vector operator*(const Matrix &other);

    Matrix operator*(const Vector &other);


    // Mul and assign
    Vector &operator*=(const MatrixBase &other);

    // Sum
    Vector operator+(const MatrixBase &other);

    // Sum and assign
    Vector &operator+=(const MatrixBase &other);

    // Subtraction
    Vector operator-(const MatrixBase &other);

    // Sub and assign
    Vector &operator-=(const MatrixBase &other);
};


#endif //SECONDASSIGNMENT_VECTOR_H
