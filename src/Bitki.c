#include "Bitki.h"
#include <stdlib.h>

int BitkiDegerGetir(struct Bitki *bitki) {
    return bitki->Deger;
}

int BitkiSatirGetir(struct Bitki *bitki) {
    return bitki->Satir;
}

int BitkiSutunGetir(struct Bitki *bitki) {
    return bitki->Sutun;
}

char BitkiTurGetir(struct Bitki *bitki) {
    return bitki->Tur;
}

Bitki *newBitki(int sayi1, int sayi2, int sayi3) {
    Bitki *this = (Bitki*)malloc(sizeof(Bitki));
    if (this == NULL) {
        return NULL; // Bellek tahsisi başarısız oldu
    }
    this->Tur = 'B';
    this->canli = newCanli();
    this->Satir = sayi2;
    this->Sutun = sayi3;
    this->Deger = sayi1;
    this->BitkiDegerGetir = &BitkiDegerGetir;
    this->BitkiSatirGetir = &BitkiSatirGetir;
    this->BitkiSutunGetir = &BitkiSutunGetir;
   
    return this;
}
void SetBitkiTur(struct Bitki* bitki){
    bitki->Tur = 'X';
}

void deleteBitki(Bitki* bitki) {
    if (bitki == NULL) {
        return;
    }
    // Dinamik olarak tahsis edilmiş olan 'canlii' yapısının belleğini serbest bırak
    deleteCanli(bitki->canli);
    free(bitki);
}