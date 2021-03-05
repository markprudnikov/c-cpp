#include "matrix.hpp"
#include <cassert>
#include <cstring>

Matrix::Matrix(std::size_t r, std::size_t c): _rows(r), _cols(c) {
    _data = allocate_memory(_rows, _cols);
}

Matrix::Matrix(Matrix const &m): _rows(m._rows), _cols(m._cols) {
    _data = allocate_memory(_rows, _cols);
    memcpy(_data[0], m._data[0], _cols * sizeof(int) * _rows);
}

Matrix::~Matrix() {
    delete[] _data[0];
    delete[] _data;
}

std::size_t Matrix::get_rows() const { return _rows; }
std::size_t Matrix::get_cols() const { return _cols; }

void Matrix::set(std::size_t i, std::size_t j, int val) const {
    assert(i < _rows && j < _cols);
    _data[i][j] = val;
}

int Matrix::get(std::size_t i, std::size_t j) const {
    assert(i < _rows && j < _cols);
    return _data[i][j];
}

void Matrix::print(FILE* f) const {
    for (std::size_t i = 0; i < _rows; i++) {
        for (std::size_t j = 0; j < _cols; j++) {
            fprintf(f, "%d ", _data[i][j]);
        }
        fprintf(f, "\n");
    }
}

Matrix& Matrix::operator+=(Matrix const &m) {
    for (std::size_t i = 0; i < _rows; i++) {
        for (std::size_t j = 0; j < _cols; j++) {
            _data[i][j] += m._data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator+(Matrix const &m) {
    Matrix copy(*this);
    copy += m;
    return copy;
}

Matrix& Matrix::operator-=(Matrix const &m) {
    for (std::size_t i = 0; i < _rows; i++) {
        for (std::size_t j = 0; j < _cols; j++) {
            _data[i][j] -= m._data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator-(Matrix const &m) {
    Matrix copy(*this);
    copy -= m;
    return copy;
}

Matrix Matrix::operator*=(Matrix const &m) {
    Matrix copy(_rows, m._cols);

    for (std::size_t i = 0; i < _rows; i++)
        for (std::size_t j = 0; j < copy._cols; j++)
            for (std::size_t k = 0; k < m._cols; k++)
                copy._data[i][j] += _data[i][k] * m._data[k][j];

    return copy;
}


Matrix& Matrix::operator*(Matrix const &m) {
    Matrix* copy = new Matrix(*this *= m);
    return *copy;
}

bool Matrix::operator==(Matrix const &m) {
    for (std::size_t i = 0; i < _rows; i++) {
        for (std::size_t j = 0; j < _cols; j++) {
            if (_data[i][j] != m._data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(Matrix const &m) {
    return !(*this == m);
}

Matrix& Matrix::operator=(Matrix const &m) {
    if (this == &m)
        return *this;

    delete[] _data[0];
    delete[] _data;
    _rows = m._rows;
    _cols = m._cols;
    _data = allocate_memory(_rows, _cols);

    for (std::size_t i = 0; i < _rows; i++) {
        for (std::size_t j = 0; j < _cols; j++) {
            _data[i][j] = m._data[i][j];
        }
    }

    return *this;
}

int** Matrix::allocate_memory(std::size_t rows, std::size_t cols){
    if(rows == 0 || cols == 0)
        return nullptr;

    int** data = new int*[rows];
    data[0] = new int[rows * cols]();

    for (std::size_t i = 1; i < rows; i++){
        data[i] = data[0] + i*cols;
    }

    return data;
}