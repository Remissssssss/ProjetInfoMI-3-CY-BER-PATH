#include display.c
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