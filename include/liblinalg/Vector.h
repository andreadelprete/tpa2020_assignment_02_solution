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

    Vector(double *data, int size, bool vertical = true);

    [[nodiscard]] int getSize() const { return size; }

    Vector &transposeInPlace();

    Vector transpose();

    void resize(int size, bool vertical = true);

    Vector &operator=(const Vector &other);

    // Access using single index
    virtual double operator()(int i) const;

    // Modify using single index
    virtual double &operator()(int i);

    // Multiplication
    Vector operator*(const Matrix &other) const;

    Matrix operator*(const Vector &other) const;


    // Sum
    Vector operator+(const MatrixBase &other) const;

    // Sum and assign
    Vector &operator+=(const MatrixBase &other);

    // Subtraction
    Vector operator-(const MatrixBase &other) const;

    // Sub and assign
    Vector &operator-=(const MatrixBase &other);
};


#endif //SECONDASSIGNMENT_VECTOR_H
