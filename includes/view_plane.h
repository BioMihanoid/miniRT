#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

typedef struct s_vplane
{
	float	width;
	float	hight;
	float	x_px;
	float	y_px;
}	t_vplane;

t_vplane	*get_view_plane(float width, float hight, float fov);
int sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere);
void	ray_tracing();

#endif
