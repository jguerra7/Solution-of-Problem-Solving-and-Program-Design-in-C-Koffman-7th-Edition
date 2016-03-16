#include<stdio.h>
#include<math.h>
void drag_force(double *f,double CD, double A, double P, double V)
{
	*f=0.5*(CD * A * P * pow(V,2));
}
int main()
{
	double f, CD, A, P = 1.23, V;
	printf("Enter CD AND A\n");
	scanf("%lf%lf",&CD,&A);
	printf("Velocity%10cDrag_Force\n",' ');
	for(V=0;V<=40;V=V+5)
	{
		drag_force(&f,CD,A,P,V);
		printf("%4.0lf%20.2lf\n",V,f);
	}
	
	
	return 0;
}
