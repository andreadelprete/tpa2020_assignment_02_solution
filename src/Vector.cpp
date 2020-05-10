//
// Created by olli on 04/05/20.
//

#include <cassert>
#include "liblinalg/Vector.h"
#include "liblinalg/Matrix.h"


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


Vector Vector::operator*(const Matrix &other) const {

    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    return Vector(res, rows, other.getCols());
}

Matrix Vector::operator*(const Vector &other) const {
    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    return Matrix(res, rows, other.getCols());
}


Vector &Vector::operator*=(const MatrixBase &other) {

    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

Vector Vector::operator+(const MatrixBase &other) const {

    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    return Vector(res, rows, cols);
}

Vector &Vector::operator+=(const MatrixBase &other) {

    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

Vector Vector::operator-(const MatrixBase &other) const {
    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    return Vector(res, rows, cols);
}

Vector &Vector::operator-=(const MatrixBase &other) {
    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

Vector &Vector::transposeInPlace() {
    int temp = cols;
    cols = rows;
    rows = temp;

    return *this;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArgumentSelectionDefects"

Vector Vector::transpose() {
    auto res = new double[size];
    for (int i = 0; i < size; ++i) {
        res[i] = data[i];
    }
    return Vector(res, cols, rows);
}

#pragma clang diagnostic pop

Vector &Vector::operator=(const Vector &other) {
    assignementOperator(other);

    return *this;
}

void Vector::resize(int size, bool vertical) {
    assert(size > 0);

    delete[] data;

    data = new double[size];

    if (vertical) {
        rows = size;
        cols = 1;
    } else {
        rows = 1;
        cols = size;
    }
}












