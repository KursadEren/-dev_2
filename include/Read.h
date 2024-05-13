#ifndef READ_H
#define READ_H
#include "Canli.h"
// Soyut sınıf benzetimi için yapı tanımı
typedef struct {
    
  
     
    void (*sadece_oku)(const char* dosya_ad,struct Canli * canli);
    void (*dosya_boyutu)(const char* dosya_ad,struct Canli * canli);
} Read;
Read* newRead();
void deleteRead(Read* read);
// Soyut fonksiyonun prototipi


#endif
