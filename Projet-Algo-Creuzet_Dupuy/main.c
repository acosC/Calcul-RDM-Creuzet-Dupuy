#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rdm.h"


/*
Interface utilisateur-->Questions à choix multiple

Constitution des éléments nécessaires à la résolution du problème.
Renvoi aux fonctions de "créationtorseur.c"

Menu de résolution, affichage des données calculées.
*/

int main()
{
    int nb_point, i, var = -1, a = 0, origine = -1, longueur = -1;
    int ChoixUtilisateur = 0;

    int* ptr_longueur = NULL;
    torseur_cohesion toco[3];

    printf("Bonjour, nous allons vous aider dans la resolution de votre probleme de RDM.\n");
    printf("Quelques questions pour comprendre l'exercice : \n");
    printf("Combien de points dans votre probleme ? ");
    scanf("%i",&nb_point);

    NombrePoints(nb_point);
    torseur t[nb_point];


    printf("Est-t-on sur un probleme a 2 dimensions ou a 3 dimensions ? ");
    printf("\nEntrez 2 ou 3\n");

    scanf("%i", &var);

    while (var != 2 && var != 3){
        printf("Choisissez entre 2 ou 3 ");
        scanf("%i",&var);
    }

    printf("Quelle est la longueur de la poutre étudiée ? ");
    scanf("%i", &longueur);

    while (longueur < 0){
        printf("Une longueur doit être positive ");
        scanf("%i",&longueur);
    }

    ptr_longueur = &longueur;

    for (i = 0 ; i < nb_point ; i++){
        printf("On va remplir les information du torseur %i\n",i+1);
        origine = EntrerTorseurInit(i, t, var, origine);
        EntrerTorseurFin(i, t, var, origine);
    }

    printf("1 - Donnez les Resultantes\n");
    printf("2 - Donnez les Moments\n");
    printf("3 - Donnez les Moments en 0\n");
    printf("4 - Donnez les Torseurs\n");
    printf("5 - Donnez les Diagrammes\n");
    printf("6 - Quitter le programme\n");
    printf("\nVeuillez entrer votre choix !\n");
    scanf("%i",&ChoixUtilisateur);

    do {
        switch(ChoixUtilisateur){

        case 1 :
            printf("Voici vos resultantes\n");
	    if (nb_point == 2)
		ResolForce2Torseurs(t);
	    else
            	ResolForce3Torseurs(t);
            break;

        case 2 :
            printf("Voici vos moments\n");
	          babar(t, origine, nb_point);
            break;

        case 3 :
            printf("Voici vos torseurs\n");
            AfficherlesTorseurs(t,0);
            AfficherlesTorseurs(t,1);
            if (nb_point == 3)
              AfficherlesTorseurs(t,2);
            break;

        case 4 :
            printf("Voici vos torseurs de cohesion\n");
            break;

        case 5 :
            printf("Voici vos diagrammes\n");
            Affichercourbe(t, ptr_longueur);
            break;

        case 6 :
            assert (a == 0);
        default :
            printf("Vous n'avez pas fais de choix\n");
            break;
        }

        printf("1 - Donnez les Resultantes\n");
        printf("2 - Donnez les Moments\n");
        printf("3 - Donnez les Torseurs\n");
        printf("4 - Donnez les Torseurs Cohesion\n");
        printf("5 - Donnez les Diagrammes\n");
        printf("6 - Quitter le programme\n");
        printf("\nVeuillez entrer votre choix !\n");
        scanf("%i",&ChoixUtilisateur);

    } while (ChoixUtilisateur != 6);

    return 0;
}
