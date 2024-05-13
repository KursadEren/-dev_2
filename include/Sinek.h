#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

typedef struct Sinek {
    char Tur;
    struct Bocek *bocek;
    int Satir; 
    int Sutun;
    int Deger;
    int (*SinekDegerGetir)(struct Sinek *);
    int (*SinekSatirGetir)(struct Sinek *);
    int (*SinekSutunGetir)(struct Sinek *);
    char (*SinekTurGetir)(struct Sinek *);
} Sinek;

Sinek *newSinek(int sayi1, int sayi2, int sayi3);
void deleteSinek(Sinek* Sinek);
void SetSinekTur(Sinek* Sinek);
#endif
