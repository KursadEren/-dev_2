#include "Node.h"

// Düğüm oluşturma fonksiyonu
Node* createNode(void *data, char NesneTipi, Node *next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL; // Bellek tahsisi başarısız oldu
    }
    newNode->NesneTipi = NesneTipi;
    switch (NesneTipi) {
        case 'b':
            newNode->data.bitki = (struct Bitki *)data;
            break;
        case 'c':
            newNode->data.bocek = (struct Bocek *)data;
            break;
        case 's':
            newNode->data.sinek = (struct Sinek *)data;
            break;
        case 'p':
            newNode->data.pire = (struct Pire *)data;
            break;
        default:
            free(newNode); // Belleği serbest bırak
            return NULL;
    }
     // Veriye uygun olarak union'ı güncelle
    newNode->next = next;
    return newNode;
}
