#include "../../includes/minirt.h"

int sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere)
{
	float		b;
	float		c;
	float		discriminant;
	float		dist_to_intersect_sphere;
	float		dist_behind_the_sphere;
	t_vector	*cam_sphere_dist;

	dist_to_intersect_sphere = 0;
	dist_behind_the_sphere = 0;
	cam_sphere_dist = vec_subtract(cam->origin, sphere->center);
	b = 2 * (vec_dot_product(cam_sphere_dist, ray));
	c = vec_dot_product(cam_sphere_dist, cam_sphere_dist) - (sphere->radius * sphere->radius);
	discriminant = (b * b) - (4 * c);
	free(cam_sphere_dist);
	if (discriminant < 0)
		return (0);
	dist_to_intersect_sphere = ((b * (-1)) - sqrt(discriminant)) / 2;
	dist_behind_the_sphere = ((b * (-1)) + sqrt(discriminant)) / 2;
	if (dist_to_intersect_sphere > 0)
		return (1);
	return (0);
}