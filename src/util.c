#include "util.h"
#include "stdlib.h"
#include "stdio.h"
#include "malloc.h"
#include<string.h>
#include<math.h>
#include <assert.h>
#include <assert.h>
#include<math.h>


NewVol* CreateVol(){

    NewVol *vol = (NewVol*)malloc(sizeof(NewVol));
    Date dat;

    long int numVol;
    int date;
    int heure;
    char aeroportDep [100];
    char aeroportArr [100];
    char *aeroportDep2 = (char*)malloc(sizeof(char)*100);
    char *aeroportArr2 = (char*)malloc(sizeof(char)*100);
    int nmbPlaceTotale;


    system("clear");

    printf("\nEntrez le numéro du vol: ");
    scanf("%ld", &numVol);

    printf("\nEntrez la date (AAAAMMJJ): ");
    scanf("%d", &date);

    printf("\nEntrez l'heure (HHMM): ");
    scanf("%d", &heure);

    printf("\nEntrez l'aeroport de départ: ");
    scanf("%s", aeroportDep);

    printf("\nEntrez l'aeroport d'arrivée: ");
    scanf("%s", aeroportArr);
    
    printf("\nEntrez le nombre de place totale de l'avion: ");
    scanf("%d", &nmbPlaceTotale);

    
    system("clear");

    vol->numVol = numVol;
    dat.date = date;
    dat.heure = heure;
    vol->dateActuelle = dat;
    vol->dateActuelle.heure = heure;
    
    strcpy(aeroportDep2, aeroportDep);
    strcpy(aeroportArr2, aeroportArr);

    vol->aeroportDep = aeroportDep2;
    vol->aeroportArrivée = aeroportArr2;
    vol->nmbPlaceTotale = nmbPlaceTotale;
    vol->nmbPlaceDispo = nmbPlaceTotale;
    vol->suivant = NULL;
    

    return vol;

}

void printS(char*s){
    int i=0;
    while(1){

        if(s[i]==NULL){
            break;
        }

        printf("%c", s[i]);
        i++;
    }
}

int choisir(){

    menu();

    int choix = getchar();

    return choix;

}

void menu(){

    system("clear");
    printf("Que voulez-vous faire?\n");
    printf("1- créer un nouveau vol\n");

    
}

void printVol(NewVol*vol){

    printf("Vol %ld\n", vol->numVol);
    
}