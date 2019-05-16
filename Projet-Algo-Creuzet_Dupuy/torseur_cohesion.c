#include "rdm.h"
#include "gnuplot_i.h"

void Initialisation_cohesion(torseur_cohesion *tc, int i){

      int j;

      for (j = 0 ; j < 3 ; j++){
          tc[i].f[j] = 0;
          tc[i].m[j] = 0;
      }
}

void Affichercourbe(torseur *t, int *ptr_longueur){

  int i, limite = 20;
  double x[157], y[157];
  gnuplot_ctrl *h;      //on touche pas à ça
  h = gnuplot_init();   //pas touche

  gnuplot_setstyle(h, "lines");   //pas touche deco

  for (i = 0 ; i <= *ptr_longueur ; i++){

    x[i] = (double)i;
    y[i] = (double)i + 5;

  }
  gnuplot_plot_xy(h, x, y, *ptr_longueur, "TEST :)");
  sleep(2);

  return;
}
