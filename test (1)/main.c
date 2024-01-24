#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    Rock,
    Jazz,
    ElectronicDanceMusic,
    Dubstep,
    Techno,
    RhythmAndBlues,
    Country,
    Pop
} Genre;

typedef enum
{
    ThomYorke,
    JonnyGreenwood,
    EdOBrien,
    ColinGreenwood,
    PhilipSelway,
    GeordieGreep,
    MattKwasniewskiKelvin,
    CameronPicton,
    MorganSimpson,
    IsaacWood,
    LukeMark,
    TylerHyde,
    LewisEvans,
    GeorgiaEllery,
} Names;

typedef union
{
    int male;
    int female;
} Gender;

typedef struct
{
    Gender sex;
    int age;
    Names name;
    char *role;
} member;

typedef struct
{
    int membersnum;
    member *members;
    float rating;
    Genre genre;
} Band;
const char *getGenreName(Genre genre);
const char *getMusicianName(Names musician);
void PrintInfoAboutBand(Band b);
void fillMembers(member *m, int num);
void fillBands(Band *b, int num);
int GetRandomNumInrange(int lowerBorder, int upperBorder);
float GetBandRating(Band b);
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
    for (int i = 0; i < bNumber; i++)
    {
        PrintInfoAboutBand(bands[i]);
    }

    for (int i = 0; i < bNumber; i++)
    {
        free(bands[i].members);
    }
    free(bands);
    return 0;
}
void PrintInfoAboutBand(Band b)
{
    printf("Band Information:\n");
    printf("Genre: %s\n", getGenreName(b.genre));
    printf("Rating: %.2f\n", b.rating);

    printf("\nMembers:\n");
    for (int i = 0; i < 35; i++)
    {
        printf("_");
    }

    printf("\n\|%-30s\|%-3s\|\n", "Name", "Age");

    for (int i = 0; i < b.membersnum; i++)
    {
        printf("\|%-30s\|%-3d\|\n\|", getMusicianName(b.members[i].name), b.members[i].age);
        for (int i = 0; i < 34; i++)
        {
            printf("-");
        }
        printf("\|\n");
    }
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
        if (GetRandomNumInrange(0, 1) == 0)
        {
            m[n].sex.male = 1;
        }
        else
        {
            m[n].sex.female = 1;
        }
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
