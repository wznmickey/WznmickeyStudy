#include "assignment.h"

// ex. 3 function: disptach work to other functions for exercise 3
void ex3()
{
    int n, a, b;
    scanf("%d", &n);
    int i = 1;
    while (n > i)
    {
        n -= i;
        i++;
    }
    if (i % 2 == 0)
    {
        b = (i + 1 - n);
        a = n;
    }
    else
    {
        a = (i + 1 - n);
        b = n;
    }
    printf("%d\n-\n%d", a, b);
    return;
}

#ifdef JOJ
int main()
{
    ex3();
    return 0;
}
#endif
