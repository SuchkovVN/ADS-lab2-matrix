#pragma once
#include "Vector.h"

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template<typename T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix();
  TDynamicMatrix(size_t size);
  TDynamicMatrix(const TDynamicMatrix& m);
  // TDynamicMatrix& operator=(const TDynamicMatrix<T>& m);

  using TDynamicVector<TDynamicVector<T>>::operator[];
  

  bool operator==(const TDynamicMatrix& m) const noexcept;
  bool operator!=(const TDynamicMatrix& m) const noexcept;

  TDynamicMatrix<T> operator+(const T& val);
  TDynamicMatrix<T> operator-(const T& val);
  TDynamicMatrix<T> operator*(const T& val);

  TDynamicMatrix<T> operator+(const TDynamicVector<T>& v);
  TDynamicMatrix<T> operator-(const TDynamicVector<T>& v);
  TDynamicVector<T> operator*(const TDynamicVector<T>& v);

  TDynamicMatrix operator+(const TDynamicMatrix& m);
  TDynamicMatrix operator-(const TDynamicMatrix& m);
  TDynamicMatrix operator*(const TDynamicMatrix& m);

  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
    for (size_t i = 0; i < sz; i++)
    {
      for (size_t j = 0; j < sz; j++)
      {
        istr >> v[i][j];
      }
    }
    return istr; 
  }

  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
    ostr << '(';
    for (size_t i = 0; i < v.size(); i++)
    {
      for (size_t j = 0; j < v.size(); j++)
      {
        ostr << v[i][j] << ' ';
      }
      if (i != v.size() - 1) ostr << '\n';
    }
    ostr << ')';

    return ostr;
  }

};

template<typename T>
inline TDynamicMatrix<T>::TDynamicMatrix(): TDynamicVector<TDynamicVector<T>>()
{
}


template<typename T>
inline TDynamicMatrix<T>::TDynamicMatrix(size_t size) : TDynamicVector<TDynamicVector<T>>(size) 
{
  if (size <= 0) throw "Error: dynamicMarix size <= 0";
  for (size_t i = 0; i < sz; i++)
    pMem[i] = TDynamicVector<T>(sz);
}

template<typename T>
TDynamicMatrix<T>::TDynamicMatrix(const TDynamicMatrix<T>& m): TDynamicVector<TDynamicVector<T>>(m)
{
  // TDynamicVector<TDynamicVector<T>> temp(m.pMem);
}

// template<typename T>
// TDynamicMatrix<T>& TDynamicMatrix<T>::operator=(const TDynamicMatrix<T>& m)
// {
//   if (&m == this) return *this;

//   if (sz == m.sz)
//   {
//     for (size_t i = 0; i < sz; i++)
//     {
//       pMem[i] = m.pMem[i];
//     }
//     return *this;
//   }

//   delete [] pMem;
//   sz = m.sz;

//   for (size_t i = 0; i < sz; i++)
//     {
//       pMem[i] = m.pMem[i];
//     }
//   return *this;
// }

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
  TDynamicMatrix<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] + val;
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const T& val)
{ 
  TDynamicMatrix<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] - val;
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const T& val)
{ 
  TDynamicMatrix<T> temp(*this);

  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] * val;
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const TDynamicVector<T>& v)
{
  if (sz != v.sz) throw "Error: vector and matrix disparity";

  TDynamicMatrix<T> temp(*this);
  for(size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] + v;
  }
  
  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const TDynamicVector<T>& v)
{
  if (sz != v.sz) throw "Error: vector and matrix disparity";

  TDynamicMatrix<T> temp(*this);
  for(size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] - v;
  }

  return temp;
}

template<typename T>
TDynamicVector<T> TDynamicMatrix<T>::operator*(const TDynamicVector<T>& v)
{
  if (sz != v.sz) throw "Error: vector and matrix disparity";

  TDynamicVector<T> temp(sz);

  for(size_t i = 0; i < sz; i++)
  {
    temp[i] = pMem[i] * v;
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const TDynamicMatrix<T>& m)
{
  if (sz != m.sz) throw "Error: matrix disparity";

  TDynamicMatrix<T> temp(*this);
  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] + m[i];
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const TDynamicMatrix<T>& m)
{
  if (sz != m.sz) throw "Error: matrix disparity";

  TDynamicMatrix<T> temp(*this);
  for (size_t i = 0; i < sz; i++)
  {
    temp[i] = temp[i] - m[i];
  }

  return temp;
}

template<typename T>
TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const TDynamicMatrix<T>& m)
{
  if (sz != m.sz) throw "Error: matrix disparity";
  TDynamicMatrix<T> temp(sz);
  
  for (size_t i = 0; i < sz; i++)
  {
    for (size_t j = 0; j < sz; j++)
    {
      for (size_t k = 0; k < sz; k++)
      {
        temp[i][j] += pMem[i][k] * m[k][j];
      }
    }
  }

  return temp;
}
