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

/*
Advantages

1. The iterative approach avoids redundant calculations and can be more efficient than the recursive approach, especially for larger inputs.
2. The iterative approach usually requires less memory compared to the recursive approach, as it doesn't involve maintaining a large stack of recursive function calls.

Disadvantages.
1. The iterative approach may require more complex code and may be harder to understand, especially for complex algorithms.
2. Iterative code can sometimes be more error-prone and harder to maintain, particularly when dealing with complex loop conditions and index management.

*/
