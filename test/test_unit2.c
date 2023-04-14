#include "stdio.h"
#include<stdlib.h>
#include <unistd.h>
#include "util.h"
#include "malloc.h"
#include<string.h>
#include <assert.h>
#include<math.h>

    
char path[] = "Mouvement.txt";


int chiffre(char c){

    if(c=='0'){
        return 0;
    }

    if(c=='1'){
        return 1;
    }
    
    if(c=='2'){
        return 2;
    }
    
    if(c=='3'){
        return 3;
    }
    
    if(c=='4'){
        return 4;
    }
    
    if(c=='5'){
        return 5;
    }
    
    if(c=='6'){
        return 6;
    }
    
    if(c=='7'){
        return 7;
    }
    
    if(c=='8'){
        return 8;
    }
    
    if(c=='9'){
        return 9;
    }

}


void main(){

    int* fichier = fopen(path, "r");

    Mouvement *mouvement = (Mouvement*)malloc(sizeof(Mouvement));

    char c;

    int x=1;
    int debut=1;
    int x_dix=0;



    //printf("QQQ\n");
    Mouvement mouv;
    mouv.suivant=NULL;
    while(c != EOF) {
        
        if (c != EOF){
            
            printf("XXX\n");
            c = fgetc(fichier);
            if(c!='0' && c!='1' && c!='2' && c!='3' && c!='4' && c!='5' && c!='6' && c!='7' && c!='8' && c!='9' && c!='#'){
                continue;
            }
            if(c=='#'&& x==0){
                printf("!@!@\n");
                x=1;
                x_dix=0;
                if(debut==1){
                    printf("caliss\n");
                    mouvement->x = mouv.x;
                    mouvement->y = mouv.y;
                    printf("de tabarnack\n");
                    printf("888\n");
                    mouvement->suivant=NULL;
                    debut=0;
                    mouv.x=0;
                    mouv.y=0;
                    continue;
                    }

                if(debut==0){
                    Mouvement *F = mouvement;
                    while(1){
                        if(F->suivant==NULL){
                            break;
                        }
                        F=F->suivant;
                    }
                    printf("fuckyou\n");
                    F->suivant->x=mouv.x;
                    F->suivant->y=mouv.y;
                    
                    mouv.x=0;
                    mouv.y=0;
                }
                continue;
            }

            if(c=='#'&& x==1){
                printf("&&&\n");
                x=0;
                x_dix=0;
                    continue;
                }

            if(c!='#' && x==1){
                printf("???\n");
                if(x_dix==1){
                    mouv.x+=(mouv.x*10)+chiffre(c);;
                    printf("%d = mouv x\n", mouv.x);
                }

                else{
                    printf("$$$\n");

                    printf("%c == c\n", c);
                    int x = chiffre(c);

                    mouv.x = x;
                    printf("WWWW\n");
                    x_dix=1;
                    
                    printf("%d = mouv x\n", mouv.x);

                }  
            }
            printf("LLL\n");

            if(c!='#' && x==0){
                printf("!!!\n");
                if(x_dix==1){

                    mouv.y+=(mouv.y*10)+chiffre(c);;
                    printf("%d = mouv y \n", mouv.y);
                }

                else{
                    printf("@@@\n");
                    printf("%c == c\n", c);
                    printf("%d == chiffre(c)\n", chiffre(c));
                    mouv.y = chiffre(c);;
                    x_dix=1;
                    printf("%d = mouv y\n", mouv.y);
                }  
            }
            printf("***\n");

            
        

        }
        
    }
    
   
    Mouvement *liste = mouvement;
    while(mouvement->suivant!=NULL){
        printf("%d = liste x, ", liste->x);
        printf("%d\n = liste y", liste->y);
        liste = liste->suivant;
    }
}