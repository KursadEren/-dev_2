// main.c

#include "Read.h"
#include "Canli.h"
#include "Habitat.h"
#include <stdlib.h> // free() fonksiyonunu kullanabilmek için stdlib.h başlık dosyasını ekliyoruz

int main() {
   
    Read* read = newRead(); 
    Habitat * hab = newHabitat();
    
    
    Canli* canli = newCanli(); 
    
    read->sadece_oku("veriler.txt", canli); 
    read->dosya_boyutu("veriler.txt",canli);
   
   int i = canli->MaxSatirGetir(canli);
   int b = canli->MaxSutunGetir(canli);
   
    
   hab->Karsilastirma(canli);
    
   
   
   
    free(hab);
    free(read);
    free(canli);
    return 0;
}
