#include<stdio.h>
	void calc_h(double *H,double K,double A,double T1,double T2,double X)
	{
		*H=(K*A*(T2-T1))/X;
		printf("Rate of heat transfer is %5.0lf W\n",*H);
	}
	void calc_k(double H,double *K,double A,double T1,double T2,double X)
	{
		*K=(H*X)/(A*(T2-T1));
		printf("Coefficient of thermal conductivity is %5.0lf W/m-K\n",*K);
	}
	void calc_a(double H,double K,double *A,double T1,double T2,double X)
	{
		*A=(H*X)/(K*(T2-T1));
		printf("Cross-sectional area of conductor is %5.0lf m^2\n",*A);
	}
	void calc_t1(double H,double K,double A,double *T1,double T2,double X)
	{
		*T1=T2-(H*X)/(K*A);
		printf("Temperature on one side is %5.0lf K\n",*T1);
	}
	void calc_t2(double H,double K,double A,double T1,double *T2,double X)
	{
		*T2=T1+(H*X)/(K*A);
		printf("Temperature on other side is %5.0lf K\n",*T2);
	}
	void calc_x(double H,double K,double A,double T1,double T2,double *X)
	{
		*X=K*A*(T2-T1)/H;
		printf("Thickness of conductor is %lf m\n",*X);
	}
	void driver(double *H,double *K,double *A,double *T1,double *T2,double *X,int *comp)
	{
	printf("Respond to the prompts with the data known. For the\n");
	printf("unknown quantity, enter a question mark (?).\n");
	printf("Rate of heat transfer (watts) >> ");
	if(scanf("%lf",&*H)==0)
	{
	scanf("%c",&*H);
	*comp=1;
	}
	printf("Coefficient of thermal conductivity (W/m-K) >>");
	if(scanf("%lf",&*K)==0)
	{
	scanf("%c",&*K);
	*comp=2;
	}
	printf("Cross-sectional area of conductor (m^2) >>");
	if(scanf("%lf",&*A)==0)
	{
	scanf("%c",&*A);
	*comp=3;
	}
	printf("Temperature on one side (K) >>");
	if(scanf("%lf",&*T2)==0)
	{
	scanf("%c",&*T2);
	*comp=4;
	}
	printf("Temperature on the other side (K) >>");
	if(scanf("%lf",&*T1)==0)
	{
	scanf("%c",&*T1);
	*comp=5;
	}
	printf("Thickness of conductor (m) >>");
	if(scanf("%lf",&*X)==0)
	{
	scanf("%c",&*X);
	*comp=6;
	}
	printf("H=KA(T2-T1)/X\n");	
	}
int main()
{
	double H,K,A,T1,T2,X;
	int comp;
	driver(&H,&K,&A,&T1,&T2,&X,&comp);
	switch(comp)
	{
	case 1:
		calc_h(&H,K,A,T1,T2,X);
		break;
	case 2:
		calc_k(H,&K,A,T1,T2,X);
		break;
	case 3:
		calc_a(H,K,&A,T1,T2,X);
		break;
	case 4:
		calc_t2(H,K,A,T1,&T2,X);
		break;
	case 5:
		calc_t1(H,K,A,&T1,T2,X);
		break;
	case 6:
		calc_x(H,K,A,T1,T2,&X);
		break;
	}
	printf(" H = %lf W             T2 = %lf K\n",H,T2);
	printf(" K = %lf W/m-K         T1 = %lf K\n",K,T1);
	printf(" A = %lf m^2            X = %lf m\n",A,X);	
	return 0;
}
