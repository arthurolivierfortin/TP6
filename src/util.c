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
    vol->dateDepart = dat;
    vol->dateDepart.heure = heure;
    
    strcpy(aeroportDep2, aeroportDep);
    strcpy(aeroportArr2, aeroportArr);

    vol->aeroportDep = aeroportDep2;
    vol->aeroportArrivée = aeroportArr2;
    vol->nmbPlaceTotale = nmbPlaceTotale;
    vol->nmbPlaceDispo = nmbPlaceTotale;
    vol->suivant = NULL;
    
    printf("Voici les informations du nouveau vol :\n");
    printVol(vol);
    
    printf("\nEst-ce correct?\n");
    printf("1- OUI\n");
    printf("2- NON\n");
    sleep(1);
    int x;
    scanf("%d", &x);
    if(x==2){
        vol = CreateVol();
    }

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

int choisir(int*p_debut){

    menu(p_debut);

    int choix;
    scanf("%d", &choix);

    return choix;

}

void menu(int *p_debut){

    system("clear");
    printf("Que voulez-vous faire?\n");
    printf("1- créer un nouveau vol\n");
    if(*p_debut==0){
        printf("2- créer un nouveau client\n");
    }

    
}

void printVol(NewVol*vol){
    
    int année = vol->dateDepart.date/10000;
    int mois = ((vol->dateDepart.date/100)-année*100);
    int jour = vol->dateDepart.date-(mois)*100-année*10000;
    int heure = vol->dateDepart.heure/100;
    int min = vol->dateDepart.heure-heure*100;
    
    printf("numéro du vol : %ld\n", vol->numVol);
    printf("Aeroport de départ : ");
    printS(vol->aeroportDep);
    printf("\n");
    printf("Aeroport d'arrivée : ");
    printS(vol->aeroportArrivée);
    printf("\n");
    printf("nombnre de places disponibles : %d\n", vol->nmbPlaceDispo);
    printf("Date de départure : %d/%d/%d à %d:%d\n", année, mois, jour, heure, min);
    sleep(1);
}


void printLesVol(NewVol*vol){

    while(1){

        printVol(vol);

        if(vol->suivant==NULL){
            printf("\n");
            return;
        }

        vol=vol->suivant;
    }

}

int rechercherVol(NewVol *vol, long int numVole){

    printf("Voici les vols existants :\n");

    printLesVol(vol);
    while(1){
        if(vol->numVol==numVole){
            vol->nmbPlaceDispo-=1;
            return CORRECT;
        }
        if(vol->suivant==NULL){
            printf("Le numéro de vol n'existe pas\n");
            return PASCORRECT;
        }  
        vol=vol->suivant;
        sleep(2);
    }
    
}

void printClient(NewClient *client){
    int année = client->dateNaissance.date/10000;
    int mois = ((client->dateNaissance.date/100)-année*100);
    int jour = client->dateNaissance.date-(mois)*100-année*10000;


    printf("Date de naissance : %d/%d/%d\n", année, mois, jour);
    printf("Nom du client : ");
    printS(client->nom);
    printf("\n");
    printf("Prenom du client : ");
    printS(client->prenom);
    printf("\n");

    printf("Numéro du passeport du client : %ld\n",client->numPasseport);
    printf("Numéro de vol du client : %ld\n",client->numVol);

    
}

NewClient* CreateClient(NewVol *vol){

    system("clear");
    NewClient *client;
    long int numPasseport;
    char nom[100];
    char prenom[100];
    int dateNaissanceDate;
    int dateNaissanceHeure;
    long int numVol;
    
    printf("Entrez le numéro du passeport: ");
    scanf("%ld", &numPasseport);
    printf("\n");

    printf("Entrez le nom du client: ");
    scanf("%s", nom);
    printf("\n");

    printf("Entrez le prenom du client: ");
    scanf("%s", prenom);
    printf("\n");

    printf("Entrez la date de naissance du client (AAAAMMJJ): ");
    scanf("%d", &dateNaissanceDate);
    printf("\n");

    dateNaissanceHeure == NULL;

    
    printf("Quel est le numéro de vol du client?\n");
    printf("Voici les vols existants: \n");
    printLesVol(vol);
    scanf("%ld", &numVol);

    int verif = rechercherVol(vol, numVol);
    if(verif==1){
        client->numVol = numVol;
    }
    if(verif==0){
        int x=0;
        printf("Voulez-vous créer un nouveau vol?\n");
        printf("1- OUI\n");
        printf("2- NON\n");
        scanf("%d", &x);
        if(x==1){
            NewVol *V = vol;
            while(1){
                if(V->suivant==NULL){
                    break;
                }
                V=V->suivant;
            }
            V=CreateVol();
            client->numVol = V->numVol;
        }
        if(x==0){
            while(1){
                printf("Veuillez-corriger le numéro du client\n");
                scanf("%ld", &numVol);
                verif = rechercherVol(vol, numVol);
                if(verif==1){
                    client->numVol = numVol;
                    break;
                }
                printf("Le numéro de vol du client n'est pas bon\n");
            }
        }
    }

    int len = strlen(prenom);
    int*pre = (char*)malloc(sizeof(char)*len);

    len = strlen(nom);
    int*nomm = (char*)malloc(sizeof(char)*len);

    strcpy(pre, prenom);
    strcpy(nomm, nom);

    client->nom = nomm;
    client->prenom = prenom;
    client->numPasseport = numPasseport;
    client->dateNaissance.date = dateNaissanceDate;
    client->dateNaissance.heure = dateNaissanceHeure;
    client->suivant = NULL;


    printClient(client);

    printf("\nEst-ce correct?\n");
    printf("1- OUI\n");
    printf("2- NON\n");
    int y;
    scanf("%d", &y);
    if(y==2){
        vol = CreateClient(vol);
    }
    
    
}