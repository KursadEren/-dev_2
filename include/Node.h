#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stddef.h>

typedef union Data {
    struct Bitki *bitki;
    struct Bocek *bocek;
    struct Sinek *sinek;
    struct Pire *pire;
} Data;

typedef struct Node {
    Data data;
    char NesneTipi;
    struct Node *next;
} Node;

Node* createNode(void *data, char NesneTipi, Node *next);

#endif
