#include "Read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sadece_oku(const char* dosya_ad, struct Canli *canli) {
    FILE *dosya = fopen(dosya_ad, "r");
    if (dosya == NULL) {
        perror("Dosya açma hatası");
        exit(EXIT_FAILURE);
    }
    int sayi;
    char satir[100]; // Maksimum satır uzunluğu
    int satir_sayisi = 1; // Toplam satır sayısı
    int toplam_sayi_sayisi = 0; // Toplam sayı sayısı

    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        // Her satır için satır sayısını bir arttır
       int i = 0;

        // Satırı boşluk karakterlerine göre parçala ve her bir sayıyı say
        char *token = strtok(satir, " ");
        int sayi_sayisi_satirda = 0; // Her satır için sayı sayısını sıfırla
        while (token != NULL) {
            // Her bir sayıyı ekrana yazdır
            sayi_sayisi_satirda++;
            i++;
            sayi = atoi(token);
            canli->TurBelirleEkle(canli,sayi,satir_sayisi,sayi_sayisi_satirda,i);
            // Her bir sayı için sayı sayısını bir arttır
           
            

            token = strtok(NULL, " "); // Sonraki sayıya geç
        }

        // Her satır için sayı sayısını toplam sayı sayısına ekle
       
        satir_sayisi++;
        // Her satırın sonunda bir alt satıra geç
      
    }
    
    // Toplam satır ve toplam sayı sayısını ekrana yazdır
  
    fclose(dosya);
}

void dosya_boyutu(const char* dosya_ad, struct Canli *canli) {
    FILE *dosya = fopen(dosya_ad, "r");
    if (dosya == NULL) {
        perror("Dosya açma hatası");
        exit(EXIT_FAILURE);
    }

    int satir_sayisi_temp = 0;
    int maksimum_sutun_sayisi_temp = 0;
    char *satir = NULL; // Dosyadan okunan her satırı tutacak dinamik dizi
    size_t satir_uzunlugu = 0; // Dosyadan okunan her satırın uzunluğunu tutacak değişken

    while (getline(&satir, &satir_uzunlugu, dosya) != -1) {
        satir_sayisi_temp++; // Her satır için satır sayısını bir arttır

        int sayi_sayisi_satirda = 0; // Her satır için sayı sayısını sıfırla

        // Satırı boşluk karakterlerine göre parçala ve her bir sayıyı say
        char *token = strtok(satir, " ");
        while (token != NULL) {
            sayi_sayisi_satirda++;
            token = strtok(NULL, " "); // Sonraki sayıya geç
        }

        // Maksimum sutun sayısını güncelle
        
            maksimum_sutun_sayisi_temp = sayi_sayisi_satirda;
        
    }

    fclose(dosya);
    free(satir); // Bellekte ayrılan alanı serbest bırak

    // Sonuçları dışarı aktar
    canli->MaxSatir = satir_sayisi_temp;
    canli->MaxSutun = maksimum_sutun_sayisi_temp;
}



Read* newRead() {
    // Bellekte Read yapısına yer ayır
    Read* read = (Read*)malloc(sizeof(Read));

    // Kurucu fonksiyon olarak atanmış olan fonksiyonu sıfırla
    read->sadece_oku = &sadece_oku;
    read->dosya_boyutu = &dosya_boyutu;
    return read;
}
// Sadece_oku fonksiyonunun gerçekleme detayı
void deleteRead(Read* read) {
    if (read == NULL) {
        return;
    }
    free(read); // Read yapısının belleğini serbest bırak
}