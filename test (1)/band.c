#include "band.h"
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
void fillBands(Band *b, int num)
{
    int i = 0;
    int mem;
    for (; i < num; i++)
    {
        mem = GetRandomNumInrange(2, 10);
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
            m[n].pitch=GetRandomNumInrange(150,600);
        }
        else
        {
            m[n].sex=female;
            m[n].pitch=GetRandomNumInrange(600,1000);
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
void PlaySong(Band b)
{
  PrintInfoAboutBand(b);
    int i;
    for(i=0;i<b.membersnum; i++)
    {
        Beep(b.members[1].pitch,GetRandomNumInrange(200,1500));
        printf("%d\n",b.members[i].pitch);
        Sleep(200);1
    }
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
