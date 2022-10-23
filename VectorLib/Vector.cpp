#include "Vector.h"

int main()
{
  TDynamicVector<int> a(3);

  int arr[3] = {0, 0, 2};

  TDynamicVector<int> b(arr, 3);

  TDynamicVector<int> c = a + b;

  cout << c;
}