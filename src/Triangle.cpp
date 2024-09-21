#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Dense>

using namespace Eigen;
bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  Vector3d x1 = corners.get<0>();
  Vector3d x2 = corners.get<1>();
  Vector3d x3 = corners.get<2>();
  Vector3d t1 = x2 - x1; 
  Vector3d t2 = x3 - x1;
  
  Matrix3d A; 
  A << t1, t2, -ray.direction;
  Vector3d b(1, ray.origin - x1, 1);
  Vector3d x = A.inverse() * b;

  if (x[0] >= 0 && x[1] >= 0 && x[2] >= min_t && x[0] + x[1] <= 1) {
    t = x[2];
    n = t1.cross(t2).normalized();
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}


