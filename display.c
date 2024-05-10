#include <stdio.h>                      //pour faire le cadrillage
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

typedef struct {
    int x, y;
} Point;

unsigned char**grille;
Point *cible;
Point *robot;
int largeur;
int hauteur;

void constructeur_grille(){
    largeur= rand()%6+15;
    hauteur= rand()%6+15;
// allocation de mémoire de la grille
    grille=malloc(sizeof(unsigned char*)*(2*hauteur+1));
    if (grille==NULL){
        printf("erreur allocation de m%cmoire",130);
        exit(1);
    }
    for (int i=0; i<2*hauteur+1; i++){
        grille[i]=malloc(sizeof(unsigned char)*(2*largeur+1));
        if(grille[i]== NULL){
            printf("erreur allocation de m%cmoire",130);
            exit(2);
        }

// remplissage estétique de de la grille 
        for (int j=0;j<2*largeur+1;j++){
            if(j%2 !=0){
                grille[i][j] = ' ';
                if(i%2==0){
                    grille[i][j] = 196;
                }
            }
            else if(j%2==0){
                grille[i][j] = 197;
                if(i%2!=0){
                    grille[i][j]= 179;
                }
            }
            grille[0][j] = 205;
            if (i==2*hauteur){
                grille[i][j] = 205;
            }
        }
        grille[i][0]=186;
        grille[i][2*largeur]=186;
    }
    grille[0][0]= 201;
    grille[0][2*largeur] = 187;
    grille[hauteur*2][0] = 200;
    grille[hauteur*2][2*largeur]= 188;
}
//permet d'avoir des coins pour les murs
void estetique_murs_coin(int i, int j){
    if(grille[i][j]==186){
        if(grille[i+1][j+1]==205){
            grille[i+1][j]=200;
        }
        else if(grille[i+1][j-1]==205){
            grille[i+1][j]=188;
        }
    }
    if(i==0 && grille[i+1][j+1]==186 && j<2*largeur-1){
        grille[i][j+1]=203;
    }
    if(i==2*hauteur && grille[i-1][j+1]==186 && j<2*largeur-1){
        grille[i][j+1]=202;
    }
    if(i>0 && grille[i][j+1]==205){
        if(i<hauteur*2){
            if (grille[i+1][j+2]==186){
                if(grille[i-1][j+2]==186){
                    grille[i][j+2]=185;
                }
                else{
                    grille[i][j+2]=187;
                }
                
            }
            if(grille[i+1][j]==186){
                grille[i][j]=201;
            }
            if(grille[i-1][j]== 186 && grille[i+1][j]==186){
                grille[i][j]=204; 
            }
        }
    }
    
}
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
                    else if (grille[i][j]== 'R'|| (grille[i][j]>48 && grille[i][j]<58)|| grille[i][j]==184){
                        printf("\033[31m%c \033[0m",grille[i][j]);
                    }
                    else{
                        printf("\033[2m%c \033[0m",grille[i][j]);
                    }
                }
            }
        printf("\n");
        }
}
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
int main(){
    srand(time(NULL)); 
    constructeur_grille();
    printf("largeur: %d\n",largeur);
    printf ("hauteur: %d\n",hauteur);
    // grille[3][6]=186;
    // grille[3][7]='R';
    // grille[4][7]=205;
    // grille[3][12] = 186;
    // grille[3][11] = 'R';
    // grille[4][11] = 205;
    // grille[3][16] = 186;
    // grille[2][15] = 205;
    // grille[3][15] = 'R';
    // grille[3][20] = 186;
    // grille[2][21] = 205;
    // grille[3][21] = 184;
    consturcteur_murs_contour();
    affiche_grille();
    free(grille); 
    return 0; 
}
