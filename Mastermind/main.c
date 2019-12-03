#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*------------------------Notes------------------------*/

/*Le programme ne gère pas la gestion des doublons*/
/*Le programme ne gère pas les couleurs*/


/*------------------------Déclaration des Prototypes------------------------*/


void init_Chaine(char t_Chaine[5]);
void saisie (char c_saisie[5]);
void controle (char t_Chaine[5], char c_saisie[5]);

/*------------------------Programme Principal------------------------*/

int main()
{
	int compt = 0;							/*On initialise la variable compteur a 0 <--- Pour savoir combien d'essais ont été joués*/
    char t_Chaine[5];						/*On donne une taille au tableau qui contient la chaine a trouver <--- Sinon il me fait n'importe quoi*/
    char c_saisie[5];						/*On donne une taille au tableau qui contient la saisie de l'utilisateur <--- Sinon il me fait n'importe quoi*/

    init_Chaine(t_Chaine);					/*On utilise init_Chaine() pour set la clé aléatoire*/
    while (compt != 12)						/*Tant que le joueur n'a pas fait 12 coups <--- J'ai pas réussi a trouver comment faire avec le vérif*/
    {
	    saisie(c_saisie);					/*On utilise saisie() pour faire saisir une valeur a l'utilisateur et la contrôler*/
	    controle(t_Chaine, c_saisie);		/*On utilise controle() pour comparer la saisie utilisateur et la chaine générée*/
	    compt++;							/*On incrémente le compteur*/
	}

	return 0;
}


/*------------------------Procédures------------------------*/


void init_Chaine(char t_Chaine[5])			/*Fonction de génération de code a trouver*/
{
	srand(time(NULL));						/*Initialisation du Rnadom*/
    for (int i=0 ; i<4 ; i++)				/*Pour i de 1 a 4*/
    {
    	t_Chaine[i]= '0' + rand()%10;		/*On met dans la chaine le caractère ascii qui correspond a la valeur du caractère 0 + le nombre généré entre 1 et 9 <--- sinon il me met que c'est un nombre */
    }
    printf("%s \n \n", t_Chaine);			/*On affiche la chaine A ENLEVER POUR LE RENDU !!!!!!!!!!!!!!!!!!!!!!*/
}

void saisie (char c_saisie[5])									/*Fonction qui fait saisir une chaine a l'utilisateur et controle si elle est valide*/
{
	printf("\n Rentrez un nombre a quatre chiffres\n");
	scanf("%s", c_saisie);
	fflush(stdin);
	while (strlen(c_saisie) != 4)								/*Si la taille de la chaine saisie n'est pas égale à 4*/
	{
		printf("\n J'ai dit a QUATRE chiffres\n");					/*On redemande à l'utilisateur de la saisir*/
		scanf("%s", c_saisie);
		fflush(stdin);
	}
}

void controle (char t_Chaine[5], char c_saisie[5]) 				/*Fonction qui vérifie la saisie et la compare au code stocké*/
{
	int i;
	int j = 0;
	int vert, jaune, rouge;

	for (int i = 0; i < 4; i++)
	{
		rouge = 1;
		vert = 0;
		jaune = 0;
		if (t_Chaine[i] == c_saisie[i])
		{
			vert = 1;
			rouge = 0;
		}
		else
		{
			j = 0;
			while (j < 4 && jaune != 1)
			{
				if (c_saisie[i] == t_Chaine[j])
				{
					jaune = 1;
					rouge =0;
				}
				j++;
			}
		}
		if (vert == 1)
		{
			printf("V");
		}
		if(jaune == 1)
		{
			printf("J");
		}
		if (rouge == 1)
		{
			printf("R");
		}
	}
}
