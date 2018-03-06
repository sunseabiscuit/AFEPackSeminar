/**
 * @file quadrature.h
 * @brief 
 * @author
 * @version 
 * @date 2018-03-06
 */


#ifndef __QUADRATURE_H_
#define __QUADRATURE_H_

#include "point.h"

template <int D> class QuadratureInfo;
template <int D> class TemplateQuadrature;
template <int TD, int D> class CoordTransform;

template <int D>
class QuadratureInfo{
public:
  enum {DIM = D};
  
  //...

private:
  unsigned int acc;
  std::vector<Point<D>> point;
  std::vector<double> wei;
};

template <>
class TemplateQuadrature<1>{
public:
  typedef Point<1> point_t;
  typedef QuadratureInfo<1> quad_t;

  //...

private:
  std::vector<quad_t> quad;
  point_t p0(-1.), p1(1.);
};

template <>
class TemplateQuadrature<2>{
public:
  typedef Point<2> point_t;
  typedef QuadratureInfo<2> quad_t;

  //...

private:
  std::vector<quad_t> quad;
  point_t p0(0., 0.), p1(1., 0.), p2(0., 1.);
};

template <int TD, int D>
class CoordTransform{
public:
  enum{ TDIM = TD, DIM = D};
  typedef Point<TD> rpoint_t;
  typedef Point<D> point_t;

  point_t local_to_global(const rpoint_t&,
      const std::vector<rpoint_t>&,
      const std::vector<point_t>&) const;

  rpoint_t global_to_local(const point_t&,
      const std::vector<rpoint_t>&,
      const std::vector<point_t>&) const;

  double local_to_global_jacobian(const rpoint_t&,
      const std::vector<rpoint_t>&,
      const std::vector<point_t>&) const;

  double global_to_local_jacobian(const point_t&,
      const std::vector<rpoint_t>&,
      const std::vector<point_t>&) const;

};

#endif
