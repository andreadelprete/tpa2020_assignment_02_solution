//
// Created by olli on 04/05/20.
//

#ifndef SECONDASSIGNMENT_MATRIX_H
#define SECONDASSIGNMENT_MATRIX_H

#include "MatrixBase.h"

class Vector;

class Matrix : public MatrixBase {
public:
    Matrix(int rows, int cols);

    Matrix(double *data, int rows, int cols);

    Matrix &transposeInPlace();

    Matrix transpose();

    void reshape(int rows, int cols);

    Matrix &operator=(const Matrix &other);

    // Multiplication
    Matrix operator*(const Matrix &other) const;

    Vector operator*(const Vector &other) const;


    // Mul and assign
    Matrix &operator*=(const MatrixBase &other);

    // Sum
    Matrix operator+(const MatrixBase &other) const;

    // Sum and assign
    Matrix &operator+=(const MatrixBase &other);

    // Subtraction
    Matrix operator-(const MatrixBase &other) const;

    // Sub and assign
    Matrix &operator-=(const MatrixBase &other);

};


#endif //SECONDASSIGNMENT_MATRIX_H
