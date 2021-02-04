# C : Snake

Durant ma première année de DUT Informatique, j'ai eu l'occasion de recréer le jeu **Snake** en C.

J'ai pu utiliser les allocations dynamiques afin de gérer la taille du serpent, mais aussi coder pour la première fois une interface graphique, et de perfectionner mes compétences en C. C'est mon tout premier grand projet, et même s'il contient bien des défauts, il m'a permit de vraiment progresser dans ce langage.

Vous trouverez dans le dossier `ressources` (ou [ici](https://github.com/nicolasdecorbez/snake/blob/main/ressources/RAPPORT.pdf)) le fichier `RAPPORT.pdf` contenant tout notre raisonnement, des screenshots et des explications plus détaillées du code. Je vous mets ci-dessous l'extrait le plus important.

## Déroulement du projet

Pour le codage de notre jeu, nous avons choisi de créer un **tableau multidimensionnel**, nommé `grille[60][40]` initialisé à 0 pour toutes les valeurs. Ensuite, il a fallu choisir des valeurs pour représenter chaque type de case possible : `1` pour les **pommes**, `3` pour l’**obstacle**, et `5` pour le **serpent**. Ainsi, il nous suffisait de tester si les coordonnées de la tête `(int x, int y)` rentrées dans la grille était égal à un **espace vide** (0), **une pomme** (1), etc. Pour la gestion des collisions, c’est ce qui nous a paru le plus simple.

Les coordonnées du corps du serpent sont stockées dans **deux tableaux de pointeurs** `(int* xQueue, int* yQueue)`. La taille du serpent est gérée par la variable `int taille`, qui s’incrémente de 2 à chaque pomme mangée. Ainsi, les tableaux sont **alloués dynamiquement** avec la fonction `xQueue = (int*) calloc(taille, sizeof(int));` afin de ne pas utiliser trop de mémoire inutilement.

Les pommes sont affichées avec la fonction `nouvellePomme(int xp, int xp, int grille[60][40])`. **Les coordonnées sont générées aléatoirement** grâce à la fonction `srand(time(NULL))` puis `rand()`. Les coordonnées sont rentrées dans grille, codées `1`. Quand une ****pomme** est mangée, les coordonnées de la tête sont rentrées dans grille pour **réinitialiser** la valeur à `0`, le **score** augmente de `5`, et la **taille** s’incrémente de `2`.

La fonction `serpentCollision()` teste les coordonnées de la tête en les rentrant dans grille. Elle continent **6 conditions** qui renvoient chacune la fonction `gameOver()`, qui elle affiche *Game over* en cas de collision avec l’obstacle, la queue ou les bords de la zone de jeu.

Les autres fonctions sont majoritairement des **fonctions d’affichage**, comme `jeuTimer()` ou `jeuScore()`, qui transforment des entier en chaine de caractère avec `sprintf()` afin de les afficher grâce à `EcrireTexte()`.


## Interface graphique

Pour l'interface graphique, nous devions utiliser un wrapper basé sur XLib, fourni par l'[IUT de Sénart-Fontainebleau](https://www.iut-fbleau.fr/).

Ci-dessous une description brève de cette bibliothèque :

> Cette bibliothèque, écrite en C, est construite directement sur la couche XLib. Elle fournit des primitives de dessins très rudimentaires. Son seul interêt est de pouvoir écrire des applications graphiques sans avoir à connaître le fonctionnement et l'API de la couche X11. Elle est evidemment (très) perfectible; tout étudiant désirant aller plus loin est fortement convier à l'apprentissage de la programmation sous X.
