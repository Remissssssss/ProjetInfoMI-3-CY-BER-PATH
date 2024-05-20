#include "display.h"
#include "!afficheGrille.h"
#include "!cible.h"
#include "!contours.h"
#include "!grilleEstetique.h"
#include "!deplacement.h"
#include "!classementGagnant.h"
#include "!murs.h"



int* info_joueurs(int nb_joueur,Point *cible, Point *robot){ 
    int* tab_coup = (int*)malloc(sizeof(int)*nb_joueur);
    if (tab_coup == NULL) {
        exit(EXIT_FAILURE);
    }
    but=malloc(sizeof(But)*nb_joueur); 
    if (but == NULL) {
        exit(EXIT_FAILURE);
    }
    int minTours = INT_MAX; 
    int premier=-1;
    int a;
    int b;
    for(int i=0; i<nb_joueur; i++ ){ 
        int nbr_tour;
        a=rand()%18;
            printf("Joueurs n%c %d est le robot: \033[91m%c\033[0m.\nEn combien de coups pensez-vous toucher la cible \033[92m%c \033[0m\n",167, i+1,grille[robot[i].y][robot[i].x],grille[cible[a].y][cible[a].x]);
            nbr_tour=meilleur_scan("Coups : ",1 );

        tab_coup[i]= nbr_tour;
        if (tab_coup[i] < minTours) {
            minTours = tab_coup[i];
            premier= i;
        }
        but[i].robot1.y=robot[i].y;
        but[i].robot1.x=robot[i].x;
        but[i].cible1.y=cible[a].y;
        but[i].cible1.x=cible[a].x;
        premier_joueur=premier; 
    }
    premier_joueur=premier;
    printf("Le joueur %d a le nombre minimal de tours : %d.\nC'est donc le joueur %d qui va commence a jouer\n", premier_joueur+1 , minTours,premier_joueur+1);
    return tab_coup;
}
