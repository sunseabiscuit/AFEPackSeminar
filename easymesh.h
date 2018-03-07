/**
 * @file easymesh.h
 * @brief 
 * @author 
 * @version 
 * @date 2018-03-05
 */


#ifndef __EASYMESH_H_
#define __EASYMESH_H_

#include "point.h"
#include <string>

class Line;
class Triangle;
class EasyMesh;

/**
 * @brief To represent a line in 2D space.
 */
class Line{
public:
  typedef EasyMesh mesh_t;
  typedef Point<2> point_t;

  Line();
  Line(const Line&);
  Line& operator = (const Line&);
  virtual ~Line();

  Line(point_t&, point_t&);
  //What happen if we add const before point_t?
  //Line(const point_t&, const point_t&);

  void reinit(point_t&, point_t&);

  point_t& point(unsigned int) const;

  double length() const;

  point_t barycenter() const;

protected:
  point_t * p0, p1;
};

class Triangle{
public:
  typedef Line line_t;
  typedef line_t::point_t point_t;
  typedef EasyMesh mesh_t;

  Triangle();
  Triangle(const Triangle&);
  Triangle& operator = (const Triangle&);
  virtual ~Triangle();

  Triangle(point_t&, point_t&, point_t&);
  
  void reinit(point_t&, point_t&, point_t&);

  point_t& point(unsigned int) const;

  line_t line(unsigned int) const;

  double area() const;

  double width() const;

  std::vector<double> unit_normal(unsigned int) const;

protected:
  point_t * p0, p1, p2;
};

class EasyMesh{
  class Face : public Line {
    typedef Line Base;
    unsigned int ind;
    std::vector<unsigned int> point_ind;
    std::vector<unsigned int> neigh;
  public:
    void reinit(mesh_t&);
  private:
    mesh_t * mesh;
  };

  class Element : public Triangle {
    typedef Triangle Base;
    unsigned int ind;
    std::vector<unsigned int> point_ind;
    std::vector<unsigned int> line_ind;
    std::vector<unsigned int> neigh;
  public:
    void reinit(mesh_t&);
  private:
    mesh_t * mesh;
  };

public:
  typedef Point<2> point_t;
  typedef Face face_t;
  typedef Element ele_t;

  // ... 

  void read_mesh(const std::string&);

  int n_point() const;
  int& n_point();

  point_t& point(unsigned int);
  const point_t& point(unsigned int) const;

  // ...

private:
  std::vector<point_t> point_cache;
  std::vector<Face> face_cache;
  std::vector<Element> element_cache;

};


#endif
