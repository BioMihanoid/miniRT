#include "../../includes/minirt.h"

void	error_exit(int code)
{
	if (code == -1)
		printf("Error: Can't allocate memory for new element\n");
	exit(code);
}

