#ifndef JEU_H
#define JEU_H

void jeuTimer(char str[100], char str2[100], int min, int sec);
void jeuScore(double suivant, char s_score[4], int score);
int winTest(int taille, int continuer);
int gameOver(int continuer);
int jeuPause(int pause, int recup);
void nouvellePomme(int xp, int yp, int grille[60][40]);
void finJeu(int fin);

#endif