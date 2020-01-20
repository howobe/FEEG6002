#include<stdio.h>

char * longest_string(char *s1, char *s2);

main()
{
	char *s1 = "Hello";
	char *s2 = "Hi";
	char *longest;
	
	longest = longest_string(s1, s2);
	printf("%s\n", longest);
	
	return 0;
}

char * longest_string(char *s1, char *s2)
{
	int len1, len2, i=0;
	
	while (s1[i++] != '\0');
	len1 = i;
	printf("s1: %d\n", len1);
	i=0;
	while (s2[i++] != '\0');
	len2 = i;
	printf("s2: %d\n", len2);
	
	if (len1>len2)
		return s1;
	else
		return s2;
}

