#include <iostream>

using namespace std;

int main()
{
  uint32_t bit_mask = ~0x3U;
  uint64_t bit_mask1 = ~0x3ULL;
  
  cout << hex << bit_mask << endl;
  cout << hex << bit_mask1 << endl;

  return 0;
}

