#include "kirajzolas.h"

void fomenu(SDL_Renderer *renderer, int *melyik, Gombtarolas *gombtomb)
{
    for( int i=0; i<2; i++)
    {
        if(*melyik%2==i)
        {
            boxRGBA( renderer, gombtomb[i].x,gombtomb[i].y,gombtomb[i].szelesseg,gombtomb[i].magassag, 30,115,205, 255 );
            stringRGBA(renderer,gombtomb[i].x+20,(gombtomb[i].y+gombtomb[i].magassag)/2, gombtomb[i].felirat, 255,255,255,255);
        }
        else
        {
            boxRGBA( renderer, gombtomb[i].x,gombtomb[i].y,gombtomb[i].szelesseg,gombtomb[i].magassag, 200,0,40, 255 );
            stringRGBA(renderer,gombtomb[i].x+20,(gombtomb[i].y+gombtomb[i].magassag)/2, gombtomb[i].felirat, 255,255,255,255);

        }
    }
}
//menugomb beállítás
void beallitas_menugomb(SDL_Renderer *renderer,int *menulepteto, Gombtarolas *gombtomb)
{
    for(int i=2; i<=5; i++)
    {
        if(*menulepteto%4==i-2)
        {
            boxRGBA(renderer, gombtomb[i].x,gombtomb[i].y,gombtomb[i].szelesseg,gombtomb[i].magassag, 30,115,205, 255 );
            stringRGBA(renderer,gombtomb[i].x+20,(gombtomb[i].y+gombtomb[i].magassag)/2, gombtomb[i].felirat, 255,255,255,255);
        }
        else
        {
            boxRGBA(renderer, gombtomb[i].x,gombtomb[i].y,gombtomb[i].szelesseg,gombtomb[i].magassag, 200,0,40, 255 );
            stringRGBA(renderer,gombtomb[i].x+20,(gombtomb[i].y+gombtomb[i].magassag)/2, gombtomb[i].felirat, 255,255,255,255);
        }

    }
}
//magszel
void magszel (SDL_Renderer *renderer,int *mags, int *szels, Gombtarolas *gombtomb )
{
    char magtomb[3];
    sprintf(magtomb, "%2d", *mags);
    //palyamagassag
    stringRGBA(renderer, gombtomb[2].x+400,(gombtomb[2].y+gombtomb[2].magassag)/2,magtomb, 255,255,255,255);

    char szeltomb[3];
    sprintf(szeltomb, "%2d", *szels);
    //palyaszelesseg
    stringRGBA(renderer, gombtomb[3].x+400,(gombtomb[3].y+gombtomb[3].magassag)/2,szeltomb, 255,255,255,255);
}
//kikezdi fv
void kikezdi (SDL_Renderer *renderer, int *kikezd, Gombtarolas *gombtomb)
{
    if(*kikezd==gep)
    {
        stringRGBA(renderer, gombtomb[4].x+400,(gombtomb[4].y+gombtomb[4].magassag)/2,"gep", 255,255,255,255);
    }
    else
    {
        stringRGBA(renderer,gombtomb[4].x+400,(gombtomb[4].y+gombtomb[4].magassag)/2,"jatekos", 255,255,255,255);
    }
}

//gep strat
void gep_strat (SDL_Renderer *renderer, int *strat, Gombtarolas *gombtomb)
{
    //gép strategiaja gomb

    switch (*strat)
    {
    case konnyu:
        stringRGBA(renderer,gombtomb[5].x+400,(gombtomb[5].y+gombtomb[5].magassag)/2,"konnyu", 255,255,255,255);
        break;
    case kozepes:
        stringRGBA(renderer,gombtomb[5].x+400,(gombtomb[5].y+gombtomb[5].magassag)/2,"kozepes", 255,255,255,255);
        break;
    case nehez:
        stringRGBA(renderer,gombtomb[5].x+400,(gombtomb[5].y+gombtomb[5].magassag)/2,"nehez", 255,255,255,255);
        break;
    }
}

