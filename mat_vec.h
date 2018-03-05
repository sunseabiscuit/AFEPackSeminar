/**
 * @file mat_vec.h
 * @brief 
 * @author 
 * @version 
 * @date 2018-03-05
 */

#ifndef __MAT_VEC_H_
#define __MAT_VEC_H_

enum {
  RowMajor = 1,
  ColMajor = -1,
  FROBENIUS = 2
};

template <typename T, int Major> class Matrix;
template <typename T> class Vector;

template <typename T>
class Vector{
public:
  typedef T value_type;
  typedef unsigned int size_type;
  //...

  //some constructors ... 

  //some operators ... 

  //some iterators ...

  size_type size() const;

  void resize(const size_type);

  template <typename Iterator>
  void assign(Iterator, Iterator);

  void lnorm(const unsigned int) const;

  template <typename stream>
  void print(stream&, const unsigned int) const;

  template <typename VEC>
  void add(const VEC&, double);

private:
  T* val;
  size_type vec_size;
  size_type max_size;
};

template <typename T, int Major = RowMajor>
class Matrix{
public:
  enum {isRowMajor = (Major > 0) ? 1 : -1};
  typedef T value_type;
  typedef unsigned int size_type;

  //some constructors ... 
  
  //some operators ...

  //T& operator()(const size_type, const size_type);
  //T* operator[](const size_type);

  void resize(const size_type, const size_type);

  size_type row() const;
  size_type col() const;

  T lnorm(const unsigned int) const;

  T determinant() const;

  T trace() const;

  template <typename stream>
  void print(stream&, const unsigned int);

  template <typename MATRIX>
  void add(const MATRIX&, double);

  template <typename MATRIX>
  void Tadd(const MATRIX&, double);

  void symmetrize();

  template <typename MATRIX>
  void inverse(MATRIX&);

  template <typename MATRIX>
  void mmult(MATRIX&, const MATRIX&);

  template <typename VECTOR>
  void vmult(VECTOR&, const VECTOR&);

  //...



private:
  T* val;
  size_type n_row, n_col;
  size_type max_size;

};


#endif

