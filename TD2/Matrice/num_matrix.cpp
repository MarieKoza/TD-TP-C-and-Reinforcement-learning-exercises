// num_matrix.cpp
#include "num_matrix.h"

template <typename T>
MatrixNumerical<T>::MatrixNumerical(std::size_t rows, std::size_t cols) : MatrixBase<T>(rows, cols) {}

template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    return this->getElement(0, 0) * (this->getElement(1, 1) * this->getElement(2, 2) - this->getElement(1, 2) * this->getElement(2, 1))
         - this->getElement(0, 1) * (this->getElement(1, 0) * this->getElement(2, 2) - this->getElement(1, 2) * this->getElement(2, 0))
         + this->getElement(0, 2) * (this->getElement(1, 0) * this->getElement(2, 1) - this->getElement(1, 1) * this->getElement(2, 0));
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    MatrixNumerical<T> inverse(this->getRows(), this->getCols());

    T determinant = getDeterminant();
    if (determinant == 0) {
        std::cerr << "Error: Singular matrix, inverse does not exist." << std::endl;
        return inverse;
    }

    T invDet = 1 / determinant;

    inverse.addElement(0, 0, (this->getElement(1, 1) * this->getElement(2, 2) - this->getElement(1, 2) * this->getElement(2, 1)) * invDet);
    inverse.addElement(0, 1, (this->getElement(0, 2) * this->getElement(2, 1) - this->getElement(0, 1) * this->getElement(2, 2)) * invDet);
    inverse.addElement(0, 2, (this->getElement(0, 1) * this->getElement(1, 2) - this->getElement(0, 2) * this->getElement(1, 1)) * invDet);
    inverse.addElement(1, 0, (this->getElement(1, 2) * this->getElement(2, 0) - this->getElement(1, 0) * this->getElement(2, 2)) * invDet);
    inverse.addElement(1, 1, (this->getElement(0, 0) * this->getElement(2, 2) - this->getElement(0, 2) * this->getElement(2, 0)) * invDet);
    inverse.addElement(1, 2, (this->getElement(0, 2) * this->getElement(1, 0) - this->getElement(0, 0) * this->getElement(1, 2)) * invDet);
    inverse.addElement(2, 0, (this->getElement(1, 0) * this->getElement(2, 1) - this->getElement(1, 1) * this->getElement(2, 0)) * invDet);
    inverse.addElement(2, 1, (this->getElement(0, 1) * this->getElement(2, 0) - this->getElement(0, 0) * this->getElement(2, 1)) * invDet);
    inverse.addElement(2, 2, (this->getElement(0, 0) * this->getElement(1, 1) - this->getElement(0, 1) * this->getElement(1, 0)) * invDet);

    return inverse;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(std::size_t size) {
    MatrixNumerical<T> identity(size, size);
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            identity.addElement(i, j, (i == j) ? 1 : 0);
        }
    }
    return identity;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& rhs) const {
    MatrixNumerical<T> result(this->getRows(), this->getCols());
    for (std::size_t i = 0; i < this->getRows(); ++i) {
        for (std::size_t j = 0; j < this->getCols(); ++j) {
            result.addElement(i, j, this->getElement(i, j) + rhs.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& rhs) const {
    MatrixNumerical<T> result(this->getRows(), this->getCols());
    for (std::size_t i = 0; i < this->getRows(); ++i) {
        for (std::size_t j = 0; j < this->getCols(); ++j) {
            result.addElement(i, j, this->getElement(i, j) - rhs.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& rhs) const {
    MatrixNumerical<T> result(this->getRows(), rhs.getCols());
    for (std::size_t i = 0; i < this->getRows(); ++i) {
        for (std::size_t j = 0; j < rhs.getCols(); ++j) {
            T sum = 0;
            for (std::size_t k = 0; k < this->getCols(); ++k) {
                sum += this->getElement(i, k) * rhs.getElement(k, j);
            }
            result.addElement(i, j, sum);
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& rhs) const {
    
    if (rhs.getRows() != rhs.getCols()) {
        std::cerr << "Error: Right-hand side matrix is not square. Division is not defined." << std::endl;
        return MatrixNumerical<T>(this->getRows(), this->getCols());  
    }

    MatrixNumerical<T> inverseRhs = rhs.getInverse();

    if (inverseRhs.getDeterminant() == 0) {
        std::cerr << "Error: Singular matrix, division is not defined." << std::endl;
        return MatrixNumerical<T>(this->getRows(), this->getCols());  // Return a matrix with default values
    }

    return (*this) * inverseRhs;
}
