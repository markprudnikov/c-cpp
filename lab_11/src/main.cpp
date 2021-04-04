#include <iostream>
#include <cstring>
#include <iosfwd>

#include "my_vector.hpp"

namespace product {
    
    class Product {
    public:
        Product(const char* name, int quantity, double price):
            name_(strcpy(new char[strlen(name) + 1], name)),
            quantity_(quantity),
            price_(price)
            {};
        
        Product(Product const& other) {
            quantity_ = other.quantity_;
            price_ = other.price_;
            name_ = std::strcpy(new char[std::strlen(other.name_)], other.name_);
        }
        friend std::ostream& operator<<(std::ostream& out, Product const& p) {
            return out << p.name_ << " " << p.quantity_ << " " << p.price_;
        }
    private:
        char* name_;  // Указатель владеет C-style строкой, на которую указывает.
        int quantity_;
        double price_;
    };

    void print(const containers::my_vector<Product>& v) {
        std::cout << v << std::endl;
    }

}  // namespace product

template<typename T>
void test_my_vector(T a, T b) {
    containers::my_vector<T> v;
    v.push_back(a);
    v.push_back(b);
    assert(v.size() == 2);
    assert(v.capacity() == 4);
    v.resize(5);
    assert(v.capacity() == 8);
    assert(v.size() == 5);
    assert(v.empty() == false);
    v.reserve(10);
    assert(v.capacity() == 16);
    assert(v[0] == a);
    assert(v[1] == a);
    v.clear();
    assert(v[0] != a);
}

int main() {
    test_my_vector<int>(5, 10);
    //test_my_vector<Product>(Product("asdf", 4, 12.0), Product("qwe", -1, 7.5));
    //test_my_vector_default_constructible<int>(5, 10);
    return 0;
}