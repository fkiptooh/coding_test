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

/*
 Advantages of Dynamic approach

 1. Dynamic programming exploits the optimal substructure property of the problem, which allows for efficient computation and storage of result.
 2. Dynamic programming can significantly improve the efficiency of computations by storing and reusing previously calculated results.

Disadvantage.

1.  Dynamic programming may require additional memory to store intermediate results, which can be a concern for problems with large inputs.
2. Dynamic programming algorithms can be more challenging to implement correctly, as they involve breaking down problems into smaller overlapping subproblems and correctly storing and retrieving results.

*/
