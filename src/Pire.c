#include "Pire.h"
#include <stdlib.h>

int PireDegerGetir(Pire *pire) {
    return pire->Deger;
}

int PireSatirGetir(Pire *pire) {
    return pire->Satir;
}

int PireSutunGetir(Pire *pire) {
    return pire->Sutun;
}

char PireTurGetir(Pire *pire) {
    return pire->Tur;
}

Pire *newPire(int sayi1, int sayi2, int sayi3) {
    Pire *pire = (Pire *)malloc(sizeof(Pire));
    if (pire == NULL) {
        return NULL; // Bellek tahsisi başarısız oldu
    }
    pire->Tur = 'P';
    pire->bocek = newBocek(sayi1, sayi2, sayi3);
    pire->Satir = sayi2;
    pire->Sutun = sayi3;
    pire->Deger = sayi1;
    pire->PireDegerGetir = &PireDegerGetir;
    pire->PireSatirGetir = &PireSatirGetir;
    pire->PireSutunGetir = &PireSutunGetir;
    pire->PireTurGetir = &PireTurGetir;
    return pire;
}
void SetPireTur(struct Pire* pire){
    pire->Tur = 'X';
}

void deletePire(Pire* pire) {
    if (pire == NULL) {
        return;
    }
    // Dinamik olarak tahsis edilmiş olan 'canli' yapısının belleğini serbest bırak
    deleteCanli(pire->bocek->canli);
    free(pire->bocek); // İlgili Bocek yapısının belleğini serbest bırak
    free(pire);
}
