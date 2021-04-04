#pragma once
#include <iostream>
#include "my_vector.hpp"

namespace containers {
    using namespace std;

    // static int is_power_of_two(size_t cp) {
    //     return (cp > 0) && ((cp & (cp - 1)) == 0);
    // }

    template<typename T>
    my_vector<T>::my_vector():
        _cp(2),
        _sz(0),
        _array((T*) new char[sizeof(T) * 2])
        {};

    template<typename T>
    my_vector<T>::my_vector(size_t n):
        _sz(0),
        _cp(n),
        _array((T*) new char[sizeof(T) * n])
        {};

    template<typename T>
    my_vector<T>::my_vector(my_vector const& other) {
        _cp = other._cp;
        _sz = other._sz;
        _array = (T*) new char[sizeof(T) * _cp];
        for (size_t i = 0; i < _sz; i++) {
            _array[i].T(other._array[i]);
        }
    }

    template<typename T>
    my_vector<T> my_vector<T>::operator=(my_vector other) {
        if (this == &other)
            return;
            
        this->resize(other._sz);
        this->reserve(other._cp);

        for (size_t i = 0; i < _sz; i++) {
            this->_array[i].T(other._array[i]);
        }
            
        return *this;
    }

    template<typename T>
    my_vector<T>::~my_vector() { delete[] (char*) _array; }

    template<typename T>
    size_t my_vector<T>::size() const { return _sz; }

    template<typename T>
    size_t my_vector<T>::capacity() const { return _cp; }

    template<typename T>
    bool my_vector<T>::empty() const { return _sz == 0; }

    template<typename T>
    void my_vector<T>::resize(size_t n) {
        n > _sz ? resize_up(n) : resize_down(n);
    }

    template<typename T>
    void my_vector<T>::resize_up(size_t n) {
        assert(n > _sz);

        if (n > _cp) reserve(2 * n);

        for (size_t i = _sz; i < n; i++) {
            new(&_array[i]) T();
        }
    }

    template<typename T>
    void my_vector<T>::resize_down(size_t n) {
        assert(n <= _sz);

        for (size_t i = n; i != _sz - 1; i++) {
            new(&_array[i]) T();
        }

        _sz = n;
    }

    template<typename T>
    void my_vector<T>::reserve(size_t n) {
        if (_cp >= n)
            return;

        while (!((n > 0) && ((n & (n - 1)) == 0))) n++;
        

        T* new_array = (T *) new char[sizeof(T) * n];

        for (size_t i = 0; i < _sz; i++) {
            new(&new_array[i]) T(_array[i]); //copy cstors
        }

        for (size_t i = 0; i < _sz; i++) {
            _array[i].~T();
        }

        delete[] (char *) _array;
        _array = new_array;
        _cp = n;
    }

    template<typename T>
    T& my_vector<T>::operator[](size_t index){
        assert(index < _sz);
        return _array[index];
    }

    template<typename T>
    T const& my_vector<T>::operator[](size_t index) const {
        assert(index < _sz);
        return _array[index];
    }

    template<typename T>
    void my_vector<T>::push_back(T const& t) {
        if (_sz == _cp) {
            reserve(_cp * 2);
        }

        new(&_array[_sz++]) T(t); // здесь именно конструктор копий!
    }

    template<typename T>
    void my_vector<T>::pop_back() {
        if (_sz != 0) _array[_sz - 1].~T();
    }

    template<typename T>
    void my_vector<T>::clear() {
        resize_down(0);
    }

    template<typename T>
    ostream& operator<<(std::ostream& out, my_vector<T> const& v) {
        for (size_t i = 0; i < v._sz; i++) out << v._array[i];
        return out;
    }
}