//
// Created by olli on 04/05/20.
//

#ifndef SECONDASSIGNMENT_MATRIXBASE_H
#define SECONDASSIGNMENT_MATRIXBASE_H

#include <string>

class MatrixBase {
protected:
    double *data = nullptr; // pointer to the data
    int size;               // total size of the matrix
    int rows;               // number of rows
    int cols;               // number of columns

    int initIndex;          // index to be used for the list initialization with operators <<= and ,

    MatrixBase(int rows, int cols);

    MatrixBase(double *data, int rows, int cols);

    double *matrixMultiplication(const double B[], int rb, int cb) const;

    /**
     * Sum (or subtract) to the given matrix
     * @param B Matrix to sub or subtract
     * @param rb number of rows
     * @param cb number of columns
     * @param sub If true then perform subtraction, if false then perform addition
     * @return
     */
    double *matrixAddition(const double B[], int rb, int cb, bool sub = false) const;

    void assignmentOperator(const MatrixBase &other);
public:

    // Destructor
    ~MatrixBase() { delete[] data; }

    MatrixBase(const MatrixBase &other);

    int getCols() const { return cols; }

    int getRows() const { return rows; }

    const double *getData() const { return data; }


    // Get element
    virtual double operator()(int r, int c) const;

    // Set element
    virtual double &operator()(int r, int c);

    /**
     * Initialize all entries of the MatrixBase to the same specified value
     */
    void setAllValuesAt(double value);

    /**
     * Operator used for initializing a MatrixBase ith the following syntax:
     * A <<= 1, 2, 3;
     */
    virtual MatrixBase &operator,(double val);

    /**
     * Operator used for initializing a MatrixBase ith the following syntax:
     * MatrixBase a <<= 1, 2, 3;
     */
    virtual MatrixBase &operator<<=(double val);

    // Return a string representation of the MatrixBase
    std::string toString();
};


#endif //SECONDASSIGNMENT_MATRIXBASE_H
