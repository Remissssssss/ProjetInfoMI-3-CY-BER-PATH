#include "display.h"


void afficheManche(int nb_manche, int manche)
{ // Affiche les manches tout le temps
    printf("Manche %d/%d\n", manche, nb_manche);
    if (manche == nb_manche)
    {
        printf("La partie est terminée après %d manches.\n", nb_manche);
    }
}

int difficulte()
{
    int diff;
    do
    {
        printf("Choisir le mode de difficulté : \n");
        printf("1 => Facile\n");
        printf("2 => Moyen\n");
        printf("3 => Difficile\n");

        diff = meilleur_scan("Veuillez donner le mode de difficulté\n", 1);
    } while (diff > 3);
    return diff;
}

// Intervale en secondes

int horloge(int difficulte)
{
    int tempsPasse;
    switch (difficulte)
    {
    case (1):
        tempsPasse = 90;
        break;

    case (2):
        tempsPasse = 60;
        break;

    case (3):
        tempsPasse = 30;
        break;
    }

    while (tempsPasse >= 0)
    {
        if (tempsPasse % 10 == 0)
        {
            printf("Temps restant : %d secondes\n", tempsPasse);
        }
        sleep(1); // Attendre une seconde
        tempsPasse--;
    }
    printf("Temps écoulé !\n");
}

int cacherGrille()
{
    system("clear");

    printf("   ____ __     __           ____  ______ _____             _____     _______ _    _ \n");
    printf("  / ____\\ \\   / /          |  _ \\|  ____|  __ \\           |  __ \\ /\\|__   __| |  | |\n");
    printf(" | |     \\ \\_/ /   ______  | |_) | |__  | |__) |  ______  | |__) /  \\  | |  | |__| |\n");
    printf(" | |      \\   /   |______| |  _ <|  __| |  _  /  |______| |  ___/ /\\ \\ | |  |  __  |\n");
    printf(" | |____   | |             | |_) | |____| | \\ \\           | |  / ____ \\| |  | |  | |\n");
    printf("  \\_____|  |_|             |____/|______|_|  \\_\\          |_| /_/    \\_\\_|  |_|  |_|\n");
    printf("\n");
}
