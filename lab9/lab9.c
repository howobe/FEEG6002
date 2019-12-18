#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793

/*
 The function number_of_lines(...) takes as input a file name
 string and reads each line using formatted input to count
 the number of lines in the file.
*/

int read_number_of_lines(char *s)
/* Function that counts the number of lines. */
{
    FILE *fr;
    double x1, x2, x3;
    int n;

    if ((fr = fopen(s, "r")) == NULL)
    {
        printf("Cannot open file 'data.in'.\n");
        return -1;
    }

    n = 0;
    while ((fscanf(fr, "%lf %lf %lf\n", &x1, &x2, &x3) == 3))
    {
        n += 1;
    }

    if ((fclose(fr) == EOF))
    {
        printf("File could not be closed.\n");
        return -1;
    }

    return n;
}

/*
 The function read_data(...) takes as input a file name
 string, a double pointer pointing to a two-dimensional
 array n x 3 elements where n is the number of lines in the
 input file, and n as integer, and reads each line using
 formatted input to count the number of lines in the file.
*/

int read_data(char *s, double **a, int n)
{
    FILE *fr;
    int i;

    if ((fr = fopen(s, "r")) == NULL)
    {
        printf("Unable to open file %s.\n", s);
        return -1;
    }

    for (i = 0; i < n; i++)
    {
        fscanf(fr, "%lf %lf %lf\n", &a[i][0], &a[i][1], &a[i][2]);
    }

    if ((fclose(fr) == EOF))
    {
        printf("Unable to close file.\n");
        return -1;
    }

    return 0;
}

/*
 The function write_data(...) takes as input a file name
 string, a double pointer pointing to a two-dimensional
 array n x 3 elements where n is the number of lines in the
 input file, and n given as integer, and writes the data to a file in
 in the n x 3 format.
*/

int write_data(char *s, double **a, int n)
{
    FILE *fw;
    int i;

    if ((fw = fopen(s, "w")) == NULL)
    {
        printf("Cannot open the file %s.\n", s);
        return -1;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fw, "%lf %lf %lf\n", a[i][0], a[i][1], a[i][2]);
    }

    if ((fclose(fw) == EOF))
    {
        printf("File '%s' could not be closed.\n", s);
        return -1;
    }

    return 0;
}


/*
 The function rotate_vector(...) takes as input an 3-element array v
 representing a vector and the rotation angle and rotates the vector
 around the z-axis. Angle is expected to be given in degrees.
 The rotation matrix around the z-axis is:
 | cos(angle) -sin(angle) 0 |
 R = | sin(angle) cos(angle) 0 |
 | 0 0 1 |
 and the rotation means multipication of a vector by this matrix:
 w_i = \sum_j R_ij * v_j
 The functon is expected to return the rotated vector through updated
 elements of the input vector v.
*/
void rotate_vector(double v[], double angle)
{
    double R[3][3];
    double w[3] = {0.0, 0.0, 0.0};
    int i, j;
    /* Convert angle to radians */
    angle *= PI / 180.0;
    /* initialise matrix R */
    R[0][0] = cos(angle);
    R[0][1] = -sin(angle);
    R[0][2] = 0.0;
    R[1][0] = sin(angle);
    R[1][1] = cos(angle);
    R[1][2] = 0.0;
    R[2][0] = 0.0;
    R[2][1] = 0.0;
    R[2][2] = 1.0;
    /* rotate vector v by multiplying it by the rotation matrix */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            w[i] += R[i][j] * v[j];
        }
    }
    /* copy w to v for return */
    for (i = 0; i < 3; i++) {
        v[i] = w[i];
    }
}
/******************************************************/
int main()
{
    /*FILE *fr, *fw;*/
    int i, j, n;
    double **m;
    double v[3];
    double angle = 90.0; /* rotation angle */
    char s_in[] = "data.in"; /* input data file */
    char s_out[] = "data.out"; /* output data file */

    /* Find how many lines in the input file */
    n = read_number_of_lines(s_in);

    /* Dynamic memory allocation is necessary because we
    don't know the size of the matrix apriori, i.e.
    the input file can have a variable number of lines.
    First allocate memory for an array of n pointers of
    type double pointing to individual rows (vectors). */

    m = (double **) malloc(sizeof(double *)*n);
    if (m == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 1;
    }

    /* Now allocate memory for every row (vector). */
    for (i = 0; i < 3; i++)
    {
        m[i] = (double *) malloc(sizeof(double) * 3);
        if (m[i] == NULL)
        {
            printf("Unable to allocate memory.\n");
            return 1;
        }
    }

    /* read data from file */
    read_data(s_in, m, n);
    
    /* now rotate every vector */
    for (i = 0; i < n; i++)
    {

        /* copy i-th row to vector v */
        for (j = 0; j < 3; j++) {
            v[j] = m[i][j];
        }
        rotate_vector(v, angle);

        /* copy back */
        for (j = 0; j < 3; j++) {
            m[i][j] = v[j];
        }
    }

    /* write data to file */
    write_data(s_out, m, n);

    /* Don't forget to free the allocated memory */
    for (i = 0; i < n; i++)
    {
        free((void *) m[i]);
    }
    free((void **) m);
    return 0;
}
