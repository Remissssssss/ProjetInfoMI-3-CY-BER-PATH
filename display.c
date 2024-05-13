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

char constructeur_cible1(int i, int max, Point* cible){
    if(i==max){
        return 0;
    }
    cible[i].x=rand()%(largeur*2-1)+1;
    cible[i].y=rand()%(hauteur *2-1)+1;
    if(cible[i].x%2==0 || cible[i].y%2==0 ||cible[i].y==1 || cible[i].x==1 || cible[i].y==2*hauteur-1 || cible[i].x==2*largeur-1){
        return constructeur_cible1(i,max,cible);
    }
    if(grille[cible[i].y-1][cible[i].x-2]==205 || grille[cible[i].y-1][cible[i].x+2] ==205|| grille[cible[i].y+1][cible[i].x+2]==205 || grille[cible[i].y+1][cible[i].x-2]==205){
        return constructeur_cible1(i,max,cible);
    }
    if(grille[cible[i].y-2][cible[i].x-1]==186|| grille[cible[i].y-2][cible[i].x+1]==186 || grille[cible[i].y+2][cible[i].x+1]==186 || grille[cible[i].y+2][cible[i].x-1]==186){
        return constructeur_cible1(i,max,cible);
    }
    for(int j=65; j<115;j++){
        if(grille[cible[i].y-2][cible[i].x]==j|| grille[cible[i].y+2][cible[i].x]==j|| grille[cible[i].y][cible[i].x-2]==j|| grille[cible[i].y][cible[i].x+2]==j|| grille[cible[i].y-2][cible[i].x-2]==j|| grille[cible[i].y-2][cible[i].x+2]==j|| grille[cible[i].y+2][cible[i].x-2]==j|| grille[cible[i].y+2][cible[i].x+2]==j){
            
            return constructeur_cible1(i,max,cible);
        }
    }

    if(max==18){
        grille[cible[i].y][cible[i].x]=97+i;
    }
    else{
        grille[cible[i].y][cible[i].x]=65+i;
    }
    return constructeur_cible1(i+1,max,cible);
}

void consturcteur_murs_(){
    int a; 
    int b; 
    for(int i=0; i<2* hauteur+1;i++){
        for(int j=0; j<2*largeur+1;j++){
            if(grille[i][j]>=65 && grille[i][j]<=122){
                a=rand()%2;
                b=rand()%2;
                if(a==0){
                    a--;
                }
                if(b==0){
                    b--;
                }
                grille[i+a][j]=205;
                grille[i][j+b]=186;
            }
        }
    }
}




        affiche_grille();
        if(grille[but[joueur].cible1.y][but[joueur].cible1.x]==w){
            printf("le robot %c est sur la cible, vous gagner 1 point.\n",grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]);
            tab_point[joueur-1]+=1;
        }
    }
    if(grille[but[joueur].cible1.y][but[joueur].cible1.x]!=w){
         printf("le robot %c n'est pas sur la cible,donc pas de point.\n", grille[ but[joueur].robot1.y ][ but[joueur].robot1.x]);
    }
}

