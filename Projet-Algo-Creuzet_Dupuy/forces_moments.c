#include "rdm.h"
/*
Recherche des incconues :

Résolution des systèmes constituant le PFS
Affichage des résultantes
Affichage des Moments
*/

void AfficherForces(torseur* t, int i){
    int j;
    printf("\n\n---- Calcul des forces ----\n\n");
    printf("NOM : %s\n",t[i].nom);
    printf("FORCES : ");
    for (j = 0 ; j < 3; j++){
        printf("%f ",t[i].f[j]);
    }
    printf("\n");
}

void ResolForce2Torseurs(torseur *t){ //Cas simple

    int k = 0, i = 0;

    for (i = 0 ; i < 3 ; i++){
       if (t[k].f[i] == -1){
            t[k].f[i] = -(t[k+1].f[i]);
        }

        else if (t[k+1].f[i] == -1)
            t[k+1].f[i] = -(t[k].f[i]);
    }

    AfficherForces(t, 0);
    AfficherForces(t, 1);
}

void ResolForce3Torseurs(torseur *t){ //Cas " tors 1 inc

//test t[k+1].f.x == -2 && t[k+2].f.x != -2)

    int k = 0, i = 0;

    for (i = 0 ; i < 3 ; i++){
        if (t[k].f[i] == -1){

            t[k].f[i] = -(t[k+1].f[i] + t[k+2].f[i]);
        }

        else
            if (t[k+1].f[i] == -1)

                t[k+1].f[i] = -(t[k].f[i] + t[k+2].f[i]);

        else
            if (t[k+2].f[i] == -1)

              t[k+2].f[i] = -(t[k].f[i] + t[k+1].f[i]);
    }

    AfficherForces(t, 0);
    AfficherForces(t, 1);
    AfficherForces(t, 2);
}


void AfficherMoments(torseur* t, int i){
    int j;
    printf("\n\n---- Calcul des Moments ----\n\n");
    printf("NOM : %s\n",t[i].nom);
    printf("MOMENTS : ");
    for (j = 0 ; j < 3 ; j++){
        printf("%f ",t[i].m[j]);
    }
    printf("\n");
}

void babar(torseur *t, int nb_point){

	int k = 0, i = 0; 	// i=torseur k=x y z

  for (i = 0 ; i < 3 ; i++){
    for (k = 0 ; k < 3 ; k++){
      if(t[i].m[k] == -1)
        t[i].m[k] = 0;
    }
  }
  printf("oui");

	for (i = 0 ; i < 3 ; i++){
    if (t[i].inconnu == 1){
      t[i].m[2] = t[i].m[2]+(t[i].c[0]*t[i].f[1])-(t[i].c[1]*t[i].f[0]);
  		t[i].m[0] = t[i].m[0]+(t[i].c[1]*t[i].f[2])-(t[i].c[2]*t[i].f[1]);
  		t[i].m[1] = t[i].m[1]+(t[i].c[2]*t[i].f[0])-(t[i].c[0]*t[i].f[2]);
    }
	}

  if (nb_point == 2) {
    for (i = 0 ; i < 3 ; i++){
      if (i != 0){
        t[i].m[2] = -t[0].m[2] - t[i].m[2];
        t[i].m[0] = -t[0].m[0] - t[i].m[0];
        t[i].m[1] = -t[0].m[1] - t[i].m[1];
      }
    }
  }

  if (nb_point == 3) {
    for (i = 0 ; i < nb_point ; i++) {
      if (t[i].inconnu == 1){
        if (i == 0){
          t[i].m[2] = -t[1].m[2] - (t[1].c[0]*t[1].f[1]-t[1].c[1]*t[1].f[0]) - t[2].m[2] - (t[2].c[0]*t[2].f[1]-t[2].c[1]*t[2].f[0]);
          t[i].m[0] = -t[0].m[0] - (t[1].c[1]*t[1].f[2]-t[1].c[2]*t[1].f[1]) - t[2].m[0] - (t[2].c[1]*t[2].f[2]-t[2].c[2]*t[2].f[1]);
          t[i].m[1] = -t[0].m[1] - (t[1].c[2]*t[1].f[0]-t[1].c[0]*t[1].f[2]) - t[2].m[1] - (t[2].c[2]*t[2].f[0]-t[2].c[0]*t[2].f[2]);
        }
        if (i == 1){
          t[i].m[2] = -t[0].m[2] - t[i].m[2] - t[2].m[2] - (t[2].c[0]*t[2].f[1]);
          t[i].m[0] = -t[0].m[0] - t[i].m[0] - t[2].m[0] - (t[2].c[1]*t[2].f[2]);
          t[i].m[1] = -t[0].m[1] - t[i].m[1] - t[2].m[1] - (t[2].c[2]*t[2].f[0]);
        }
        if (i == 2){
          t[i].m[2] = -t[0].m[2] - t[i].m[2] - t[1].m[2] - (t[1].c[0]*t[1].f[1]);
          t[i].m[0] = -t[0].m[0] - t[i].m[0] - t[1].m[0] - (t[1].c[1]*t[1].f[2]);
          t[i].m[1] = -t[0].m[1] - t[i].m[1] - t[1].m[1] - (t[1].c[2]*t[1].f[0]);
        }
      }
    }
  }

	printf("\n");

  if (nb_point == 2){
    AfficherMoments(t,0);
  	AfficherMoments(t,1);
  }
  if (nb_point == 3){
    AfficherMoments(t,0);
  	AfficherMoments(t,1);
    AfficherMoments(t,2);
  }
}

void AfficherlesTorseurs(torseur *t, int i){

  printf("\n\n----Torseur %s----\n\n",t[i].nom);
  printf("COORD : %lf et %lf\n",t[i].c[0], t[i].c[1]);
  printf("||%lf | %lf||\n",t[i].f[0], t[i].m[0]);
  printf("||%lf | %lf||\n",t[i].f[1], t[i].m[1]);
  printf("||%lf | %lf||\n",t[i].f[2], t[i].m[2]);
  printf("ah");

}
