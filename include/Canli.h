#ifndef CANLI_H
#define CANLI_H

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h> 
// Soyut sınıf benzetimi için yapı tanımı
typedef struct Canli {
    struct LinkedList *List;
     // canlinin canlı olup olmadığını kontrol eden işlev
    int live;
    int MaxSatir;
    int MaxSutun;
    int (*MaxSatirGetir)(struct Canli* );
    int (*MaxSutunGetir)(struct Canli* );
    void (*TurBelirleEkle)(struct Canli*, int, int, int,int); // Yapı turunu belirleyen işlev
} Canli;

// Canli yapısının oluşturucusu
Canli* newCanli();
void printTurListesi(struct Canli *canli);
void deleteCanli(Canli* canli);
void SetAlive(struct Node*);
int isItAlive(struct Node*);
#endif
