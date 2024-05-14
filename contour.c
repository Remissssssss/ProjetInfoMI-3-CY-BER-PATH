#include "display.h"
#include "aaafiche.h"
#include "aacible.h"
#include "aacontours.h"
#include "aagrille.h"
#include "aajouer_coup.h"
#include "aajouer_gagnant.h"
#include "aamurs.h"

void consturcteur_murs_contour(){
    int i;
    int a;
    do{
        a=(rand()%(hauteur-3)+2);
        i=(rand()%(hauteur-3)+2);
    }while(a==i || a==i+1 || i==a+1);
    grille[a*2][1]=205;
    grille[i*2][1]=205;
    do{
        a=(rand()%(hauteur-3)+2);
        i=(rand()%(hauteur-3)+2);
    }while(a==i || a==i+1 || i==a+1);
    grille[a*2][2*largeur-1]=205;
    grille[i*2][2*largeur-1]=205;
    do{
        a=(rand()%(largeur-3)+2);
        i=(rand()%(largeur-3)+2);
    }while(a==i || a==i+1 || i==a+1);
    grille[1][2*a]=186;
    grille[1][2*i]=186;
    do{
        a=(rand()%(largeur-3)+2);
        i=(rand()%(largeur-3)+2);
    }while(a==i || a==i+1 || i==a+1);
    grille[2*hauteur-1][2*a]=186;
    grille[2*hauteur-1][2*i]=186;
}
