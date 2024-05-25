#include "display.h"
#include "!grilleEstetique.h"


/**
 * @brief Affiche la grille de jeu.
 */

void afficheGrille()
{ // écrire la grille
    for (int i = 0; i < 2 * hauteur + 1; i++)
    {
        for (int j = 0; j < 2 * largeur + 1; j++)
        {
            estetiqueCoin(i, j);
            // affichage ligne et colonnes avec les murs
            if (j % 2 != 0 && i % 2 == 0 && i > 0 && i < 2 * hauteur)
            {
                if (grille[i][j] == 205)// 205= ═
                { 
                    if (grille[i][j + 1] == 188 || grille[i][j + 1] == 187 || grille[i][j + 1] == 185)
                    {
                        printf("\033[34m%c%c\033[0m", grille[i][j], 205); // 205= ═
                    }
                    else
                    {
                        printf("\033[34m%c\033[0m\033[2m%c\033[0m", grille[i][j], 196); // 196= ─
                    }
                }
                else
                {
                    printf("\033[2m%c%c\033[0m", grille[i][j], 196); // 196= ─
                }
            }
            else if (j % 2 == 0 && i % 2 == 0 && i > 0 && i < 2 * hauteur && j < 2 * largeur)
            {
                if (grille[i][j] == 200 || grille[i][j] == 201 || grille[i][j] == 204)
                {                                                     // 200= ╚, 201= ╔ , 204=╠
                    printf("\033[34m%c%c\033[0m", grille[i][j], 205); // 205= ═
                }
                else if (grille[i][j] == 187 || grille[i][j] == 188 || grille[i][j] == 186)
                {
                    printf("\033[34m%c\033[0m\033[2m%c\033[0m", grille[i][j], 196); // 196= ─
                }
                else
                {
                    printf("\033[2m%c%c\033[0m", grille[i][j], 196); // 196= ─
                }
            }

            // affichage de la première et dernière ligne
            else if (i == 0 || i == 2 * hauteur)
            {
                if (j == 2 * largeur)
                {
                    printf("\033[34m%c\033[0m", grille[i][j]);
                }
                else
                {
                    printf("\033[34m%c%c\033[0m", grille[i][j], 205); // 205= ═
                }
            }

            // affichage des cases (robots/cible/déplacement)
            else
            {
                if (grille[i][j] == 186 || grille[i][j] == 185) // 186= ║ , 185= ╣
                { 
                    printf("\033[34m%c \033[0m", grille[i][j]);
                }
                else if (grille[i][j] >= 65 && grille[i][j] <= 90) // 65=A ; 90=Z
                { 
                    printf("\033[91m%c \033[0m", grille[i][j]);
                }
                else if (grille[i][j] >= 97 && grille[i][j] <= 122) // 97=a, 122=z
                { 
                    printf("\033[92m%c \033[0m", grille[i][j]);
                }
                else
                {
                    printf("\033[2m%c \033[0m", grille[i][j]);
                }
            }
        }
        printf("\n");
    }
}
