#include "../../includes/minirt.h"

void	ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int 		mlx_y;
	float		x_angle;
	float		y_angle;
	int 		color;
	float 		y_ray;
	float 		x_ray;
	t_vector	*ray;
	t_vplane	*vplane;

	vplane = get_view_plane(scene->width, scene->width, scene->cams->fov);
	mlx_y = 0;
	y_angle = scene->hight / 2;
	while(y_angle >= (scene->hight / 2 * (-1)))
	{
		y_ray = y_angle * vplane->y_px;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_px;
			ray = new_vector(x_ray, y_ray, -1);
			vec_normalize(ray);
			if (sphere_intersect(scene->cams, ray, scene->sphere))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

t_vplane	*get_view_plane(float width, float hight, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	fov = 1;
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		error_exit(-1);
	aspect_ratio = width / hight;
	vplane->width = 1;
	vplane->hight = vplane->width / aspect_ratio;
	vplane->x_px = vplane->width / width;
	vplane->y_px = vplane->hight / hight;
	return (vplane);
}