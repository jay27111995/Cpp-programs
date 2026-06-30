// Address Sanitizer Demo
// Compile: g++ -fsanitize=address -g asan_demo.cpp -o asan_demo

#include <iostream>

// Bug 1: Buffer overflow
void buffer_overflow() {
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << "Accessing arr[10] (out of bounds): ";
    std::cout << arr[10] << std::endl;  // BUG: reading past array
}

// Bug 2: Use after free
void use_after_free() {
    int* p = new int(42);
    delete p;
    std::cout << "Use after free: " << *p << std::endl;  // BUG: accessing freed memory
}

// Bug 3: Memory leak
void memory_leak() {
    int* p = new int[100];  // BUG: never freed
    p[0] = 123;
    std::cout << "Leaked memory: " << p[0] << std::endl;
    // forgot delete[] p;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <test>\n";
        std::cout << "  1 - buffer overflow\n";
        std::cout << "  2 - use after free\n";
        std::cout << "  3 - memory leak\n";
        return 1;
    }

    int test = std::stoi(argv[1]);
    
    switch (test) {
        case 1: buffer_overflow(); break;
        case 2: use_after_free(); break;
        case 3: memory_leak(); break;
        default: std::cout << "Unknown test\n";
    }

    return 0;
}
