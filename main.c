#include "display.h"
#include "!afficheGrille.h"
#include "!cible.h"
#include "!contours.h"
#include "!grilleEstetique.h"
#include "!deplacement.h"
#include "!classementGagnant.h"
#include "!murs.h"
#include "!temps.h"

int *tab_point;
unsigned char **grille;
int largeur;
int hauteur;
But *but;
int premier_joueur;

int meilleur_scan(char *message, int min)
{
    int ret_var = 0;
    int value = min - 1;
    while (value < min || ret_var != 1)
    {
        printf("%s", message);
        ret_var = scanf("%d", &value);
        while (getchar() != '\n')
        {
        }
    }
    return value;
}

int main()
{
    system("clear");
    srand(time(NULL));
    Point *cible;
    Point *robot;
    int nb_joueur;
    printf("  ____ _____ ______ _   ___      ________ _   _ _    _ ______                       \n");
    printf(" |  _ \\_   _|  ____| \\ | \\ \\    / /  ____| \\ | | |  | |  ____|                      \n");
    printf(" | |_) || | | |__  |  \\| |\\ \\  / /| |__  |  \\| | |  | | |__                         \n");
    printf(" |  _ < | | |  __| | . ` | \\ \\/ / |  __| | . ` | |  | |  __|                        \n");
    printf(" | |_) || |_| |____| |\\  |  \\  /  | |____| |\\  | |__| | |____                       \n");
    printf(" |____/_____|______|_| \\_|___\\/   |______|_| \\_|\\____/|______|                      \n");
    printf(" |  __ \\   /\\   | \\ | |/ ____|                                                      \n");
    printf(" | |  | | /  \\  |  \\| | (___                                                        \n");
    printf(" | |  | |/ /\\ \\ | . ` |\\___ \\                                                       \n");
    printf(" | |__| / ____ \\| |\\  |____) |                                                      \n");
    printf(" |_____/_/    \\_\\_| \\_|_____/___  ______ _____             _____     _______ _    _ \n");
    printf("  / ____\\ \\   / /          |  _ \\|  ____|  __ \\           |  __ \\ /\\|__   __| |  | |\n");
    printf(" | |     \\ \\_/ /   ______  | |_) | |__  | |__) |  ______  | |__) /  \\  | |  | |__| |\n");
    printf(" | |      \\   /   |______| |  _ <|  __| |  _  /  |______| |  ___/ /\\ \\ | |  |  __  |\n");
    printf(" | |____   | |             | |_) | |____| | \\ \\           | |  / ____ \\| |  | |  | |\n");
    printf("  \\_____|  |_|             |____/|______|_|  \\_\\          |_| /_/    \\_\\_|  |_|  |_|\n");
    printf("\n");

    do
    {
        nb_joueur = meilleur_scan("Combien de joueurs participent, un minimum de 2 joueurs est requis et un maximum de 8 joueurs\n", 2);
    } while (nb_joueur > 8);
    int nb_manche = meilleur_scan("Combien de manches voulez vous faire\n", 0);
    tab_point = malloc(nb_joueur * sizeof(int));
    if (tab_point == NULL)
    {
        printf("erreur allocation de mémoire");
        exit(3);
    }
    for (int i = 0; i < nb_joueur; i++)
    {
        tab_point[i] = 0;
    }
    for (int i = 0; i < nb_manche; i++)
    {
        constructeurGrille();
        cible = malloc(sizeof(Point) * 18);
        if (cible == NULL)
        {
            printf("erreur allocation de mémoire"); 
            exit(3);
        }
        robot = malloc(sizeof(Point) * nb_joueur);
        if (robot == NULL)
        {
            printf("erreur allocation de mémoire"); 
            exit(3);
        }
        printf("largeur: %d\n", largeur);
        printf("hauteur: %d\n", hauteur);
        consturcteurContour();
        constructeurCible(0, 18, cible);
        constructeurCible(0, nb_joueur, robot);
        constructeurMurs();
        afficheGrille();
        int *tab_coup = info_joueurs(nb_joueur, cible, robot, nb_manche, i + 1);
        afficheGrille();
        // printf("%d",premier_joueur);
        // printf("\n%c   %c\n",grille[but[0].robot1.y][but[0].robot1.x],grille[but[0].cible1.y][but[0].cible1.x]);
        classement(tab_coup, nb_joueur);
        free(grille);
        free(robot);
        free(cible);
        free(tab_coup);
        free(but);
    }
    gagnant(nb_joueur);
    free(tab_point);
    return 0;
}
