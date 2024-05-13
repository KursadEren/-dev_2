#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"
#include "Sinek.h"
#include "Pire.h"
#include "Bocek.h"
#include "Bitki.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

typedef struct Habitat {
   
    
    void (*Karsilastirma)(struct Canli *);
    int (*Kontrol)(struct Canli *);
    struct Node* (*savas)(struct Node*,struct Node*);
} Habitat;
void bekleyenTus();
Habitat *newHabitat();

#endif
