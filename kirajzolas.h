#ifndef KIRAJZOLAS_H_INCLUDED
#define KIRAJZOLAS_H_INCLUDED
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "strukturak.h"
#include "debugmalloc.h"


//fomenu fv
void fomenu(SDL_Renderer *renderer, int *melyik, Gombtarolas *gombtomb);

//menugomb beállítás
void beallitas_menugomb(SDL_Renderer *renderer,int *menulepteto, Gombtarolas *gombtomb);

//*magszel fv
void magszel (SDL_Renderer *renderer,int *mags, int *szels, Gombtarolas *gombtomb );

//kikezdi fv eleje
void kikezdi (SDL_Renderer *renderer, int *kikezd, Gombtarolas *gombtomb);

//gep strat fv
void gep_strat (SDL_Renderer *renderer, int *strat, Gombtarolas *gombtomb);

////****mentes és kilépés fv***////
void mentes(SDL_Renderer *renderer, Gombtarolas *gombtomb);

//uj jatek kezdese
void uj_jatek_kezd(SDL_Renderer *renderer, Gombtarolas *gombtomb);

//palyarajz
void palyarajz (SDL_Renderer *renderer, int* mezooldal, int *szels, int *mags);

//kör
void kor_rajz(SDL_Renderer *renderer, Tabla *tabla,int *mezooldal );

//iksz
void iksz_rajz(SDL_Renderer *renderer, Tabla *tabla);

//dontetlen kiir
void dontetlen_kiir(SDL_Renderer *renderer, int SZELESSEG, int MAGASSAG);

#endif // KIRAJZOLAS_H_INCLUDED
