#include <iostream>
#include <vector> // Sort of Array
#include <deque> // Double ended Que
#include <list> // Linked List

int main()
{
  std::vector <int>numbers;
  numbers = {0, 1, 2, 3};
  
  std::cout << numbers.front() << std::endl;
  std::cout << numbers.back() << std::endl;

  numbers.push_back(9);

  std::cout << numbers.back() << std::endl;

  numbers.pop_back();

  std::cout << numbers.back() << std::endl;
  
  std::cout << std::endl;

  std::deque <int>que;
  que = {0, 1, 2, 3, 4, 5};

  std::cout << que.front() << std::endl;
  std::cout << que.back() << std::endl;
  
  que.pop_back();

  std::cout << que.back() << std::endl;

  // Only deque can be used to pop from front
  que.pop_front();

  std::cout << que.front() << std::endl;

  // Can be used like array indexing
  std::cout << que[0] << " " << que[1] << std::endl;

  std::cout << std::endl;
  
  // New for loop to iterate over collections like vector or Q
  for (int num : que)
  {
    std::cout << num << std::endl;
  }
  
  // Note: When a vector grows in size, it copies the old contents to a new mem with new elems
  
  std::list <int>lis;
  lis = {0, 1, 2, 3, 4, 5};

  struct example {
    int a;
    int b;
  };

  std::vector <struct example>examples;
  struct example a = {.a=1, .b=2};
  examples.push_back(a);
  
  class ex_obj
  {
  public:
    ex_obj(int a1, int b1) : a(a1), b(b1){};
    int a;
    int b;
  };
  
  // Emplace back will create an object and then add it to the vector
  std::vector <ex_obj>ex_objs;
  ex_objs.emplace_back(1, 2);

  return 0;
}
