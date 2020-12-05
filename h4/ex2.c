#include "assignment.h"
void swap(long long *a,long long *b)
{
	long long temp=*a;
	*a=*b;
	*b=temp;
	return;
}
long long gcd(long long a,long long b)
{
	if (a<b) swap (&a,&b);
	if (a!=b) return gcd(a-b,b);
	else return a;
}
void ex2() 
{
    long long a,b;
	short get_ans;
	get_ans=scanf("%lld%lld",&a,&b);
	if (get_ans!=0) printf("%lld",gcd(a,b));
	return;
}
#ifdef JOJ
int main()
{
    ex2();
    return 0;
}
#endif
