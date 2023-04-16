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

    int verifDatee = verifDate(date);

    if(verifDatee==0){
        
        while(1){
            printf("La date n'est pas correct\n");
            printf("\nEntrez la date (AAAAMMJJ): ");
            scanf("%d", &date);
            verifDatee = verifDate(date);
            if(verifDatee==1){
                break;
            }
        }

    }
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

int verifDate(int date){
    int année = date/10000;
    int mois = ((date/100)-année*100);
    int jour = date-(mois)*100-année*10000;

    if(mois>12 || mois<1){
        return PASCORRECT;
    }

    if(jour>31 || jour<1){
        return PASCORRECT;
    }

    return CORRECT;

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

int choisir(int*p_debut, int *p_client){

    menu(p_debut, p_client);

    int choix;
    scanf("%d", &choix);

    return choix;

}

void menu(int *p_debut, int *p_client){

    system("clear");
    printf("Que voulez-vous faire?\n");
    printf("1- créer un nouveau vol\n");
    if(*p_debut==0){
        printf("2- créer un nouveau client\n");
    }
    if(*p_debut==0){
        printf("3- voir le nombre de places diponibles dans un vol\n");
    }

    if(*p_debut==0 && *p_client==1){
        printf("4- voir le vol d'un client\n");
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
    printf("nombre de places disponibles : %d\n", vol->nmbPlaceDispo);
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


    while(1){
        if(vol->numVol==numVole){
            if(vol->nmbPlaceDispo<=0){
                printf("Ce vol n'a plus de place disponible\n");
                return PASCORRECT;
            }
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
    NewVol * Vole = vol;
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

    int verifDatee = verifDate(dateNaissanceDate);

    if(verifDatee==0){
        
        while(1){
            printf("La date n'est pas correct\n");
            printf("\nEntrez la date (AAAAMMJJ): ");
            scanf("%d", &dateNaissanceDate);
            verifDatee = verifDate(dateNaissanceDate);
            if(verifDatee==1){
                break;
            }
        }

    }

    dateNaissanceHeure == NULL;

    
    printf("Quel est le numéro de vol du client?\n");
    printf("Voici les vols existants: \n\n");
    printLesVol(vol);
    scanf("%ld", &numVol);

    int verif = rechercherVol(vol, numVol);
    if(verif==1){
        client->numVol = numVol;
        while(1){
            
            if(Vole->numVol==numVol){
                Vole->nmbPlaceDispo-=1;
                break;
            }
            if(Vole->suivant==NULL){
                break;
            }

        }
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

    system("clear");
    printf("Voici les informations du nouveau client :\n");
    sleep(1);
    printClient(client);

    printf("\nEst-ce correct?\n");
    printf("1- OUI\n");
    printf("2- NON\n");
    int y;
    scanf("%d", &y);
    if(y==2){
        vol = CreateClient(vol);
    }

    return client;
    
    
}

void rechercherPlaceDispo(NewVol*vol){

    long int numVol;
    system("clear");
    printf("Voici les vols existants: \n\n");
    printLesVol(vol);

    printf("Entrez le numéro de vol dont vous voulez voir les informations\n");
    scanf("%ld", &numVol);

    int verif = rechercherVol(vol, numVol);
    
    if(verif==0){
        while(1){
                printf("Veuillez-corriger le numéro du client\n");
                scanf("%ld", &numVol);
                verif = rechercherVol(vol, numVol);
                if(verif==1){
                    break;
                }
                printf("Le numéro de vol du client n'est pas bon\n");
            }
    }

    while(1){

        if(vol->numVol == numVol){
            printVol(vol);
            return;
        }
        if(vol->suivant==NULL){
            printf("Il n'y a aucun vol avec ce numéro\n");
            return;
        }

        vol=vol->suivant;
    }


}



void regarderVolClient(NewVol*vol, NewClient* client){
    system("clear");
    NewVol* LesVols = vol;
    NewClient* Lesclients = client;

    printf("Voici les clients\n\n");
    while(1){
        printClient(client);
        if(client->suivant==NULL){
            break;
        }
        client=client->suivant;

    }

    printf("Entrez le numéro de passeport du client : ");
    long int numPasseport;
    scanf("%ld", &numPasseport);
    printf("\n");
    client=Lesclients;

    while(1){
        if(client->numPasseport==numPasseport){
            break;
        }
        if(client->suivant==NULL){
            break;
        }
        client=client->suivant;

    }

    while(1){

        if(client->numVol==vol->numVol){

            printf("Voici le vol du client: \n");
            printVol(vol);
            return;
        }

        if(vol->suivant==NULL){

            printf("Le client n'a pas de vol, voulez-vous lui en rajouter un?\n");
            printf("1- OUI\n");
            printf("2- NON\n");
            int choix;
            scanf("%d", &choix);

            if(choix==1){

                system("clear");
                printf("Voici les vols existant :\n\n");
                printLesVol(LesVols);

                printf("\n Entrez le numéro de vol du client: ");
                long int numVol;
                scanf("%ld", &numVol);
                printf("\n");

                int verif = rechercherVol(LesVols, numVol);

                if(verif==0){
                    while(1){
                            printf("Veuillez-corriger le numéro de vol du client\n");
                            scanf("%ld", &numVol);
                            verif = rechercherVol(LesVols, numVol);
                            if(verif==1){
                                client->numVol=numVol;
                                break;
                            }
                            printf("Le numéro de vol du client n'est pas bon\n");
                    }
                    regarderVolClient(LesVols, client);
                    return;
                }
            }

            if(choix == 2){
                return;
            }
        }

        vol = vol->suivant;


    }
}