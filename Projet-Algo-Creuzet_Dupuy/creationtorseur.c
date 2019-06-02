#include "rdm.h"
#include <assert.h>

/*
Détail de la collecte des données :

-Paramètres du problème
-Initialisation et création des Torseurs
-Localisation de ces derniers
-Mise en évidence des paramètres inconnus

-Banque de données des types de liaisons et leurs torseurs associés
*/


//===================================

const int valMax = 4;
int* ptr_longueur = NULL;
int nb_point, i, var = -1, a = 0, longueur = -1;

void NombrePoints(int nombre_point){

    while (nombre_point > 4 || nombre_point <= 0){

        while (nombre_point <= 0){
        printf("Vous ne pouvez pas avoir un nombre de point negatif, combien de points avez-vous dans votre exercice ? ");
        scanf("%i",&nombre_point);
        }
        while (nombre_point > 3){
        printf("Vous ne pouvez pas nous donner trop de points, combien de poins avez-vous dans ton exercice ? ");
        scanf("%i",&nombre_point);
        }
    }
}

void Dimension(int var){

  while (var != 2 && var != 3){

      printf("Choisissez entre 2 ou 3 ");
      scanf("%i",&var);

  }
}

void Fctlongueur(int longueur,torseur *t){

  while (longueur < 0){
      printf("Une longueur doit être positive ");
      scanf("%i",&longueur);
  }

  ptr_longueur = &longueur;

}

void CreationT(int i,int nb_point,torseur *t,int var){

  int origine = 1;

  for (i = 0 ; i < nb_point ; i++){
      printf("On va remplir les information du torseur %i\n",i+1);

      origine = EntrerTorseur(i, t, var,origine);
  }

}

void MenuChoix(int ChoixUtilisateur,torseur *t,int origine){

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
          printf("Voici vos diagrammes\n");
          EffortNormal(t,longueur,nb_point);
          EffortTranchant(t,longueur,nb_point);
          MomentdeFlexionZ(t,longueur,nb_point);
          break;

      case 5 :
          assert (a == 0);
      default :
          printf("Vous n'avez pas fais de choix\n");
          break;
      }

      printf("1 - Donnez les Resultantes\n");
      printf("2 - Donnez les Moments\n");
      printf("3 - Donnez les Torseurs\n");
      printf("4 - Donnez les Diagrammes\n");
      printf("5 - Quitter le programme\n");
      printf("\nVeuillez entrer votre choix !\n");
      scanf("%i",&ChoixUtilisateur);

  } while (ChoixUtilisateur != 6);
}

void Initialisation(int i, torseur* t){

    int j;

    t[i].l = -1;
    for (j = 0 ; j < 3 ; j++){
        t[i].f[j] = 1;
        t[i].m[j] = 1;
    }
}

int Origine(int origine,int i){

  if (origine == 1 ){
    printf("Est-ce le point d'origine ? (0 : oui | 1 : non)\n");
    scanf("%i",&origine);
  }
  return origine;

}


int Localisation(int var, torseur* t, int i, int origine){

    origine = Origine(origine,i);

    if (var == 2){
        t[i].c[2] = 0;
        if (origine == 0)
        {
          origine=2;
          t[i].c[0] = 0;
          t[i].c[1] = 0;
        }
        else {
          printf("Ou est-il localise ?\n");
          printf("en x : ");
          scanf("%lf",&t[i].c[0]);
          printf("en y : ");
          scanf("%lf",&t[i].c[1]);
          }
    }
    if (var == 3){
        if (origine == 0)
        {
          origine=2;
          t[i].c[0] = 0;
          t[i].c[1] = 0;
          t[i].c[2] = 0;
        }
        else
        {
          printf("Ou est-il localise ?\n");
           printf("en x : ");
           scanf("%lf",&t[i].c[0]);
           printf("en y : ");
           scanf("%lf",&t[i].c[1]);
           printf("en z : ");
           scanf("%lf",&t[i].c[2]);
        }
    }
    return origine;
}

