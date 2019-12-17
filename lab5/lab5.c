#include <stdio.h>
/* Function void rstrip(char s[])modifies the string s: if at the end of the string s there are one or more spaces,then remove these from the string.The name rstrip stands for Right STRIP, trying to indicate that spaces at the 'right'end of the string should be removed.*/
void lstrip(char s[]);

int main(void) 
{
	char test1[] = "    Hello World";
	char test2[] = " Hello world this is a test";
	printf("Original string reads  : |%s|\n", test1);
	lstrip(test1);
	printf("l-stripped string reads: |%s|\n", test1);
	printf("|%s|\n", test2);
	lstrip(test2);
	printf("|%s|\n", test2);
	return 0;
}


void lstrip(char s[])
{
	int i,nw,j;
	i=nw=j=0;
	while(s[i] != '\0')
	{
		i++;
	}

	while(s[nw] == ' ')
	{
		nw++;
	}

	i -=1;
	while(j<=i-nw)
	{
		s[j] = s[j+nw];
		j++;
	}
	s[j] = '\0';
}
