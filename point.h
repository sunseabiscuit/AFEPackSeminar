/**
 * @file point.h
 * @brief 
 * @author Yang Fanyi <yfy__92@126.com>
 * @version 1.01
 * @date 2018-03-04
 */
#ifndef __POINT_H_
#define __POINT_H_

#include <vector>
#include <cmath>
#include "exception.h"

template <int D, typename T> class Point;
/**
 * @brief Get a midpoint between two points
 */
template <int D, typename T> Point<D, T>
midpoint(const Point<D, T>&, const Point<D, T>&);

/**
 * @brief Get the distance between two points
 */
template <int D, typename T> double
distance(const Point<D, T>&, const Point<D, T>&);

/**
 * @brief Get the barycenter from a series of points stores 
 * in a std::vector.
 */
template <int D, typename T> Point<D, T>
barycenter(const std::vector<Point<D, T>>&);

/**
 * @brief Add two points.
 */
template <int D, typename T> Point<D, T>
operator + (const Point<D, T>&, const Point<D, T>&);

/**
 * @brief Subtract two points.
 */
template <int D, typename T> Point<D, T>
operator - (const Point<D, T>&, const Point<D, T>&);


/**
 * @brief Get the inner product of two points.
 */
template <int D, typename T> double
operator * (const Point<D, T>&, const Point<D, T>&);

/**
 * @brief The steam operator.
 */
template <int D, typename T, typename stream> stream&
operator << (stream&, const Point<D, T>&);

template <int D, typename T = double>
class Point{
public:
  enum {DIM = D};
  /**
   * @brief Standard constructor.
   */
  Point();
  /**
   * @brief Copy constructor.
   */
  Point(const Point<D, T>&);
  /**
   * @brief Equal another point.
   */
  Point& operator = (const Point<D, T>&);
  /**
   * @brief Initialize all entries to t.
   */
  explicit Point(const T t);
  Point(const T, const T);
  Point(const T, const T, const T);

  /**
   * @brief return a unit vector in coordinate 
   * direction i.
   */
  static Point<D, T> unit_normal(unsigned int i);

  /**
   * @brief Access operator.
   */
  T& operator[](unsigned int);
  const T& operator[](unsigned int) const;
  T& operator()(unsigned int);
  const T& operator()(unsigned int) const;

  /**
   * @brief Add anothor point.
   */
  Point& operator += (const Point<D, T>&);
  /**
   * @brief Subtract anothor point.
   */
  Point& operator -= (const Point<D, T>&);
  /**
   * @brief Multiply a factor.
   */
  Point& operator *= (const double);
  /**
   * @brief Divide by a factor.
   */
  Point& operator /= (const double);

  /**
   * @brief Get the l2 norm.
   */
  double length() const;

  friend Point<D, T> midpoint<>(const Point<D, T>&, const Point<D, T>&);
  friend double distance<>(const Point<D, T>&, const Point<D, T>&);
  friend Point<D, T> barycenter<>(const std::vector<Point<D, T>>&);
  friend Point<D, T> operator + <>(const Point<D, T>&, const Point<D, T>&);
  friend Point<D, T> operator - <>(const Point<D, T>&, const Point<D, T>&);
  friend double operator * <>(const Point<D, T>&, const Point<D, T>&);
  template <int D2, typename T2, typename stream> friend
  stream& operator << (stream&, const Point<D2, T2>&);

private:
  T v[D]{0};
};


template <int D, typename T>
Point<D, T>::Point(){}

template <int D, typename T>
Point<D, T>::Point(const Point<D, T>& p){
  for(int i = 0; i < D; ++i)
    v[i] = p.v[i];
}

template <int D, typename T>
Point<D, T>&
Point<D, T>::operator = (const Point<D, T>& p){
  for(int i = 0; i < D; ++i)
    v[i] = p.v[i];
}


template <int D, typename T>
Point<D, T>::Point(const T t){
  for(int i = 0; i < D; ++i)
    v[i] = t;
}

template <int D, typename T>
Point<D, T>::Point(const T v0, const T v1){
  static_assert(D >= 2, "the dimension must be greater than 2");
  v[0] = v0;
  v[1] = v1;
}

template <int D, typename T>
Point<D, T>::Point(const T v0, const T v1, const T v2){
  static_assert(D >= 3, "the dimension must be greater than 3");
  v[0] = v0;
  v[1] = v1;
  v[2] = v2;
}

template <int D, typename T>
inline Point<D, T>
Point<D, T>::unit_normal(unsigned int i){
  Assert(i < D, "the index must be smaller than DIM");
  Point<D, T> p;
  p.v[i] = 1.;
  return p;
}

template <int D, typename T>
inline T& 
Point<D, T>::operator[](unsigned int i){
  Assert(i < D, "the index must be smaller than DIM");
  return v[i];
}

template <int D, typename T>
inline const T& 
Point<D, T>::operator[](unsigned int i) const {
  Assert(i < D, "the index must be smaller than DIM");
  return v[i];
}

template <int D, typename T>
inline T& 
Point<D, T>::operator()(unsigned int i){
  Assert(i < D, "the index must be smaller than DIM");
  return v[i];
}

template <int D, typename T>
inline const T& 
Point<D, T>::operator()(unsigned int i) const {
  Assert(i < D, "the index must be smaller than DIM");
  return v[i];
}

template <int D, typename T>
inline Point<D, T>&
Point<D, T>::operator += (const Point<D, T>& p){
  for(int i = 0; i < D; ++i)
    v[i] += p.v[i];
  return *this;
}

template <int D, typename T>
inline Point<D, T>&
Point<D, T>::operator -= (const Point<D, T>& p){
  for(int i = 0; i < D; ++i)
    v[i] += p.v[i];
  return *this;
}

template <int D, typename T>
inline Point<D, T>&
Point<D, T>::operator *= (const double t){
  for(int i = 0; i < D; ++i)
    v[i] *= t;
  return *this;
}

template <int D, typename T>
inline Point<D, T>&
Point<D, T>::operator /= (const double t){
  Assert(t != 0, "the dominator should be nonzero");
  double f = 1./t;
  return (this->operator*=(f));
}

template <int D, typename T>
inline double
Point<D, T>::length() const{
  double val = 0.;
  for(int i = 0; i < D; ++i)
    val += v[i]*v[i];
  return sqrt(val);
}

template <int D, typename T>
Point<D, T>
midpoint(const Point<D, T>& p0, const Point<D, T>& p1){
  Point<D, T> p(p0);
  return ((p += p1)*=0.5);
}

template <int D, typename T>
double
distance(const Point<D, T>& p0, const Point<D, T>& p1){
  double val = 0.;
  for(int i = 0; i < D; ++i)
    val += (p0[i] - p1[i])*(p0[i] - p1[i]);
  return sqrt(val);
}

template <int D, typename T>
Point<D, T>
operator + (const Point<D, T>& p0, const Point<D, T>& p1){
  Point<D, T> p(p0);
  return (p += p1);
}

template <int D, typename T>
Point<D, T>
operator - (const Point<D, T>& p0, const Point<D, T>& p1){
  Point<D, T> p(p0);
  return (p -= p1);
}

template <int D, typename T>
double
operator * (const Point<D, T>& p0, const Point<D, T>& p1){
  double val = 0.;
  for(int i = 0; i < D; ++i)
    val += p0[i]*p1[i];
  return val;
}

template <int D, typename T, typename stream> 
stream&
operator << (stream& os, const Point<D, T>& p){
  for(int i = 0; i < D; ++i)
    os << p.v[i] << " ";
  return os;
}

#endif

