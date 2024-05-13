#include "Habitat.h"
#include <stdio.h> // printf fonksiyonunun bildirimi için gerekli başlık dosyası
#include <stdlib.h> 

#include <unistd.h>
int Kontrol(struct Canli *Canli){
        return 0;
}

void bekleyenTus() {
    struct termios eski, yeni;
    tcgetattr(STDIN_FILENO, &eski);
    yeni = eski;
    yeni.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &yeni);
    getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &eski);
}

Node* savas(struct Node * pivot , struct Node* pivot2){
        Node *current = pivot;
        Node* current2 = pivot2;
        Node * kazanan = pivot;
       
        if(current->NesneTipi == 'b'){
            
             if(current2->NesneTipi == 'b'){
                 if(current->data.bitki->Deger >current2->data.bitki->Deger )
                 {
                   SetAlive(current2);
                   
                   SetBitkiTur(current2->data.bitki);
                   
                   return current;
                 }
                 else if(current2->data.bitki->Deger > current->data.bitki->Deger){
                    SetAlive(current);
                   SetBitkiTur(current->data.bitki);
                  
                   return current2;
                 }
                 if(current2->data.bitki->Deger == current->data.bitki->Deger){
                    if(current2->data.bitki->Satir > current->data.bitki->Satir ){
                         SetAlive(current2);
                         SetBitkiTur(current2->data.bitki);
                         
                         return current;
                    }else if(current->data.bitki->Satir > current2->data.bitki->Satir )
                    {
                         SetAlive(current);
                         SetBitkiTur(current->data.bitki);
                         
                         return current2;
                    }
                    else if(current->data.bitki->Satir == current2->data.bitki->Satir )
                    {
                        if(current->data.bitki->Sutun > current2->data.bitki->Sutun ){
                            SetAlive(current);
                         SetBitkiTur(current->data.bitki);
                        
                         return current2;
                        }
                        else if(current2->data.bitki->Sutun > current->data.bitki->Sutun ){
                        SetAlive(current2);
                         SetBitkiTur(current2->data.bitki);
                         
                         return current;
                        }
                    }
                 }
             }else if(current2->NesneTipi == 's'){
                SetAlive(current2);
                SetSinekTur(current2->data.sinek);
               
                return current;
             }else if(current2->NesneTipi  == 'p'){
               SetAlive(current2);
              
                SetPireTur(current2->data.pire);
                
                return current;
             } else if(current2->NesneTipi  == 'c'){
                    SetAlive(current);
        
                  SetBitkiTur(current->data.bitki);
                 
                return current2;
             }


        }else if(current->NesneTipi == 's'){
            
                 if(current2->NesneTipi == 'b'){
                        SetAlive(current);             
                        SetSinekTur(current->data.sinek);
                        
                        return current2;
                 }
                 else if(current2->NesneTipi == 's'){


                if(current->data.sinek->Deger >current2->data.sinek->Deger )
                 {
                   SetAlive(current2);
                   SetSinekTur(current2->data.sinek);
                   
                   return current;
                 }
                 else if(current2->data.sinek->Deger > current->data.sinek->Deger){
                    SetAlive(current);
                   SetSinekTur(current->data.sinek);
                  
                   return current2;
                 }
                 if(current2->data.sinek->Deger == current->data.sinek->Deger){
                    //
                    if(current2->data.sinek->Satir > current->data.sinek->Satir ){
                         SetAlive(current2);
                         SetSinekTur(current2->data.sinek);
                         
                         return current;
                    }//
                    else if(current->data.sinek->Satir > current2->data.sinek->Satir )
                    {
                         SetAlive(current);
                         SetSinekTur(current->data.sinek);
                         
                         return current2;
                    }
                    //
                    else if(current->data.sinek->Satir == current2->data.sinek->Satir )
                    {
                        //
                        if(current->data.sinek->Sutun > current2->data.sinek->Sutun ){
                            SetAlive(current);
                         SetSinekTur(current->data.sinek);
                         
                         return current2;
                        }
                        else if(current2->data.sinek->Sutun > current->data.sinek->Sutun ){
                        SetAlive(current2);
                         SetSinekTur(current2->data.sinek);
                         
                         return current;
                        }
                    }
                 }

                    
             
                 }else if(current2->NesneTipi  == 'p'){
                        SetAlive(current2);             
                        SetPireTur(current2->data.pire);
                        
                        return current;
                 } else if(current2->NesneTipi  == 'c'){
                        SetAlive(current2);             
                        SetBocekTur(current2->data.bocek);
                        
                        return current;
                 }
             
        }
        /////
        else if(current->NesneTipi  == 'p'){

                if(current2->NesneTipi == 'b'){
                        SetAlive(current);             
                        SetPireTur(current->data.pire);
                       
                        return current2;
                }//
                else if(current2->NesneTipi == 's'){
                       SetAlive(current);             
                        SetPireTur(current->data.pire);
                       
                        return current2;
                 }//
                 else if(current2->NesneTipi  == 'p'){

                          if(current->data.pire->Deger >current2->data.pire->Deger )
                             {  
                                     SetAlive(current2);
                                     SetPireTur(current2->data.pire);
                                     
                            return current;
                            }

                            else if(current2->data.pire->Deger > current->data.pire->Deger)
                            {
                                     SetAlive(current);
                                     SetPireTur(current->data.pire);
                                     
                                     return current2;
                            }

                        if(current2->data.pire->Deger == current->data.pire->Deger)
                         {
                    //
                                 if(current2->data.pire->Satir > current->data.pire->Satir ){
                                     SetAlive(current2);
                                     SetPireTur(current2->data.pire);
                                     
                                    return current;
                                 }//
                                 else if(current->data.pire->Satir > current2->data.pire->Satir )
                                 {
                                         SetAlive(current);
                                         SetPireTur(current->data.pire);
                                         
                                         return current2;
                                  }
                    //
                                     else if(current->data.pire->Satir == current2->data.pire->Satir )
                                  {
                        //
                                if(current->data.pire->Sutun > current2->data.pire->Sutun ){
                                         SetAlive(current);
                                         SetPireTur(current->data.pire);
                                         
                                         return current2;
                                }
                                else if(current2->data.pire->Sutun > current->data.pire->Sutun ){
                                         SetAlive(current2);
                                         SetPireTur(current2->data.pire);
                                         
                                         return current;
                                }
                            }
                         }


                            


                 }//
                  else if(current2->NesneTipi  == 'c'){
                        SetAlive(current);             
                        SetPireTur(current->data.pire);
                        
                        return current2;
                 }
            
        } 
        ///
        else if(current->NesneTipi  == 'c'){
                if(current2->NesneTipi == 'b'){ // bocek kazandı
                        SetAlive(current2);             
                        SetBitkiTur(current2->data.bitki);
                        
                        return current;
                 }
                 else if(current2->NesneTipi == 's'){ //Sinek kazandı
                        SetAlive(current);             
                        SetBocekTur(current->data.bocek);
                        
                        return current2;
                 }else if(current2->NesneTipi  == 'p'){
                        SetAlive(current2);             
                        SetPireTur(current2->data.pire);
                        
                        return current;
            
                 } else if(current2->NesneTipi  == 'c'){



                         if(current->data.bocek->Deger > current2->data.bocek->Deger )
                             {  
                                     SetAlive(current2);
                                     SetBocekTur(current2->data.bocek);
                                   
                               return current;
                            }

                            else if(current2->data.bocek->Deger > current->data.bocek->Deger)
                            {
                                     SetAlive(current);
                                     SetBocekTur(current->data.bocek);
                                     
                                     return current2;
                            }

                                if(current2->data.bocek->Deger == current->data.bocek->Deger)
                                {
                    //
                                 if(current2->data.bocek->Satir > current->data.bocek->Satir ){
                                     SetAlive(current2);
                                     SetBocekTur(current2->data.bocek);
                                     
                                    return current;
                                 }//
                                 else if(current->data.bocek->Satir > current2->data.bocek->Satir )
                                 {
                                         SetAlive(current);
                                         SetBocekTur(current->data.bocek);
                                         
                                         return current2;
                                  }
                    //
                                     else if(current->data.pire->Satir == current2->data.pire->Satir )
                                  {
                        //
                                if(current->data.bocek->Sutun > current2->data.bocek->Sutun ){
                                         SetAlive(current);
                                         SetBocekTur(current->data.bocek);
                                         
                                         return current2;
                                }
                                else if(current2->data.bocek->Sutun > current->data.bocek->Sutun ){
                                         SetAlive(current2);
                                         SetBocekTur(current2->data.bocek);
                                         
                                         return current;
                                }
                    }
                 }




                 }
           
        }

        /*if(current->NesneTipi == 'b'){

        }
        else if(current->NesneTipi == 's'){
             
        }else if(current->NesneTipi  == 'p'){
            
        } else if(current->NesneTipi  == 'c'){
           
        }*/

}

