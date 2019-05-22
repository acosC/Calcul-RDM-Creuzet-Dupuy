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
  torseur_cohesion toco[3];
  
  
    printf("\n=============================Calcul-Rdm-Dupuy-Creuzet===========================\n\n");
    printf("Bonjour, nous allons vous aider dans la resolution de votre probleme de RDM.\n");
    printf("Quelques questions pour comprendre l'exercice : \n");
    printf("\nAvant toute chose :\n");
    printf("Veillez à entrer vos torseurs dans l'ordre suivant :\n-->origine puis suivant les x croissant\n\n");
    printf("Combien de points dans votre probleme ? ");
    scanf("%i",&nb_point);

    NombrePoints(nb_point);
    torseur t[nb_point];

    printf("Est-t-on sur un probleme a 2 dimensions ou a 3 dimensions ? ");
    printf("\nEntrez 2 ou 3\n");
    scanf("%i", &var);

    Dimension(var);


    printf("Quelle est la longueur de la poutre étudiée ? ");
    scanf("%i", &longueur);

    Fctlongueur(longueur,t);

    CreationT(i,nb_point,t,var);

    printf("1 - Donnez les Resultantes\n");
    printf("2 - Donnez les Moments\n");
    printf("3 - Donnez les Moments en 0\n");
    printf("4 - Donnez les Torseurs\n");
    printf("5 - Donnez les Diagrammes\n");
    printf("6 - Quitter le programme\n");
    printf("\nVeuillez entrer votre choix !\n");
    scanf("%i",&ChoixUtilisateur);


    MenuChoix(ChoixUtilisateur,t,origine);

    return 0;
}
