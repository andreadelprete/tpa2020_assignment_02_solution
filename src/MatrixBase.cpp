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

double MatrixBase::operator()(int r, int c) const {
    return data[c + r * cols];
}

double &MatrixBase::operator()(int r, int c) {
    return data[c + r * cols];
}

MatrixBase MatrixBase::operator*(MatrixBase &other) {
    assert(cols == other.rows);

    auto* res = new double[rows * other.cols];

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < other.cols; ++c) {
            double scalSum = 0.0;
            for (int i = 0; i < cols; i++)
                scalSum += data[r * cols + i] * other.data[i * other.cols + c];

            res[r * other.cols + c] = scalSum;
        }
    }

    return MatrixBase(data, rows, other.cols);
}

void MatrixBase::setAllMatrixAt(double value) {
    for (int i = 0; i < size; ++i) {
        data[i] = value;
    }
}

MatrixBase &MatrixBase::operator,(double val) {
    initIndex++;

    if(initIndex < size)
        data[initIndex] = val;

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





