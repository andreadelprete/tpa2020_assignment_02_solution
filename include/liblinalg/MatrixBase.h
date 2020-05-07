//
// Created by olli on 04/05/20.
//

#ifndef SECONDASSIGNMENT_MATRIXBASE_H
#define SECONDASSIGNMENT_MATRIXBASE_H

#include <string>

class MatrixBase {
protected:
    double *data;
    int size;
    int rows;
    int cols;

    int initIndex;

    MatrixBase(int rows, int cols);

    MatrixBase(double *data, int rows, int cols);

    // Destructor
    ~MatrixBase() { delete[] data; }

public:

    int getCols() const { return cols; }

    int getRows() const { return rows; }

    // Get element
    virtual double operator()(int r, int c) const;

    // Set element
    virtual double &operator()(int r, int c);

    // Bulk initialization
    void setAllMatrixAt(double value);

    // List initialization
    virtual MatrixBase &operator,(double val);

    // List initialization starter
    virtual MatrixBase &operator<<=(double val);

    // Multiplication
    virtual MatrixBase operator*(MatrixBase &other);

    std::string toString();
};


#endif //SECONDASSIGNMENT_MATRIXBASE_H
