#include<stdio.h>
#include<math.h>
void checksum(char ch,int *cs)
{
	if(ch!='.')
	*cs=*cs+(int)ch;
	else
	{
	*cs=*cs%64;
	*cs=*cs+(int)' ';
	}
}
int main()
{
	char ch,ch1='\0';
	int cs=0;
	scanf("%c",&ch);
	while(ch!='.' || ch1!='.')
	{
		checksum(ch,&cs);
		if(ch=='.')
		{
			printf("\n%d charcter value=%c\n",cs,(char)cs);
			cs=0;
		}
		ch1=ch;
		scanf("%c",&ch);
		
	}
	return 0;
}
