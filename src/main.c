#include "stdio.h"
#include <unistd.h>
#include "util.h"
#include "malloc.h"
#include<string.h>
#include<stdlib.h>

NewVol *vol;
void main(){
    
    
    
    int choix = choisir();
    printf("%d\n", choix);
    
    if(choix == 49){ //49 == 1
        vol = CreateVol();
        
        printVol(vol);


    }
}

