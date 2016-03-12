#include<stdio.h>
void get_problem(int *ch)
{
printf("Select the form that you would like to convert to slope-intercept form:\n");
printf("1) Two-point form (you know two points on the line)\n");
printf("2) Point-slope form (you know the line's slope and one point)\n=>");
scanf("%d",&(*ch));
}
void get2_pt(double *x1,double *y1,double *x2,double *y2)
{
	printf("Enter the x-y coordinates of the first point separated by a space=>");
	scanf("%lf%lf",&(*x1),&(*y1));
	printf("Enter the x-y coordinates of the second point separated by a space=>");
	scanf("%lf%lf",&(*x2),&(*y2));
}
void get_pt_slope(double *m,double *x,double *y)
{
	printf("Enter the slope=>");
	scanf("%lf",&(*m));
	printf("Enter the x-y coordinates of the point separated by a space=>");
	scanf("%lf%lf",&(*x),&(*y));
}
void slope_intcpt_from2_pt(double x1,double y1,double x2,double y2,double *m,double *b)
{
	*m=(y2-y1)/(x2-x1);
	*b=-(*m*x2)+y2;
}
void intcpt_from_pt_slope(double x,double y,double m,double *b)
{
	*b=y-(m*x);
}
void display2_pt(double x1,double y1,double x2,double y2)
{
	printf("Two Point-slope form\n");
	printf("m=(%.2lf-%.2lf)/(%.2lf-%.2lf)\n",y2,y1,x2,x1);
}
void display_pt_slope(double m,double x,double y)
{
	printf("Point-slope form\n");
	printf("y-%.2lf=%.2lf(x-%.2lf)\n",y,m,x);
}
void display_slope_intcpt(double m,double c)
{
	printf("slope intercept form\n");
	printf("y=%.2lfx+%.2lf\n",m,c);
}
int main()
{
	char ch='y';
	int choice;
	while(ch=='y' || ch=='Y')
	{
	get_problem(&choice);
	switch(choice)
	{
		case 1:
			{
				double x1,y1,x2,y2,m,b;
				get2_pt(&x1,&y1,&x2,&y2);
				display2_pt(x1,y1,x2,y2);
				slope_intcpt_from2_pt(x1,y1,x2,y2,&m,&b);
				display_slope_intcpt(m,b);
				break;
			}
		case 2:
			{
				double x,y,m,b;
				get_pt_slope(&m,&x,&y);
				display_pt_slope(m,x,y);
				intcpt_from_pt_slope(x,y,m,&b);
				display_slope_intcpt(m,b);
				break;
			}
		default:
		printf("wrong choice\n");		
	}
	printf("Do another conversion (Y or N)=>");
	scanf("\n%c",&ch);	
	}	
	return 0;
}
