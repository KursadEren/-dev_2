#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

typedef struct Bitki {
    char Tur;
    struct Canli *canli;
    int Satir;
    int Sutun;
    int Deger;
    int (*BitkiDegerGetir)(struct Bitki *);
    int (*BitkiSatirGetir)(struct Bitki *);
    int (*BitkiSutunGetir)(struct Bitki *);
    
} Bitki;

Bitki *newBitki(int sayi1, int sayi2, int sayi3);
void deleteBitki(Bitki* bitki);
void SetBitkiTur(struct Bitki* Bitki);
char BitkiTurGetir(struct Bitki *);
#endif
