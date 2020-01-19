#include <stdio.h>
#include <string.h>
struct designData
{
    int numDesigns;
    float data[4];
};
int write_to_file(char *filename, int num, float len) /* Need parameter definitions */
{
    FILE *file; /* pointer to output file */
    /* Enter code here */
    if ((file = fopen(filename, "w")) == NULL)
    {
        printf("Unable to open file.\n");
        return -1;
    }

    fprintf(file, "Input script for design %d\nLength of strut is %.1f mm\n", num, len);

    if (fclose(file) == EOF)
    {
        printf("Unable to close file.\n");
        return -1;
    }
    return 0;
}
struct designData read_from_file(void)
{
    FILE *file; /* pointer to input file */
    struct designData desdat;
    int i=0;
    /* Enter code here */
    if ((file=fopen("designData.txt", "r"))== NULL)
    {
        printf("Unable to read file.\n");
    }
    fscanf(file, "%d\n", &desdat.numDesigns);

    while (!feof(file))
    {
        fscanf(file, "%f", &desdat.data[i++]);
    }

    if (fclose(file) != 0)
        printf("Unable to close file.\n");
    return desdat;
}
int main(void)
{
    int i, numPts;
    char outfile[12];
    struct designData desdat;

/* Define other variables etc here */
/*** Read data from file */
    desdat = read_from_file();
    numPts = desdat.numDesigns;
/* Enter code here */
/*** Loop through each design and write to file */
    for(i=0; i<numPts; i++)
    {
/* Enter code here*/
        sprintf(outfile, "design%d.txt", i+1);
        write_to_file(outfile, i+1, desdat.data[i]);
    }
    return 0;
}