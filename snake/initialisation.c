#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>

#include "initialisation.h"
#include "jeu.h"

#define MIN_Xp 10
#define MAX_Xp 59
#define MIN_Yp 10
#define MAX_Yp 39

void initialisationAffichage(char str[100], char str2[100], int min, int sec, char s_score[4], int score, int grille[60][40]){

	int ini, jni;

	for (ini = 0; ini < 60; ini++)
	{
		for (jni = 0; jni < 40; jni++)
		{
			grille[ini][jni]=0;
		}
	} /*initialisation de grille à 0 sur toutes les valeurs*/

	InitialiserGraphique();
    CreerFenetre(200,200,610,460);

	couleur fond;
	couleur texte;
	texte=CouleurParNom("white");
	fond=CouleurParNom("dark red");

	EffacerEcran(fond);

	ChoisirCouleurDessin(texte);

	sprintf(str,"%.2d",min);
    sprintf(str2,"%.2d",sec);

    EcrireTexte(10,450, str,2);
    EcrireTexte(40,450,":",2);
    EcrireTexte(50,450, str2,2);

    sprintf(s_score,"%.4d",score);

	EcrireTexte(540,450,s_score,2); /*score*/

	DessinerSegment(10,10,600,10);
	DessinerSegment(10,10,10,400);
	DessinerSegment(600,10,600,400);
	DessinerSegment(10,400,600,400);

}

void initialisationObstacle(int xo, int yo, int grille[60][40]){
	
	int io;

	couleur obstacle;
	obstacle=CouleurParNom("Yellow");

	ChoisirCouleurDessin(obstacle);

	srand(time(NULL));

	xo=(rand() % (MAX_Xp - MIN_Xp + 1)) + MIN_Xp;
    yo=(rand() % (MAX_Yp - MIN_Yp + 1)) + MIN_Yp;

    while(yo>20){
          		xo=(rand() % (MAX_Xp - MIN_Xp + 1)) + MIN_Xp;
          		yo=(rand() % (MAX_Yp - MIN_Yp + 1)) + MIN_Yp;
          	}

    if (xo>29)
    {
    	for (io = 0; io < 20; io++)
    	{
    		grille[xo-io][yo]=3;
    		/* printf("xo : %d, yo : %d\n", xo-io, yo); <---- Coordonnées de l'obstacle */
    		RemplirRectangle((xo-io)*10,yo*10,10,10);
    	}
    } else {
    	for (io = 0; io < 20; io++)
    	{
    		grille[xo+io][yo]=3;
    		/* printf("xo : %d, yo : %d\n", xo+io, yo); <---- Coordonnées de l'obstacle */
    		RemplirRectangle((xo+io)*10,yo*10,10,10);
    	}
    }

    /* putchar('\n'); <---- A activer pour afficher les coordonnées */


}

void initialisationPomme(int xp, int yp, int grille[60][40]){

	int i;
	for (i = 0; i < 5; ++i)
	{
		nouvellePomme(xp,yp,grille);
	}

}

void initialisationSerpent(int x, int y, int taille, int* xQueue, int* yQueue){

	int ii;

	couleur serpent;
	serpent=CouleurParNom("white");

	ChoisirCouleurDessin(serpent);

	for (ii = 0; ii < taille; ii++){
		xQueue[ii]=x;
		yQueue[ii]=y+10*(taille-(ii));
		/*printf("xQueue[%d] = %d; yQueue[%d] = %d \n", ii, xQueue[ii], ii, yQueue[ii]);*/
		RemplirRectangle(xQueue[ii],yQueue[ii],10,10);
	}
}

