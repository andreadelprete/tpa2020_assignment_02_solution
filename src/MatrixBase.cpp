//
// Created by olli on 04/05/20.
//

#include "MatrixBase.h"

MatrixBase::MatrixBase(int rows, int cols) : size(rows * cols), rows(rows), cols(cols) {
    data = new double[size];
}

MatrixBase::MatrixBase(double *data, int rows, int cols) : size(rows * cols), rows(rows), cols(cols) {
    this->data = data;
}

double MatrixBase::operator()(int r, int c) const {
    return data[c + r * cols];
}

double &MatrixBase::operator()(int r, int c) {
    return data[c + r * cols];
}

double *MatrixBase::operator*(MatrixBase &other) {
    auto* res = new double[rows * other.cols];

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < other.cols; ++c) {
            double scalSum = 0.0;
            for (int i = 0; i < cols; i++)
                scalSum += data[r * cols + i] * other.data[i * other.cols + c];

            res[r * other.cols + c] = scalSum;
        }
    }

    return res;
}




