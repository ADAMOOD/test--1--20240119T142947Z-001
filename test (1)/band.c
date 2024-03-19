#include "band.h"
#include "noSurprisses.h"
#include <windows.h>
char *GetInfoAboutBand(Band b)
{
    int tableWidth = 46;
    char *result = (char *)malloc(1);


    void appendString(const char *str)
    {
        result = (char *)realloc(result, strlen(result) + strlen(str) + 1);
        strcat(result, str);
    }

    appendString("Genre: ");
    appendString(getGenreName(b.genre));
    appendString("\nRating: ");
    char ratingStr[10];
    sprintf(ratingStr, "%.2f", b.rating);
    appendString(ratingStr);
    appendString("\n\nMembers:\n");

    for (int i = 0; i < tableWidth + 2; i++)
    {
        appendString("_");
    }
    appendString("\n|%-30s|%-3s|%-3s|%-7s|\n");
    appendString("|");
    for (int i = 0; i < tableWidth; i++)
    {
        if (i == 30 || i == 34 || i == 38)
        {
            appendString("|");
        }
        else
        {
            appendString("-");
        }
    }
    appendString("|\n");

    for (int i = 0; i < b.membersnum; i++)
    {
        char memberInfo[100];
        sprintf(memberInfo,"|%-30s|%-3d|%-3c|%-7s|\n", getMusicianName(b.members[i].name), b.members[i].age, getSex(b.members[i].sex), b.members[i].role);
        appendString(memberInfo);
    }

    for (int i = 0; i < tableWidth + 2; i++)
    {
        appendString("*");
    }
    appendString("\n");

    return result;
}
void PrintInfoAboutBand(Band b)
{
    int tableWidth=52;
    printf("Genre: %s\n", getGenreName(b.genre));
    printf("Rating: %.2f\n", b.rating);

    printf("\nMembers:\n");
    for (int i = 0; i < tableWidth+2; i++)
    {

        printf("_");
    }
    printf("\n|%-30s|%-3s|%-3s|%-7s|%-5s|\n", "Name", "Age", "Sex","Role","Pitch");
    printf("|");
    for (int i = 0; i < tableWidth; i++)
    {
        if(i==30||i==34||i==38||i==46)
        {
            printf("|");
        }
        else
        {
            printf("-");
        }
    }
    printf("|\n");

    for (int i = 0; i < b.membersnum; i++)
    {
        printf("|%-30s|%-3d|%-3c|%-7s|%-5d|\n", getMusicianName(b.members[i].name), b.members[i].age, getSex(b.members[i].sex),b.members[i].role,b.members[i].pitch );
    }

    for (int i = 0; i < tableWidth+2; i++)
    {
        printf("*");
    }
    printf("\n");

}
char getSex(Gender g)
{
    if(g==female)
    {
        return 'f';
    }
    return 'm';
}

#define RIFF   Beep(3520.00,500);Beep(2093.00,500);Beep(2793.83,500);Beep(2093.00,500);
#define DOWNWARDRIFF   Beep(932.33,500);Beep(2217.46,500);Beep(2793.83,500);Beep(3135.96,500);
#define D7(x) Beep(	440.00,x);
#define E8(x) Beep(	261.63,x);
#define D5(x) Beep(	392.00 ,x);
#define A8(x) Beep(	349.23 ,x);
#define E6(x) Beep(	233.08 ,x);
#define D8(x) Beep(	466.16 ,x);
#define E10(x) Beep(293.66 ,x);
#define A7(x) Beep(329.63 ,x);
#define E3(x) Beep(659.26 ,x);


