#ifndef INITIALISATION_H
#define INITIALISATION_H

void initialisationAffichage(char str[100], char str2[100], int min, int sec, char s_score[4], int score, int grille[60][40]);
void initialisationObstacle(int xo, int yo, int grille[60][40]);
void initialisationPomme(int xp, int yp, int grille[60][40]);
void initialisationSerpent(int x, int y, int taille, int* xQueue, int* yQueue);

#endif