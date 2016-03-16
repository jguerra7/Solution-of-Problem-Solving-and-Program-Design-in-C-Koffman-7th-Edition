#include<stdio.h>
#include<math.h>
void round_3(double *val)
{
	*val=(int)(*val*1000+0.5)/1000.0;
}
void revenue(double *R,int t)
{
*R=203.265*pow(1.071,t);
round_3(R);
}
void predict(double amt,double R,int *t)
{
	while(R<amt)
	{
		revenue(&R,*t);
		*t=*t+1;
	}
	*t=*t-1;
}
int main()
{
	
	int t1,i;
	double R=0.0;
	FILE *out=fopen("revenue.txt","w");
	predict(1000,R,&t1);	
	fprintf(out,"Year%5cRevenue(in $millions)\n",' ');
	for(i=0;i<t1;i++)
	{
		revenue(&R,i);
		fprintf(out,"%d%5c%lf\n",1984+i,' ',R);
	}
	fclose(out);
	return 0;
}
