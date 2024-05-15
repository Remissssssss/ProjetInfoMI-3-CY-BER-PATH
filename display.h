#ifndef aadisplay
#define aadisplay

#include <stdio.h>                      //pour faire le cadrillage
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <limits.h> //INT_MAX est une constante définie dans l'en-tête <limits.h> qui représente la valeur entière la plus grande possible que peut stocker une variable de type int

typedef struct Point{
    int x, y;
}Point;

typedef struct But{
    Point robot1; 
    Point cible1;
}But;

int* tab_point; 
unsigned char**grille;
int largeur;
int hauteur;
But *but;
int premier_joueur;

int meilleur_scan(char * message, int min);




#endif 
