#ifndef BAND_H
#define BAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <pthread.h>
#include <term.h>

typedef enum {
    Rock,
    Jazz,
    ElectronicDanceMusic,
    Dubstep,
    Techno,
    RhythmAndBlues,
    Country,
    Pop
} Genre;

typedef enum {
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

typedef enum {
    male,
    female,
} Gender;

typedef struct {
    Gender sex;
    int age;
    Names name;
    char *role;
    int pitch;
} member;

typedef struct {
    int membersnum;
    member *members;
    float rating;
    Genre genre;
} Band;

char *GetInfoAboutBand(Band b);
char *GetRandomstring();
const char *getGenreName(Genre genre);
const char *getMusicianName(Names musician);
void PrintInfoAboutBand(Band b);
void fillMembers(member *m, int num);
void fillBands(Band *b, int num);
int GetRandomNumInrange(int lowerBorder, int upperBorder);
char getSex(Gender g);
float GetBandRating(Band b);
void BandSoundShow(Band b);
void PlaySong(Band b);
void* noSurprises();
void* cleenGuitar();
void* tomas();
void printWithDelay(const char* message, useconds_t delay);
#endif // BAND_H
