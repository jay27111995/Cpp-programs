# C++ Programs

C++ learning examples and concepts.

## Files

| File | Description |
|------|-------------|
| `algo.cc` | STL algorithms - sort, count_if, find |
| `bitwise.cpp` | Bitwise operations |
| `const.cpp` | const keyword usage |
| `copy_constructor.cc` | Deep copy constructor example |
| `copy_assignment_constructor.cc` | Copy assignment operator (stub) |
| `dyn_lib.cpp` | Dynamic library loading |
| `foo.cpp` | Shared library example |
| `init_values_class.cc` | Class member initialization |
| `lambdas.cc` | Lambda expressions |
| `move.cc` | Move semantics (stub) |
| `operator_overloading.cc` | Operator overloading |
| `recursive_mutex.cc` | Recursive mutex usage |
| `smart_ptr.cc` | Smart pointers (stub) |
| `static_inheritance.cc` | Static members with inheritance |
| `templates_class.cc` | Class templates (stub) |
| `templates_func.cc` | Function templates (stub) |
| `vector.cc` | STL vector usage |
| `asan_demo.cpp` | Address Sanitizer demo |
| `ubsan_demo.cpp` | Undefined Behavior Sanitizer demo |
| `codecheck_demo.cpp` | Static analysis demo |

## Build

```bash
g++ -std=c++17 -o program file.cc
./program
```

## Sanitizers & Code Checking

### Address Sanitizer (ASan)
Catches memory bugs at runtime: buffer overflow, use-after-free, memory leaks.

```bash
# Compile
clang++ -fsanitize=address -g asan_demo.cpp -o asan_demo

# Run (crashes with report if bug found)
./asan_demo 1    # buffer overflow
./asan_demo 2    # use after free
./asan_demo 3    # memory leak
```

### Undefined Behavior Sanitizer (UBSan)
Catches undefined behavior: integer overflow, divide by zero, bad shifts.

```bash
# Compile
clang++ -fsanitize=undefined -g ubsan_demo.cpp -o ubsan_demo

# Run
./ubsan_demo 1   # signed overflow
./ubsan_demo 2   # divide by zero
./ubsan_demo 4   # shift overflow
```

### Combine both
```bash
clang++ -fsanitize=address,undefined -g myfile.cpp -o myfile
```

### Static Analysis (clang-tidy)
Finds bugs without running code: unused variables, memory leaks, insecure functions.

```bash
# Basic check
clang-tidy codecheck_demo.cpp -- -std=c++17

# More checks
clang-tidy file.cpp --checks='bugprone-*,performance-*' -- -std=c++17

# Auto-fix where possible
clang-tidy file.cpp --fix -- -std=c++17
```

### Summary

| Tool | When | What it catches |
|------|------|-----------------|
| ASan | Runtime | Buffer overflow, use-after-free, leaks |
| UBSan | Runtime | Integer overflow, div/0, bad shifts |
| clang-tidy | Static | Style, bugs, security issues |

## Topics to complete

- [ ] smart_ptr.cc
- [ ] move.cc
- [ ] templates_class.cc
- [ ] templates_func.cc
- [ ] copy_assignment_constructor.cc
