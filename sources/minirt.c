#include <stdio.h>

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
        printf ("Usage: ./miniRT file.rt\n");
    return (0);
}
