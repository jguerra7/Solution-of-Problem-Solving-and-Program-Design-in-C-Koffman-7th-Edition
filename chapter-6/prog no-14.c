#include<stdio.h>
#include<math.h>
void efunc(int x,double *app_val)
{
	double t=((2.0*x)+1)/((2.0*x)-1.0);
	*app_val=pow(t,x);
}
int main()
{
int x=1;
double cal_val,app_val,diff=1;
cal_val=exp(1);
while(diff>0.000001)
{
	efunc(x,&app_val);
	printf("x value = %d\n",x);
	printf("final approx=> %10.7lf\n",app_val);
	printf("library value=> %10.7lf\n",cal_val);
	diff=fabs(cal_val-app_val);
	x=x+1;
}

	
}
