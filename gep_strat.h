#ifndef GEP_STRAT_H_INCLUDED
#define GEP_STRAT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "strukturak.h"
#include "debugmalloc.h"

void lista_felszabadit(ListaElem* eleje);
int lista_hossz (ListaElem *lista);
ListaElem * lista_elejere_beszur(ListaElem *eleje, RubrikaAdatok *mezo);

void vizszintes_vedekez(Tabla *tabla, ListaElem **veszelyes_mezo);
void fuggoleges_vedekez(Tabla *tabla,  ListaElem **veszelyes_mezo);
void eny_vedekez(Tabla *tabla,  ListaElem **veszelyes_mezo);
void ek_vedekez(Tabla *tabla,  ListaElem **veszelyes_mezo);

void ved_akadalyoz(Tabla *tabla,  ListaElem **veszelyes_mezo);


void vizszintes_tamad(Tabla *tabla,  ListaElem **tamado_mezok, int *szam);
void fuggoleges_tamad(Tabla *tabla,  ListaElem **tamado_mezok,int *szam);
void eny_tamad(Tabla *tabla,  ListaElem **tamado_mezok,int *szam);
void ek_tamad(Tabla *tabla,  ListaElem **tamado_mezok,int *szam);

void epito_tamado(Tabla *tabla,  ListaElem **tamado_mezok,int *szam);

void epito(Tabla *tabla);
void akadalyozo(Tabla *tabla);
void geprak( int *strat, Tabla *tabla);


#endif // GEP_STRAT_H_INCLUDED
