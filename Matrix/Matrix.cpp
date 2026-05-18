#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0;
        }
    }
}

// copy constructor
Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

// destructor
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

// set
void Matrix::setValue(int row, int col, double value) {
    data[row][col] = value;
}

// get
double Matrix::getValue(int row, int col) const {
    return data[row][col];
}

// suma
Matrix Matrix::add(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] =
                data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// multiplicación
Matrix Matrix::multiply(const Matrix& other) const {
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result.data[i][j] +=
                    data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// transpuesta
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

// imprimir
void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
