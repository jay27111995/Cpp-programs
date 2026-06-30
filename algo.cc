#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  vector <int>num = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  
  sort(num.begin(), num.end());

  for (int i : num)
    cout << i << endl;

  auto is_even = [](int x){return (x % 2 == 0);};
  
  int even = count_if(num.begin(), num.end(), is_even);
  
  cout << endl;
  cout << even << endl;
  
  auto pos = find(num.begin(), num.end(), 5);  
  
  cout << endl;
  cout << *pos << endl;

  return 0;
}
