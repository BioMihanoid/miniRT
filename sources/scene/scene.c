#include "../../includes/minirt.h"

t_scene	*new_scene(t_camera *cam, t_sphere *sphere)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if(!scene)
		error_exit(-1);
	scene->sphere = sphere;
	scene->cams = cam;
	scene->hight = 0;
	scene->width = 0;
	return (scene);
}