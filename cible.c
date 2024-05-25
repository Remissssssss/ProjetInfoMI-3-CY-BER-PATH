#include "display.h"

/**
 * @brief Construit les cibles de jeu.
 *
 * @param i L'index de la cible actuelle.
 * @param max Le nombre maximum de cibles.
 * @param cible Le tableau des cibles à remplir.
 * @return 0 si la construction est terminée, sinon appelle récursivement la fonction.
 */

char constructeurCible(int i, int max, Point *cible)
{
    // Condition d'arrêt de la récursion : si toutes les cibles ont été construites, retourner 0
    if (i == max)
    {
        return 0;
    }

    // Générer des coordonnées aléatoires pour la cible
    cible[i].x = rand() % (largeur * 2 - 1) + 1;
    cible[i].y = rand() % (hauteur * 2 - 1) + 1;

    // Vérifier si les coordonnées générées sont valides
    if (cible[i].x % 2 == 0 || cible[i].y % 2 == 0 || cible[i].y == 1 || cible[i].x == 1 || 
        cible[i].y == 2 * hauteur - 1 || cible[i].x == 2 * largeur - 1 || 
        ('a' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'z') || 
        ('A' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'Z'))
    {
        // Si les coordonnées ne sont pas valides, rappeler la fonction récursivement
        return constructeurCible(i, max, cible);
    }

    // Vérifier les conditions supplémentaires de validité des coordonnées
    if (grille[cible[i].y - 1][cible[i].x - 2] == 205 || grille[cible[i].y - 1][cible[i].x + 2] == 205 || 
        grille[cible[i].y + 1][cible[i].x + 2] == 205 || grille[cible[i].y + 1][cible[i].x - 2] == 205 || 
        ('a' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'z') || 
        ('A' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'Z'))
    {
        // Si les coordonnées ne sont pas valides, rappeler la fonction récursivement
        return constructeurCible(i, max, cible);
    }

    // Vérifier les conditions supplémentaires de validité des coordonnées
    if (grille[cible[i].y - 2][cible[i].x - 1] == 186 || grille[cible[i].y - 2][cible[i].x + 1] == 186 || 
        grille[cible[i].y + 2][cible[i].x + 1] == 186 || grille[cible[i].y + 2][cible[i].x - 1] == 186 || 
        ('a' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'z') || 
        ('A' <= grille[cible[i].y][cible[i].x] && grille[cible[i].y][cible[i].x] <= 'Z'))
    {
        // Si les coordonnées ne sont pas valides, rappeler la fonction récursivement
        return constructeurCible(i, max, cible);
    }

    // Vérifier les conditions supplémentaires de validité des coordonnées pour les caractères de A à z
    for (int j = 65; j < 115; j++)
    {
        if (grille[cible[i].y - 2][cible[i].x] == j || grille[cible[i].y + 2][cible[i].x] == j || 
            grille[cible[i].y][cible[i].x - 2] == j || grille[cible[i].y][cible[i].x + 2] == j || 
            grille[cible[i].y - 2][cible[i].x - 2] == j || grille[cible[i].y - 2][cible[i].x + 2] == j || 
            grille[cible[i].y + 2][cible[i].x - 2] == j || grille[cible[i].y + 2][cible[i].x + 2] == j)
        {
            // Si les coordonnées ne sont pas valides, rappeler la fonction récursivement
            return constructeurCible(i, max, cible);
        }
    }

    // Si max est 18, assigner une lettre minuscule à la grille, sinon une lettre majuscule
    if (max == 18)
    {
        grille[cible[i].y][cible[i].x] = 97 + i;
    }
    else
    {
        grille[cible[i].y][cible[i].x] = 65 + i;
    }

    // Appeler récursivement la fonction pour l'index suivant
    return constructeurCible(i + 1, max, cible);
}
