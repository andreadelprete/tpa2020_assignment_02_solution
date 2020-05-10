//
// Created by olli on 04/05/20.
//

#ifndef SECONDASSIGNMENT_MATRIXBASE_H
#define SECONDASSIGNMENT_MATRIXBASE_H

#include <string>

class MatrixBase {
protected:
    double *data = nullptr;
    int size;
    int rows;
    int cols;

    int initIndex;

    MatrixBase(int rows, int cols);

    MatrixBase(double *data, int rows, int cols);

    double *matrixMultiplication(const double B[], int rb, int cb) const;

    double *matrixAddition(const double B[], int rb, int cb, bool sub = false) const;

    void assignementOperator(const MatrixBase &other);
public:

    // Destructor
    ~MatrixBase() { delete[] data; }

    MatrixBase(const MatrixBase &other);

    [[nodiscard]] int getCols() const { return cols; }

    [[nodiscard]] int getRows() const { return rows; }

    [[nodiscard]] const double *getData() const { return data; }


    // Get element
    virtual double operator()(int r, int c) const;

    // Set element
    virtual double &operator()(int r, int c);

    // Bulk initialization
    void setAllValuesAt(double value);

    // List initialization
    virtual MatrixBase &operator,(double val);

    // List initialization starter
    virtual MatrixBase &operator<<=(double val);


    std::string toString();
};


#endif //SECONDASSIGNMENT_MATRIXBASE_H
