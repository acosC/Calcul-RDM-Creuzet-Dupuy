#include "rdm.h"
#include "gnuplot_i.h"

void Initialisation_cohesion(torseur_cohesion *tc){

      int j,i;
      for (i = 0 ; i < 3 ; i++) {

        for (j = 0 ; j < 3 ; j++){

            tc[i].f[j] = 0;
            tc[i].m[j] = 0;

        }

      }
}

void EffortNormal(torseur *t, int longueur, int nb_point){

  int i;
  double x[157], y[157];
  gnuplot_ctrl *h;    //on touche pas à ça

  h = gnuplot_init();   //pas touche

  gnuplot_setstyle(h, "linespoints");   //pas touche deco

  if (nb_point == 2 && t[1].c[0] == (double)longueur){ //si 2 torseurs qui parcourent toute la poutre
    if (t[0].f[0] != 0 && t[1].f[0] != 0){  //cas ou l'effort normal existe
      for (i = 0 ; i <= longueur + 35 ; i++){   //une seule zone a etudier

        x[i] = (double)i;
        y[i] = -t[0].f[0];

      }
    }
    else{
      for (i = 0 ; i <= longueur + 2 ; i++){  //cas ou l'effort normal n'existe pas

        x[i] = (double)i;
        y[i] = (double)0;

      }
    }
  }

  if (nb_point == 2 && t[1].c[0] != longueur){ //si 2 torseurs qui ne parcourent pas toute la poutre -> 2 zones a etudier
    if (t[0].f[0] != 0 && t[1].f[0] != 0){  //cas ou l'effort normal existe

      for (i = 0 ; i <= t[1].c[0] ; i++){ //1ere zone etudier entre les 2 torseurs

        x[i] = (double)i;
        y[i] = -t[0].f[0];

      }

      for (i = t[1].c[0] ; i <= longueur ; i++){  //2eme zone a étudier entre 2eme torseurs et le bout de la poutre

        x[i] = (double)i;
        y[i] = -t[0].f[0] - t[1].f[0];

      }
    }

    else{
      for (i = 0 ; i <= longueur ; i++){  //cas ou l'effort normal n'existe pas

        x[i] = (double)i;
        y[i] = (double)0;

      }
    }
  }

  if (nb_point == 3 && t[2].c[0] == longueur){ //si 3 torseurs qui parcourent toute la poutre -> 2 zones a etudier
    if (t[0].f[0] != 0 && t[1].f[0] != 0 && t[2].f[0] != 0){  //cas ou l'effort normal existe

      for (i = 0 ; i <= t[1].c[0] ; i++){ //1ere zone a etudier entre 1er et 2eme torseur

        x[i] = (double)i;
        y[i] = -t[0].f[0];

      }

      for (i = t[1].c[0] ; i <= t[2].c[0] ; i++){ //2eme zone a etudier entre 2eme et 3eme torseur

        x[i] = (double)i;
        y[i] = -t[0].f[0] - t[1].f[0];

      }

    }
    else{
      for (i = 0 ; i <= longueur ; i++){  //cas ou l'effort normal n'existe pas

        x[i] = (double)i;
        y[i] = (double)0;

      }
    }
  }

  if (nb_point == 3 && t[2].c[0] != longueur){ //si 3 torseurs qui ne parcourt pas toute la poutre -> 3 zones a etudier
    if (t[0].f[0] != 0 && t[1].f[0] != 0 && t[2].f[0] != 0){  //cas ou l'effort normal existe

      for (i = 0 ; i <= t[1].c[0] ; i++){ //1ere zone a etudier entre le 1er et le 2eme torseur

        x[i] = (double)i;
        y[i] = -t[0].f[0];

      }

      for (i = t[1].c[0] ; i <= t[2].c[0] ; i++){ //2eme zone a etudier entre le 2eme et le 3eme torseur

        x[i] = (double)i;
        y[i] = -t[0].f[0] - t[1].f[0];

      }

      for (i = t[2].c[0] ; i <= longueur ; i++){  //3eme zone a etudier entre le 3eme torseur et le bout de la poutre

        x[i] = (double)i;
        y[i] = -t[0].f[0] - t[1].f[0] - t[2].f[0];

      }
    }
    else{
      for (i = 0 ; i <= longueur ; i++){  //cas ou l'effort normal n'existe pas

        x[i] = (double)i;
        y[i] = (double)0;

      }
    }
  }

  gnuplot_plot_xy(h, x, y, longueur, "Effort normal (N)");
  sleep(0);

  gnuplot_plot_slope(h, 0.0, 0.0, "y = 0");
  sleep(2);

  return;
}

