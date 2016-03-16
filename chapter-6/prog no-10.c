#include<stdio.h>
#include<math.h>
void scan_data(char *optr,double *r_oprnd)
{
	printf("Enter operator and right operand => ");
	scanf("\n%c",&*optr);
	scanf("%lf",&*r_oprnd);
}
void do_next_op(char optr,double r_oprnd,double *accum)
{
	switch(optr)
	{
		case '+':
			{
				*accum+=r_oprnd;
				break;
			}
		case '-':
			{
				*accum-=r_oprnd;
				break;
			}
		case '*':
			{
				*accum*=r_oprnd;
				break;
			}
		case '/':
			{
				if(r_oprnd!=0)
				*accum/=r_oprnd;
				else
				printf("Divide by zero not defined\n");
				break;
			}
		case '^':
			{
				*accum=pow(*accum,r_oprnd);
				break;
			}
		default:
			printf("invalid operator\n");
	}
	
}
	

int main()
{
	double accum=0,r_oprnd;
	char optr;
	scan_data(&optr,&r_oprnd);
	while(optr!='q')
	{
	do_next_op(optr,r_oprnd,&accum);
	printf("Result so far is %lf\n",accum);
	scan_data(&optr,&r_oprnd);
	}
	printf("Result so far is %lf\n",accum);
	return 0;
}
