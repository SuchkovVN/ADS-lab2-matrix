#pragma once

#include "Matrix.h"

template<typename T>
class TTriangMatrix : public TDynamicMatrix<T>
{
public:
  TTriangMatrix(const size_t size = 1);
  TTriangMatrix(const TTriangMatrix<T>& tm);
  TTriangMatrix(TTriangMatrix<T>&& tm);

  //using TDynamicVector<TDynamicVector<T>>::operator[];
  //at() 
  //size_t size() const noexcept;

  bool operator==(const TTriangMatrix<T>& tm) const noexcept;
  bool operator!=(const TTriangMatrix<T>& tm) const noexcept;


  TTriangMatrix<T>& operator=(const TTriangMatrix<T>& tm);

  TTriangMatrix<T> operator+(T value);
  TTriangMatrix<T> operator-(T value);
  TTriangMatrix<T> operator*(T value);

  TTriangMatrix<T> operator+(const TTriangMatrix<T>& tm);
  TTriangMatrix<T> operator-(const TTriangMatrix<T>& tm);
  TTriangMatrix<T> operator*(const TTriangMatrix<T>& tm);


 friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
    
    return istr; 
  }

  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
    
    return ostr;
  }
};

template<typename T>
TTriangMatrix<T>::TTriangMatrix(const size_t size) : TDynamicVector<TDynamicVector<T>>(size)
{
  for (int i = 0; i < size; i++)
  {
    for(int j = 0; j < i; j++)
    {
      pMem[i][j] = 0;
    }
  }
}

template<typename T>
TTriangMatrix<T>::TTriangMatrix(const TTriangMatrix<T>& tm): TDynamicVector<TDynamicVector<T>>(tm) {}

template<typename T>
TTriangMatrix<T>::TTriangMatrix(TTriangMatrix<T>&& tm): TDynamicVector<TDynamicVector<T>>(tm) {}

template<typename T>
bool TTriangMatrix<T>::operator==(const TTriangMatrix<T>& tm) const noexcept
{
  if (sz != m.sz) return false;
  for (size_t i = 0; i < sz; i++) 
  {
    if (pMem[i] != m[i]) return false;
  }
  return true;
}

template<typename T>
bool TTriangMatrix<T>::operator!=(const TTriangMatrix<T>& tm) const noexcept
{
  return !(*this == m);
}








  