void *cleenGuitar()
{

    RIFF;
    RIFF;
    RIFF;
    DOWNWARDRIFF;
    printf("fadsfds");
    return NULL;
}
void printWithDelay(const char* message, useconds_t delay)
{
    printf("\033[H");
    printf("%s", message);
    usleep(delay); // Zpoždìní
}
void* tomas()
{

       system("cls");
    printf("\033[104;30m");
    FILE *animationFile;
    animationFile = fopen("tomas.TXT", "r");

    if (animationFile == NULL)
    {
        printf("Soubor nenalezen.\n");
        return NULL;
    }

    int framesNUM = 1, reader, num = 0;
    int animationResolution[100] = {0}; // Inicializace všech prvků na 0

    while ((reader = fgetc(animationFile)) != EOF)
    {
        animationResolution[framesNUM - 1]++;
        if (reader == 'o')
        {
            framesNUM++;
        }
    }

    rewind(animationFile); // Návrat na začátek souboru

    char **animation;
    if ((animation = (char**)malloc(sizeof(char*) * framesNUM)) == NULL)
    {
        printf("Paměť pro pole animací nebyla úspěšně alokována.\n");
        fclose(animationFile);
        return NULL;
    }

    for (int i = 0; i < framesNUM; i++)
    {
        if ((animation[i] = (char*)malloc(sizeof(char) * (animationResolution[i] + 1))) == NULL)
        {
            printf("Paměť pro animaci %d nebyla úspěšně alokována.\n", i);
            fclose(animationFile);
            // Uvolníme paměť před ukončením funkce
            for (int j = 0; j < i; j++)
            {
                free(animation[j]);
            }
            free(animation);
            return NULL;
        }

        int j = 0;
        while ((reader = fgetc(animationFile)) != EOF && reader != 'o')
        {
            animation[i][j++] = reader;
        }
        animation[i][j] = '\0'; // Přidání ukončovacího nulového znaku
    }
    fclose(animationFile); // Uzavřeme soubor po jeho čtení
    while(!kbhit())
    {
      for(int f=0;f<framesNUM;f++)
    {
      printWithDelay(animation[f],80000);
    }
    }

    /* int count = 0;
     while (tomas2[count] != '\0')
     {
         count++;
     }
     system("cls");
    printf("\033[104;30m");
     system("clear || cls");
     printf("%s",tomas1);
     for(int b=0; !kbhit(); b++)
     {
     printWithDelay(tomas2, 80000);
     printWithDelay(tomas3, 80000);
     printWithDelay(tomas4, 80000);
     printWithDelay(tomas5, 80000);
     printWithDelay(tomas6, 80000);
     printWithDelay(tomas7, 80000);
     printWithDelay(tomas8, 80000);
     printWithDelay(tomas9, 80000);
     printWithDelay(tomas10, 80000);
     printWithDelay(tomas11, 80000);
     printWithDelay(tomas12, 80000);
     printWithDelay(tomas13, 80000);
     printWithDelay(tomas14, 80000);

     // Seznam funkcí
     void (*functions[])(const char*, useconds_t) = {
         printWithDelay,
         printWithDelay,
         printWithDelay,
         printWithDelay
     };

     // Pole zpráv
     const char* messages[] = {tomas11, tomas12, tomas13, tomas14};

     // Nastavení generátoru náhodných èísel
     srand(time(NULL));

     // Provedení ètveøice funkcí 10krát v náhodném poøadí
     for (int i = 0; i < 10; i++) {
         // Náhodné zamíchání funkcí
         for (int j = 3; j > 0; j--) {
             int randomIndex = rand() % (j + 1);
             void (*temp)(const char*, useconds_t) = functions[j];
             functions[j] = functions[randomIndex];
             functions[randomIndex] = temp;
         }
         // Volání funkcí v náhodném poøadí
         for (int j = 0; j < 4; j++) {
             functions[j](messages[j], 80000);
         }
     }

     // Výpisy zpráv s mezièasem
     printWithDelay(tomas15, 80000);
     printWithDelay(tomas16, 80000);
     printWithDelay(tomas17, 80000);
     printWithDelay(tomas18, 80000);
     printWithDelay(tomas19, 80000);
    /* printWithDelay(tomas20, 50000);
     printWithDelay(tomas21, 50000);
     printWithDelay(tomas22, 50000);
     printWithDelay(tomas23, 50000);
     printWithDelay(tomas24, 50000);
     printWithDelay(tomas25, 50000);
     printWithDelay(tomas26, 50000);
     printWithDelay(tomas27, 50000);
     printWithDelay(tomas28, 50000);
     printWithDelay(tomas29, 50000);
     printWithDelay(tomas30, 50000);*/

    /* printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas2[i]);
     }
     printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas3[i]);
     }
     printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas4[i]);
     }
     printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas5[i]);
     }
     printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas6[i]);
     }
     printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas7[i]);
     }
             printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas8[i]);
     }
             printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas9[i]);
     }
             printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas10[i]);
     }
             printf("\033[H");
     for(int i=0; i<count; i++)
     {
         printf("%c",tomas11[i]);
     }*/
    /* }
     */
}
void* noSurprises()
{
    RIFF;
    RIFF;
    RIFF;
    DOWNWARDRIFF;
    RIFF;
    RIFF;
    RIFF;
    DOWNWARDRIFF;
    D7(2000);
    E8(2000);
    D7(500);
    D7(1000);
    D5(1400);
    A8(500);
    D5(500);
    D7(2000);
    E6(2000);
    D7(500);
    D7(1000);
    D5(1400);
    A8(500);
    D5(500);
    D8(2000);
    E10(2000);
    A8(500);
    A7(1000);
    A8(1000);
    D5(1000);
    D7(1000);
    Beep(2093.00,500);
    Beep(2793.83,500);
    Beep(2093.00,500);
    RIFF;
    RIFF;
    DOWNWARDRIFF;
    D7(2000);
    E8(2000);
    D7(500);
    D7(1000);
    D5(1400);
    A8(500);
    D5(500);
    D7(2000);
    E6(2000);
    D7(500);
    D7(1000);
    D5(1400);
    A8(500);
    D5(500);
    D8(2000);
    E10(2000);
    A8(500);
    A7(1000);
    A8(1000);
    D5(1000);
    D7(1000);
    Beep(2093.00,500);
    Beep(2793.83,500);
    Beep(2093.00,500);
    RIFF;
    RIFF;
    DOWNWARDRIFF;
}
void fillBands(Band *b, int num)
{
    int i = 0;
    int mem;
    for (; i < num; i++)
    {
        mem = GetRandomNumInrange(2, 20);
        b[i].membersnum = mem;
        b[i].genre = GetRandomNumInrange(0, 13);
        if (((b[i].members) = (member *)malloc(sizeof(member) * mem)) == NULL)
        {
            return;
        }
        fillMembers(b[i].members, mem);
        b[i].rating = GetBandRating(b[i]);
    }
}
float GetBandRating(Band b)
{
    float rating = b.genre;
    float x = (float)b.membersnum;
    for (int i = 0; i < b.membersnum; i++)
    {
        rating += b.members[i].age;
        x += (float)b.members[i].name;
    }
    return rating /= x;
}
void fillMembers(member *m, int num)
{
    for (int n = 0; n < num; n++)
    {
        m[n].name = (Names)GetRandomNumInrange(1, 13);
        m[n].age = GetRandomNumInrange(20, 60);
        m[n].role=GetRandomstring();
        if (GetRandomNumInrange(0, 100)%2==0)
        {
            m[n].sex=male;
            m[n].pitch=GetRandomNumInrange(100,1000);
        }
        else
        {
            m[n].sex=female;
            m[n].pitch=GetRandomNumInrange(600,3000);
        }
    }
}
char *GetRandomstring()
{
    int length=GetRandomNumInrange(3,7);
    char *role;
    if((role=(char*)malloc(sizeof(char)*length))==NULL)
    {
        return NULL;
    }
    for(int i=0; i<length; i++)
    {
        role[i]=(char)GetRandomNumInrange('A','B');
    }
    return role;
}
void BandSoundShow(Band b)
{
    PrintInfoAboutBand(b);
    int i;
    for(i=0; i<b.membersnum; i++)
    {
        int time=GetRandomNumInrange(50,300);
        Beep(b.members[i].pitch,time);
    }
}
void PlaySong(Band b)
{
    PrintInfoAboutBand(b);
    printf("PRESS ANY KEY TO END THE SONG\n");
    int i;
    do
    {
        int memberToPlay=GetRandomNumInrange(0,b.membersnum-1);
        int time=GetRandomNumInrange(20,300);
        printf("|%-30s|%-3d|%-3c|%-7s|%-5d|\n", getMusicianName(b.members[memberToPlay].name), b.members[memberToPlay].age, getSex(b.members[memberToPlay].sex),b.members[memberToPlay].role,b.members[memberToPlay].pitch );
        Beep(b.members[memberToPlay].pitch,time);
    }
    while(!kbhit());
}
int GetRandomNumInrange(int lowerBorder, int upperBorder)
{
    return (rand() % (upperBorder - lowerBorder + 1) + lowerBorder);
}
const char *getGenreName(Genre genre)
{
    switch (genre)
    {
    case Rock:
        return "Rock";
    case Jazz:
        return "Jazz";
    case ElectronicDanceMusic:
        return "Electronic Dance Music";
    case Dubstep:
        return "Dubstep";
    case Techno:
        return "Techno";
    case RhythmAndBlues:
        return "Rhythm and Blues";
    case Country:
        return "Country";
    case Pop:
        return "Pop";
    default:
        return "Unknown";
    }
}
const char *getMusicianName(Names musician)
{
    switch (musician)
    {
    case ThomYorke:
        return "Thom Yorke";
    case JonnyGreenwood:
        return "Jonny Greenwood";
    case EdOBrien:
        return "Ed O'Brien";
    case ColinGreenwood:
        return "Colin Greenwood";
    case PhilipSelway:
        return "Philip Selway";
    case GeordieGreep:
        return "Geordie Greep";
    case MattKwasniewskiKelvin:
        return "Matt Kwasniewski-Kelvin";
    case CameronPicton:
        return "Cameron Picton";
    case MorganSimpson:
        return "Morgan Simpson";
    case IsaacWood:
        return "Isaac Wood";
    case LukeMark:
        return "Luke Mark";
    case TylerHyde:
        return "Tyler Hyde";
    case LewisEvans:
        return "Lewis Evans";
    case GeorgiaEllery:
        return "Georgia Ellery";
    default:
        return "Unknown";
    }
}
