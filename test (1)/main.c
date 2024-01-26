#include "band.h"

int main()
{
    srand(time(NULL));
    Band *bands;
    int bNumber;
    printf("Give me a number of bands\n");
    scanf("%d", &bNumber);
    if ((bands = (Band *)malloc(sizeof(Band) * bNumber)) == NULL)
    {
        return -1;
    }
    fillBands(bands, bNumber);
        FILE *file;
   file= fopen("file.txt","w");
    for (int i = 0; i < bNumber; i++)
    {
        printf("Band number %d:\n", i + 1);
        PrintInfoAboutBand(bands[i]);
         fprintf(file,"%s",GetInfoAboutBand(bands[i]));
    }
    fclose(file);
    for (int i = 0; i < bNumber; i++)
    {
        free(bands[i].members);
    }
    free(bands);
    return 0;
}