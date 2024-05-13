#include "Bocek.h"
#include <stdlib.h>

int BocekDegerGetir(Bocek *bocek) {
    return bocek->Deger;
}

int BocekSatirGetir(Bocek *bocek) {
    return bocek->Satir;
}

int BocekSutunGetir(Bocek *bocek) {
    return bocek->Sutun;
}

char BocekTurGetir(Bocek *bocek) {
    return bocek->Tur;
}

Bocek *newBocek(int sayi1, int sayi2, int sayi3) {
    Bocek *bocek = (Bocek *)malloc(sizeof(Bocek));
    if (bocek == NULL) {
        return NULL; // Bellek tahsisi başarısız oldu
    }
    bocek->Tur = 'C';
    bocek->canli = newCanli();
    bocek->Satir = sayi2;
    bocek->Sutun = sayi3;
    bocek->Deger = sayi1;
    bocek->BocekDegerGetir = &BocekDegerGetir;
    bocek->BocekSatirGetir = &BocekSatirGetir;
    bocek->BocekSutunGetir = &BocekSutunGetir;
    bocek->BocekTurGetir = &BocekTurGetir;
    return bocek;
}
void SetBocekTur(struct Bocek* bocek){
    bocek->Tur = 'X';
}

void deleteBocek(Bocek* bocek) {
    if (bocek == NULL) {
        return;
    }
    // Dinamik olarak tahsis edilmiş olan 'canli' yapısının belleğini serbest bırak
    deleteCanli(bocek->canli);
    free(bocek);
}
