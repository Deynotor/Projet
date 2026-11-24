
#include <stdio.h>

// ===== Constantes =====
#define LIGNES 15
#define COLONNES 15
#define MORTE 0
#define VIVANTE 1

// Regles de Conway
#define NAISSANCE 3
#define SURVIE_MIN 2
#define SURVIE_MAX 3
#define VOISINAGE 1

// Regles du jeu
#define TOURS_MAX 30
#define NB_POSES 2
#define NB_CATASTROPHES_DEBUT 2
#define TOURS_PAR_PALIER 10

// Depart : des blocs de 4 cellules (formes stables) sur la diagonale
#define NB_BLOCS 3
#define DEBUT_BLOCS 2
#define ECART_BLOCS 4

// Constantes du programme
#define NB_LIGNES 10
#define NB_COLONNES 10

// Initialisation de la grille
void initialiser_grille(int grille[NB_LIGNES][NB_COLONNES])
{
    int ligne;
    int colonne;

    // Parcours de toutes les lignes
    for (ligne = 0; ligne < NB_LIGNES; ligne++)
    {
        // Parcours de toutes les colonnes
        for (colonne = 0; colonne < NB_COLONNES; colonne++)
        {
            // Toutes les cellules sont mortes au départ
            grille[ligne][colonne] = 0;
        }
    }

    // Configuration initiale pour les premiers tests
    grille[4][4] = 1;
    grille[4][5] = 1;
    grille[4][6] = 1;
}

// Affichage de la grille
void afficher_grille(int grille[NB_LIGNES][NB_COLONNES])
{
    int ligne;
    int colonne;

    printf("\n");

    // Parcours de toutes les lignes
    for (ligne = 0; ligne < NB_LIGNES; ligne++)
    {
        // Parcours de toutes les colonnes
        for (colonne = 0; colonne < NB_COLONNES; colonne++)
        {
            // Affichage d'une cellule vivante
            if (grille[ligne][colonne] == 1)
            {
                printf(" O ");
            }
            // Affichage d'une cellule morte
            else
            {
                printf(" . ");
            }
        }

        printf("\n");
    }
}

// Programme principal
int main()
{
    // Déclaration du tableau représentant la grille
    int grille[NB_LIGNES][NB_COLONNES];

    // Initialisation de la grille
    initialiser_grille(grille);

    // Affichage du titre
    printf("===== JEU DE LA VIE =====\n");

    // Affichage de la grille
    afficher_grille(grille);

    return 0;
}