void Liaison(int liaison, torseur* t, int i, int var){
    switch (liaison){
    case 0:
        if (var == 2){
            t[i].f[2] = 0;
            t[i].m[0] = 0;
            t[i].m[1] = 0;
        }
        break;

    case 1:
        if (var == 2){
            t[i].f[2] = 0;
            t[i].m[0] = 0;
            t[i].m[1] = 0;
        }
        t[i].f[0] = 0;
        break;

    case 2 :
        if (var == 2){
            t[i].f[2] = 0;
            t[i].m[1] = 0;
        }
        t[i].m[0] = 0;
        break;

    case 3 :
        if (var == 2){
            t[i].f[2] = 0;
            t[i].m[1] = 0;
        }
        t[i].m[0] = 0;
        t[i].f[0] = 0;
        break;

    case 4 :
        if (var == 2){
            t[i].f[2] = 0;
        }
        t[i].m[0] = 0;
        t[i].m[1] = 0;
        t[i].m[2] = 0;
        break;

    case 5 :
        t[i].m[0] = 0;
        t[i].m[1] = 0;
        t[i].f[2] = 0;
        t[i].f[0] = 0;
        break;

    case 6 :
        if (var == 2){
            t[i].f[2] = 0;
        }
        t[i].m[2] = 0;
        t[i].m[0] = 0;
        t[i].m[1] = 0;
        t[i].f[0] = 0;
        break;

    case 7 :
        if (var == 2){
            t[i].f[2] = 0;
        }
        t[i].m[2] = 0;
        t[i].m[1] = 0;
        t[i].m[0] = 0;
        t[i].f[2] = 0;
        t[i].f[0] = 0;
        break;
    }
}

void Forces(int var, torseur* t, int i, int forces){

    int j = 0;

    switch(forces){
    case 0 :
        t[i].inconnu = 0;
        while (j < 3){
            if (t[i].f[j] != 0){
                if (j == 0)
                    printf("Force en X : ");
                if (j == 1)
                    printf("Force en Y : ");
                if (j == 2)
                    printf("Force en Z : ");
                scanf("%lf", &t[i].f[j]);
            }
            j++;
        }
        j = 0;
        while (j < 3){
            if (t[i].m[j] != 0){
                if (j == 0)
                    printf("Moment en X : ");
                if (j == 1)
                    printf("Moment en Y : ");
                if (j == 2)
                    printf("Moment en Z : ");
                scanf("%lf", &t[i].m[j]);
            }
            j++;
        }
        break;

    case 1 :
        t[i].inconnu = 1;
        for (j = 0 ; j < 3 ; j++){
            if (t[i].f[j] != 0)
                t[i].f[j] = -1;
            if (t[i].m[j] != 0)
                t[i].m[j] = -1;
        }
        break;
    }
}

/*
scinder la fonction entrer torseur pour permettre de définir
si il est à l'origine ou non. (éviter répétition de la qst)
*/

int EntrerTorseur(int i, torseur t[valMax], int var, int origine){
    int  liaison = -1, forces = -1;

    Initialisation(i, t);

    printf("Comment s'appelle votre point ? ");
    scanf("%s",t[i].nom);

    origine=Localisation(var, t, i, origine);

    printf("test origine 3 %i\n",origine);

    printf("Quelle est la liaison de votre point ?\n");
    printf("0 - Encastrement\n");
    printf("1 - Glissiere\n");
    printf("2 - Pivot\n");
    printf("3 - Pivot Glissant\n");
    printf("4 - Rotule\n");
    printf("5 - Lineaire rectitiligne\n");
    printf("6 - Lineaire annulaire\n");
    printf("7 - Ponctuelle\n");
    scanf("%i", &liaison);
    t[i].l = liaison;              //choix type de liaison

    Liaison(liaison, t,i, var);

    printf("Connaissez-vous les forces/moments qui s'appliquent sur ce point ?\n"); //-1
    printf("0 - oui\n");
    printf("1 - non\n");
    scanf("%i", &forces);

    Forces(var, t, i, forces);
    AfficherTorseur(t, i);

    return origine;
}

/*
Affichages de vérification :
*/

void AfficherTorseur(torseur* t, int i){
    printf("\n\n----RECAP Torseur----\n\n");
    printf("NOM : %s\n",t[i].nom);
    printf("TYPE : %i\n",t[i].l);
    printf("COORD : %lf et %lf\n",t[i].c[0], t[i].c[1]);
    printf("FORCES : %lf, %lf et %lf\n\n",t[i].f[0], t[i].f[1], t[i].f[2]);
    printf("MOMENTS : %lf, %lf et %lf\n\n",t[i].m[0], t[i].m[1], t[i].m[2]);
}
