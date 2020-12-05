#include "assignment.h"
struct ComplexNum plus(struct ComplexNum num1,struct ComplexNum num2)
{
	struct ComplexNum ans;
	ans.a=num1.a+num2.a;
	ans.b=num1.b+num2.b;
	return ans;
}
struct ComplexNum times(struct ComplexNum num1,struct ComplexNum num2)
{
	struct ComplexNum ans;
	ans.a=num1.a*num2.a-num1.b*num2.b;
	ans.b=num1.b*num2.a+num1.a*num2.b;
	return ans;
}
void print(struct ComplexNum ans)
{
	printf("%lld",ans.a);
	if (ans.b>=0) printf("+");
	printf("%lldi",ans.b);
	return;
}
struct ComplexNum init()
{
	struct ComplexNum ans;
	ans.a=0;
	ans.b=0;
	return ans;
}
void ex1() 
{
	char temp;
	char number[1050];
	struct ComplexNum complex[15];
	struct ComplexNum ans;
	int i=0;
	for (i=0;i<=9;i++)
	{
		complex[i]=init();
	}
	int now_index=0;
	int complex_num=0;
	while (scanf("%c",&temp))
	{
		if (complex_num<=1)
		{
			if ((temp>='0' && temp<='9' ))
			{
				number[now_index]=temp;
				now_index++;
			}
			if (temp=='+' || temp=='-')
			{
				if (now_index==0)
				{
					number[now_index]=temp;
					now_index++;
				}
				else 
				{
					complex[complex_num].a=atol(number);			
					memset(number,'\0',1000);
					now_index=0;
					number[now_index]=temp;
					now_index++;
				}
			}
			if (temp=='i')
			{
				complex[complex_num].b=atol(number);
				memset(number,'\0',1000);
				now_index=0;
				complex_num++;
			}
		}
		else
		{
			if (temp=='+') 
			{
				ans=plus(complex[0],complex[1]);
				print(ans);
				return;
			}
			if (temp=='*') 
			{
				ans=times(complex[0],complex[1]);
				print(ans);
				return;
			}	
		}	
	}
	return;
}
#ifdef JOJ
int main()
{
    ex1();
    return 0;
}
#endif