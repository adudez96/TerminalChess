#include <cstdio>
#include <iostream>
#include <ostream>


class Number;

class Number {
    public:
        // Constructor
        // Copy Constructor
        // Copy assignment
        // Move Constructor
        // Move assignment

        Number(int v): value{v} {};

        Number(const Number &n) = default;

        Number& operator=(const Number &other) = default;

        Number(Number &&n): value{std::move(n.value)} {
            n.value = 0;
        }

        Number& operator=(Number &&other) {
            this->value = std::move(other.value);
            other.value = 0;
            return *this;
        }

        ~Number() = default;

        int getValue() const { return this->value; }

        int operator+(const Number &rhs) const {
            return this->value + rhs.getValue();
        }

        friend std::ostream& operator<< (std::ostream &os, const Number &n);

    private:
        int value;
};

std::ostream& operator<<(std::ostream &os, const Number &n) {
    os << n.getValue();
    return os;
}

int main () {
    Number n = 10;
    Number n0{n};
    Number n2 = n + n;
    Number n3 = std::move(n2);
    Number n4{std::move(n)};

    std::cout << n << " " << n0 << " " << n2 << " " << n3 << " " << n4 << "\n";
    return 0;
}