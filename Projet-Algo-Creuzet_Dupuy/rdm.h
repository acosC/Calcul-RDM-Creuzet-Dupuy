#ifndef RDM_H_INCLUDED
#define RDM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/*
Création des structures du programme :

Nous avons fait le choix de mettre nos torseurs sous forme de tableau.

--> 3 paramètres principaux

-FORCES (f)
-Moment (m)
-Localisation (coordonnées : c)

*/

typedef enum {ENCASTREMENT = 0, GLISSIERE, PIVOT, PIVOT_GLISSANT, ROTULE,
LINEAIRE_RECT, LINEAIRE_ANNULAIRE, PONCTUELLE}liaison;

typedef struct{
    double m[3];
    double f[3];
    double c[3];
    char nom[1];
    liaison l;
    int inconnu;
    }torseur;

typedef struct{
    double m[3];
    double f[3];
    double c[3];
}torseur_cohesion;

/*
Création des prototypes des fonctions du programme :
*/

void NombrePoints(int nombre_point);
void Dimension(int var);
void Fctlongueur(int longueur,torseur *t);
void CreationT(int i,int nb_point,torseur *t,int var);
void MenuChoix(int ChoixUtilisateur,torseur *t,int origine);
void Initialisation(int i,torseur* t);
int Origine(int origine,int i);
int Localisation(int pb_plan, torseur* t, int i, int origine);

//int Orientation(torseur* t, int var);
void Liaison(int liaison, torseur* t, int i, int var);
void Forces(int var, torseur* t, int i, int forces);
int EntrerTorseur(int numero_torseur, torseur t[5], int variation,int origine);
void AfficherTorseur(torseur* t, int i);

//Résultante
void ResolForce2Torseurs(torseur* t);
void ResolForce3Torseurs(torseur* t);
void AfficherForces(torseur* t, int i);

//Moments
void babar(torseur *t, int origine, int nb_point);
void AfficherMoments(torseur* t, int i);

//torseurs
void AfficherlesTorseurs(torseur *t, int i);

//Graphique
void Initialisation_cohesion(torseur_cohesion *tc, int i);
void EffortNormal(torseur *t, int longueur, int nb_point);
void EffortTranchant(torseur *t, int longueur, int nb_point);
void MomentdeFlexionZ(torseur *t, int longueur, int nb_point);
void sleep(int o);


#endif // RDM_H_INCLUDED