void EffortTranchant(torseur *t, int longueur, int nb_point){

  int i;
  double x[157], y[157];
  gnuplot_ctrl *h;      //on touche pas à ça
  h = gnuplot_init();   //pas touche

  gnuplot_setstyle(h, "linespoints");   //pas touche deco

  if (nb_point == 2 && t[1].c[0] == (double)longueur){ //si 2 torseurs qui parcourent toute la poutre
    if (t[0].f[1] != 0 && t[1].f[1] != 0){  //cas ou l'effort tranchant existe
      for (i = 0 ; i <= longueur ; i++){   //une seule zone a etudier

        x[i] = (double)i;
        y[i] = -t[0].f[1];

      }
    }
    else{
      for (i = 0 ; i <= longueur ; i++){  //cas ou l'effort tranchant n'existe pas

        x[i] = (double)i;
        y[i] = (double)0;

      }
    }
  }

  if (nb_point == 2 && t[1].c[0] != longueur){ //si 2 torseurs qui ne parcourent pas toute la poutre -> 2 zones a etudier
    if (t[0].f[1] != 0 && t[1].f[1] != 0){  //cas ou l'effort tranchant existe

      for (i = 0 ; i <= t[1].c[0] ; i++){ //1ere zone etudier entre les 2 torseurs

        x[i] = (double)i;
        y[i] = -t[0].f[1];

      }

      for (i = t[1].c[0] ; i <= longueur ; i++){  //2eme zone a étudier entre 2eme torseurs et le bout de la poutre

        x[i] = (double)i;
        y[i] = -t[0].f[1] - t[1].f[1];

      }
    }

    else{
      for (i = 0 ; i <= longueur ; i++){  //cas ou l'effort tranchant n'existe pas

        x[i] = (double)i;
        y[i] = (double)0;

      }
    }
  }

  if (nb_point == 3 && t[2].c[0] == (double)longueur){ //si 3 torseurs qui parcourent toute la poutre -> 2 zones a etudier
    if (t[0].f[1] != 0 && t[1].f[1] != 0 && t[2].f[1] != 0){  //cas ou l'effort tranchant existe

      for (i = 0 ; i <= t[1].c[0]+1 ; i++){ //1ere zone a etudier entre 1er et 2eme torseur

        x[i] = (double)i;
        y[i] = -t[0].f[1];

      }

      for (i = t[1].c[0] ; i < t[2].c[0]+2 ; i++){ //2eme zone a etudier entre 2eme et 3eme torseur

        x[i] = (double)i;
        y[i] = -t[0].f[1] - t[1].f[1];

      }

    }
    else{
      for (i = 0 ; i <= longueur ; i++){  //cas ou l'effort tranchant n'existe pas

        x[i] = (double)i;
        y[i] = (double)0;

      }
    }
  }

  if (nb_point == 3 && t[2].c[0] != longueur){ //si 3 torseurs qui ne parcourt pas toute la poutre -> 3 zones a etudier
    if (t[0].f[1] != 0 && t[1].f[1] != 0 && t[2].f[1] != 0){  //cas ou l'effort tranchant existe

      for (i = 0 ; i <= t[1].c[0] ; i++){ //1ere zone a etudier entre le 1er et le 2eme torseur

        x[i] = (double)i;
        y[i] = -t[0].f[1];

      }

      for (i = t[1].c[0] ; i <= t[2].c[0] ; i++){ //2eme zone a etudier entre le 2eme et le 3eme torseur

        x[i] = (double)i;
        y[i] = -t[0].f[1] - t[1].f[1];

      }

      for (i = t[2].c[0] ; i <= longueur ; i++){  //3eme zone a etudier entre le 3eme torseur et le bout de la poutre

        x[i] = (double)i;
        y[i] = -t[0].f[1] - t[1].f[1] - t[2].f[1];

      }
    }
    else{
      for (i = 0 ; i <= longueur ; i++){  //cas ou l'effort tranchant n'existe pas

        x[i] = (double)i;
        y[i] = (double)0;

      }
    }
  }

  gnuplot_plot_xy(h, x, y, longueur, "Effort tranchant (N)");
  sleep(0);

  gnuplot_plot_slope(h, 0.0, 0.0, "y = 0");
  sleep(2);

  return;
}

