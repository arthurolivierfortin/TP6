#include "stdio.h"
#include <unistd.h>
#include "../src/util.h"
#include "malloc.h"
#include<string.h>
#include<stdlib.h>

#define HAUT
#define BAS
#define GAUCHE
#define DROITE


void main(){


    char p [100]= "Arthur-Olivier";

    printf("%c\n", *(p+1));
}