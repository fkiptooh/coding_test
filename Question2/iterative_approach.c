#include <stdio.h>

int fibIterative(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int a, b, c;
    a = 0;
    b = 1;
    c = 2;

    for (int i = 3; i <= n; i++)
    {
        int next = a + b;
        a = b;
        b = c;
        c = next;
    }

    return c;
}

int main()
{
    int n = 10;
    int result = fibIterative(n);
    printf("F(%d) = %d\n", n, result);
    return 0;
}
