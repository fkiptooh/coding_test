#include <stdio.h>
#include <stdlib.h>

int fibDynamic(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    int result = dp[n];
    free(dp);
    return result;
}

int main()
{
    int n = 10;
    int result = fibDynamic(n);
    printf("F(%d) = %d\n", n, result);
    return 0;
}
