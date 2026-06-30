#include <iostream>

class test_cl
{
  public:
  test_cl()
  {
    std::cout << "object A constructor" << std::endl;
  }

  void alloc()
  {
    a = new int[10];
  }

  // Other is the class from which you copy from
  // this is your present class
  test_cl(const test_cl &other)
  {
    this->a = new int[10];
    for (int i = 0; i < 10; i++)
    {
      this->a[i] = other.a[i];
    }
  };
 
  void fill()
  {
    for (int i = 0; i < 10; i++)
    {
      a[i] = i;
    }
  }

  void print()
  {
    for (int i = 0; i < 10; i++)
    {
      std::cout << a[i] << std::endl; 
    }
    std::cout << std::endl;
  }

  private:
  int *a = nullptr;
};

int main()
{
  test_cl cl;
  cl.alloc();
  cl.fill();
  cl.print();
  test_cl nl = cl;
  nl.print();

  return 0;
}
