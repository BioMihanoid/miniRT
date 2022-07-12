#include "../../includes/minirt.h"

void	handler_key_events(int key_code)
{
	printf ("%d", key_code);
	if (key_code == KEY_ESC)
	{
		printf("You enter the ESC key. Program exit!\n");
		exit (0);
	}
}