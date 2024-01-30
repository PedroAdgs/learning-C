#include <stdio.h>

void swap(int* a, int* b);

int main(int argc, char const *argv[])
{
    int a = 3, b = 9;
    swap(&a, &b);
    printf("a: %d\nb: %d", a, b);
    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}