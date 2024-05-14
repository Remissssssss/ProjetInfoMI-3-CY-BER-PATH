#ifndef display
#define dislpay

#include <stdio.h>                      //pour faire le cadrillage
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <limits.h> //INT_MAX est une constante définie dans l'en-tête <limits.h> qui représente la valeur entière la plus grande possible que peut stocker une variable de type int

typedef struct {
    int x, y;
} Point;

typedef struct{
    Point robot1; 
    Point cible1;
}But;

int* tab_point; 
unsigned char**grille;
int largeur;
int hauteur;
But *but;
int premier_joueur;

int meilleur_scan(char * message, int min){
    int ret_var = 0;
    int value = min -1;
    while (value < min || ret_var != 1)
    {   
        printf("%s", message);
        ret_var = scanf("%d",&value);
        while (getchar()!='\n'){}

    }
    return value;

}




#endif 