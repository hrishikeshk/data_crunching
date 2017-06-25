#ifndef POINT2D
#define POINT2D

#include <math.h>
#include "Common_Funcs.h"

#include "Clustering_Funcs.h"

struct Point2D{
  using DistType = double;
  //const DistType min = 0.0;

  DistType x;
  DistType y;
  Point2D(DistType a, DistType b): x(a), y(b){
  }
};

template <>
inline Point2D::DistType distance(const Point2D& p1, const Point2D& p2){
  return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

#endif

