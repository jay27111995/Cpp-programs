#include <iostream>
#include <dlfcn.h>

using namespace std;

int jay_dbg = 100;

int main()
{
  void* handle = dlopen("./libfoo.so", RTLD_NOW | RTLD_LOCAL);
  auto func = (void (*)())dlsym(handle, "print_jay_dbg");
  func();

  cout << "jay_dbg from main = " << jay_dbg << endl;

  return 0;
}
