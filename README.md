# Projet : CY-BER-PATH

## Description
Ce projet est un jeu de labyrinthe interactif où les joueurs contrôlent des robots pour atteindre des cibles dans une grille générée aléatoirement. Le jeu comporte plusieurs manches et offre différents niveaux de difficulté. Le joueur avec le plus de points à la fin du jeu est déclaré gagnant.

## Fonctionnalités
- **Génération aléatoire de la grille** : Création dynamique des murs et des contours du labyrinthe.
- **Affichage esthétique de la grille** : Affichage amélioré pour une meilleure expérience utilisateur.
- **Gestion des mouvements des robots** : Contrôle des déplacements des robots par les joueurs.
- **Calcul et affichage des scores** : Suivi des scores des joueurs et détermination du gagnant.
- **Niveaux de difficulté** : Choix entre plusieurs niveaux de difficulté  ainsi que le temps pour une expérience de jeu adaptée.

## Structure des Fichiers
- `main.c` : Point d'entrée du programme, gère le déroulement général du jeu.
- `afficheGrille.c` : Fonctions pour afficher la grille du jeu.
- `cible.c` : Fonctions pour générer et placer les cibles ainsi que les robots dans la grille.
- `contour.c` : Génère les contours du labyrinthe.
- `grilleEstetique.c` : Fonctions pour la génération esthétique de la grille.
- `deplacement.c` : Gère le déplacement des robots dans le labyrinthe.
- `classementGagnant.c` : Gestion du classement des joueurs et détermination du gagnant.
- `murs.c` : Génère les murs du labyrinthe.
- `temps.c` : Gestion du chronomètre et des niveaux de difficulté.
- `nbrTour.c` : Gère les informations des joueurs et le nombre de tours.

## Utilisation

### Configuration initiale :
- Aller dans Terminal => modifier l'encodage => Europe => IBM8505 (marche sans changer l'encodage, mais pour une question d'éstétique, il est préférable de réaliser cette étape).
- Lancer le programme (avec la commande make clean && make && ./exec).
- Saisir le nombre de joueurs (minimum 2, maximum 8).
- Saisir le nombre de manches à jouer.

### Contrôle des robots :
- Utiliser les touches Z (haut), Q (gauche), S (bas), D (droite) , (les miniscules marchent également) puis appuyer sur entrée pour déplacer les robots.
- Atteindre les cibles avec le moins de coups possible (si la cible est atteignable).

### Déroulement du jeu :
- La grille est affichée à chaque manche.
- Les utilisateurs doivent choisir un niveau de difficultés qui fait varier le temps où la grille restera affiché.
- A la fin du temps la grille disparaît, les joueurs doivent rentrer le nombre de coups pour atteindre leur cible.
- Si le joueurs atteint avec le bon nombre de coup, il gagne 2 points, si il l'atteint avec un nombre de coup inférieur à celui renseigné il perd un points, si il n'atteint pas sa cible à la fin de ses coups tous les autres joueurs gagne 1 points.
- Les joueurs déplacent leurs robots tour à tour.
- Les scores sont calculés et affichés après chaque manche.

### Fin de la partie :
- Le joueur avec le plus de points après toutes les manches est déclaré gagnant.

## Auteurs
- **Développeur 1** : Archi Adame
- **Développeur 2** : Saouli Rémi
- **Développeur 2** : Vetier Guirec

## Installation
1. Clonez le dépôt sur votre machine locale :
   ```bash
   [https://github.com/Remissssssss/ProjetInfoMI-3-CY-BER-PATH](https://github.com/Remissssssss/ProjetInfoMI-3-CY-BER-PATH.git)
