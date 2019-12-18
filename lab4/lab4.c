#include <stdio.h>
#define MAXLINE 1000 /* maximum length of string */

/* function prototype */
void reverse(char source[], char target[]);

int main(void)
{
	char original[] = "This is a test: can you print me in reverse character order?";
	char reversed[MAXLINE];
	printf("%s\n", original);
	reverse(original, reversed);
	printf("%s\n", reversed);
	return 0;
}
/* reverse the order of characters in 'source', write to 'target'.
Assume 'target' is big enough. */
void reverse(char source[], char target[])
{
	int i, nc;
	nc = i = 0;
	while (source[nc] != '\0')
	{
		nc++;
	}
	nc -= 1;
	for (i; i <= nc; i++)
	{
		target[nc - i] = source[i];
	}
	target[nc + 1] = '\0';
}