void Karsilastirma(struct Canli *canli) {
   
    Node *current = canli->List->head->next;
    Node *pivot = canli->List->head;
    int sayma = 0;
     while(current != NULL ){
      int kabul =0;
      
     while (current != NULL && current->next != NULL) {
       
    
       if(sayma ==0)
       {
        printf("\n");
        printLinkedList(canli->List->head);
        printf("devam etmek için bir tuşa tıklayınız ");
        bekleyenTus();
        sayma++;
       }
    
    
    if (current->NesneTipi == 'b') {
         kabul = isItAlive(current);
    } else if (current->NesneTipi == 's') {
        kabul = isItAlive(current);
    } else if (current->NesneTipi == 'p') {
        kabul = isItAlive(current);
    } else if (current->NesneTipi == 'c') {
        kabul = isItAlive(current); 
    }
    
    if (kabul == 1) {
        kabul = 0;
        break;
      
        
    }
    
   
    
    }
    pivot =savas(pivot,current);
    current = current->next;
    printLinkedList(canli->List->head);
}
printf("\n");
printf("\n");
printf("\n");
if (pivot->NesneTipi == 'b') {
            printf("Kazanan: %c  (%d,%d)",  pivot->data.bitki->Tur,pivot->data.bitki->Satir,pivot->data.bitki->Sutun);
    } else if (pivot->NesneTipi == 's') {
          printf("Kazanan: %c  (%d,%d)" ,pivot->data.sinek->Tur,pivot->data.sinek->Satir,pivot->data.sinek->Sutun);
    } else if (pivot->NesneTipi == 'p') {
          printf("Kazanan: %c  (%d,%d)" ,pivot->data.pire->Tur,pivot->data.pire->Satir,pivot->data.pire->Sutun);
    } else if (pivot->NesneTipi == 'c') {
          printf("Kazanan: %c  (%d,%d)" ,pivot->data.bocek->Tur,pivot->data.bocek->Satir,pivot->data.bocek->Sutun);
    }
 
 printf("\n");
 printf("\n"); 
}

Habitat * newHabitat() {
    Habitat* this = (Habitat*)malloc(sizeof(Habitat));
    this->Karsilastirma=&Karsilastirma;
    this->Kontrol=&Kontrol;
    this->savas=&savas; // doğru fonksiyonu işaret etmeli
    return this;
}
