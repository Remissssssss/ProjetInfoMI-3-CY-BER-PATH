#include "display.h"
#include "aaafiche.h"
#include "aacible.h"
#include "aacontours.h"
#include "aagrille.h"
#include "aajouer_coup.h"
#include "aajouer_gagnant.h"
#include "aamurs.h"



void jouer(int* tab_coup, int nb_joueur){
    printf("le déplacement du robot ce fait avec les touche Z(haut) Q(gauche) S(bas) D(droite)\n"); 
    printf("le jeu commence!!!!\n");
    jouer_coup(tab_coup,nb_joueur, premier_joueur);
    for(int i=0; i<nb_joueur;i++){
        if(i!=premier_joueur){
            jouer_coup(tab_coup, nb_joueur,i);
        }
    }
    printf("la partie est termine\n");
    for(int j=0; j<nb_joueur;j++){
        printf("joueur %d %c %d point\n",j+1,133,tab_point[j]);
    }
}

void gagnant(int nb_joueur){
    int a=tab_point[0];
    int j=0; 
    for(int i=0; i<nb_joueur;i++){
        if(a<tab_point[i]){
            a=tab_point[i];
            j=i;
        }
    }
    printf("Le gagnant est le joueur n%c%d, avec %d points.\n",167,j+1,a); 
}