//palyarajz
void palyarajz (SDL_Renderer *renderer, int* mezooldal, int *szels, int *mags)
{
    for(int j=0; j<=*mags; j++)
    {
        lineRGBA(renderer, 20,20+(j*(*mezooldal)), 20+((*szels)*(*mezooldal)), 20+(j*(*mezooldal)),255,255,255,255 );
    }
    for (int i=0; i<=*szels; i++)
    {
        lineRGBA(renderer, 20+(i*(*mezooldal)), 20,20+(i*(*mezooldal)), 20+((*mags)*(*mezooldal)), 255,255,255,255);
    }
}

//kör
void kor_rajz(SDL_Renderer *renderer,Tabla *tabla,int *mezooldal)
{
    for (int i=0; i<(tabla->szels); ++i) //kör rajz
    {
        for( int j=0; j<(tabla->mags); ++j)
        {
            if ((tabla->mezo)[i][j].babu == kor)
            {
                circleRGBA(renderer, ((tabla->mezo)[i][j].balfelsoX+ (tabla->mezo)[i][j].jobbalsoX)/2, ((tabla->mezo)[i][j].balfelsoY+ (tabla->mezo)[i][j].jobbalsoY)/2, (*mezooldal/2)-3, 30,115,205, 255 );
            }
        }
    }
}
//iksz
void iksz_rajz(SDL_Renderer *renderer,Tabla *tabla)
{
    for (int i=0; i<(tabla->szels); ++i)
    {
        for( int j=0; j<(tabla->mags); ++j)
        {
            if ((tabla->mezo)[i][j].babu == iksz)
            {
                lineRGBA(renderer, (tabla->mezo)[i][j].balfelsoX+3, (tabla->mezo)[i][j].balfelsoY+3, (tabla->mezo)[i][j].jobbalsoX-3, (tabla->mezo)[i][j].jobbalsoY-3, 200,0,40, 255 );
                lineRGBA(renderer, (tabla->mezo)[i][j].balfelsoX+3, (tabla->mezo)[i][j].jobbalsoY-3, (tabla->mezo)[i][j].jobbalsoX-3, (tabla->mezo)[i][j].balfelsoY+3, 200,0,40, 255 );
            }
        }
    }
}
//mentes
void mentes(SDL_Renderer *renderer, Gombtarolas *gombtomb)
{
    boxRGBA(renderer, gombtomb[6].x,gombtomb[6].y,gombtomb[6].szelesseg,gombtomb[6].magassag,30,115,205 , 155 );
    stringRGBA(renderer,gombtomb[6].x+55,(gombtomb[6].y+gombtomb[6].magassag)/2,gombtomb[6].felirat,255,255,255 ,255);
}

void uj_jatek_kezd(SDL_Renderer *renderer, Gombtarolas *gombtomb){

    boxRGBA(renderer, gombtomb[7].x, gombtomb[7].y, gombtomb[7].szelesseg, gombtomb[7].magassag,30,115,205 ,155);
    stringRGBA(renderer,gombtomb[7].x+25, (gombtomb[7].y+gombtomb[7].magassag)/2, gombtomb[7].felirat,255,255,255 ,255);
}

void dontetlen_kiir(SDL_Renderer *renderer, int SZELESSEG, int MAGASSAG)
{
    boxRGBA(renderer, SZELESSEG/4, (MAGASSAG/2)-20, 3*(SZELESSEG/4),(MAGASSAG/2)+20,200,0,40,255);
    thickLineRGBA(renderer, (SZELESSEG/4)-5, (MAGASSAG/2)-20, 3*(SZELESSEG/4)+5, (MAGASSAG/2)-20,12, 30,115,205,255);

    thickLineRGBA(renderer, (SZELESSEG/4)-5, (MAGASSAG/2)+20, 3*(SZELESSEG/4)+5, (MAGASSAG/2)+20,12, 30,115,205,255);

    thickLineRGBA(renderer, SZELESSEG/4, (MAGASSAG/2)-25, SZELESSEG/4, (MAGASSAG/2)+25,12, 30,115,205,255);

    thickLineRGBA(renderer, 3*(SZELESSEG/4), (MAGASSAG/2)-25, 3*(SZELESSEG/4), (MAGASSAG/2)+25,12, 30,115,205,255);
    stringRGBA(renderer,(SZELESSEG/2)-55,(MAGASSAG/2)-5, "Dontetlen lett!", 255,255,255,255);
}
