#include <iostream>

using namespace std;

class base
{
  public:
    static int socket_fd;
};

int base::socket_fd = -1;

class child : base
{
  public:
    void print_func();
};

void child::print_func()
{
  cout << socket_fd << endl;
}

int main()
{
  base bs;
  bs.socket_fd = 10;

  child ch;

  ch.print_func();

  return 0;
}


