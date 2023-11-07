#include <stdlib.h>
#include <stdio.h>

void tracer_courbe(){
  char const *gnuname ="c:\\gnuplot\\bin\\plotingFile.txt";//chemin vers un fichier dans le quelle y a des instructions pour lancer gnuplot ce fichier va contenir les données de notre courbe "on peut le mettre ou en veux"
  char const *gnupath = "c:\\gnuplot\\bin\\wgnuplot.exe";//chemin vers l'executable de gnubplot
  char command[500];//open terminal
  FILE* f_plot = fopen(gnuname,"w");
  printf("test1");
  if(f_plot != NULL){
    fprintf(f_plot,"set grid;\n");
    fprintf(f_plot,"set xrange[0:10000];\n");
    fprintf(f_plot,"set yrange[0:3];\n");
    fprintf(f_plot,"set key box;\n");
    fprintf(f_plot, "set ylabel \"Temps de Tri (s * 10)\";\n");
    fprintf(f_plot, "set xlabel \"taille des donnees\";\n");
    fprintf(f_plot, "set title \"Performance des Algorithmes de Tri\";\n");

// tracer de courbe
    fprintf(f_plot,"set multiplot;\n");
    fprintf(f_plot,"plot 'data.txt' u 1:2 title 'insertion' w lp lt rgb 'red' lw 2 axes x1y1,");
    fprintf(f_plot,"  'data.txt' u 1:3 title 'bulle' w lp lt rgb 'green' lw 2 axes x1y1,");
    fprintf(f_plot,"  'data.txt' u 1:4 title 'selection' w lp lt rgb 'blue' lw 2 axes x1y1,");
    fprintf(f_plot,"  'data.txt' u 1:5 title 'fusion' w lp lt rgb 'black' lw 2 axes x1y1,");
    fprintf(f_plot,"  'data.txt' u 1:6 title 'Shell' w lp lt rgb 'purple' lw 2 axes x1y1,");
    fprintf(f_plot,"  'data.txt' u 1:7 title 'Rapide' w lp lt rgb 'orange' lw 2 axes x1y1;");
    fprintf(f_plot,"unset multiplot;\n");
    fclose(f_plot);


    sprintf(command, "start %s -persist %s", gnupath, gnuname);
    int status = system(command);
if (status == -1) {
    printf("Error executing GNUPLOT.\n");
} else {
    printf("GNUPLOT executed successfully.\n");
};
  }
  printf("test0");

}