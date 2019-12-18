#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * mix(char *s1, char *s2);

void use_mix(void);

int main (void) {
    use_mix();
    return 0;
}

void use_mix(void) {
    char s1[] = "Hello World";
    char s2[] = "1234567890!";

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    printf("r = %s\n", mix(s1, s2));
}

char * mix(char *s1, char *s2) {
    int len, j;
    char *r;
    len = strlen(s1);
    printf("Length: %d characters\n", len);
    r = (char *) malloc(sizeof(char) * len * 2);
    if (r == NULL) {
        return NULL;
    }
    for (j = 0; j < len; j++) {
        r[j * 2] = s1[j];
        r[j * 2 + 1] = s2[j];
    }
    r[len * 2] = '\0';
    return r;
}