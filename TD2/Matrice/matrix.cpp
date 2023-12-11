// matrix.cpp
#include "matrix.h"

template <typename T>
MatrixBase<T>::MatrixBase(std::size_t rows, std::size_t cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols, T())) {}

template <typename T>
void MatrixBase<T>::addElement(std::size_t row, std::size_t col, T value) {
    data[row][col] = value;
}

template <typename T>
T MatrixBase<T>::getElement(std::size_t row, std::size_t col) const {
    return data[row][col];
}

template <typename T>
std::size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
std::size_t MatrixBase<T>::getCols() const {
    return cols;
}

template <typename T>
void MatrixBase<T>::Display() const {
    for (const auto& row : data) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}
