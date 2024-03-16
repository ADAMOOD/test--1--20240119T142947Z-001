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
    int choice;
    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Generate new bands\n");
        printf("2. Play a band\n");
        printf("3. Play a song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Generating new bands...\n");
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
            break;
        case 2:
            printf("Give me a number of Band\n");
            int bandNum;
            scanf("%d",&bandNum);
            BandSoundShow(bands[bandNum-1]);
            break;
        case 3:
            printf("Playing a song...\n");
            // Add your code for playing a song here
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    while(choice != 4);
    for (int i = 0; i < bNumber; i++)
    {
        free(bands[i].members);
    }
    free(bands);
    return 0;
}


