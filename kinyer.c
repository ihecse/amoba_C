#include "kinyer.h"

///vizszintesen
void gyoze_vsz(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak)
{
    for(int x=0; x<=(tabla->szels)-5; ++x)
    {
        for(int y=0; y<(tabla->mags); ++y)
        {
            int odb=0;
            int xdb=0;
            for(int k=0; k<5; ++k)
            {
                if((tabla->mezo)[x+k][y].babu==kor)
                {
                    odb++;
                }
                if((tabla->mezo)[x+k][y].babu==iksz)
                {
                    xdb++;
                }
            }
            if(odb==5)
            {
                *kor_nyert=true;
                *babutrak=false;
            }
            if(xdb==5)
            {
                *x_nyert=true;
                *babutrak=false;
            }
        }
    }
}
void gyoze_fg(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak)
{
    for(int x=0; x<tabla->szels; ++x)
    {
        for(int y=0; y<=(tabla->mags)-5; ++y)
        {
            int odb=0;
            int xdb=0;
            for(int k=0; k<5; ++k)
            {
                if((tabla->mezo)[x][y+k].babu==kor)
                {
                    odb++;
                }
                if((tabla->mezo)[x][y+k].babu==iksz)
                {
                    xdb++;
                }
            }
            if(odb==5)
            {
                *kor_nyert=true;
                *babutrak=false;
            }
            if(xdb==5)
            {
                *x_nyert=true;
                *babutrak=false;
            }
        }
    }
}
void gyoze_eny(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak)
{
    for(int x=0; x<=(tabla->szels)-5; ++x)
    {
        for(int y=0; y<=(tabla->mags)-5; ++y)
        {
            int odb=0;
            int xdb=0;
            for(int k=0; k<5; ++k)
            {
                if((tabla->mezo)[x+k][y+k].babu==kor)
                {
                    odb++;
                }
                if((tabla->mezo)[x+k][y+k].babu==iksz)
                {
                    xdb++;
                }
            }
            if(odb==5)
            {
                *kor_nyert=true;
                *babutrak=false;
            }
            if(xdb==5)
            {
                *x_nyert=true;
                *babutrak=false;
            }
        }
    }
}
void gyoze_ek(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak)
{
    for(int x=4; x<(tabla->szels); ++x)
    {
        for(int y=0; y<=(tabla->mags)-5; ++y)
        {
            int odb=0;
            int xdb=0;
            for(int k=0; k<5; ++k)
            {
                if((tabla->mezo)[x-k][y+k].babu==kor)
                {
                    odb++;
                }
                if((tabla->mezo)[x-k][y+k].babu==iksz)
                {
                    xdb++;
                }
            }
            if(odb==5)
            {
                *kor_nyert=true;
                *babutrak=false;
            }
            if(xdb==5)
            {
                *x_nyert=true;
                *babutrak=false;
            }
        }
    }
}

void nyert_e(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak, bool *dontetlen)
{
    gyoze_ek(tabla,kor_nyert,x_nyert,babutrak);
    gyoze_eny(tabla,kor_nyert,x_nyert,babutrak);
    gyoze_vsz(tabla,kor_nyert,x_nyert,babutrak);
    gyoze_fg(tabla,kor_nyert,x_nyert,babutrak);

    int db=0;
    for(int x=0; x<tabla->szels; x++)
    {
        for(int y=0; y<tabla->mags; y++)
        {
            if((tabla->mezo)[x][y].babu==ures)
                db++;
        }
    }
    if(db==0 && *x_nyert==false && *kor_nyert==false)
    {
        *dontetlen=true;
    }
}
