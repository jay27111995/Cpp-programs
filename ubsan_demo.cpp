// UBSan Demo - Undefined Behavior Sanitizer
// Compile: clang++ -fsanitize=undefined -g ubsan_demo.cpp -o ubsan_demo

#include <iostream>
#include <climits>

// Bug 1: Signed integer overflow
void signed_overflow() {
    int x = INT_MAX;
    std::cout << "INT_MAX = " << x << std::endl;
    std::cout << "INT_MAX + 1 = " << x + 1 << std::endl;  // BUG: undefined behavior
}

// Bug 2: Divide by zero
void divide_by_zero() {
    int x = 10;
    int y = 0;
    std::cout << "10 / 0 = " << x / y << std::endl;  // BUG: undefined
}

// Bug 3: Null pointer dereference
void null_deref() {
    int* p = nullptr;
    std::cout << "Null deref: " << *p << std::endl;  // BUG: undefined
}

// Bug 4: Shift overflow
void shift_overflow() {
    int x = 1;
    std::cout << "1 << 32 = " << (x << 32) << std::endl;  // BUG: shift too large
}

// Bug 5: Out of bounds array index (with variable)
void array_oob() {
    int arr[5] = {1, 2, 3, 4, 5};
    int i = 10;
    std::cout << "arr[10] = " << arr[i] << std::endl;  // BUG
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <test>\n";
        std::cout << "  1 - signed overflow\n";
        std::cout << "  2 - divide by zero\n";
        std::cout << "  3 - null dereference\n";
        std::cout << "  4 - shift overflow\n";
        std::cout << "  5 - array out of bounds\n";
        return 1;
    }

    int test = std::stoi(argv[1]);
    
    switch (test) {
        case 1: signed_overflow(); break;
        case 2: divide_by_zero(); break;
        case 3: null_deref(); break;
        case 4: shift_overflow(); break;
        case 5: array_oob(); break;
        default: std::cout << "Unknown test\n";
    }

    return 0;
}
