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
void PrintInfoAboutBand(Band b);
void fillMembers(member *m, int num);
void fillBands(Band *b, int num);
int GetRandomNumInrange(int lowerBorder, int upperBorder);
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
    printf("Genre: %d\n", b.genre);
    printf("Rating: %.2f\n", b.rating);

    printf("\nMembers:\n");
    printf("%-20s%-10s\n", "Name", "Age");

    for (int i = 0; i < b.membersnum; i++)
    {
        printf("%-20d%-10d\n", b.members[i].name, b.members[i].age);
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
        if (((b[i].members) = (member *)malloc(sizeof(member) * mem)) == NULL)
        {
            return;
        }
        fillMembers(b[i].members, mem);
    }
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
