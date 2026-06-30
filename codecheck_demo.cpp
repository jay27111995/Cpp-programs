// Static Analysis Demo
// Run: clang-tidy codecheck_demo.cpp -- -std=c++17

#include <iostream>
#include <cstring>

// Bug 1: Unused variable
void unused_var() {
    int x = 10;  // never used
    std::cout << "Hello\n";
}

// Bug 2: Memory leak
void memory_leak() {
    int* p = new int(42);
    std::cout << *p << std::endl;
    // forgot delete p;
}

// Bug 3: Unsafe C function
void unsafe_strcpy() {
    char buf[10];
    const char* src = "This string is way too long for the buffer";
    strcpy(buf, src);  // unsafe, use strncpy
    std::cout << buf << std::endl;
}

// Bug 4: Uninitialized variable
void uninitialized() {
    int x;
    std::cout << x << std::endl;  // x not initialized
}

// Bug 5: Redundant condition
void redundant_check() {
    unsigned int x = 5;
    if (x >= 0) {  // always true for unsigned
        std::cout << "always true\n";
    }
}

// Bug 6: Magic numbers
void magic_numbers() {
    int timeout = 86400;  // what is this? 
    int retry = 3;
    std::cout << timeout * retry << std::endl;
}

// Bug 7: C-style cast
void c_style_cast() {
    double d = 3.14;
    int i = (int)d;  // should use static_cast<int>(d)
    std::cout << i << std::endl;
}

int main() {
    unused_var();
    uninitialized();
    redundant_check();
    magic_numbers();
    c_style_cast();
    return 0;
}
