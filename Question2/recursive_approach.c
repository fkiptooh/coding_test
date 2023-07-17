#include <stdio.h>

int fibRecursive(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return fibRecursive(n - 3) + fibRecursive(n - 2);
}

int main()
{
    int n = 10;
    int result = fibRecursive(n);
    printf("F(%d) = %d\n", n, result);
    return 0;
}
