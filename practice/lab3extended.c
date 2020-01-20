#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define ARGS 6
#define MLEN 5


/*This script almost incooperates all aspects of FEEG6002 course. Stemming from the lab 3
excersize, this has been extended to work more dynamically. This script takes a trigonometric
function (currently limited to sin, cos and tan), (integer) limits for tabulation, number of points
over which it is calculated, and finally writes the data to a text file.

Usage:

C:\Users\user\documents\homework>lab3extended.exe sin 0 4 1000 sindata.txt

Calculating sin between 0 and 4 over 1000 segments; writing data to sindata.txt
Calculations completed.
Opening file 'sindata.txt' to write to.
Writing to file 'sindata.txt'.
Writing to file 'sindata.txt' completed.
File 'sindata.txt' closed.

C:\Users\user\documents\homework>lab3extended.exe cos 0 4 cosdata.txt

Number of segments not defined; default is 1000.
Calculating sin between 0 and 4 over 0 segments; writing data to cosdata.txt
Calculations completed.
Opening file 'cosdata.txt' to write to.
Writing to file 'cosdata.txt'.
Writing to file 'cosdata.txt' completed.
File 'cosdata.txt' closed.

C:\Users\user\documents\homework>lab3extended.exe tan 0 4 10

Output filename not given; data written to data.txt.
Calculating tan between 0 and 4 over 10 segments; writing data to data.txt
Calculations completed.
Opening file 'data.txt' to write to.
Writing to file 'data.txt'.
Writing to file 'data.txt' completed.
File 'data.txt' closed.

*/




/*Function declarations*/

int read_file(char *s, int *m);
int checknumlines(char *s);
int tabulatefunc(int *m, double *x, double *y);
int write_file(char *s, double *x, double *y, int n, char *sep);
int getfunc(char *arg);

const int defseg = 1000;

int main(int argc, char *argv[])
{
	double *x, *y;
	char *s_out = "data.txt", *sep = ",";
	int m[MLEN], i;
	

	if (argc == ARGS)
	{
		s_out = argv[ARGS-1];
	}

	else if (argc == ARGS - 1 && atoi(argv[argc-1]) == 0)
	{
		s_out = argv[argc-1];
		m[3] = defseg;
		printf("Number of segments not defined; default is %d.\n", m[3]);
	}

	else if (argc == ARGS - 1 && atoi(argv[argc-1]) != 0)
	{
		printf("Output filename not given; data written to %s.\n", s_out);
	}

	else if (argc == ARGS-2 && atoi(argv[argc-1]) != 0)
	{
		m[3] = defseg;
		printf("Neither output filename nor number of segments given; default number of segments (%d)\nand data writen to data.txt\n", m[3]);
	}

	else
	{
		printf("Incorrect number of arguments given. Please try again.\n");
		return 1;
	}

	m[0] = getfunc(argv[1]);

	for (i=2; i<MLEN; i++)
	{
		m[i-1] = atoi(argv[i]);
	}

	printf("between %d and %d over %d segments; writing data to %s\n", m[1], m[2], m[3], s_out);

	x = (double *) malloc(m[3]*sizeof(double));
	y = (double *) malloc(m[3]*sizeof(double));

	tabulatefunc(m, x, y);

	write_file(s_out, x, y, m[3], sep);
	
	return 0;
}



int getfunc(char *arg)
{
	char *funcs[] = {"sin", "cos", "tan"};
	int f;

	if (strcmp(arg, funcs[0]) == 0)
	{
		f=0;
	}
	else if (strcmp(arg, funcs[1]) == 0)
	{
		f=1;
	}
	else if (strcmp(arg, funcs[2]) == 0)
	{
		f=2;
	}
	else
	{
		printf("Invalid function given!\n");
		return 1;
	}
	printf("Calculating %s ", funcs[f]);
	return f;
}

int tabulatefunc(int *m, double *x, double *y)
{
	/*Calculates chosen trig function between limits in defined segments*/
	double (*fpa[])() = {sin, cos, tan};
	int i;
	
	for (i=0; i<m[3]; i++)
	{
		*(x+i) = m[1] + (m[2]-m[1])*(double)i/(m[3]-1);
		*(y+i) = (*fpa[m[0]])(x[i]);
	}
	printf("Calculations completed.\n");
	return 0;
	
}

int write_file(char *s, double *x, double *y, int n, char *sep)
{
	/*Writes data to file*/
	FILE *fw;
	int i;
	
	printf("Opening file '%s' to write to.\n", s);
	if ((fw=fopen(s, "w")) == NULL)
	{
		printf("Unable to open file '%s'.\n", s);
		return -1;
	}
	printf("Writing to file '%s'.\n", s);
	for (i=0; i<n; i++)
	{
		fprintf(fw, "%lf%s%lf\n", x[i], sep, y[i]);
	}
	printf("Writing to file '%s' completed.\n", s);
	
	if (fclose(fw) == EOF)
	{
		printf("Unable to close file '%s'.\n", s);
		return -1;
	}
	
	printf("File '%s' closed.\n", s);
	return 0;
}
	
	
		

