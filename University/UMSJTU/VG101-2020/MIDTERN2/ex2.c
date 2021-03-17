#include "assignment.h"
#include <stdio.h>
// ex. 2 function: disptach work to other functions for exercise 2
void check(int x, int *flag);
void print_10(int x);
void print_1(int x);
void ex2()
{
    int n;
    int flag = 1;
    printf("Input an integer: ");
    scanf("%d", &n);
    printf("%d: ", n);
    check(n, &flag);
    return;
}
void check(int x, int *flag)
{
    if (x >= 1000)
    {
        check(x / 1000, flag);
        if ((*flag) == 0)
            printf(" ");
        printf("thousand");
        *flag = 0;
        x = x % 1000;
    }
    if (x >= 100)
    {
        if ((*flag) == 0)
            printf(" ");
        print_1(x / 100);
        *flag = 0;
        printf(" ");
        printf("hundred");
        x = x % 100;
        if (x>0) printf(" and");
    }
    if (x >= 20)
    {
        if ((*flag) == 0)
            printf(" ");
        print_10(x / 10);
        *flag = 0;
        x = x % 10;
    }
    if (x >= 10 && x < 20)
    {
        if ((*flag) == 0)
            printf(" ");
        *flag = 0;
        if (x == 10)
            printf("ten");
        if (x == 11)
            printf("eleven");
        if (x == 12)
            printf("twelve");
        if (x == 13)
            printf("thirteen");
        if (x == 14)
            printf("fourteen");
        if (x == 15)
            printf("fifteen");
        if (x == 16)
            printf("sixteen");
        if (x == 17)
            printf("seventeen");
        if (x == 18)
            printf("eighteen");
        if (x == 19)
            printf("nineteen");
        return;
    }
    if (x >= 1)
    {
        if ((*flag) == 0)
            printf(" ");
        print_1(x);
        *flag = 0;
    }
    return;
}
void print_1(int x)
{
    if (x == 1)
        printf("one");
    if (x == 2)
        printf("two");
    if (x == 3)
        printf("three");
    if (x == 4)
        printf("four");
    if (x == 5)
        printf("five");
    if (x == 6)
        printf("six");
    if (x == 7)
        printf("seven");
    if (x == 8)
        printf("eight");
    if (x == 9)
        printf("nine");
    return;
}
void print_10(int x)
{
    if (x == 2)
        printf("twenty");
    if (x == 3)
        printf("thirty");
    if (x == 4)
        printf("forty");
    if (x == 5)
        printf("fifty");
    if (x == 6)
        printf("sixty");
    if (x == 7)
        printf("seventy");
    if (x == 8)
        printf("eighty");
    if (x == 9)
        printf("ninety");
    return;
}
#ifdef JOJ
int main()
{
    ex2();
    return 0;
}
#endif
