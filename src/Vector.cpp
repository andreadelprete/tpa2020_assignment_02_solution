//
// Created by olli on 04/05/20.
//

#include <cassert>
#include "liblinalg/Vector.h"


Vector::Vector(int size, bool vertical) : MatrixBase(size, 1) {
    if (!vertical) {
        rows = 1;
        cols = size;
    }
}

Vector::Vector(double *data, int rows, int cols) : MatrixBase(data, rows, cols) {

}

double Vector::operator()(int i) const {
    assert(i >= 0);
    assert(i < size);
    return data[i];
}

double &Vector::operator()(int i) {
    assert(i >= 0);
    assert(i < size);
    return data[i];
}


Vector Vector::operator*(Matrix &other) {

    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    return Vector(res, rows, other.getCols());
}

Matrix Vector::operator*(Vector &other) {
    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    return Matrix(res, rows, other.getCols());
}


Vector &Vector::operator*=(MatrixBase &other) {

    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

Vector Vector::operator+(MatrixBase &other) {

    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    return Vector(res, rows, cols);
}

Vector &Vector::operator+=(MatrixBase &other) {

    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

Vector Vector::operator-(MatrixBase &other) {
    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    return Vector(res, rows, cols);
}

Vector &Vector::operator-=(MatrixBase &other) {
    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}










