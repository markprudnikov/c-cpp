#pragma once

#include <iostream>
#include <iosfwd>
#include <cstddef>

namespace containers {
    using namespace std;

    template<typename T>
    class my_vector {
    public:
        my_vector();
        my_vector(size_t n);
        my_vector(my_vector const& other);
        my_vector<T> operator=(my_vector other);
        ~my_vector();

        size_t size() const;
        size_t capacity() const;
        bool empty() const;

        void resize(size_t n);
        void reserve(size_t n);

        T& operator[](size_t index);
        T const& operator[](size_t index) const;

        void push_back(T const& t);
        void pop_back();
        void clear();

        friend ostream& operator<<(ostream& out, my_vector<T> const& v);
        
    private:
        //static int is_power_of_two(size_t cp);
        void resize_up(size_t n);
        void resize_down(size_t n);

    private:
        size_t _cp;
        size_t _sz;
        T* _array;
    };
    
}

#include "my_vector_impl.hpp"
