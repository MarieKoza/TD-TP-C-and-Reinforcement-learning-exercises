// matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

template <typename T>
class MatrixBase {
public:
    MatrixBase(std::size_t rows, std::size_t cols);
    void addElement(std::size_t row, std::size_t col, T value);
    T getElement(std::size_t row, std::size_t col) const;
    std::size_t getRows() const;
    std::size_t getCols() const;
    void Display() const;

private:
    std::size_t rows;
    std::size_t cols;
    std::vector<std::vector<T> > data;
};

#endif
