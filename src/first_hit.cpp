#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Loop over all objects in the scene, call their intersect method, and
  // find the closest intersection.
  for (int i = 0; i < objects.size(); i++) {
    double t_obj;
    Eigen::Vector3d n_obj;
    if (objects[i]->intersect(ray, min_t, t_obj, n_obj)) {
      if (t_obj < t) {
        t = t_obj;
        n = n_obj;
        hit_id = i;
      }
    }
  }
  
  ////////////////////////////////////////////////////////////////////////////
}

