#include<stdio.h>
#include<math.h>
void check1(double a,double b);
void check2(double a,double b,double c);
int main()
{
	double a,b,c;
	short get_num;
	get_num=scanf("%lf%lf%lf",&a,&b,&c);
	if (get_num!=0) check2(a,b,c);
	return 0;
}
void check2(double a,double b,double c)
{
	if (fabs(a)<=0.000001) check1(b,c);
	else {
		double delta=b*b-4*a*c;
		if (fabs(delta)<=0.000001)
		{
			double ans=-b/a/2;
			printf("%.5lf",ans);
		}
		else
		{
			if (delta<0)
			{
				double real=-b/2/a;
				double imaginary=fabs(sqrt(-delta)/2/a);
				printf("%.5lf-%.5lfi\n",real,imaginary);
				printf("%.5lf+%.5lfi",real,imaginary);
			}
			if (delta>0)
			{
				double ans1=(-b-sqrt(delta))/2/a;
				double ans2=(-b+sqrt(delta))/2/a;
				printf("%.5lf\n%.5lf",ans1,ans2);
			}
		}
	}
	return;
}
void check1(double a,double b)
{
	if (fabs(a)<=0.000001)
	{
		if (fabs(b)<=0.000001)
		{
			printf("ALL");
		}
		else
		{
			printf("NONE");
		}
	}
	else 
	{
		double ans;
		ans=-b/a;
		printf("%.5lf",ans);
	}
	return;
}
