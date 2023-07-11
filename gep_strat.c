#include "gep_strat.h"

ListaElem * lista_elejere_beszur(ListaElem *eleje, RubrikaAdatok *mezo)
{
    ListaElem *uj;
    uj = (ListaElem*) malloc(sizeof(ListaElem));
    uj->adat = mezo;
    uj->kov = eleje;
    return uj;
}
void lista_felszabadit(ListaElem* eleje)
{
    while (eleje!=NULL)
    {
        ListaElem *temp = eleje->kov;
        free(eleje);
        eleje =temp;
    }
}

int lista_hossz (ListaElem *lista)
{
    int db=0;
    for(ListaElem* i=lista; i!=NULL; i=i->kov)
    {
        db++;
    }
    return db;
}

void vizszintes_vedekez (Tabla *tabla, ListaElem **veszelyes_mezo)
{
    for(int x=0; x<=(tabla->szels)-4; ++x)
    {
        for(int y=0; y<(tabla->mags); ++y)
        {
            int db=0;

            for(int k=0; k<4; ++k)
            {
                if(tabla->mezo[x+k][y].babu==kor)
                {
                    db++;
                }

            }
            if(db==3)
            {
                for(int k=0; k<4; ++k)
                {
                    if(tabla->mezo[x+k][y].babu==ures)
                    {
                        *veszelyes_mezo =  lista_elejere_beszur(*veszelyes_mezo, &(tabla->mezo)[x+k][y]);
                    }
                }
            }
        }
    }
}
void fuggoleges_vedekez(Tabla *tabla,  ListaElem **veszelyes_mezo)
{

    for(int x=0; x<(tabla->szels); ++x)
    {
        for(int y=0; y<=(tabla->mags)-4; ++y)
        {
            int db=0;
            for(int k=0; k<4; ++k)
            {
                if(tabla->mezo[x][y+k].babu==kor)
                {
                    db++;
                }
            }


            if(db==3)
            {
                for (int k=0; k<4; ++k)
                {
                    if (tabla->mezo[x][y+k].babu==ures)
                    {
                        *veszelyes_mezo =  lista_elejere_beszur(*veszelyes_mezo,&tabla->mezo[x][y+k]);

                    }
                }

            }
        }
    }
}
void eny_vedekez(Tabla * tabla,  ListaElem **veszelyes_mezo)
{
    for(int x=0; x<=(tabla->szels)-4; ++x)
    {
        for(int y=0; y<=(tabla->mags)-4; ++y)
        {
            int db=0;
            for(int k=0; k<4; ++k)
            {
                if(tabla->mezo[x+k][y+k].babu==kor)
                {
                    db++;
                }
            }

            if(db==3)
            {
                for (int k=0; k<4; ++k)
                {
                    if (tabla->mezo[x+k][y+k].babu==ures)
                    {
                        *veszelyes_mezo =  lista_elejere_beszur(*veszelyes_mezo,&tabla->mezo[x+k][y+k]);

                    }
                }
            }
        }
    }
}
void ek_vedekez(Tabla * tabla,  ListaElem **veszelyes_mezo)
{
    for(int x=3; x<(tabla->szels); ++x)
    {
        for(int y=0; y<=(tabla->mags)-4; ++y)
        {
            int db=0;
            for(int k=0; k<4; ++k)
            {
                if(tabla->mezo[x-k][y+k].babu==kor)
                {
                    db++;
                }
            }
            if(db==3)
            {
                for (int k=0; k<4; ++k)
                {
                    if (tabla->mezo[x-k][y+k].babu==ures)
                    {
                        *veszelyes_mezo =  lista_elejere_beszur(*veszelyes_mezo,&tabla->mezo[x-k][y+k]);

                    }
                }
            }
        }
    }
}

void vizszintes_tamad(Tabla * tabla,  ListaElem **tamado_mezok, int *szam)
{
    for(int x=0; x<=((tabla->szels)-(*szam)); ++x)
    {
        for(int y=0; y<(tabla->mags); ++y)
        {
            int db=0;
            for (int k=0; k<(*szam); ++k)
            {
                if(tabla->mezo[x+k][y].babu == iksz)
                {
                    db++;
                }
            }
            if(db==(*szam)-1)
            {
                for(int k=0; k<(*szam); ++k)
                {
                    if(tabla->mezo[x+k][y].babu == ures)
                    {
                        *tamado_mezok = lista_elejere_beszur(*tamado_mezok,&tabla->mezo[x+k][y]);
                    }
                }
            }
        }
    }
}
void fuggoleges_tamad(Tabla * tabla,  ListaElem **tamado_mezok, int* szam)
{
    for(int x=0; x<(tabla->szels); ++x)
    {
        for(int y=0; y<=(tabla->mags)-(*szam); ++y)
        {
            int db=0;
            for (int k=0; k<(*szam); ++k)
            {
                if(tabla->mezo[x][y+k].babu == iksz)
                {
                    db++;
                }
            }
            if(db==(*szam)-1)
            {
                for(int k=0; k<(*szam); ++k)
                {
                    if(tabla->mezo[x][y+k].babu == ures)
                    {
                        *tamado_mezok = lista_elejere_beszur(*tamado_mezok, &tabla->mezo[x][y+k]);
                    }
                }
            }
        }
    }
}

