#include "assignment.h"
void call_f1()
{
	printf("YOU CHOOSE ONE.\n");
	printf("PLEASE INPUT A LETTER.");
	char ans;
	short get_ans=0;
	while (get_ans==0||ans=='\n') get_ans=scanf("%c",&ans);
	if (get_ans!=0)
	{
		if (ans>='A' && ans<='Z') ans=ans-'A'+'a';
		if (ans=='a'||ans=='e'||ans=='i'||ans=='o'||ans=='u')
		{
			printf("vowel\n");
		} 
		else
		{
			printf("consonant\n");
		}
	}
	return;
}
void call_f2()
{
	double ans1;
	char ans2;
	short get_ans;
	get_ans=scanf("%lf%c",&ans1,&ans2);
	if (get_ans!=0)
	{
		if (ans2=='B') ans1*=8;
		if (fabs(ans1-8)<=0.001) printf("char\nunsigned char"); 
		if (fabs(ans1-16)<=0.001) printf("short\nunsigned short");
		if (fabs(ans1-32)<=0.001) printf("int\nunsigned int\nfloat");
		if (fabs(ans1-64)<=0.001) printf("double");
	}
	return;
}
void ex4() 
{
    short get_ans=0;
	char ans;
	while (get_ans==0) 
	{ 
		printf("NOW YOU HAVE 2 CHOICE:\n1.check whether the given letter is a vowel or a consonant\n2.find data types stored in given size\n(1/2)");
		get_ans=scanf("%c",&ans);
	} 
	
	if (ans=='1') call_f1();
	if (ans=='2') call_f2(); 
	return;
}
#ifdef JOJ
int main()
{
    ex4();
    return 0;
}
#endif
