#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>



LinkedList* createLinkedList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL; // Bellek tahsisi başarısız oldu
    }
    list->head = NULL;
    return list;
}
void printLinkedList(struct Node* root) {
    Node *temp = root;
  int satir = 0;
  int satirtakip =1;
  int sayma = 0;
  system("clear");
    while(temp != NULL ){
     
       

        if(temp->NesneTipi == 'b'){
            
           
            satir = temp->data.bitki->Satir;
            if(satir == satirtakip)
            {
                printf("\n");
                printf("\n");
                satirtakip++;
            }
             printf("%c  " ,temp->data.bitki->Tur);
              
        }
        else if(temp->NesneTipi == 's'){
            
            satir = temp->data.sinek->Satir;
             if(satir == satirtakip)
            {
                printf("\n");
                printf("\n");
                satirtakip++;
            }
            printf("%c  " ,temp->data.sinek->Tur);
            
        }else if(temp->NesneTipi  == 'p'){
            
            satir = temp->data.pire->Satir;
            if(satir == satirtakip)
            {
                printf("\n");
                printf("\n");
                satirtakip++;
            }
            printf("%c  " ,temp->data.pire->Tur);
             
        } else if(temp->NesneTipi  == 'c'){
           
           satir = temp->data.bocek->Satir;
           if(satir == satirtakip)
            {
                printf("\n");
                printf("\n");
                satirtakip++;
            }
            printf("%c  " ,temp->data.bocek->Tur);
            
        }
        
        temp = temp->next;
    }
   
    printf("\n");
}

void appendNode(LinkedList *list, void *data, char NesneTipi) {
    Node *newNode = createNode(data, NesneTipi, NULL);
    if (newNode == NULL) {
        return; // Bellek tahsisi başarısız oldu
    }
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    Node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void clearLinkedList(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}
