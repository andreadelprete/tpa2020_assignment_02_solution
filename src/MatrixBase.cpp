//
// Created by olli on 04/05/20.
//

#include <cassert>
#include <ios>
#include <iomanip>
#include "liblinalg/MatrixBase.h"

MatrixBase::MatrixBase(int rows, int cols) : size(rows * cols), rows(rows), cols(cols) {
    data = new double[size];
    initIndex = 0;
}

MatrixBase::MatrixBase(double *data, int rows, int cols) : size(rows * cols), rows(rows), cols(cols) {
    this->data = data;
    initIndex = 0;
}

MatrixBase::MatrixBase(const MatrixBase &other) {
    size = other.size;
    rows = other.rows;
    cols = other.cols;
    initIndex = other.initIndex;

    delete[] data;
    data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

double MatrixBase::operator()(int r, int c) const {
    assert(r >= 0 && c >= 0);
    assert(r < rows && c < cols);
    return data[c + r * cols];
}

double &MatrixBase::operator()(int r, int c) {
    assert(r >= 0 && c >= 0);
    assert(r < rows && c < cols);
    return data[c + r * cols];
}


void MatrixBase::setAllValuesAt(double value) {
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
        //stream << std::endl;
    }

    return stream.str();
}

double *MatrixBase::matrixMultiplication(const double *B, int rb, int cb) const {
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

double *MatrixBase::matrixAddition(const double *B, int rb, int cb, bool sub) const {
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

void MatrixBase::assignementOperator(const MatrixBase &other) {
    if (this != &other) {
        assert(rows == other.rows && cols == other.cols);

        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
}












