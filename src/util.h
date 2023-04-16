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
void menu(int*p_debut);
int choisir(int*p_debut);
NewClient* CreateClient(NewVol *vol);
void printLesVol(NewVol*vol);
void printVol(NewVol*Vol);
