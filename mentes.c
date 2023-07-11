#include "mentes.h"

void jatek_ment( char const *fajlnev,Tabla *tabla,int strat,int kijon)
{
    FILE *fp;
    fp = fopen(fajlnev, "w");
     if (fp == NULL){
         perror("Nem sikerult fajlt megnyitni!");
         }
    fprintf(fp, "%d ", tabla->mags);
    fprintf(fp, "%d ", tabla->szels);
    fprintf(fp, "%d\n", strat);
    fprintf(fp, "%d\n", kijon);
    for (int x = 0; x < tabla->szels; ++x)
    {
        for (int y = 0; y < tabla->mags; ++y)
        {
            fprintf(fp, "%d ", tabla->mezo[x][y].babu);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

RubrikaAdatok **jatek_betolt(char const *fajlnev, int *szels, int *mags,int *strat,int *kijon)
{
    FILE *fp;
    fp = fopen(fajlnev, "r");

    if (fp == NULL){
        perror("Nem sikerult beolvasasra nyitni a fajlt!");
    }
    fscanf(fp, "%d ", mags);
    fscanf(fp, "%d ", szels);
    fscanf(fp, "%d\n", strat);
    fscanf(fp, "%d\n", kijon);

    RubrikaAdatok **uj;
    uj = (RubrikaAdatok**) malloc (*szels * sizeof(RubrikaAdatok*));
    for (int x = 0; x<(*szels); ++x)
    {
        uj[x] = (RubrikaAdatok*) malloc(*mags*sizeof(RubrikaAdatok));
    }
int tarol;
    for (int x = 0; x < *szels; ++x)
    {
        for (int y = 0; y < *mags; ++y)
        {
            fscanf(fp, "%d ",  &tarol);
            uj[x][y].babu = tarol;
        }
        fscanf(fp, "\n");
    }
    fclose(fp);
    return uj;
}
