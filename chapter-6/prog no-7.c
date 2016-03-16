#include<stdio.h>
#include<math.h>
#define diff 0.005
void square_root(double N,double LG,double *NG)
{
	double d;
	do{
	*NG=0.5*(LG+(N/LG));
	d=fabs(*NG-LG);
	LG=*NG;
	}while(d>diff);
}
int main()
{
	double n,LG=0.1,NG;
	char ask='y';
	while(ask=='y')
	{
		printf("Enter number: ");
		scanf("%lf",&n);
		square_root(n,LG,&NG);
		printf("square root:%lf\n ",NG);
		printf("Press 'y' to find more:");
		scanf("\n%c",&ask);
	}
	
	printf("");
}
