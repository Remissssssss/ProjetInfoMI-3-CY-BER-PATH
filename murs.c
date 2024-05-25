#include "display.h"

/**
 * @brief Construit les murs dans la grille.
 */

void constructeurMurs()
{
    int a;
    int b;
    for (int i = 0; i < 2 * hauteur + 1; i++)
    {
        for (int j = 0; j < 2 * largeur + 1; j++)
        {
            if (grille[i][j] >= 97 && grille[i][j] <= 122)
            { // 97= a , 122= z
                a = rand() % 2;
                b = rand() % 2;
                if (a == 0)
                {
                    a--;
                }
                if (b == 0)
                {
                    b--;
                }
                grille[i + a][j] = 205; // 205= ═
                grille[i][j + b] = 186; // 186= ║
            }
        }
    }
}
