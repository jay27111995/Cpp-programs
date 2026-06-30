#include <iostream>

using namespace std;

int main()
{
  int x = 10;
  auto lam = [x](){
    cout << "Value of x = " << x << endl;
  };

  lam();

  auto lam1 = [&x](int a){
    x += a;
    cout << "Value of x = " << x << endl;
  };

  lam1(10);
  
  // Make copied capture variables as mutable or modifyable from const type
  auto lam2 = [x](int a) mutable {
    x += a;
    cout << "Value of x = " << x << endl;
  };
  
  lam2(20);

  // Capture all by reference
  auto lam3 = [&](int a){
    x += a;
    cout << "Value of x = " << x << endl;
  };
  
  lam3(40);

  // Capture all by value
  auto lam4 = [=](int a) mutable {
    x += a;
    cout << "Value of x = " << x << endl;
  };
  
  lam4(40);

  return 0;
}
