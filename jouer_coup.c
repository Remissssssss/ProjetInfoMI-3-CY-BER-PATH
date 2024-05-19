#include "display.h"
#include "aaafiche.h"
#include "aacible.h"
#include "aacontours.h"
#include "aagrille.h"
#include "aajouer_coup.h"
#include "aajouer_gagnant.h"
#include "aamurs.h"



void jouer_coup(int* tab_coup, int nb_joueur,int joueur){
    char R;
    char C=' '; 
    char deplacement;
    int a;
    char w;
    w=grille[but[joueur].robot1.y][but[joueur].robot1.x];
    R=grille[but[joueur].robot1.y][but[joueur].robot1.x];
    printf("tour du joueur n%c%d\n",167,joueur+1);
    for (int j=tab_coup[joueur]; j>0; j--){
        printf("vous avez %d coups\n",j);
        do{
            printf("votre cible est %c\n", grille[but[joueur].cible1.y][but[joueur].cible1.x]);
            printf("donner votre direction (ZQSD)\n"); 
            scanf(" %c", &deplacement); 
        }while(deplacement!= 90 && deplacement!=122 && deplacement!= 81 && deplacement!= 113 && deplacement!= 83 && deplacement!= 115 && deplacement!= 68 && deplacement!= 100);// 90=Z; 122=z;81=Q;113=q;83=S
        if(deplacement== 90 || deplacement==122){
            printf("%c\n",grille[but[joueur].robot1.y][but[joueur].robot1.x]);
            for(a=0; a<hauteur*2+1;a++){
                if(grille[but[joueur].robot1.y -a][but[joueur].robot1.x] ==205){
                    char c=C;
                    if(a==1){break;}
                    C=grille[but[joueur].robot1.y -a+1][but[joueur].robot1.x];
                    grille[but[joueur].robot1.y -a+1][but[joueur].robot1.x] =grille[but[joueur].robot1.y][but[joueur].robot1.x]; 
                    grille[but[joueur].robot1.y][but[joueur].robot1.x] =c;
                    but[joueur].robot1.y=but[joueur].robot1.y -a+1;
                    a=hauteur*2+1;
                }
            }
        }
        if(deplacement== 81 || deplacement== 113){
            for(a=0; a<2*largeur+1;a++){
                if(grille[ but[joueur].robot1.y ][ but[joueur].robot1.x-a]==186){
                    char c=C;
                    if(a==1){break;}
                    C=grille[ but[joueur].robot1.y ][ but[joueur].robot1.x-a+1];
                    grille[ but[joueur].robot1.y ][ but[joueur].robot1.x-a+1] = grille[ but[joueur].robot1.y ][ but[joueur].robot1.x];
                    grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]=c;
                    but[joueur].robot1.x = but[joueur].robot1.x-a+1;
                    a=largeur*2+1;
                }
            }
        }
        if(deplacement== 83 || deplacement== 115){
            for(a=0; a<2*hauteur+1;a++){
                if(grille[ but[joueur].robot1.y+a ][but[joueur].robot1.x]==205){
                    char c=C;
                    if(a==1){break;}
                    C=grille[ but[joueur].robot1.y+a-1][but[joueur].robot1.x];
                    grille[ but[joueur].robot1.y+a-1][but[joueur].robot1.x]=grille[but[joueur].robot1.y][but[joueur].robot1.x];
                    grille[ but[joueur].robot1.y][but[joueur].robot1.x]=c;
                    but[joueur].robot1.y=but[joueur].robot1.y+a-1;
                    a=hauteur*2+1;
                }
            }
        }
        if(deplacement== 68 || deplacement== 100){
            for(a=0; a<2*largeur+1;a++){
                if(grille[ but[joueur].robot1.y ][ but[joueur].robot1.x +a]==186){
                    char c=C;
                    if(a==1){break;}
                    C=grille[ but[joueur].robot1.y ][ but[joueur].robot1.x +a-1];
                    grille[ but[joueur].robot1.y ][ but[joueur].robot1.x +a-1] = grille[ but[joueur].robot1.y ][ but[joueur].robot1.x];
                    grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]=c;
                    but[joueur].robot1.x=but[joueur].robot1.x +a-1;
                    a=largeur*2-1;
                }
            }
        }
        affiche_grille();
        if(grille[but[joueur].cible1.y][but[joueur].cible1.x]==w){
            printf("le robot %c est sur la cible, vous gagner 1 point.\n",grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]);
            tab_point[joueur]+=1;
            return ;
        }
    }
      //on n'a pas besoin de conditions if car si on sort de la boucle juste au dessus l'utilisateur n'a pas gagner de pts
      printf("le robot %c n'est pas sur la cible,donc pas de point.\n", grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]);
      for(int i=0; i<nb_joueur;i++){
        if(i!=joueur){
            tab_point[i]++;
        }
      }
    
}
