#include "display.h"
#include "!deplacement.h"

/**
 * @brief Classe les joueurs en fonction de leur nombre de coups.
 *
 * @param tab_coup Tableau contenant le nombre de coups pour chaque joueur.
 * @param nb_joueur Nombre de joueurs.
 */


void classement(int *tab_coup, int nb_joueur)
{
    printf("le déplacement du robot ce fait avec les touche Z(haut) Q(gauche) S(bas) D(droite)\n");
    printf("le jeu commence!!!!\n");
    int a = tab_coup[0];
    for (int i = 1; i < nb_joueur; i++)
    {
        if (tab_coup[i] > a)
        { // on cherche le joueur avec le plus grands nombre de coups
            a = tab_coup[i];
        }
    }
    for (int k = 1; k <= a; k++)
    {
        for (int i = 0; i < nb_joueur; i++)
        {
            if (tab_coup[i] == k)
            { // on part de 1(le min) à a (le max) puis je cherhce dans la liste des joueurs et on les classes dans l'ordre croissant
                deplacement(tab_coup, nb_joueur, i);
            }
        }
    }
    printf("la partie est termine\n");
    for (int j = 0; j < nb_joueur; j++)
    {
        printf("joueur %d à %d point\n", j + 1, tab_point[j]);
    }
}

/**
 * @brief Détermine le gagnant parmi les joueurs en fonction de leurs points.
 *
 * @param nb_joueur Nombre de joueurs.
 */

void gagnant(int nb_joueur)
{
    int a = tab_point[0];
    int j = 0;
    int r = 0;
    for (int i = 0; i < nb_joueur; i++)
    {
        if (a < tab_point[i])
        {
            a = tab_point[i];
            j = i; // plus max de pts et son indice
        }
    }
    for (int i = 0; i < nb_joueur; i++)
    {
        if (a == tab_point[i])
        {
            r++; // parcours les pts pour savoir combien de joueurs ont le maximum de pts
        }
    }
    if (r == 1)
    { // si 1 seule prsn a le max de pts alors c'est le gagant
        printf("Le gagnant est le joueur n°%d, avec %d points.\n", j + 1, a);
    }
    else
    { //  il y a donc égalité
        printf("égalité!\n");
    }
}
