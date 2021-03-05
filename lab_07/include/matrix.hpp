#ifndef WW_MATRIX_MATRIX_HPP
#define WW_MATRIX_MATRIX_HPP

#include <cstdio>
#include <cstddef>

class Matrix {
public:
    Matrix(std::size_t r, std::size_t c);
    Matrix(Matrix const &m);
    ~Matrix();

    std::size_t get_rows() const;
    std::size_t get_cols() const;

    void set(std::size_t i, std::size_t j, int val) const;
    int get(std::size_t i, std::size_t j) const;
    void print(FILE *f) const;

    Matrix& operator+=(Matrix const &m);
    Matrix operator+(Matrix const &m);

    Matrix& operator-=(Matrix const &m);
    Matrix operator-(Matrix const &m);

    Matrix& operator*=(Matrix const &m);
    Matrix operator*(Matrix const &m) const;


    bool operator==(Matrix const &m) const;
    bool operator!=(Matrix const &m) const;

    Matrix& operator=(Matrix const &m);

private:
    static int** allocate_memory(std::size_t rows, std::size_t cols);
private:
    std::size_t _rows;
    std::size_t _cols;
    int** _data;
};
#endif //WW_MATRIX_MATRIX_HPP
