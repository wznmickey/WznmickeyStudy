#include "assignment.h"
long int mpow (int a, int b);
int quo (int a, int b) ;
int sum (int a, int b) ;
int prod (int a, int b);
int rem (int a, int b);
void ex5()
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d",&a, &b);
    printf("Quotient: %d\n",quo(a,b));
    printf("Remainder: %d\n",rem(a,b));
    printf("Sum: %d\n",sum(a,b));
    printf("Product: %d\n",prod(a,b));
    printf("Exponent: %ld\n",mpow(a,b));
    return;
}
#ifdef JOJ
int main(){
    ex5();
    return 0;
}
#endif