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

/*
Advantages

1. The recursive approach is often the simplest to understand and implement, as it directly follows the problem definition.
2. Recursive code can often closely resemble the problem statement or mathematical definition, making it easier to read and understand.

Disadvantage.

1. Recursive algorithms may lead to stack overflow errors for very large inputs, as each recursive call adds a new stack frame.

*/