#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>

#include"serpent.h"
#include"jeu.h"

#define CYCLE 80000L
#define MIN_Xp 10
#define MAX_Xp 59
#define MIN_Yp 10
#define MAX_Yp 39

int serpentCollision(int grille[60][40], int x, int y, int continuer, int* xQueue, int* yQueue, int taille){ /*En cas de collision avec un obstacle/la queue/les bords*/

  	if (grille[x/10][y/10]==3) /*collision avec l'obstacle*/
        {
          continuer=gameOver(continuer);
        }

    if (grille[x/10][y/10]==5)
    {
        if (xQueue[taille-1]!=x||yQueue[taille-1]!=y)
        {
          continuer=gameOver(continuer);
        }
    }

    if (x<10)
        {
          continuer=gameOver(continuer);
        }

    if (y<10)
        {
          continuer=gameOver(continuer);
        }

    if (x>590)
        {
          continuer=gameOver(continuer);
        }

    if (y>390)
        {
          continuer=gameOver(continuer);
        }

        return continuer;
}

int recupTouche(int recup, int touche){ /*Récupère la touche pressée et teste si elle n'est pas opposée à la touche préssée juste avant*/
	recup=touche;
    touche=Touche();

    if (touche==XK_Down&&recup==XK_Up)
    {
        touche=recup;
    }
    if (touche==XK_Up&&recup==XK_Down)
    {
        touche=recup;
    }
    if (touche==XK_Left&&recup==XK_Right)
    {
        touche=recup;
    }
    if (touche==XK_Right&&recup==XK_Left)
    {
        touche=recup;
    }

    return touche;
}

void verifBord(int x, int y){ /*Evite que le cadre s'efface quand le serpent frôle*/
	couleur texte;
	texte=CouleurParNom("white");

	ChoisirCouleurDessin(texte);

	DessinerSegment(10,10,600,10); 
    DessinerSegment(10,10,10,400);

}

void afficherTete(int x, int y){ /*Affiche la tete du serpent*/
	couleur serpent;
	serpent=CouleurParNom("white");
	ChoisirCouleurDessin(serpent);
    RemplirRectangle(x,y,10,10);
}
