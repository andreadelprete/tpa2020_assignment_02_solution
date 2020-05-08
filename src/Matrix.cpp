//
// Created by olli on 04/05/20.
//

#include "liblinalg/Matrix.h"


Matrix::Matrix(int rows, int cols) : MatrixBase(rows, cols) {}

Matrix::Matrix(double *data, int rows, int cols) : MatrixBase(data, rows, cols) {}


Matrix Matrix::operator*(Matrix &other) {

    double *res = matrixMultiplication(other.data, other.rows, other.cols);

    return Matrix(res, rows, other.cols);
}

Vector Matrix::operator*(Vector &other) {
    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    return Vector(res, rows, other.getCols());
}


Matrix &Matrix::operator*=(MatrixBase &other) {

    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

Matrix Matrix::operator+(MatrixBase &other) {

    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    return Matrix(res, rows, cols);
}

Matrix &Matrix::operator+=(MatrixBase &other) {

    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

Matrix Matrix::operator-(MatrixBase &other) {
    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    return Matrix(res, rows, cols);
}

Matrix &Matrix::operator-=(MatrixBase &other) {
    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

