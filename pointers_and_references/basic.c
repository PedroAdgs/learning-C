#include <stdio.h>

int main(int argc, char const *argv[])
{
    int y, x, *ip;

    y = 8; 
    x = 90;

    ip = &y;
    printf("valor apontado por ptr: %d\n", *ip);
    ip = &x;
    printf("valor apontado por ptr agora: %d\n", *ip);
    return 0;
}