void eny_tamad(Tabla * tabla,  ListaElem **tamado_mezok, int *szam)
{
    for(int x=0; x<=(tabla->szels)-(*szam); ++x)
    {
        for(int y=0; y<=(tabla->mags)-(*szam); ++y)
        {
            int db=0;
            for (int k=0; k<(*szam); ++k)
            {
                if(tabla->mezo[x+k][y+k].babu == iksz)
                {
                    db++;
                }
            }
            if(db==(*szam)-1)
            {
                for(int k=0; k<(*szam); ++k)
                {
                    if(tabla->mezo[x+k][y+k].babu == ures)
                    {
                        *tamado_mezok = lista_elejere_beszur(*tamado_mezok, &tabla->mezo[x+k][y+k]);
                    }
                }
            }
        }
    }
}
void ek_tamad(Tabla * tabla,  ListaElem **tamado_mezok, int *szam)
{
    for(int x=(*szam); x<(tabla->szels); ++x)
    {
        for(int y=0; y<=(tabla->mags)-(*szam); ++y)
        {
            int db=0;
            for (int k=0; k<(*szam); ++k)
            {
                if(tabla->mezo[x-k][y+k].babu == iksz)
                {
                    db++;
                }
            }
            if(db==(*szam)-1)
            {
                for(int k=0; k<(*szam); ++k)
                {
                    if(tabla->mezo[x-k][y+k].babu == ures)
                    {
                        *tamado_mezok = lista_elejere_beszur(*tamado_mezok, &tabla->mezo[x-k][y+k]);
                    }
                }
            }
        }
    }
}
void epito_tamado(Tabla * tabla,  ListaElem **tamado_mezok,int *szam)
{
    vizszintes_tamad(tabla,tamado_mezok,szam);
    fuggoleges_tamad(tabla,tamado_mezok,szam);
    eny_tamad(tabla,tamado_mezok,szam);
    ek_tamad(tabla,tamado_mezok,szam);
}

void ved_akadalyoz(Tabla *tabla, ListaElem **veszelyes_mezo)
{
    vizszintes_vedekez (tabla,veszelyes_mezo);
    fuggoleges_vedekez (tabla,veszelyes_mezo);
    eny_vedekez(tabla,veszelyes_mezo);
    ek_vedekez (tabla,veszelyes_mezo);
}

void epito(Tabla *tabla)
{
    ListaElem *tamado_mezok = NULL;
    int szam=5;
    while(tamado_mezok==NULL)
    {
        epito_tamado(tabla,&tamado_mezok,&szam);
        szam--;
    }
    if(tamado_mezok == NULL)
    {
        int rszel = rand()%(tabla->szels);
        int rmag = rand()%(tabla->mags);
        while (tabla->mezo[rszel][rmag].babu != ures)
        {
            rszel = rand()%(tabla->szels);
            rmag = rand()%(tabla->mags);
        }
        tabla->mezo[rszel][rmag].babu = iksz;
    }
    else
    {
        int elemszam = lista_hossz(tamado_mezok);
        int ran = rand()%elemszam;
        struct ListaElem *rak = tamado_mezok;
        for (int i =0; i<ran; i++)
        {
            rak = rak->kov;
        }
        rak->adat->babu = iksz;
    }
    lista_felszabadit(tamado_mezok);
}

void akadalyozo(Tabla *tabla)
{
    ListaElem *veszelyes_mezo =  NULL;
    ved_akadalyoz(tabla,&veszelyes_mezo);

    ListaElem *tamado_mezok = NULL;
    int szam = 5;
    epito_tamado(tabla, &tamado_mezok, &szam);
    if(veszelyes_mezo != NULL)
    {
        if(tamado_mezok == NULL)
        {
            // potencialisan veszelyes mezok egyikere rak
            int elemszam = lista_hossz(veszelyes_mezo);
            int ran = rand()%elemszam;
            struct ListaElem *rak = veszelyes_mezo;
            for (int i = 0; i<ran; i++)
            {
                rak = rak->kov;
            }
            rak->adat->babu = iksz;
        }

        if(tamado_mezok != NULL)
        {
            int elemszam = lista_hossz(tamado_mezok);
            int ran = (rand()%elemszam);
            struct ListaElem *rak = tamado_mezok;
            for (int i =0; i<ran; i++)
            {
                rak = rak->kov;
            }
            rak->adat->babu = iksz;
        }
    }
    else //ha nincs potencialisan veszelyes mezo, akkor magat epiti
    {
        epito(tabla);
    }

    lista_felszabadit(tamado_mezok);
    lista_felszabadit(veszelyes_mezo);
}
void geprak( int *strat, Tabla *tabla)
{
    switch (*strat)
    {
    case nehez:

        akadalyozo(tabla);
        break;

    case konnyu:
        epito(tabla);
        break;

    case kozepes:
        if(rand()%100<50)
        {
            akadalyozo(tabla);
        }
        else
        {
            epito(tabla);
        }
        break;
    }
}
