
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
