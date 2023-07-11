#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "kirajzolas.h"
#include "strukturak.h"
#include "debugmalloc.h"
#include "gep_strat.h"
#include "kinyer.h"
#include "mentes.h"

//globalis valtozok (megjeleno kepernyo merete)
int const SZELESSEG=1080;
int const MAGASSAG=720;
//ablak letrehozasa
void sdl_init(char const *felirat, int szeles, int magas, SDL_Window **pwindow, SDL_Renderer **prenderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("Nem indithato az SDL: %s", SDL_GetError());
        exit(1);
    }
    SDL_Window *window = SDL_CreateWindow(felirat, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, szeles, magas, 0);
    if (window == NULL)
    {
        SDL_Log("Nem hozhato letre az ablak: %s", SDL_GetError());
        exit(1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL)
    {
        SDL_Log("Nem hozhato letre a megjelenito: %s", SDL_GetError());
        exit(1);
    }
    SDL_RenderClear(renderer);

    *pwindow = window;
    *prenderer = renderer;
}
void gombfeltoltes(Gombtarolas *gombtomb,int x, int y, int szelesseg, int magassag, int azonosito, char *felirat)
{
    gombtomb[azonosito].x=x;
    gombtomb[azonosito].y=y;
    gombtomb[azonosito].azonosito=azonosito;
    gombtomb[azonosito].szelesseg=gombtomb[azonosito].x+szelesseg;
    gombtomb[azonosito].magassag=gombtomb[azonosito].y+magassag;
    gombtomb[azonosito].felirat = felirat ;
}
double oldalhossz (int szels, int mags, int teljszel, int teljmag)
{
    if (teljszel/szels < teljmag/mags)
    {
        return teljszel/szels;
    }
    else
    {
        return teljmag/mags;
    }
}
int main(int argc, char *argv[])
{
    //osszes gomb tulajdonsagait itt allitottam eddig be (annyi elemu a tomb ahany gomb)
    Gombtarolas gombtomb[8];
    gombfeltoltes (gombtomb,135,260,270,144,0,"Uj jatek");
    gombfeltoltes (gombtomb,690,260,270,144,1,"Korabbi jatek betoltese");
    gombfeltoltes (gombtomb,50, MAGASSAG/6,200,(MAGASSAG/6)-15,2,"Palyamagassag");
    gombfeltoltes (gombtomb,50, 2*MAGASSAG/6,200,(MAGASSAG/6)-15,3,"Palyaszelesseg");
    gombfeltoltes (gombtomb,50, 3*MAGASSAG/6,200,(MAGASSAG/6)-15,4,"Ki kezdjen?");
    gombfeltoltes (gombtomb,50, 4*MAGASSAG/6,200,(MAGASSAG/6)-15,5,"Nehezsegi szint");
    gombfeltoltes (gombtomb,865,100,200, 100,6, "Mentes");
    gombfeltoltes (gombtomb,865,250, 200, 100,7, "Uj jatek kezdese");

    // ablak letrehozasa
    SDL_Window *window;
    SDL_Renderer *renderer;
    sdl_init("AMOBA JATEK", SZELESSEG, MAGASSAG, &window, &renderer);

    //valtozok letrehozasa

    bool quit = false;
    bool uj_jatek_e=false;
    bool jatekrajz=false;
    int melyik=0; //fõmenühöz
    int menulepteto=0; //játék beállítás menühöz
    //rendelkezesre allo terulet (margok es a gombra szukseges hely kivonasaval) :830 (szel), 680 (mag)
    int tablaszel= 830;
    int tablamag= 680;
    int mezooldal=0;
    int kikezd=gep;
    int strat= konnyu;
    srand(time(0));
    int kijon=0;
    bool babutrak = false;
    bool kor_nyert = false;
    bool x_nyert = false;
    bool dontetlen = false;
    Tabla tabla;
    tabla.mags = 5;
    tabla.szels = 5;
    tabla.mezo = NULL;

    while(!quit)
    {
        if(!jatekrajz) //MENÜ
        {
            SDL_SetRenderDrawColor (renderer, 0,0,0,255);
            SDL_RenderClear(renderer);
            if(!uj_jatek_e) //gombok kirajzolasa
            {
                fomenu(renderer, &melyik, &*gombtomb);
            }
            else
            {
                beallitas_menugomb(renderer,&menulepteto,&*gombtomb);
                magszel (renderer, &tabla.mags, &tabla.szels, &*gombtomb);
                kikezdi (renderer, &kikezd, &*gombtomb);
                gep_strat (renderer, &strat, &*gombtomb);
            }
        }
        else //jatekpalya
        {
            SDL_SetRenderDrawColor (renderer, 0,0,0,255);
            SDL_RenderClear(renderer);

            mentes(renderer,&*gombtomb);
            uj_jatek_kezd(renderer,&*gombtomb);
            stringRGBA(renderer, gombtomb[6].x+10,((gombtomb[6].y+gombtomb[6].magassag)/2)+350, "KILEPES A PIROS X-EL!", 255,0,0,255 );
            lineRGBA(renderer, gombtomb[6].x-10, 0, gombtomb[6].x-10, 720,200,0,40,200);

            palyarajz (renderer, &mezooldal, &tabla.szels, &tabla.mags);
            kor_rajz(renderer, &tabla,&mezooldal);
            iksz_rajz(renderer, &tabla);

            if(kor_nyert==true)
            {
                boxRGBA(renderer, SZELESSEG/4, (MAGASSAG/2)-20, 3*(SZELESSEG/4),(MAGASSAG/2)+20,30,115,205,255);
                stringRGBA(renderer,(SZELESSEG/2)-55,(MAGASSAG/2)-5, "A kor gyozott!", 255,255,255,255);
            }
            if(x_nyert==true)
            {
                boxRGBA(renderer, SZELESSEG/4, (MAGASSAG/2)-20, 3*(SZELESSEG/4),(MAGASSAG/2)+20,200,0,40,255);
                stringRGBA(renderer,(SZELESSEG/2)-55,(MAGASSAG/2)-5, "Az X gyozott!", 255,255,255,255);
            }
            if(dontetlen==true)
            {
                dontetlen_kiir(renderer,SZELESSEG,MAGASSAG);
            }
        }
        SDL_Event event;
        SDL_WaitEvent(&event);
        switch (event.type) //vezerles (gomb,eger, kilepes...)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {

            case SDLK_LEFT:
                if(!uj_jatek_e && !jatekrajz)
                {
                    melyik--;
                    if(melyik%2==-1)
                    {
                        melyik=1;
                    }
                }

                if (menulepteto%4==0 && tabla.mags>5 && !jatekrajz)
                {
                    tabla.mags--;
                }
                if(menulepteto%4==1 && tabla.szels>5 && !jatekrajz)
                {
                    tabla.szels--;
                }
                if(menulepteto%4==2 && !jatekrajz)
                {
                    switch (kikezd)
                    {
                    case gep:
                        kikezd=jatekos;
                        break;
                    case jatekos:
                        kikezd = gep;
                        break;
                    }
                }
                if(menulepteto%4==3 && !jatekrajz)
                {

                    switch (strat)
                    {
                    case konnyu:
                        strat=nehez;
                        break;
                    case kozepes:
                        strat=konnyu;
                        break;
                    case nehez:
                        strat= kozepes;
                        break;
                    }

                }
                break;
            case SDLK_RIGHT:

                if(!uj_jatek_e && !jatekrajz)
                {
                    melyik++;
                }
                if (menulepteto%4==0 && tabla.mags<30 && !jatekrajz && uj_jatek_e)
                {
                    tabla.mags++;
                }
                if(menulepteto%4==1 && tabla.szels<30 &&!jatekrajz )
                {
                    tabla.szels++;
                }
                if (menulepteto%4==2 && !jatekrajz)
                {
                    switch (kikezd)
                    {
                    case gep:
                        kikezd=jatekos;
                        break;
                    case jatekos:
                        kikezd = gep;
                        break;
                    }
                }
                if (menulepteto%4==3 && !jatekrajz)
                {
                    switch (strat)
                    {
                    case konnyu:
                        strat=kozepes;
                        break;
                    case kozepes:
                        strat=nehez;
                        break;
                    case nehez:
                        strat= konnyu;
                        break;
                    }
                }
                break;
            case SDLK_UP:
                if(uj_jatek_e &&!jatekrajz)
                {
                    menulepteto--;
                    if (menulepteto==-1)
                        menulepteto=3;
                }
                break;
            case SDLK_DOWN:
                if (uj_jatek_e && !jatekrajz)
                {
                    menulepteto++;
                }
                break;
            case SDLK_RETURN:

                if (uj_jatek_e && !jatekrajz)
                {
                    mezooldal =oldalhossz(tabla.szels, tabla.mags, tablaszel, tablamag);

                    jatekrajz=true;
                }
                if (jatekrajz && !babutrak )
                {
                    tabla.mezo = (RubrikaAdatok**) malloc (tabla.szels*sizeof(RubrikaAdatok*));

                    for (int x = 0; x<tabla.szels; ++x)
                    {
                        tabla.mezo[x] =  (RubrikaAdatok*) malloc(tabla.mags*sizeof(RubrikaAdatok));

                    }
                    for( int x=0; x<tabla.szels; ++x)
                    {
                        for( int y=0; y<tabla.mags; ++y)
                        {
                            tabla.mezo[x][y].balfelsoX = 20+x*mezooldal;
                            tabla.mezo[x][y].balfelsoY = 20+y*mezooldal;
                            tabla.mezo[x][y].jobbalsoX = 20+(x+1)*mezooldal;
                            tabla.mezo[x][y].jobbalsoY = 20+(y+1)*mezooldal;
                            tabla.mezo[x][y].babu = ures;
                        }
                    }
                    if(kikezd==gep)
                    {
                        geprak (&strat,&tabla);
                    }
                    babutrak=true;
                }
                if (melyik%2==0)
                {
                    uj_jatek_e=true;
                }
                else
                {
                    tabla.mezo = jatek_betolt("amoba.txt", &tabla.szels, &tabla.mags, &strat, &kijon);
                    mezooldal =oldalhossz(tabla.szels, tabla.mags, tablaszel, tablamag);

                    jatekrajz=true;

                    for( int x=0; x<tabla.szels; ++x)
                    {
                        for( int y=0; y<tabla.mags; ++y)
                        {
                            tabla.mezo[x][y].balfelsoX = 20+x*mezooldal;
                            tabla.mezo[x][y].balfelsoY = 20+y*mezooldal;
                            tabla.mezo[x][y].jobbalsoX = 20+(x+1)*mezooldal;
                            tabla.mezo[x][y].jobbalsoY = 20+(y+1)*mezooldal;
                        }
                    }
                    babutrak=true;
                }
                break;
            }
            break;

        case SDL_QUIT:
            quit = true;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if(event.button.button == SDL_BUTTON_LEFT && babutrak==true && kijon%2==0 && (tabla.szels*tabla.mags)>kijon) //gep kezd, jatekos jon
            {
                //mindig:  gép:iksz ,  jatekos:kör
                for(int i=0; i<tabla.szels; ++i)
                {
                    for(int j=0; j<tabla.mags; ++j)
                    {
                        if(tabla.mezo[i][j].babu==ures &&
                                tabla.mezo[i][j].balfelsoX < event.motion.x &&
                                tabla.mezo[i][j].jobbalsoX > event.motion.x &&
                                tabla.mezo[i][j].balfelsoY < event.motion.y &&
                                tabla.mezo[i][j].jobbalsoY > event.motion.y)
                        {
                            tabla.mezo[i][j].babu=kor; //jatekos rak
                            nyert_e(&tabla, &kor_nyert, &x_nyert,&babutrak,&dontetlen);
                            if(x_nyert==false && kor_nyert==false )
                            {
                                kijon++;
                            }
                        }
                    }
                }
                if(kijon%2==1 && (tabla.szels*tabla.mags)>kijon)
                {
                    geprak(&strat,&tabla);
                    nyert_e(&tabla,&kor_nyert,&x_nyert, &babutrak, &dontetlen);
                    if(x_nyert==false && kor_nyert==false)
                        kijon++;
                }
            }
            if(event.button.button == SDL_BUTTON_LEFT &&
                    865<event.motion.x &&
                    1065>event.motion.x &&
                    250<event.motion.y &&
                    350>event.motion.y)
            {
                kor_nyert = false;
                x_nyert = false;
                dontetlen = false;
                SDL_SetRenderDrawColor (renderer, 0,0,0,255);
                SDL_RenderClear(renderer);

                for(int i=0; i<tabla.szels; i++)
                {
                    free(tabla.mezo[i]);
                }
                free (tabla.mezo);

                kijon=0;
                melyik=0;
                menulepteto=0;
                tabla.szels=5;
                tabla.mags=5;
                kikezd=gep;
                strat=konnyu;
                babutrak=false;
                uj_jatek_e=false;
                jatekrajz=false;

                fomenu(renderer, &melyik, &*gombtomb);
            }

            if(event.button.button == SDL_BUTTON_LEFT &&
                    865<event.motion.x &&
                    1065>event.motion.x &&
                    100<event.motion.y &&
                    200>event.motion.y &&
                    jatekrajz==true )
            {
                jatek_ment( "amoba.txt", &tabla, strat, kijon);
            }
            break;

        }
        SDL_RenderPresent(renderer);
    }
// itt rajzolunk ki a képernyõre mindent
    SDL_Event ev;
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT)
    {
    }
// ablak bezarasa
    SDL_Quit();

    if(babutrak || x_nyert || kor_nyert || dontetlen)
    {
        for(int i=0; i<tabla.szels; i++)
        {
            free(tabla.mezo[i]);
        }
        free (tabla.mezo);
    }

    return 0;
}
