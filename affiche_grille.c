#include "display.h"
#include "aaafiche.h"
#include "aacible.h"
#include "aacontours.h"
#include "aagrille.h"
#include "aajouer_coup.h"
#include "aajouer_gagnant.h"
#include "aamurs.h"


void affiche_grille() {// écrire la grille
    for (int i = 0; i < 2*hauteur+1; i++) {
            for (int j = 0; j < 2*largeur+1; j++) { 
                estetique_murs_coin(i,j);
// affichage ligne et colonnes avec les murs
                if (j%2!=0  &&  i%2==0 && i>0 && i<2*hauteur){
                    if (grille[i][j]==205){
                        if(grille[i][j+1]== 188 || grille[i][j+1]== 187 ||grille[i][j+1]== 185){
                            printf("\033[34m%c%c\033[0m",grille[i][j],205);
                        }
                        else{
                            printf("\033[34m%c\033[0m\033[2m%c\033[0m",grille[i][j],196);
                        }
                    }
                    else{
                        printf("\033[2m%c%c\033[0m",grille[i][j],196);
                    }
                }
                else if(j%2==0 && i%2==0 && i>0 && i<2*hauteur && j<2*largeur){
                    if(grille[i][j]==200 || grille[i][j] ==201 || grille[i][j] ==204){
                        printf("\033[34m%c%c\033[0m",grille[i][j],205);
                    }
                    else if(grille[i][j]==187 || grille[i][j]==188 || grille[i][j]==186){
                        printf("\033[34m%c\033[0m\033[2m%c\033[0m",grille[i][j],196);
                    }
                    else{
                        printf("\033[2m%c%c\033[0m",grille[i][j],196);
                    }
                }

// affichage de la première et dernière ligne
                else if(i==0 || i==2*hauteur){
                    if(j==2*largeur){
                        printf("\033[34m%c\033[0m",grille[i][j]);
                        //printf("%c", grille[i][j]);
                    }
                    else{
                        printf("\033[34m%c%c\033[0m",grille[i][j],205);
                        //printf("%c%c", grille[i][j],205);
                    }
                }

// affichage des cases (robots/cible/déplacement)
                else{
                    if(grille[i][j]== 186 || grille[i][j]== 185){
                        printf("\033[34m%c \033[0m",grille[i][j]);
                    }
                    else if (grille[i][j]>=65 && grille[i][j]<=90){
                        printf("\033[91m%c \033[0m",grille[i][j]);
                    }
                    else if(grille[i][j]>=97 && grille[i][j]<=122){
                        printf("\033[92m%c \033[0m",grille[i][j]);
                    }
                    else{
                        printf("\033[2m%c \033[0m",grille[i][j]);
                    }
                }
            }
        printf("\n");
        }
}
