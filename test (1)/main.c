#include "band.h"
#include <windows.h>

int main()
{
    pthread_t cleenG;
    pthread_t vocals;
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
        printf("1. Generate new bands\n");
        printf("2. Play a band\n");
        printf("3. Play a song\n");
        printf("4. No Surprisses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int bandNum;
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
            scanf("%d",&bandNum);
            BandSoundShow(bands[bandNum-1]);
            break;
        case 3:
            printf("Playing a song...\n");
            printf("Give me a number of Band\n");
            scanf("%d",&bandNum);
            PlaySong(bands[bandNum-1]);
            break;
        case 4:

          /*  if (pthread_create(&cleenG, NULL, tomas(), NULL) != 0)
            {
                fprintf(stderr, "Chyba pøi vytváøení vlákna cleenG.\n");
                return 1;
            }
            if (pthread_create(&vocals, NULL, noSurprises, NULL) != 0)
            {
                fprintf(stderr, "Chyba pøi vytváøení vlákna vocals.\n");
                return 1;
            }
            if (pthread_join(cleenG, NULL) != 0)
            {
                fprintf(stderr, "Chyba pøi èekání na ukonèení vlákna cleenG.\n");
                return 1;
            }

            if (pthread_join(vocals, NULL) != 0)
            {
                fprintf(stderr, "Chyba pøi èekání na ukonèení vlákna vocals.\n");
                return 1;
            }*/
           // tomas();
             noSurprises();
            break;
        case 5:
            printf("Exiting...\n");
            Beep(150,1000);
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    while(choice != 5);
    for (int i = 0; i < bNumber; i++)
    {
        free(bands[i].members);
    }
    free(bands);
    return 0;
}


