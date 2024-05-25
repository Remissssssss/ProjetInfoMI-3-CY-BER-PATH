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

## Utilisation

### Configuration initiale :
- Aller dans Terminal => modifier l'encodage => Europe => ## IBM850
- Lancer le programme.
- Saisir le nombre de joueurs (minimum 2, maximum 8).
- Saisir le nombre de manches à jouer.

### Contrôle des robots :
- Utiliser les touches Z (haut), Q (gauche), S (bas), D (droite) pour déplacer les robots.
- Atteindre les cibles avec le moins de coups possible.

### Déroulement du jeu :
- La grille est affichée à chaque manche.
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
