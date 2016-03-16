#include<stdio.h>
void information(int n,int *mul,int *sum,int *p)
{
	int num,i,rem,c=0;
	if(n%7==0 || n%11==0 || n%13==0)
	*mul=1;
	num=n;
	while(num>0)
	{
		rem=num%10;
		*sum=*sum+rem;
		num=num/10;
	}
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			*p=*p+1;
			break;
		}
	}
}
int main()
{
	char c='y';
	while(c=='y')
	{
		int n,mul=0,sum=0,p=0;       //note-sum,p,mul should be zero before each num check
		printf("enter number to test\n");
		scanf("%d",&n);
		information(n,&mul,&sum,&p);
		if(mul==1)
		printf("value is multiple of 7, 11 or 13\n");
		else
		printf("value is not multiple of 7 & 11 & 13\n");
		if(sum%2==0)
		printf("the sum of the digits even\n");
		else
		printf("the sum of the digits odd\n");
		if(p==0)
		printf("the value is a prime number\n");
		else
		printf("the value is not a prime number\n");
		printf("enter 'y' to test more number or 'n' to exit\n");
		scanf("\n%c",&c);
	}
	
	return 0;
}
