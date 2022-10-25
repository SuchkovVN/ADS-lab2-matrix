#include "Matrix.h"

int main()
{
  try
  {
     int arr[3] = {1, 0, 2};
     TDynamicVector<int> a(3);
     TDynamicVector<int> b(arr, 3);
     TDynamicVector<int> c;
    

    TDynamicMatrix<int> A(3);

    cout << A;
  }
  catch (const char* s)
  {
    cout << s;
  }

  return 0;
}