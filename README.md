# C
C project template with codespace container to start coding.

Survie

Notre projet de première année de bachelor aéronautique et spatiale : un jeu en tour par tour basé sur le jeu de la vie de Conway, écrit en C pour la console.
L'idée
Le jeu de la vie de Conway, c'est fascinant à regarder, mais ce n'est pas vraiment un jeu : une fois la grille de départ posée, plus personne n'a de choix à faire. On a voulu ajouter une vraie décision pour le joueur.
Dans Survie, tu diriges une colonie de cellules vivantes. À chaque tour, tu en ajoutes pour la renforcer, la grille évolue comme dans le jeu de la vie, puis une catastrophe tue quelques cellules au hasard. Le but est simple : garder ta colonie en vie jusqu'au bout.
On joue seul. Il n'y a pas d'adversaire, le hasard vient des catastrophes.
Les règles de Conway
Chaque cellule est vivante ou morte. Ses voisines sont les 8 cellules autour d'elle, en comptant les diagonales. À chaque génération, toutes les cellules changent en même temps :
1.	Une cellule morte qui a exactement 3 voisines vivantes devient vivante (naissance).
2.	Une cellule vivante qui a 2 ou 3 voisines vivantes reste vivante (survie).
3.	Dans les autres cas, une cellule vivante meurt (isolement ou surpopulation).
On n'a pas touché à ces règles. La seule chose qu'on ajoute, c'est la catastrophe, et elle arrive après l'évolution, jamais pendant.
Comment se joue une partie
Le départ
La grille commence avec 3 blocs de 4 cellules (des petits carrés de 2 sur 2), placés en diagonale. Un bloc ne bouge pas tout seul : tant que rien ne le dérange, il reste tel quel.
Un tour
1.	Tu poses 2 cellules vivantes. Tu donnes la ligne, puis la colonne. Si la case est déjà prise, le programme te redemande. Tu ne peux pas passer ton tour.
2.	La grille évolue d'une génération, avec les règles de Conway.
3.	Une catastrophe tue des cellules vivantes choisies au hasard.
La catastrophe
Elle devient plus dure avec le temps :
•	tours 1 à 10 : 2 cellules tuées
•	tours 11 à 20 : 3 cellules tuées
•	tours 21 à 30 : 4 cellules tuées
S'il reste moins de cellules que ce nombre, elles meurent toutes.
Gagner ou perdre
Tu perds s'il ne reste plus aucune cellule vivante. Ton score est alors le nombre de tours que tu as tenus.
Tu gagnes si, à la fin du tour 30 et après la dernière catastrophe, il reste au moins une cellule vivante.
Quelques astuces
Un bloc de 2 sur 2 est stable, donc pense à en reformer. Si une catastrophe en laisse seulement 3 cellules en L, la quatrième naît toute seule à la génération suivante. À l'inverse, évite de coller trop de cellules ensemble : elles meurent de surpopulation.
Nos choix pour la grille
•	Taille : 15 sur 15. C'est assez grand pour jouer et ça tient bien dans la console.
•	Grille torique : les bords sont reliés entre eux, la droite touche la gauche et le haut touche le bas. Comme ça il n'y a pas de bord où les cellules sont moins bien entourées que les autres.
•	30 tours : une partie qui reste assez courte pour être jouée et montrée à l'oral.
•	2 cellules posées par tour : de quoi réagir à une catastrophe sans que ce soit trop facile.
Tous ces réglages sont des constantes écrites au début de program.c (LIGNES, COLONNES, TOURS_MAX, NB_POSES, NB_CATASTROPHES_DEBUT, TOURS_PAR_PALIER). Pour rendre le jeu plus facile ou plus dur, il suffit de les changer.
À l'écran
La grille s'affiche avec les numéros de lignes et de colonnes. Un O est une cellule vivante et un . est une case vide.
Lancer le jeu
Il faut compiler program.c puis lancer le programme :
gcc -std=c99 -Wall -o survie program.c
./survie

Ce qu'il y a dans le dépôt
•	program.c : le code du jeu
•	README.md : ce fichier
•	LLM.md : le modèle d'IA qu'on a utilisé, nos prompts et les documents qu'on lui a donnés
•	flows/ : les logigrammes des fonctions qui contiennent de la logique de jeu, faits avec Flow-C
Comment le code est organisé
On a séparé la logique du jeu de l'affichage et de la saisie.
•	Logique du jeu : vider_grille, placer_bloc, placer_depart, compter_vivantes, compter_voisins, evoluer_grille, nombre_catastrophes, provoquer_catastrophe, poser_cellule, partie_en_cours
•	Affichage et saisie : afficher_grille, saisie_nombre, phase_joueur, afficher_bilan
•	Le programme principal : main
On a respecté les contraintes du sujet : pas de struct, pas de pointeurs, un seul fichier, pas de bibliothèque externe, et aucune constante écrite en dur dans le code.
L'équipe
•	Ethan : le code et le dépôt
•	Sacha : le README
•	Noah : les logigrammes
•	Noé : la présentation orale
