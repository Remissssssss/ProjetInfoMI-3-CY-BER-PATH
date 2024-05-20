#include "display.h"
#include "!afficheGrille.h"
#include "!cible.h"
#include "!contours.h"
#include "!grilleEstetique.h"
#include "!deplacement.h"
#include "!classementGagnant.h"
#include "!murs.h"

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

int main(){
    srand(time(NULL));

    Point *cible;
    Point *robot;
    int nb_joueur = meilleur_scan("Combien de joueurs participent, un minimum de 2 joueurs est requis\n",2);
    int nb_manche= meilleur_scan("Combien de manches voulez vous faire\n",0);
    tab_point= malloc(nb_joueur*sizeof(int));
    if (tab_point==NULL){
        printf("erreur allocation de m%cmoire",130);
        exit(3);
    }
    for(int i=0; i<nb_joueur; i++){
        tab_point[i]=0; 
    }
    for(int i=0; i<nb_manche; i++){
        constructeurGrille();
        cible=malloc(sizeof(Point)*18);
        if (cible==NULL){
            printf("erreur allocation de m%cmoire",130); // 130=é
            exit(3);
        }
        robot=malloc(sizeof(Point)*nb_joueur);
        if (robot==NULL){
            printf("erreur allocation de m%cmoire",130); // 130=é
            exit(3);
        }
        printf("largeur: %d\n",largeur);
        printf ("hauteur: %d\n",hauteur);
        consturcteurContour();
        constructeurCible(0,18,cible);

        constructeurCible(0,nb_joueur,robot);
        constructeurMurs();
        afficheGrille();
        int* tab_coup = info_joueurs(nb_joueur,cible,robot);
        //printf("%d",premier_joueur);
        //printf("\n%c   %c\n",grille[but[0].robot1.y][but[0].robot1.x],grille[but[0].cible1.y][but[0].cible1.x]);
        classement(tab_coup,nb_joueur);
        free(grille);
        free(robot);
        free(cible);
        free(tab_coup);
        free(but);
    }
    gagnant(nb_joueur); 
    free(tab_point);
    return 0; 
}
