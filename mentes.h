#ifndef MENTES_H_INCLUDED
#define MENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "strukturak.h"
#include <stdbool.h>

void jatek_ment( char const *fajlnev, Tabla *tabla,int strat,int kijon);
RubrikaAdatok ** jatek_betolt( char const *fajlnev, int *szels, int *mags,int *strat,int *kijon);

#endif // MENTES_H_INCLUDED
