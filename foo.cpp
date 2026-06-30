#include <iostream>

extern int jay_dbg;

extern "C" void print_jay_dbg() {
    std::cout << "jay_dbg = " << jay_dbg << std::endl;
}
