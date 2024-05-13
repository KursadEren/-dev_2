#include "Canli.h"
#include "LinkedList.h"
#include <stdio.h> // printf fonksiyonunun bildirimi için gerekli başlık dosyası
#include <stdlib.h> 

// Canli yapısının oluşturucusu

// Canlinin canlı olup olmadığını kontrol eden işlev
int isItAlive(struct Node* deneme) {
    Node *current=deneme;
        if(current->NesneTipi == 'b'){
            return current->data.bitki->canli->live;
            
         
        }else if(current->NesneTipi == 's'){
            return current->data.sinek->bocek->canli->live;
        }else if(current->NesneTipi  == 'p'){
           return current->data.pire->bocek->canli->live;
        } else if(current->NesneTipi  == 'c'){
             return current->data.bocek->canli->live;
        }
}

void SetAlive(struct Node* pivot)
{
    Node * current = pivot;
        if(current->NesneTipi == 'b'){
           current->data.bitki->canli->live = 0;
        }else if(current->NesneTipi == 's'){
             current->data.sinek->bocek->canli->live = 0;
        }else if(current->NesneTipi  == 'p'){
            current->data.pire->bocek->canli->live=0;
        } else if(current->NesneTipi  == 'c'){
              current->data.bocek->canli->live=0;
        }

}
// Yapı turunu belirleyen işlev
void TurBelirleEkle(struct Canli *this, int sayi, int satir, int sutun, int sayi3) {
    printf("%d", 1);
    LinkedList *list = this->List;
    if (list == NULL) {
        // Mevcut bağlı liste yoksa, yeni bir tane oluştur
        list = createLinkedList();
        if (list == NULL) {
            return; // Bellek tahsisi başarısız oldu
        }
        this->List = list; // Oluşturulan bağlı listeyi Canli yapısının List üyesine ekle
    }

    // Gelen sayıya göre uygun öğeyi belirle ve bağlı listeye ekle
    void *data = NULL;
    char NesneTipi;

    if (1 <= sayi && sayi <= 9) {
        Bitki *bitki = newBitki(sayi, satir, sutun);
        data = (void *)bitki;
        NesneTipi = 'b';
    } else if (9 < sayi && sayi <= 20) {
        Bocek *bocek = newBocek(sayi, satir, sutun);
        data = (void *)bocek;
        NesneTipi = 'c';
    } else if (20 < sayi && sayi <= 50) {
        Sinek *sinek = newSinek(sayi, satir, sutun);
        data = (void *)sinek;
        NesneTipi = 's';
    } else if (50 < sayi && sayi <= 99) {
        Pire *pire = newPire(sayi, satir, sutun);
        data = (void *)pire;
        NesneTipi = 'p';
    }

    appendNode(list, data, NesneTipi);
}


// Bağlı listedeki türleri yazdırmak için fonksiyon
void printTurListesi(struct Canli *canli) {
    Node *current = canli->List->head;

    
       

}
int MaxSatirGetir(struct Canli* canli) {
    return canli->MaxSatir;
}

int MaxSutunGetir(struct Canli* canli) {
    return canli->MaxSutun;
}


Canli* newCanli() {
    Canli* this = (Canli*)malloc(sizeof(Canli));
    this->live = 1;
    this->MaxSatir=0;
    this->MaxSutun=0;
    
    
    this->List = NULL; // List başlangıçta boş olmalı
    this->TurBelirleEkle = &TurBelirleEkle; 
    this->MaxSatirGetir = &MaxSatirGetir;
    this->MaxSutunGetir = &MaxSutunGetir;
// İşlev işaretçisine doğrudan atama
    return this;
}

void deleteCanli(Canli* canli) {
    if (canli == NULL) {
        return;
    }

    // Bağlı listeyi temizle
    if (canli->List != NULL) {
        clearLinkedList(canli->List); // Bağlı listedeki tüm öğeleri serbest bırak
        free(canli->List); // Bağlı liste yapısını serbest bırak
    }

    // Canli yapısını serbest bırak
    free(canli);
}
