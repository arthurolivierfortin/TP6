#include "stdio.h"
#include <unistd.h>
#include "util.h"
#include "malloc.h"
#include<string.h>
#include<stdlib.h>

NewVol *vol;
NewClient *client;
int debut=1;
int*p_debut = &debut;


void main(){
    
    
    while(1){
        int choix = choisir(p_debut);
        printf("%d\n", choix);
        
        if(choix == 1){
            vol = CreateVol();
            *p_debut=0;
            
        }

        if(choix == 2 && debut==0){

            client = CreateClient(vol);        
        }
    }
}

