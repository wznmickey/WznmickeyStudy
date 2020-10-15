#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
struct ComplexNum
{
	long long a,b;
};
void clear(char *number,int *num);
struct ComplexNum plus(struct ComplexNum num1,struct ComplexNum num2);
struct ComplexNum times(struct ComplexNum num1,struct ComplexNum num2);
void print(struct ComplexNum ans);
int main()
{
	char temp;
	char number[1000];
	struct ComplexNum complex[10];
	struct ComplexNum ans;
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
					complex[complex_num].a=atof(number);				
					memset(number,'\0',sizeof(number));
					now_index=0;
					number[now_index]=temp;
					now_index++;
				}
			}
			if (temp=='i')
			{
				complex[complex_num].b=atof(number);
				memset(number,'\0',sizeof(number));
				now_index=0;
				complex_num++;
			}
		}
		else
		{
			if (temp=='+') 
			{
				ans=plus(complex[0],complex[1]);print(ans);
				return 0;
			}
			if (temp=='*') 
			{
				ans=times(complex[0],complex[1]);print(ans);
				return 0;
			}	
		}	
	}
	return 0;
}
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
