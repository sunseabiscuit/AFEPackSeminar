/**
 * @file sparsematrix.h
 * @brief 
 * @author 
 * @version 
 * @date 2018-03-05
 */
#ifndef __SPARSE_MATRIX_H_
#define __SPARSE_MATRIX_H_

template <typename T> class SparseMatrix;
class SolverBase;
template <typename VECTOR> class KrylovBase;
template <typename MATRIX, typename VECTOR> class CGSolver;
template <typename MATRIX, typename VECTOR> class BiCGSTABSolver;



/**
 * @brief The implementation of the sparse matrix bases on CSR method.
 */
template <typename T>
class SparseMatrix{
public:
  typedef T value_type;
  typedef unsigned int size_type;

  static T invalid = (size_type)-1;

  // constructors ...

  // operators ...

  void resize(const size_type, const size_type, 
      const size_type max);

  void add(const size_type, const size_type);

  void add(const size_type, const size_type, const T);

  void set(const size_type, const size_type, const T);
  
  /**
   * @brief Important!!
   */
  void compress();

  template <typename VECTOR>
  void vmult(VECTOR&, const VECTOR&) const;

  template <typename stream>
  void print(stream&, const unsigned int) const;

  size_type nonzero_elements() const;

  bool has_compressed() const;

private:
  T* val;
  size_type max_per_row, n_col, n_row;
  size_type * col_ind;
  size_type * row_ind;
  bool is_compressed;

};

class SolverBase{
public:
  //...
private:
  double tol;
  unsigned int max_step;
  std::vector<double> history;
  //...
};


template <typename VECTOR>
class KrylovBase{
public:
  typedef unsigned int size_type;
  typedef VECTOR value_type;

  //...

  virtual void vmult(VECTOR&, const VECTOR&);

  virtual void itertor_onestep();

  virtual void run();


private:
  SolverBase * base;
  VECTOR initial_value, rhs;
};

template <typename MATRIX, typename VECTOR>
class CGSolver : public KrylovBase<VECTOR>{
  //...

private:
  const MATRIX * matrix;
};

#endif
