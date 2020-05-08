//
// Created by olli on 04/05/20.
//

#include <cassert>
#include <ios>
#include <iomanip>
#include "MatrixBase.h"

MatrixBase::MatrixBase(int rows, int cols) : size(rows * cols), rows(rows), cols(cols) {
    data = new double[size];
    initIndex = 0;
}

MatrixBase::MatrixBase(double *data, int rows, int cols) : size(rows * cols), rows(rows), cols(cols) {
    this->data = data;
    initIndex = 0;
}

MatrixBase::MatrixBase(MatrixBase &other) {
    size = other.size;
    rows = other.rows;
    cols = other.cols;
    initIndex = other.initIndex;

    data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    assert(true); // Should be never called
}

double MatrixBase::operator()(int r, int c) const {
    return data[c + r * cols];
}

double &MatrixBase::operator()(int r, int c) {
    return data[c + r * cols];
}


void MatrixBase::setAllMatrixAt(double value) {
    for (int i = 0; i < size; ++i) {
        data[i] = value;
    }
}

MatrixBase &MatrixBase::operator,(double val) {
    initIndex++;

    if (initIndex < size)
        data[initIndex] = val;
    else
        assert(initIndex > size);

    return *this;
}

MatrixBase &MatrixBase::operator<<=(double val) {
    data[0] = val;
    initIndex = 0;
    return *this;
}

std::string MatrixBase::toString() {
    std::stringstream stream;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            stream << std::fixed << std::setprecision(2) << data[r * cols + c] << " ";
        }
        stream << std::endl;
    }

    return stream.str();
}

double *MatrixBase::matrixMultiplication(double *B, int rb, int cb) {
    assert(cols == rb);

    auto *res = new double[rows * cb];

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cb; ++c) {
            double scalSum = 0.0;
            for (int i = 0; i < cols; i++)
                scalSum += data[r * cols + i] * B[i * cb + c];

            res[r * cb + c] = scalSum;
        }
    }

    return res;
}

double *MatrixBase::matrixAddition(double *B, int rb, int cb, bool sub) {
    assert(rows == rb && cols == cb);

    auto *res = new double[rows * cb];

    if (sub) {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cb; ++c) {
                res[r * cols + c] = data[r * cols + c] - B[r * cols + c];
            }
        }
    } else {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cb; ++c) {
                res[r * cols + c] = data[r * cols + c] + B[r * cols + c];
            }
        }
    }

    return res;
}

MatrixBase MatrixBase::operator*(MatrixBase &other) {

    double *res = matrixMultiplication(other.data, other.rows, other.cols);

    return MatrixBase(res, rows, other.cols);
}

MatrixBase &MatrixBase::operator*=(MatrixBase &other) {

    double *res = matrixMultiplication(other.data, other.rows, other.cols);
    delete[] data;
    data = res;

    return *this;
}

MatrixBase MatrixBase::operator+(MatrixBase &other) {

    double *res = matrixAddition(other.data, other.rows, other.cols);

    return MatrixBase(res, rows, cols);
}

MatrixBase &MatrixBase::operator+=(MatrixBase &other) {

    double *res = matrixAddition(other.data, other.rows, other.cols);

    delete[] data;
    data = res;

    return *this;
}

MatrixBase MatrixBase::operator-(MatrixBase &other) {
    double *res = matrixAddition(other.data, other.rows, other.cols, true);

    return MatrixBase(res, rows, cols);
}

MatrixBase &MatrixBase::operator-=(MatrixBase &other) {
    double *res = matrixAddition(other.data, other.rows, other.cols, true);

    delete[] data;
    data = res;

    return *this;
}











