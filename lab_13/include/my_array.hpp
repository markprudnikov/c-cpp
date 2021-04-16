#include <cassert>

#pragma once
#include <bitset>
namespace lab_13 {

    template<typename T, std::size_t N>
    class my_array {
    public:

        T& operator[](std::size_t index) {
            return _data[index];
        }

        T const& operator[](std::size_t index) const {
            return _data[index];
        }

        T& at(std::size_t index) {
            assert(index < N);

            return _data[index];
        }

        T const& at(std::size_t index) const {
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
        T _data[N]{};
    };

    template<std::size_t N>
    class my_array<bool, N> {
    public:
        class bool_ref {
        public:
            bool_ref() = default;

            explicit operator bool() const {
                //TODO("")
            }

            bool operator=(bool new_value) {
                //TODO("")
            }

        private:

        };

        bool operator[](std::size_t index) const {
            //TODO("");
        }

        bool_ref operator[](std::size_t index) {
            return bool_ref();
        }

    private:
        uint8_t _data[!((N - 1) & N && N >= 8) ? N / 8 : N / 8 + 1];
    };

}
