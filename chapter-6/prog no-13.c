#include<stdio.h>  //IN OUTPUT ADD SPACE AT END TO STOP
#include<ctype.h>
int start=1,current_state=2,build_id=3,build_num=4,identifier=5,number=6,stop=7;
int transition(int current_state,char transition_char)
{
	int next_state;
	if(current_state==start)
	{
		if(isdigit(transition_char))
		next_state=build_num;
		else if(isalpha(transition_char))
		next_state=build_id;
		else if(transition_char==' ')
		next_state=start;
		else
		next_state=stop;
	}
	else if(current_state==build_num)
	{
		if(transition_char==' ')
		next_state=number;
	}
	else if(current_state==build_id)
	{
		if(transition_char==' ')
		next_state=identifier;
	}
	
	return next_state;
}
int main()
{
int	current_state = start;
char transition_char;
do {
if (current_state == identifier) {
printf(" - Identifier\n");
current_state = start;
} else if (current_state == number) {
printf(" - Number\n");
current_state = start;
}
scanf("%c", &transition_char);
if (transition_char != ' ')
printf("%c", transition_char);
current_state = transition(current_state, transition_char);
} while (current_state != stop);
}

