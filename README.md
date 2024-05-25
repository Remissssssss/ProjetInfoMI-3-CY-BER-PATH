# Projet : CY-BER-PATH

## Description
Ce projet est un jeu de labyrinthe interactif où les joueurs contrôlent des robots pour atteindre des cibles dans une grille générée aléatoirement. Le jeu comporte plusieurs manches et offre différents niveaux de difficulté. Le joueur avec le plus de points à la fin du jeu est déclaré gagnant.

## Fonctionnalités
- **Génération aléatoire de la grille** : Création dynamique des murs et des contours du labyrinthe.
- **Affichage esthétique de la grille** : Affichage amélioré pour une meilleure expérience utilisateur.
- **Gestion des mouvements des robots** : Contrôle des déplacements des robots par les joueurs.
- **Calcul et affichage des scores** : Suivi des scores des joueurs et détermination du gagnant.
- **Niveaux de difficulté** : Choix entre plusieurs niveaux de difficulté pour une expérience de jeu adaptée.

## Structure des Fichiers
- `main.c` : Point d'entrée du programme, gère le déroulement général du jeu.
- `afficheGrille.c` : Fonctions pour afficher la grille du jeu.
- `cible.c` : Fonctions pour générer et placer les cibles dans la grille.
- `contour.c` : Génère les contours du labyrinthe.
- `grilleEstetique.c` : Fonctions pour la génération esthétique de la grille.
- `deplacement.c` : Gère le déplacement des robots dans le labyrinthe.
- `classementGagnant.c` : Gestion du classement des joueurs et détermination du gagnant.
- `murs.c` : Génère les murs du labyrinthe.
- `temps.c` : Gestion du chronomètre et des niveaux de difficulté.
- `nbrTour.c` : Gère les informations des joueurs et le nombre de tours.

## Installation
1. Clonez le dépôt sur votre machine locale :
   ```bash
   [https://github.com/Remissssssss/ProjetInfoMI-3-CY-BER-PATH](https://github.com/Remissssssss/ProjetInfoMI-3-CY-BER-PATH.git)
