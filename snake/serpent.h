#ifndef SERPENT_H
#define SERPENT_H

void serpentDeplacement(int touche, double suivant, int x, int y);
int serpentCollision(int grille[60][40], int x, int y, int continuer, int* xQueue, int* yQueue, int taille);
void serpentVerification(double* suivant, int grille[60][40]);
void serpentBouge(double* suivant, int* xQueue, int* yQueue, int taille, int x, int y, int grille[60][40]);
int recupTouche(int recup, int touche);
void verifBord(int x, int y);
void afficherTete(int x, int y);
void verifSerpent(double suivant, int grille[60][40]);

#endif