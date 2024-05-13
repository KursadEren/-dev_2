#include "Sinek.h"
#include <stdlib.h>

int SinekDegerGetir(Sinek *sinek) {
    return sinek->Deger;
}

int SinekSatirGetir(Sinek *sinek) {
    return sinek->Satir;
}

int SinekSutunGetir(Sinek *sinek) {
    return sinek->Sutun;
}

char SinekTurGetir(Sinek *sinek) {
    return sinek->Tur;
}

Sinek *newSinek(int sayi1, int sayi2, int sayi3) {
    Sinek *sinek = (Sinek *)malloc(sizeof(Sinek));
    if (sinek == NULL) {
        return NULL; // Bellek tahsisi başarısız oldu
    }
    sinek->Tur = 'S';
    sinek->bocek = newBocek(sayi1, sayi2, sayi3);
    sinek->Satir = sayi2;
    sinek->Sutun = sayi3;
    sinek->Deger = sayi1;
    sinek->SinekDegerGetir = &SinekDegerGetir;
    sinek->SinekSatirGetir = &SinekSatirGetir;
    sinek->SinekSutunGetir = &SinekSutunGetir;
    sinek->SinekTurGetir = &SinekTurGetir;
    return sinek;
}
void SetSinekTur(struct Sinek* sinek){
    sinek->Tur = 'X';
}

void deleteSinek(Sinek* sinek) {
    if (sinek == NULL) {
        return;
    }
    // Dinamik olarak tahsis edilmiş olan 'canli' yapısının belleğini serbest bırak
    deleteCanli(sinek->bocek->canli);
    free(sinek->bocek); // İlgili Bocek yapısının belleğini serbest bırak
    free(sinek);
}