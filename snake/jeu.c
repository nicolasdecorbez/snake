#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>

#include"jeu.h"

#define CYCLE 80000L
#define SEC 1000000L
#define MIN_Xp 10
#define MAX_Xp 59
#define MIN_Yp 10
#define MAX_Yp 39

void jeuTimer(char str[100], char str2[100], int min, int sec){ /*Affiche le timer*/

  couleur fond;
  couleur texte;

  fond=CouleurParNom("dark red");
  texte=CouleurParNom("White");


  sprintf(str,"%.2d",min);
  sprintf(str2,"%.2d",sec);

  ChoisirCouleurDessin(fond);
  RemplirRectangle(0,420,200,100);

  ChoisirCouleurDessin(texte);

  EcrireTexte(10,450, str,2);
  EcrireTexte(40,450,":",2);
  EcrireTexte(50,450, str2,2);
}

void jeuScore(double suivant, char s_score[4], int score){ /*Affiche le score*/

  couleur fond;
  couleur texte;

  fond=CouleurParNom("dark red");
  texte=CouleurParNom("White");

  if (Microsecondes()>suivant) /*Le score*/
    {
      ChoisirCouleurDessin(fond);
      RemplirRectangle(520,420,200,100);

      ChoisirCouleurDessin(texte);
      sprintf(s_score,"%.4d",score);
      EcrireTexte(540,450,s_score,2);
    }
}

int winTest(int taille, int continuer){ /*Test si on a gagné*/
	couleur texte;
	texte=CouleurParNom("white");

	if (taille==60*40)
	{
		ChoisirCouleurDessin(texte);
        EcrireTexte(235,450,"You win!",2);
        continuer=0;
	}

	return continuer;
}

int gameOver(int continuer){ /*Affichage du game over*/
	couleur texte;
	texte=CouleurParNom("white");

	ChoisirCouleurDessin(texte);
    EcrireTexte(235,450,"Game Over",2);
    continuer=0;

    return continuer;
}

int jeuPause(int pause, int recup){ /*Mise en pause du jeu*/

	couleur texte;
	couleur fond;
	texte=CouleurParNom("white");
	fond=CouleurParNom("dark red");

	ChoisirCouleurDessin(texte);
    EcrireTexte(255,450,"Pause",2);

    pause=Touche();
    while(pause!=XK_space){
        pause=Touche();
    }

    ChoisirCouleurDessin(fond);
    RemplirRectangle(215,425,150,100);

    return recup;
}

void nouvellePomme(int xp, int yp, int grille[60][40]){ /*Affichage d'une nouvelle pomme et codage de cette dernière dans la grille*/

	couleur pomme;
	pomme=CouleurParNom("black");
	ChoisirCouleurDessin(pomme);

	xp=(rand() % (MAX_Xp - MIN_Xp + 1)) + MIN_Xp;
  	yp=(rand() % (MAX_Yp - MIN_Yp + 1)) + MIN_Yp;

  	while(grille[xp][yp]!=0){
  		xp=(rand() % (MAX_Xp - MIN_Xp + 1)) + MIN_Xp;
  		yp=(rand() % (MAX_Yp - MIN_Yp + 1)) + MIN_Yp;
    }

  	grille[xp][yp]=1;

  	xp=xp*10;
  	yp=yp*10;
  	
  	RemplirRectangle(xp,yp,10,10);

}

void finJeu(int fin){ /*Fin du jeu*/
	fin=Touche();
    while(fin!=XK_Escape)
    {
        fin=Touche();
    }
}