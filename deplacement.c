#include "display.h"
#include "!afficheGrille.h"
#include "!cible.h"
#include "!contours.h"
#include "!grilleEstetique.h"
#include "!deplacement.h"
#include "!classementGagnant.h"
#include "!murs.h"



void deplacement(int* tab_coup, int nb_joueur,int joueur){
    char R;
    char C=' '; 
    char deplacement;
    int a;
    char w;
    int g=0;
    w=grille[but[joueur].robot1.y][but[joueur].robot1.x];
    R=grille[but[joueur].robot1.y][but[joueur].robot1.x];
    printf("\n \n                                tour du joueur n°%d\n\n",joueur+1); // les espaces sont fait pour l'éstétiques
    for (int j=tab_coup[joueur]; j>0; j--){
        printf("vous avez %d coups\n",j);
        do{
            printf("votre cible est %c\n", grille[but[joueur].cible1.y][but[joueur].cible1.x]);
            printf("donner votre direction (ZQSD)\n"); 
            scanf(" %c", &deplacement); 
        }while(deplacement!= 90 && deplacement!=122 && deplacement!= 81 && deplacement!= 113 && deplacement!= 83 && deplacement!= 115 && deplacement!= 68 && deplacement!= 100);// 90=Z; 122=z; 81=Q; 113=q; 83=S, 115=s, 68=D, 100=d
        if(deplacement== 90 || deplacement==122){ // 90= Z , 122=z
            printf("%c\n",grille[but[joueur].robot1.y][but[joueur].robot1.x]);
            for(a=0; a<hauteur*2+1;a++){
                if(grille[but[joueur].robot1.y -a][but[joueur].robot1.x] ==205){ // 205= ═
                    char c=C;
                    if(a==1){break;}
                    C=grille[but[joueur].robot1.y -a+1][but[joueur].robot1.x];
                    grille[but[joueur].robot1.y -a+1][but[joueur].robot1.x] =grille[but[joueur].robot1.y][but[joueur].robot1.x]; 
                    grille[but[joueur].robot1.y][but[joueur].robot1.x] =c;
                    but[joueur].robot1.y=but[joueur].robot1.y -a+1;
                    a=hauteur*2+1;
                    g++;
                }
            }
        }
        if(deplacement== 81 || deplacement== 113){ // 81=Q, 113=q
            for(a=0; a<2*largeur+1;a++){
                if(grille[ but[joueur].robot1.y ][ but[joueur].robot1.x-a]==186){ // 186= ║
                    char c=C;
                    if(a==1){break;}
                    C=grille[ but[joueur].robot1.y ][ but[joueur].robot1.x-a+1];
                    grille[ but[joueur].robot1.y ][ but[joueur].robot1.x-a+1] = grille[ but[joueur].robot1.y ][ but[joueur].robot1.x];
                    grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]=c;
                    but[joueur].robot1.x = but[joueur].robot1.x-a+1;
                    a=largeur*2+1;
                    g++;
                }
            }
        }
        if(deplacement== 83 || deplacement== 115){ // 83=S, 115=s
            for(a=0; a<2*hauteur+1;a++){
                if(grille[ but[joueur].robot1.y+a ][but[joueur].robot1.x]==205){  // 205= ═
                    char c=C;
                    if(a==1){break;}
                    C=grille[ but[joueur].robot1.y+a-1][but[joueur].robot1.x];
                    grille[ but[joueur].robot1.y+a-1][but[joueur].robot1.x]=grille[but[joueur].robot1.y][but[joueur].robot1.x];
                    grille[ but[joueur].robot1.y][but[joueur].robot1.x]=c;
                    but[joueur].robot1.y=but[joueur].robot1.y+a-1;
                    a=hauteur*2+1;
                    g++;
                }
            }
        }
        if(deplacement== 68 || deplacement== 100){ // 68=D , 100=d
            for(a=0; a<2*largeur+1;a++){
                if(grille[ but[joueur].robot1.y ][ but[joueur].robot1.x +a]==186){ // 186= ║
                    char c=C; 
                    if(a==1){break;}
                    C=grille[ but[joueur].robot1.y ][ but[joueur].robot1.x +a-1];
                    grille[ but[joueur].robot1.y ][ but[joueur].robot1.x +a-1] = grille[ but[joueur].robot1.y ][ but[joueur].robot1.x];
                    grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]=c;
                    but[joueur].robot1.x=but[joueur].robot1.x +a-1;
                    a=largeur*2-1;
                    g++;
                }
            }
        }
        afficheGrille();
        if(grille[but[joueur].cible1.y][but[joueur].cible1.x]==w && g==tab_coup[joueur]){
            printf("le robot %c est sur la cible, vous gagnez 2 points.\n",grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]);
            tab_point[joueur]+=2;
            return ;
        }
        else if( grille[but[joueur].cible1.y][but[joueur].cible1.x]==w && g!=tab_coup[joueur]){
        printf("le robot %c est sur la cible, vous perdez 1 point.\n",grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]);
            tab_point[joueur]--;
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
