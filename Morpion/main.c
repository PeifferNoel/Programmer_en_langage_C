//BUT: Réalisation d'un Morpion en C
//ENTREE: Les coodrdonnées de la case où le joueur veut jouer
//SORTIE: Une grille 3x3 de Morpion avec les coups des joueurs

//NB: Je n'ai pas réussi a faire une condition de victoire qui marche, donc le programme ne détecte pas la victoire d'un joueur et il faut remplir la grille pour que la partie soit officiellepment finie


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define TAILLE 3

//Définition des types: Joueur O, Joueur X et Case Vide pour remplir le tableau de façon propore
//Définition du type booleen pour faire une boucle de vérification

typedef enum {vide, rond, croix} ValeurGrille;
typedef enum {FALSE, TRUE} booleen;


//Prototypes

void initTerrain();
void affichageTerrain();
void jouerUnTour();

ValeurGrille n_terrainJeu [TAILLE][TAILLE];     //On déclare un tableau de ValeurGrille, donc de ronds, de croix et de vide
int ValeurJoueur = rond;                        //On initialise ValeurJoueur a rond, le joueur avec les O commencera toujours en premier


//Programme Principal

int main()
{

	initTerrain(n_terrainJeu);                    //On initialise le terrain
	affichageTerrain(n_terrainJeu);               //On l'affiche
	for (int i = 0; i < 9; i++)                   //Tant que le tableau n'est pas rempli:
	{
		jouerUnTour();                              //On demande au joueur de jouer un coup
		affichageTerrain();                         //On affiche le terrain modifié par les joueurs  
	}
  printf("Parie Terminée\n");

}




//--------------------------------Procédures et Fonctions--------------------------------

void initTerrain() //On initialise un tableau avec des vides, qui seront plus tard considérés comme des "."
{

	int i,j;

    for (i = 0; i < TAILLE; i++)          //Pour toutes les lignes
    {
        for (j = 0; j < TAILLE; j++)      //Pour toutes les colonnes
        {
            n_terrainJeu[i][j] = vide;    //On met "vide" dans les cases du tableau
        }
    }

}

void affichageTerrain() //On affiche le tableau en fonction de ce qu'il y a dans le case
{

	int i, j;

  	for (i=0; i<TAILLE; i++)
  	{
    	for (j=0; j<TAILLE; j++)
    	{
      		switch (n_terrainJeu[i][j])
      		{
	      		case vide:
					printf(". ");
				break;
	      		case rond:
					printf("O ");
				break;
	      		case croix:
					printf("X ");
				break;
      		}
    	}
    	printf("\n");
  	}

}


void jouerUnTour() //On demande au joueur les coordonnées de la case qu'il souaite remplir, puis on vérifie si la saisie est correcte
{

	int ligne, col;
	booleen verif = FALSE;

	printf("Saisissez le numero de la ligne puis celui de la colonne: \n");

	do
	{

		scanf("%d %d", &ligne, &col);
		printf("\n");

		if ((ligne > 0) && (ligne <= TAILLE) && (col > 0) && (col <= TAILLE))    //Si le joueur entre bien une valeur entre 1 et 3 (les bornes du tableau),
		{
    		ligne--;
    		col--;		                                                           //On enlève 1 pour rester dans le tableau (comme il va de 0 à 2)
    		if (n_terrainJeu[ligne][col] != vide)                                //Puis on vérifie si la case et déjà remplie
    		{
    			printf("Cette case est deja remplie, sale tricheur ! \n");
    		}
    		else                                                                 //Si c'est bon,
    		{
    			verif = TRUE;                                                      //verif passe à TRUE, la saisie est correcte
    			n_terrainJeu[ligne][col] = ValeurJoueur;                           //La case prends la valeur de ValeurJoueur (Donc rond ou croix)
    			if (ValeurJoueur == rond)                                          //On inverse ensuite ValeurJoueur, pour que ce soit à l'autre joueur de jouer 
    			{
   					ValeurJoueur = croix;
   				}
   				else
    			{
    				ValeurJoueur = rond;
    			}

    		}
    	}
    	else
    	{
    		printf("Saisie Incorrecte, veuillez reessayer\n");
    	}

	} while (!verif);

}