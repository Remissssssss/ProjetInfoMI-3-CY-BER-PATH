#include "display.h"

char constructeurCible(int i, int max, Point *cible)
{
    if (i == max)
    {
        return 0;
    }
    cible[i].x = rand() % (largeur * 2 - 1) + 1;
    cible[i].y = rand() % (hauteur * 2 - 1) + 1;
    if (cible[i].x % 2 == 0 || cible[i].y % 2 == 0 || cible[i].y == 1 || cible[i].x == 1 || cible[i].y == 2 * hauteur - 1 || cible[i].x == 2 * largeur - 1 || ('a' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'z') || ('A' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'Z'))
    {
        return constructeurCible(i, max, cible);
    }
    if (grille[cible[i].y - 1][cible[i].x - 2] == 205 || grille[cible[i].y - 1][cible[i].x + 2] == 205 || grille[cible[i].y + 1][cible[i].x + 2] == 205 || grille[cible[i].y + 1][cible[i].x - 2] == 205 || ('a' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'z') || ('A' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'Z'))
    {
        return constructeurCible(i, max, cible);
    }
    if (grille[cible[i].y - 2][cible[i].x - 1] == 186 || grille[cible[i].y - 2][cible[i].x + 1] == 186 || grille[cible[i].y + 2][cible[i].x + 1] == 186 || grille[cible[i].y + 2][cible[i].x - 1] == 186 || ('a' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'z') || ('A' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'Z'))
    {
        return constructeurCible(i, max, cible);
    }
    for (int j = 65; j < 115; j++)
    {
        if (grille[cible[i].y - 2][cible[i].x] == j || grille[cible[i].y + 2][cible[i].x] == j || grille[cible[i].y][cible[i].x - 2] == j || grille[cible[i].y][cible[i].x + 2] == j || grille[cible[i].y - 2][cible[i].x - 2] == j || grille[cible[i].y - 2][cible[i].x + 2] == j || grille[cible[i].y + 2][cible[i].x - 2] == j || grille[cible[i].y + 2][cible[i].x + 2] == j)
        {

            return constructeurCible(i, max, cible);
        }
    }

    if (max == 18)
    {
        grille[cible[i].y][cible[i].x] = 97 + i;
    }
    else
    {
        grille[cible[i].y][cible[i].x] = 65 + i;
    }
    return constructeurCible(i + 1, max, cible);
}