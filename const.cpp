#include <iostream>

using namespace std;

void func1(int const& val)
{
  // Will Cause error
  //val = 2;
}

void func2(int const *ptr)
{
  // Modifying a Read only location 
  // *ptr = 2;
  
  int a = 10;

  // This is valid, weird, then how to make a ptr const?
  ptr = &a;
}

void func3(int * const ptr)
{
  int a = 10;

  // This should be an error 
  //ptr = &a;
}

int main()
{
  int const a = 10;

  // Will cause error
  //a = 20;
  
  int b = 20;

  func1(b);

  int *c = &b;
  func2(c);

  return 0;
}
