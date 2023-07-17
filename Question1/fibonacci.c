#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag
{
    ADD,
    MUL,
    SUB,
    FIBO
} TypeTag;

typedef struct Node
{
    TypeTag type;
    union
    {
        struct
        {
            struct Node *left;
            struct Node *right;
        } binary;
        int value;
    } data;
} Node;

Node *makeFunc(TypeTag type)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->data.binary.left = NULL;
    node->data.binary.right = NULL;
    return node;
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    int *fib = (int *)malloc((n + 1) * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int result = fib[n];
    free(fib);

    return result;
}

void calc(Node *node)
{
    switch (node->type)
    {
    case ADD:
        node->data.value = node->data.binary.left->data.value +
                           node->data.binary.right->data.value;
        printf("add : %d\n", node->data.value);
        break;
    case MUL:
        node->data.value = node->data.binary.left->data.value *
                           node->data.binary.right->data.value;
        printf("mul : %d\n", node->data.value);
        break;
    case SUB:
        node->data.value = node->data.binary.right->data.value -
                           node->data.binary.left->data.value;
        printf("sub : %d\n", node->data.value);
        break;
    case FIBO:
        node->data.value = fibonacci(node->data.binary.left->data.value);
        printf("fibo : %d\n", node->data.value);
        break;
    }
}

int main()
{
    Node *add = makeFunc(ADD);
    add->data.binary.left = makeFunc(ADD);
    add->data.binary.left->data.value = 10;
    add->data.binary.right = makeFunc(ADD);
    add->data.binary.right->data.value = 6;

    Node *mul = makeFunc(MUL);
    mul->data.binary.left = makeFunc(ADD);
    mul->data.binary.left->data.value = 5;
    mul->data.binary.right = makeFunc(ADD);
    mul->data.binary.right->data.value = 4;

    Node *sub = makeFunc(SUB);
    sub->data.binary.left = mul;
    sub->data.binary.right = add;

    Node *fibo = makeFunc(FIBO);
    fibo->data.binary.left = sub;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}

/*
Dynamic programming is a technique for computing recursive algorithm with highly overlapping subproblems by only solving each subproblem once.

Dynamic programming demonstrates the usage of the code by creating Node structures for various arithmetic operations.

The arithmetic expressions are constructed by linking the nodes together.
The calc function is called on each node to perform the corresponding operation and print the result.
After the operations are performed, memory allocated for each node is freed.
*/