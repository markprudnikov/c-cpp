#include <iostream>

#include "my_array.hpp"

int main() {
    lab_13::my_array<int, 20> not_empty{};

    not_empty.fill(1);

    std::cout << not_empty.size() << std::endl;

    std::cout << not_empty.empty() << std::endl;

    std::cout << not_empty.at(4) << std::endl;

    return 0;
}
