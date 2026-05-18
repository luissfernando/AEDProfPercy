#ifndef MATRIX_H
#define MATRIX_H
class Matrix {
private:
    int rows;
    int cols;
    double **data;
public:
    Matrix(int r, int c);
    Matrix(const Matrix& other);
    ~Matrix();
    void setValue(int row, int col, double value);
    double getValue(int row, int col) const;
    Matrix add(const Matrix& other) const;
    Matrix multiply(const Matrix& other) const;
    Matrix transpose() const;
    void print() const;
};

#endif
