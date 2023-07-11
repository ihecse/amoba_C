#ifndef STRUKTURAK_H_INCLUDED
#define STRUKTURAK_H_INCLUDED
#include "debugmalloc.h"
#include <stdio.h>

typedef enum Babu
{
    ures,
    kor,
    iksz,
} Babu;

typedef struct RubrikaAdatok
{
    double balfelsoX;
    double balfelsoY;
    double jobbalsoX;
    double jobbalsoY;
    Babu babu;
} RubrikaAdatok;

typedef struct Gombtarolas
{
    int szelesseg, magassag;
    char *felirat;
    int x,y;
    int azonosito;
} Gombtarolas;

typedef struct ListaElem
{
    RubrikaAdatok *adat;
    struct ListaElem *kov;
} ListaElem;

enum Strat
{
    konnyu,
    kozepes,
    nehez
};

enum Kikezd
{
    gep,
    jatekos
};

typedef struct Tabla
{
    int mags;
    int szels;
    RubrikaAdatok **mezo;
} Tabla;


#endif // STRUKTURAK_H_INCLUDED
