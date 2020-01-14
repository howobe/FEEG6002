#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


int read_file(char *s, int *m);
int checknumlines(char *s);
int tabulatefunc(int *m, double *x, double *y);
int write_file(char *s, double *x, double *y, int n, char *sep);

int main(void)
{
	double *x, *y;
	char *s_in = "readfrom.txt", *s_out = "writeto.txt", *sep = ",";
	int *m, n;
	
	n = checknumlines(s_in);
	
	x = (double *) malloc(n*sizeof(double));
	y = (double *) malloc(n*sizeof(double));
	m = (int *) malloc(n*sizeof(int));

	read_file(s_in, m);

	tabulatefunc(m, x, y);

	write_file(s_out, x, y, m[3], sep);
	
	return 0;
}

int checknumlines(char *s)
/*Checks number of lines = 1; returns number of segments defined in input file*/
{
	FILE *fr;
	int xmin, xmax, num, numlines=0;
	char *func;

	func = malloc(sizeof(char)*3);
	
	if ((fr=fopen(s, "r")) == NULL)
	{
		printf("Unable to open file '%s'.\n", s);
		return -1;
	}
	
	printf("Checking number of lines in file '%s'.\n", s);	
	while ((fscanf(fr, "%s %d %d %d", func, &xmin, &xmax, &num)) == 4)
	{
		numlines++;
	}

	if (numlines>1)
	{
		printf("Too many lines.\n");
		return 1;
	}
	
	if (fclose(fr) == EOF)
	{
		printf("Unable to close file '%s'.\n", s);
		return -1;
	}
	
	return num;
}

int read_file(char *s, int *m)
{
	/*Reads input file and assigns data to array*/
	FILE *fr;
	int f;
	char *func;
	char *funcs[] = {"sin", "cos", "tan"};
	func = malloc(sizeof(char)*3);

	printf("Opening file '%s'.\n", s);
	if ((fr=fopen(s, "r")) == NULL)
	{
		printf("Unable to open file '%s'.\n", s);
		return -1;
	}
	
	printf("Reading data.\n");	  	  
	fscanf(fr, "%s %d %d %d", func, &m[1], &m[2], &m[3]);

	if (strcmp(func, funcs[0]) == 0)
	{
		f=0;
	}
	else if (strcmp(func, funcs[1]) == 0)
	{
		f=1;
	}
	else if (strcmp(func, funcs[2]) == 0)
	{
		f=2;
	}
	else
	{
		printf("Invalid function given!\n");
		return 1;
	}
	m[0] = f;
	if (fclose(fr) == EOF)
	{
		printf("Unable to close file '%s'.\n", s);
		return -1;
	}
	printf("Closing file '%s'.\n", s);
	return 0;
}



int tabulatefunc(int *m, double *x, double *y)
{
	/*Calculates chosen trig function between limits in defined segments*/
	double (*fpa[])() = {sin, cos, tan};
	char *funcs[] = {"sin", "cos", "tan"};
	int i;
	
	printf("%s selected.\nCalculating...\n", funcs[m[0]]);
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
	
	
		

