#include<stdio.h>
#include<math.h>
void round_money(double *val)
{
	*val =((int)(*val * 100 + .5) / 100.0);
}
void chargers(double h,double *charge,double *avg)
{
	if(h<=10)
	*charge=7.99;
	else
	{
		double h1=ceil(h);
		*charge=7.99+(1.99*(h1-10));
	}
	*avg=*charge/h;
	round_money(charge);
	round_money(avg);
	
}

int main()
{
	double d,yr,h,charge,avg;
	int id;
	
	FILE *inp=fopen("usage.txt","r");
	FILE *out=fopen("chargers.txt","w");
	
	fscanf(inp,"%d%d",&d,&yr);
	fprintf(out,"Charges for %d/%d\n",d,yr);
	 fprintf(out,"customers   Hours used   Charge per hour   Avg. cost\n");
	while(fscanf(inp,"%d",&id)!=EOF)
	{
		fscanf(inp,"%lf",&h);
		fprintf(out,"%d%15.2lf",id,h);
		chargers(h,&charge,&avg);
		fprintf(out,"%15.2lf%15.2lf\n",charge,avg);
	}
	
	fclose(inp);
	fclose(out);
	return 0;
}
