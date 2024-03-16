#include "band.h"
#include <windows.h>

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
    int bandNum;
    printf("Do you wanna hear any of the bands?");
    scanf("%d",&bandNum);
   /* PrintInfoAboutBand(bands[bandNum-1]);
    int i;
    for(i=0;i>bands[bandNum-1].membersnum; i++)
    {
        Beep(bands[bandNum-1].members[1].pitch,1000);
        printf("%d\n",bands[bandNum-1].members[i].pitch);
    }*/
    //Beep(bands[bandNum-1].members[1].pitch,1000);
    PlaySong(bands[bandNum-1]);
    for (int i = 0; i < bNumber; i++)
    {
        free(bands[i].members);
    }
    free(bands);
    return 0;
}
