#include <stdio.h>

int fibIterative(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int a, b, c, i;
    a = 0;
    b = 1;
    c = 2;

    for (i = 3; i < n; i++)
    {
        /* code */
        int temp = c;
        c = c + b;
        b = a;
        a = temp;
    }

    return c;
}

int main()
{
    int n = 0;
    int finalResult = fibIterative(n);
    printf("F(%d) =  %d\n", n, finalResult);
    return 0;
}