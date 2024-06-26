#include "display.h"
#include "!temps.h"

/**
 * @brief Collecte les informations des joueurs pour chaque manche, et trouve le premier joueurs a joué.
 *
 * @param nb_joueur Nombre de joueurs.
 * @param cible Tableau de points représentant les cibles.
 * @param robot Tableau de points représentant les robots.
 * @param nb_manche Nombre total de manches.
 * @param manche Numéro de la manche actuelle.
 * @return Tableau contenant le nombre de coups pour chaque joueur.
 */

int *info_joueurs(int nb_joueur, Point *cible, Point *robot, int nb_manche, int manche)
{
    int choix_difficulte = difficulte();
    int *tab_coup = (int *)malloc(sizeof(int) * nb_joueur);
    if (tab_coup == NULL)
    {
        exit(EXIT_FAILURE);
    }
    but = malloc(sizeof(But) * nb_joueur);
    if (but == NULL)
    {
        exit(EXIT_FAILURE);
    }
    int minTours = INT_MAX;
    int premier = -1;
    int tab[8] = {0};
    int b;
    afficheManche(nb_manche, manche);
    for (int i = 0; i < nb_joueur; i++)
    {
        tab[i] = rand() % 18;
        printf("Joueurs n° %d est le robot: \033[91m%c\033[0m.\n Vous devez atteindre la cible \033[92m%c \033[0m\n", i + 1, grille[robot[i].y][robot[i].x], grille[cible[tab[i]].y][cible[tab[i]].x]);
        but[i].cible1.y = cible[tab[i]].y;
        but[i].cible1.x = cible[tab[i]].x;
    }
    horloge(choix_difficulte);
    cacherGrille();
    for (int i = 0; i < nb_joueur; i++)
    {
        int nbr_tour;
        printf("Robot\033[91m%c\033[0m.\nEn combien de coups pensez-vous toucher la cible \033[92m%c \033[0m", grille[robot[i].y][robot[i].x], grille[cible[tab[i]].y][cible[tab[i]].x]);
        nbr_tour = meilleur_scan("coups : ", 1);
        tab_coup[i] = nbr_tour;
        if (tab_coup[i] < minTours)
        {
            minTours = tab_coup[i];
            premier = i;
        }
        but[i].robot1.y = robot[i].y;
        but[i].robot1.x = robot[i].x;
        premier_joueur = premier;
    }
    premier_joueur = premier;
    printf("Le joueur %d a le nombre minimal de tours : %d.\nC'est donc le joueur %d qui va commence a jouer\n", premier_joueur + 1, minTours, premier_joueur + 1);
    return tab_coup;
}
