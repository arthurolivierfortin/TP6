#include "stdio.h"
#include<stdlib.h>

enum valide {PASCORRECT=0, CORRECT=1};
typedef enum valide Valide;
struct date{
    int date; //AAAAMMJJ;
    int heure; //HHMM;
};

typedef struct date Date;

struct newvol{
    long int numVol;
    Date dateDepart;
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
    long int numVol;
    struct newclient *suivant;

};

typedef struct newclient NewClient;

void printS(char*s);
NewVol* CreateVol();
void menu(int*p_debut, int *p_client);
int choisir(int*p_debut, int *p_client);
NewClient* CreateClient(NewVol *vol);
void printLesVol(NewVol*vol);
void printVol(NewVol*Vol);
void rechercherPlaceDispo(NewVol*vol);
void regarderVolClient(NewVol*vol, NewClient* client);
int verifDate(int date);
