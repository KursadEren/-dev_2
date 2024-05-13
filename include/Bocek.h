#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

typedef struct Bocek {
    char Tur;
    struct Canli *canli;
    int Satir;
    int Sutun;
    int Deger;
    int (*BocekDegerGetir)(struct Bocek *);
    int (*BocekSatirGetir)(struct Bocek *);
    int (*BocekSutunGetir)(struct Bocek *);
    char (*BocekTurGetir)(struct Bocek *);
} Bocek;

Bocek *newBocek(int sayi1, int sayi2, int sayi3);
void deleteBocek(Bocek* Bocek);
void SetBocekTur(struct Bocek* );

#endif
