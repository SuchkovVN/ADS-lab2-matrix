#pragma once
#include "Vector.h"

template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t size = 1) : TDynamicVector<TDynamicVector<T>>(size);
  TDynamicMatrix(const TDynamicMatrix& m) : TDynamicVector<TDynamicVector<T>>(m.pMem);
  TDynamicMatrix& operator=(const TDynamicMatrix<T>& m);

  using TDynamicVector<TDynamicVector<T>>::operator[];

  bool operator==(const TDynamicMatrix& m) const noexcept;
  bool operator!=(const TDynamicMatrix& m) const noexcept;

  TDynamicMatrix<T> operator+(const T& val);
  TDynamicMatrix<T> operator-(const T& val);
  TDynamicMatrix<T> operator*(const T& val);

  TDynamicVector<T> operator+(const TDynamicVector<T>& v);
  TDynamicVector<T> operator-(const TDynamicVector<T>& v);
  TDynamicVector<T> operator*(const TDynamicVector<T>& v);

  TDynamicMatrix operator+(const TDynamicMatrix& m);
  TDynamicMatrix operator-(const TDynamicMatrix& m);
  TDynamicMatrix operator*(const TDynamicMatrix& m);

  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
  }

};

template<typename T>
inline TDynamicMatrix<T>::TDynamicMatrix(size_t size = 1) : TDynamicVector<TDynamicVector<T>>(size) 
{
  if (size <= 0) throw "Error: dynamicMarix size <= 0";
  for (size_t i = 0; i < sz; i++)
    pMem[i] = TDynamicVector<T>(sz);
}

template<typename T>
TDynamicMatrix<T>::TDynamicMatrix(const TDynamicMatrix<T>& m) : TDynamicVector<TDynamicVector<T>>(m.pMem) {}

template<typename T>
bool TDynamicMatrix<T>::operator==(const TDynamicMatrix<T>& m) const noexcept
{
  if (sz != m.sz) return false;
  for (size_t i = 0; i < sz; i++) 
  {
    if (pMem[i] != m[i]) return false;
  }
  return true;
}

template<typename T>
bool TDynamicMatrix<T>::operator!=(const TDynamicMatrix<T>& m) const noexcept 
{
  return !(*this == m);
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const T& val)
{ 


}


