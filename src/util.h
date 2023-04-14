#include "stdio.h"
#include<stdlib.h>


struct date{
    int date; //AAAAMMJJ;
    int heure; //HHMM;
};

typedef struct date Date;

struct newvol{
    long int numVol;
    Date dateActuelle;
    char* aeroportDep;
    char* aeroportArrivée;
    int nmbPlaceTotale;
    int nmbPlaceDispo;
    struct newvol *suivant;

};

typedef struct newvol NewVol;

struct newclient{
    long int numPasseport;
    char* nom;
    char* prenom;
    Date dateNaissance;
    int* numVol;
    struct newclient *suivant;

};

typedef struct newclient NewClient;

void printS(char*s);
NewVol* CreateVol();
void menu();
int choisir();
