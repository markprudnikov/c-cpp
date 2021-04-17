#include <iostream>

#include "my_array.hpp"

template<typename T, std::size_t N>
void test_core() {
    lab_13::my_array<T, N> a;
    const lab_13::my_array<T, N> &ca = a;
    a.empty();
    ca.empty();
    a.size();
    ca.size();

    a.at(0);
    ca.at(0);
    a[0];
    ca[0];
    (void)static_cast<const T &>(a[0]);
    (void)static_cast<const T &>(ca[0]);
}

int main() {
    lab_13::my_array<int, 20> not_empty;

    not_empty.fill(1);

    std::cout << not_empty.size() << std::endl;

    std::cout << not_empty.empty() << std::endl;

    std::cout << not_empty.at(4) << std::endl;

    lab_13::my_array<bool, 35> bitset;

    bitset.fill(true);
    assert(bitset[1] == true);
    assert(bitset[0] == true);

    bitset[0] = false;
    assert(bitset[0] == false);

    bitset[0] = bitset[1];
    assert(bitset[0] == bitset[1]);
    assert(bitset[0] == true);
    assert(bitset.at(1) ==  true);

    //test_core<int, 10>();
    test_core<bool, 10>();

    return 0;
}
