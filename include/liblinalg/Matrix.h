//
// Created by olli on 04/05/20.
//

#ifndef SECONDASSIGNMENT_MATRIX_H
#define SECONDASSIGNMENT_MATRIX_H

#include "MatrixBase.h"
#include "Vector.h"

class Vector;

class Matrix : public MatrixBase {


public:
    Matrix(int rows, int cols);

    Matrix(double *data, int rows, int cols);

    // Multiplication
    Matrix operator*(Matrix &other);

    Vector operator*(Vector &other);


    // Mul and assign
    Matrix &operator*=(MatrixBase &other);

    // Sum
    Matrix operator+(MatrixBase &other);

    // Sum and assign
    Matrix &operator+=(MatrixBase &other);

    // Subtraction
    Matrix operator-(MatrixBase &other);

    // Sub and assign
    Matrix &operator-=(MatrixBase &other);

};


#endif //SECONDASSIGNMENT_MATRIX_H
