//
// Created by olli on 04/05/20.
//

#ifndef SECONDASSIGNMENT_MATRIXBASE_H
#define SECONDASSIGNMENT_MATRIXBASE_H


class MatrixBase {
protected:
    double *data;
    int size;
    int rows;
    int cols;

    MatrixBase(int rows, int cols);

    MatrixBase(double * data, int rows, int cols);

    virtual double * operator*(MatrixBase &other);

public:

    int getCols() const { return cols; }

    int getRows() const { return rows; }

    // Get element
    virtual double operator()(int r, int c) const;

    // Set element
    virtual double &operator()(int r, int c);



};


#endif //SECONDASSIGNMENT_MATRIXBASE_H
