#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>

#include "initialisation.h"
#include "serpent.h"
#include "jeu.h"

#define CYCLE 80000L
#define SEC 1000000L
#define MIN_Xp 10
#define MAX_Xp 59
#define MIN_Yp 10
#define MAX_Yp 39

	int main(int argc,char * argv[]){
		system("clear");

		int continuer=1;
    	int x=310;
    	int y=270;
    	int taille=10;
    	int min=0, sec=0;
        int score=0;
        int xp, yp; /*coord pommes*/
    	int xo, yo; /*coord obstacle*/
    	int touche=XK_Down, toucheAtta, recup, pause, fin;
    	int i, t1, t2, comp;
    	int grille[60][40];
		int* xQueue;
    	int* yQueue;
    	int* xTemp;
    	int* yTemp;

        char str[100];
        char str2[100];
        char s_score[4];

    	double seconde;
    	double suivant= Microsecondes()+CYCLE;

		srand(time(NULL));

		xQueue = (int*) calloc(taille, sizeof(int));
    	yQueue = (int*) calloc(taille, sizeof(int));

        /*------INITIALISATIONS------*/

        initialisationAffichage(str, str2, min, sec, s_score, score, grille);

        couleur fond;
        couleur serpent;
        serpent=CouleurParNom("white");
        fond=CouleurParNom("dark red");

        initialisationObstacle(xo, yo, grille);
        initialisationPomme(xp, yp, grille);
        initialisationSerpent(x, y, taille, xQueue, yQueue);

        /*------------JEU------------*/

        y=y+10;
        touche=Touche();

        while(continuer&&touche!=XK_Escape){

            verifBord(x,y);
            jeuScore(suivant, s_score, score); /*Actualise le score*/

            if (Microsecondes()>seconde){ 
                sec++;
                seconde=Microsecondes()+SEC;
                if (sec==60){
                  sec=0;
                  min++;
                }
                jeuTimer(str, str2, min, sec); /*Actualise le timer*/
            }
                
            if (toucheAtta!=1){

                if (touche==XK_space){
                    touche=jeuPause(pause, recup); /*Met le jeu en pause*/
                }

                if (Microsecondes()>suivant){
                    ChoisirCouleurDessin(fond);
                    RemplirRectangle(xQueue[0],yQueue[0],10,10); /*Efface le dernier segment du snake*/

                    grille[xQueue[0]/10][yQueue[0]/10]=0;

                    for (comp = 0; comp < taille-1; comp++){ /*Déplace toutes les coordonnées du snake suite à la suppression du dernier segment*/
                        xQueue[comp]=xQueue[comp+1];
                        yQueue[comp]=yQueue[comp+1];
                        grille[xQueue[comp]/10][yQueue[comp]/10]=5;     
                    }
                 }

                xQueue[taille-1]=x; /*Ajout des coordonnées actuelles de la tête*/
                yQueue[taille-1]=y;
                grille[x/10][y/10]=5;

                if (Microsecondes()>suivant){ /*Vérifie si tous les segments du snake sont bien collés; sinon, on supprime le segment isolé*/
                    for (t1 = 0; t1 < 60; t1++){
                        for (t2 = 0; t2 < 40; t2++){
                            if (grille[t1][t2]==5){
                                if ((grille[t1][t2-1]!=5)&&(grille[t1][t2+1]!=5)&&(grille[t1-1][t2]!=5)&&(grille[t1+1][t2]!=5)){
                                    grille[t1][t2]=0;
                                    ChoisirCouleurDessin(fond);
                                    RemplirRectangle(t1*10,t2*10,10,10);
                                }
                            }
                        }
                    }
                }

                if (touche==XK_Right){ /*Gestion des evenements pour le déplacement*/
                    if (Microsecondes()>suivant){
                        suivant= Microsecondes()+CYCLE;
                        x=x+10;
                        afficherTete(x,y);
                    }
                } else if (touche==XK_Down){
                    if (Microsecondes()>suivant){
                        suivant= Microsecondes()+CYCLE;
                        y=y+10;
                        afficherTete(x,y);
                    }
                } else if (touche==XK_Left) {
                    if (Microsecondes()>suivant){
                        suivant= Microsecondes()+CYCLE;
                        x=x-10;
                        afficherTete(x,y);
                    }
                } else if (touche==XK_Up){
                    if (Microsecondes()>suivant){
                        suivant= Microsecondes()+CYCLE;
                        y=y-10;
                        afficherTete(x,y);
                    }
                }

                if (grille[x/10][y/10]==1) /*En cas de rencontre avec une pomme*/
                {
                    score=score+5; /* Augmentation du score */
                    taille=taille+2; /* Augmentation de la taille */

                    xTemp = (int*) calloc(taille, sizeof(int));
                    yTemp = (int*) calloc(taille, sizeof(int));

                    for (i = 0; i < taille; i++){ /* realloc ne marchait pas, on a donc dû le contourner */
                        xTemp[i]=xQueue[i];
                        yTemp[i]=yQueue[i];
                    }

                    free(xQueue);
                    free(yQueue);

                    xQueue = (int*) calloc(taille, sizeof(int));
                    yQueue = (int*) calloc(taille, sizeof(int));

                    for (i = 0; i < taille; i++){
                        xQueue[i]=xTemp[i];
                        yQueue[i]=yTemp[i];
                    }

                    free(xTemp);
                    free(yTemp);

                    grille[x/10][y/10]=0;
                    nouvellePomme(xp, yp, grille);
                }

                if (winTest(taille, continuer)==0)break; /*Si la partie est gagnée*/
                if (serpentCollision(grille, x, y, continuer, xQueue, yQueue, taille)==0)break; /*En cas de collision entrainant la fin de la partie (Game Over)*/

                toucheAtta=ToucheEnAttente();
            } else {
                recup=touche;
                touche=recupTouche(recup, touche); /*Récupère la touche pressée et teste si elle n'est pas opposée à la touche préssée juste avant*/
                toucheAtta=0;
            }
        }
        
        /*------------FIN------------*/

        finJeu(fin); /*Permet de ne pas fermer la fenetre juste après le game over et attend qu'on presse la touche Echap*/
        FermerGraphique();
        free(xQueue);
        free(yQueue);

        return EXIT_SUCCESS;
    }