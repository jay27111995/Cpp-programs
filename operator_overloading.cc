#include <iostream>

class Vec2 {
public:
    int x, y;

    Vec2(int x = 0, int y = 0) : x(x), y(y) {}

    // Binary + operator (member function)
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    // Compound assignment +=
    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Unary - (negate)
    Vec2 operator-() const {
        return Vec2(-x, -y);
    }

    // Comparison ==
    bool operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }

    // Subscript [] (0=x, 1=y)
    int& operator[](int i) {
        return i == 0 ? x : y;
    }

    // Function call () - scale the vector
    Vec2 operator()(int scale) const {
        return Vec2(x * scale, y * scale);
    }
};

// Stream output << (must be non-member or friend)
std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    return os << "(" << v.x << ", " << v.y << ")";
}

int main() {
    Vec2 a(3, 4);
    Vec2 b(1, 2);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    // Binary +
    std::cout << "a + b = " << a + b << "\n";

    // Compound +=
    a += b;
    std::cout << "a += b: a = " << a << "\n";

    // Unary -
    std::cout << "-b = " << -b << "\n";

    // Comparison
    std::cout << "a == b? " << (a == b ? "yes" : "no") << "\n";

    // Subscript
    Vec2 c(10, 20);
    std::cout << "c[0] = " << c[0] << ", c[1] = " << c[1] << "\n";
    c[0] = 99;
    std::cout << "after c[0] = 99: " << c << "\n";

    // Function call
    Vec2 d(2, 3);
    std::cout << "d(5) = " << d(5) << "\n";

    return 0;
}
