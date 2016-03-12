#include <stdio.h>
void change (int amt_paid1, 
			 int amt_due1, 
			 int *dol, 
			 int *quar, 
			 int *dim, 
			 int *nick, 
			 int *pen)
{

	int temp_amt;
	temp_amt = (amt_due1 - amt_paid1);
	
	*dol =  temp_amt/100;
	*quar = (temp_amt - (*dol * 100)) / 25;
	*dim = (temp_amt - (*dol * 100) - (*quar * 25)) / 10;
	*nick = (temp_amt - (*dol * 100) - (*quar * 25) - (*dim * 10)) / 5;
	*pen =(temp_amt - (*dol * 100) - (*quar * 25) - (*dim * 10) - (*nick * 5)) / 1;
}

int main (void)
{

	int amt_paid, amt_due;
	int dollars, quarters, dimes, nickels, pennies;

	printf("Enter the amound paid in cents: ");
	scanf("%d", &amt_paid);
	printf("Enter the amound due in cents: ");
	scanf("%d", &amt_due);

	change(amt_paid, amt_due, &dollars, &quarters, &dimes, &nickels, &pennies);

	printf("Your change are: %d dollars, %d quarters, %d dimes, %d nickels, and %d pennies", 
		dollars, quarters, dimes, nickels, pennies);

	
	return (0);
}
