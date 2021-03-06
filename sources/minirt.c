#include "../includes/minirt.h"

void	program_exit(void)
{
	printf("Program exit!\n");
	exit (0);
}

// перетащил размеры окна в minirt.h (они статичны)

int main(void)
{
    void	*mlx;
	void	*window;

	mlx = mlx_init();
	t_vector	*sphere_center = new_vector(3, 2, -32);
	t_sphere	*sphere = new_sphere(sphere_center, 12 / 2);
	t_vector	*cam_origin = new_vector(0, 0, 0);
	t_vector	*cam_direction = new_vector(0, 0, -1);
	t_camera	*cam = new_cam(cam_origin, cam_direction, 70);
	t_scene		*scene = new_scene(cam, sphere);
	window = mlx_new_window(mlx, scene->width,scene->hight, "miniRT");
    ray_tracing(mlx, window, scene);
	//free scene(scene);
	//TODO do handler ESC key, i stupid
	//mlx_hook(window, KEY_ESC, 0,  (int (*)()) & program_exit, NULL);
	mlx_hook(window, KEY_EXIT, 0, (int (*)()) & program_exit, NULL);
	mlx_loop(mlx);
	return (0);
}
