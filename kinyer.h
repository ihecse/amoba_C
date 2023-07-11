#ifndef KINYER_H_INCLUDED
#define KINYER_H_INCLUDED
#include <stdio.h>
#include "strukturak.h"
#include "debugmalloc.h"
#include <stdbool.h>

void gyoze_vsz(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak);
void gyoze_fg(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak);
void gyoze_eny(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak);
void gyoze_ek(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak);

void nyert_e(Tabla *tabla, bool *kor_nyert, bool *x_nyert, bool *babutrak, bool *dontetlen);

#endif // KINYER_H_INCLUDED
