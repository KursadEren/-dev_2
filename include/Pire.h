#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

typedef struct Pire {
    char Tur;
    struct Bocek *bocek;
    int Satir; 
    int Sutun;
    int Deger;
    int (*PireDegerGetir)(struct Pire *);
    int (*PireSatirGetir)(struct Pire *);
    int (*PireSutunGetir)(struct Pire *);
    char (*PireTurGetir)(struct Pire *);
} Pire;

Pire *newPire(int sayi1, int sayi2, int sayi3);
void deletePire(struct Pire* pire);
void SetPireTur(struct Pire* Pire);
#endif
