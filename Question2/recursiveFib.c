#include <stdio.h>

int fibRecursive(int n)
{
    if (n == 1 || n == 2)
        /* code */
        return 1;
    else
        return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main()
{
    int n, result;
    printf("Enter the fibonnaci term you want to know: ");
    scanf("%d", &n);
    result = fibRecursive(n);
    printf("F(%d) = %d", n, result);
}