#include <cassert>

#pragma once

namespace lab_13 {

    template<typename T, std::size_t N>
    class my_array {
    public:

        T &operator[](std::size_t index) {
            return _data[index];
        }

        T const &operator[](std::size_t index) const {
            return _data[index];
        }

        T &at(std::size_t index) {
            assert(index < N);

            return _data[index];
        }

        T const &at(std::size_t index) const {
            assert(index < N);

            return _data[index];
        }

        bool empty() const {
            return false;
        }

        std::size_t size() const {
            return N;
        }

        void fill(T val) {
            for (std::size_t i = 0; i < N; i++)
                _data[i] = val;
        }

    private:
        T _data[N];
    };

    template<std::size_t N>
    class my_array<bool, N> {
    private:
        class bool_ref;

    public:
        bool operator[](std::size_t index) const {
            return bool_ref(_data, index);
        }

        bool_ref operator[](std::size_t index) {
            return bool_ref(&_data[0], index);
        }

        bool empty() const {
            return false;
        }

        std::size_t size() const {
            return N;
        }

        void fill(bool val) {
            for (std::size_t index = 0; index < N; ++index)
                bool_ref(&_data[0], index) = val;
        }

        bool_ref at(std::size_t index) {
            assert(index < N);

            return bool_ref(&_data[0], index);
        }

        bool at(std::size_t index) const {
            assert(index < N);

            return bool_ref(&_data[0], index);
        }

    private:
        static const uint8_t _base = 8;
        static const uint8_t _size = !(N % _base) ? N / _base : N / _base + 1;
        uint8_t _data[_size];

        class bool_ref {
        private:
            friend class my_array;
            bool_ref(uint8_t *data, std::size_t index) :
                    data(data),
                    mask(1 << (index % _base)),
                    data_index(index / _base)
            {};
        public:

            operator bool() const {
                return (bool) (data[data_index] & mask);
            }

            bool_ref &operator=(bool new_value) {
                new_value ? data[data_index] |= mask : data[data_index] &= ~mask;
                return *this;
            }

            bool_ref &operator=(bool_ref const &new_value) {
                if (this == &new_value)
                    return *this;

                *this = (bool) new_value;
                return *this;
            }

        private:
            uint8_t *data;
            uint8_t mask;
            std::size_t data_index;
        };

    };

}
