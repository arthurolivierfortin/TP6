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
int debClient=0;
int*p_client = &debClient;


void main(){
    
    
    while(1){
        system("clear");
        int choix = choisir(p_debut, p_client);
        printf("%d\n", choix);
        
        if(choix == 1 && *p_debut==1){
            vol = CreateVol();
            *p_debut=0;
            continue;
        }

        if(choix == 1 && *p_debut==0){
            NewVol *vol2=vol;
            while(1){
                if(vol2->suivant==NULL){
                    break;
                }
                vol2 = vol2->suivant;
            }

            vol2->suivant = CreateVol();
            *p_debut=0;
            continue;
            
        }


        if(choix == 2 && *p_debut==0 && *p_client==0){

            client = CreateClient(vol);    
            *p_client=1; 
            continue;   
        }


        if(choix == 2 && *p_debut==0 && *p_client==1){
            
            NewClient *client2 = client;
            while(1){
                if(client2->suivant==NULL){
                    break;
                }
                client2 = client2->suivant;
            }
            client2->suivant = CreateClient(vol); 
            continue;       
        }



        if(choix ==3 && *p_debut==0){

            rechercherPlaceDispo(vol);
            continue;
        }

        if(choix == 4 && *p_debut==0 && *p_client==1){
        
            regarderVolClient(vol, client);
            continue;
        }
    }
}

