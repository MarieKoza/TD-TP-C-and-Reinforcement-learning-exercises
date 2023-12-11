// num_matrix.h
#ifndef NUM_MATRIX_H
#define NUM_MATRIX_H

#include "matrix.h"
#include <cmath>

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical(std::size_t rows, std::size_t cols);
    T getDeterminant() const;
    MatrixNumerical<T> getInverse() const;
    static MatrixNumerical<T> getIdentity(std::size_t size);
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& rhs) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& rhs) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& rhs) const;
    MatrixNumerical<T> operator/(const MatrixNumerical<T>& rhs) const;
};

#endif