void MomentdeFlexionZ(torseur *t, int longueur, int nb_point){

  int i;
  double x[157], y[157];
  gnuplot_ctrl *h;      //on touche pas à ça
  h = gnuplot_init();   //pas touche

  gnuplot_setstyle(h, "linespoints");   //pas touche deco

  if (nb_point == 2 && t[1].c[0] == longueur){ //si 2 torseurs qui parcourent la poutre

    if (t[0].m[2] != 0 && t[1].m[2] != 0){ //cas où le moment de flexion existe

      for (i = 0 ; i <= longueur ; i++){  //1ere zone a etudier

        x[i] = (double)i;
        y[i] = - t[0].m[2] + (double)i * t[0].f[1] - (double)i * t[0].f[2];

      }

    }

    else {   //cas où le moment de flexion n'existe pas
      for (i = 0 ; i <= longueur ; i++){

        x[i] = (double)i;
        y[i] = 0;

      }
    }
  }

  if (nb_point == 2 && t[1].c[0] != longueur){ //si 2 torseurs qui ne parcourent pas toute la poutre

    if (t[0].m[2] != 0 && t[1].m[2] != 0){ //cas où le moment de flexion existe

      for (i = 0 ; i <= t[1].c[0] ; i++){  //1ere zone a etudier entre le 1er et le 2eme torseur

        x[i] = (double)i;
        y[i] = - t[0].m[2] + (double)i * t[0].f[1] - (double)i * t[0].f[2];

      }

      for (i = t[1].c[0] ; i <= longueur ; i++){  //2eme zone à étudier entre le 2eme torseur et le bout de la poutre

        x[i] = (double)i;
        y[i] = - t[0].m[2] + (double)i * t[0].f[1] - (double)i * t[0].f[2] - t[1].m[2] + (double)i * t[0].f[1] - (double)i * t[1].f[2];

      }

    }

    else {   //cas où le moment de flexion n'estiste pas
      for (i = 0 ; i <= longueur ; i++){

        x[i] = (double)i;
        y[i] = 0;

      }
    }
  }

  if (nb_point == 3 && t[1].c[0] == longueur){ //si 3 torseurs qui parcourent toute la poutre

    if (t[0].m[2] != 0 && t[1].m[2] != 0 && t[2].m[2] != 0){ //cas où le moment de flexion existe

      for (i = 0 ; i <= t[1].c[0] ; i++){  //1ere zone a etudier entre le 1er et le 2eme torseur

        x[i] = (double)i;
        y[i] = - t[0].m[2] + (double)i * t[0].f[1] - (double)i * t[0].f[2];

      }

      for (i = t[1].c[0] ; i <= t[2].c[0] ; i++){  //2eme zone à étudier entre le 2eme torseur et le 3eme torseur

        x[i] = (double)i;
        y[i] = - t[0].m[2] + (double)i * t[0].f[1] - (double)i * t[0].f[2] - t[1].m[2] + (double)i * t[0].f[1] - (double)i * t[1].f[2];

      }

    }

    else {   //cas où le moment de flexion n'estiste pas
      for (i = 0 ; i <= longueur ; i++){

        x[i] = (double)i;
        y[i] = 0;

      }
    }
  }

  if (nb_point == 3 && t[1].c[0] != longueur){ //si 3 torseurs qui ne parcourent pas toute la poutre

    if (t[0].m[2] != 0 && t[1].m[2] != 0 && t[2].m[2] != 0){ //cas où le moment de flexion existe

      for (i = 0 ; i <= t[1].c[0] ; i++){  //1ere zone a etudier entre le 1er et le 2eme torseur

        x[i] = (double)i;
        y[i] = - t[0].m[2] + (double)i * t[0].f[1] - (double)i * t[0].f[2];

      }

      for (i = t[1].c[0] ; i <= t[2].c[0] ; i++){  //2eme zone à étudier entre le 2eme torseur et le 3eme torseur

        x[i] = (double)i;
        y[i] = - t[0].m[2] + (double)i * t[0].f[1] - (double)i * t[0].f[2] - t[1].m[2] + (double)i * t[1].f[1] - (double)i * t[1].f[2];

      }

      for (i = t[2].c[0] ; i <= longueur ; i++){  //3eme zone à étudier entre le 3eme torseur et le bout de la poutre

        x[i] = (double)i;
        y[i] = - t[0].m[2] + (double)i * t[0].f[1] - (double)i * t[0].f[2] - t[1].m[2] + (double)i * t[1].f[1] - (double)i * t[1].f[2]- t[2].m[2] + (double)i * t[2].f[1] - (double)i * t[2].f[2];

      }

    }

    else {   //cas où le moment de flexion n'estiste pas
      for (i = 0 ; i <= longueur ; i++){

        x[i] = (double)i;
        y[i] = 0;

      }
    }
  }

  gnuplot_plot_xy(h, x, y, longueur, "Moment de flexion (Nm)");
  sleep(0);

  gnuplot_plot_slope(h, 0.0, 0.0, "y = 0");
  sleep(2);

}
