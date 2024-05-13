#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
typedef struct LinkedList {
   struct Node *head;
} LinkedList;

// Bağlı listeyi oluşturacak işlev
LinkedList* createLinkedList();

// Yeni bir düğümü bağlı listeye ekleyecek işlevler
void appendNode(LinkedList *list, void *data, char NesneTipi);
void printLinkedList(struct Node *);
// Bağlı listeyi temizleyecek işlev
void clearLinkedList(LinkedList *list);

#endif
