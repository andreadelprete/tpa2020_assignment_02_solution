//
// Created by olli on 04/05/20.
//

#include <cassert>
#include "liblinalg/Matrix.h"
#include "liblinalg/Vector.h"


Matrix::Matrix(int rows, int cols) : MatrixBase(rows, cols) {}

Matrix::Matrix(double *data, int rows, int cols) : MatrixBase(data, rows, cols) {}


Matrix Matrix::operator*(const Matrix &other) const {

    double *res = matrixMultiplication(other.data, other.rows, other.cols);

    return Matrix(res, rows, other.cols);
}

Vector Matrix::operator*(const Vector &other) const {
    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    return Vector(res, rows, other.getCols());
}


Matrix &Matrix::operator*=(const MatrixBase &other) {

    double *res = matrixMultiplication(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

Matrix Matrix::operator+(const MatrixBase &other) const {

    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    return Matrix(res, rows, cols);
}

Matrix &Matrix::operator+=(const MatrixBase &other) {

    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols());

    delete[] data;
    data = res;

    return *this;
}

Matrix Matrix::operator-(const MatrixBase &other) const {
    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols(), true);

    return Matrix(res, rows, cols);
}

Matrix &Matrix::operator-=(const MatrixBase &other) {
    double *res = matrixAddition(other.getData(), other.getRows(), other.getCols(), true);

    delete[] data;
    data = res;

    return *this;
}

Matrix &Matrix::transposeInPlace() {
    auto res = new double[size];

    for (int r = 0; r < cols; r++) {
        for (int c = 0; c < rows; c++)
            res[r * rows + c] = data[c * cols + r];
    }

    delete[] data;
    data = res;

    int temp = cols;
    cols = rows;
    rows = temp;

    return *this;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArgumentSelectionDefects"

Matrix Matrix::transpose() {
    auto res = new double[size];

    for (int r = 0; r < cols; r++) {
        for (int c = 0; c < rows; c++)
            res[r * rows + c] = data[c * cols + r];
    }

    return Matrix(res, cols, rows);
}

#pragma clang diagnostic pop


Matrix &Matrix::operator=(const Matrix &other) {
    assignementOperator(other);

    return *this;
}

void Matrix::reshape(int rows, int cols) {
    assert(rows > 0 && cols > 0);

    delete[] data;

    size = rows * cols;
    data = new double[size];
    this->rows = rows;
    this->cols = cols;
}


