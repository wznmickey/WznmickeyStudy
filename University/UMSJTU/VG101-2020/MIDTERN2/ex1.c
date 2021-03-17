#include "assignment.h"
#include <stdio.h>
typedef struct node
{
    int a, x;
} node_t;
typedef struct poly
{
    int n;
    node_t *x;
} po;
// ex. 1 function: disptach work to other functions for exercise 1
void ex1()
{
    return;
}
po *trans(po *a) //a is sparse
{
    int x1 = a->n;
    int maxx = 0;
    node_t *temp1 = a->x;
    for (int i = 0; i < x1; i++)
    {
        maxx = max(maxx, temp1->x);
        if (i < x1 - 1)
            temp1++;
    }
    po *b = (po *)calloc(1, sizeof(po));
    node_t *temp2 = (node_t *)calloc((size_t)maxx + 1, sizeof(node_t));
    b->n = maxx + 1;
    b->x = temp2;
    int *x = (int *)calloc((size_t)maxx + 1, sizeof(int));
    temp1 = a->x;
    for (int i = 0; i < x1; i++)
    {
        temp2->a = temp1->a;
        temp2->x = temp2->x;
        temp2++;
        x[temp2->x] = 1;
        if (i < x1 - 1)
            temp1++;
    }
    for (int i = 0; i <= maxx; i++)
    {
        if (x[i] == 0)
        {
            temp2->a = 0;
            temp2->x = i;
            temp2++;
        }
    }
    free(x);
    return b;
}
#ifdef JOJ
int main()
{
    ex1();
    return 0;
}
#endif
