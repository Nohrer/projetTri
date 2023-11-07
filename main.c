#include<stdio.h>
#include<stdlib.h>
#include "time_calc.h"
#include "algos_tri.h"
#include "table_generate.h"
#include "tracer_courbe.h"
#define MAX_SIZE 20000
#define STEP 1000


int main(int argc , char* argv[]){

    int *t;
    int i,choix,moyenneDeDonnees,conteur=0;
    double tempsMoyenneInsertion,tempsMoyenneBulle,tempsMoyenneSelection,tempsMoyenneFusion,tempsMoyenneShell,tempsMoyenneRapide;
  FILE* f = fopen("data.txt","w");
    if (f!=NULL)
    { 
    fprintf(f,"0\t0\t0\t0\t0\t0\t0\t\n");   
    printf("\n|-----------------Comparaison du performance des algorithmes de tri-----------------|\nSelectionner l'un des tests a est effectue.(entre 1 et 13)\n\t 1-test aleatoire.\n\t 2-test favorable au algorithme insertion.\n\t 3-test favorable au algorithme bulles.\n\t 4-test favorable au algorithme selection.\n\t 5-test favorable au algorithme fusion.\n\t 6-test favorable au algorithme shell.\n\t 7-test favorable au algorithme rapide.\n\t 8-test defavorable au algorithme insertion.\n\t 9-test defavorable au algorithme bulles.\n\t10-test defavorable au algorithme selection.\n\t11-test defavorable au algorithme fusion.\n\t12-test defavorable au algorithme shell.\n\t13-test defavorable au algorithme rapide.\n\tVotre choix:");
    scanf("%d",&choix);
    if(choix == 1|| choix == 2 || choix == 3 || choix == 4 || choix == 5 || choix == 6 || choix == 7 || choix == 8 || choix == 9 || choix == 10
    || choix == 11 || choix == 12 || choix == 13){
    for(int i = 0 ; i<= MAX_SIZE ; i+=STEP){
            t = (int*)malloc(sizeof(int)*i);
            if (choix == 1)
            {
                generate_table(t,i);
            }else if(choix == 2){
                generate_insertion_sort_favorable(t,i);
            }else if(choix == 3){
                generate_bulle_sort_favorable(t,i);
            }else if(choix == 4)
                generate_selection_sort_favorable(t,i);
            else if(choix == 5)
                generate_merge_sort_favorable(t,i);
            else if(choix == 6)
                generate_shell_sort_favorable(t,i);
            else if(choix == 7)
                generate_quick_sort_favorable(t,i);
            else if(choix == 8)
                generate_selection_insertion_sort_defavorable(t,i);
            else if(choix == 9)
                generate_bulle_sort_defavorable(t,i);
            else if(choix == 10)
                generate_selection_insertion_sort_defavorable(t,i);
            else if(choix == 11)
                generate_merge_sort_defavorable(t,i);
            else if(choix == 12){
                generate_quick_sort_defavorable(t,i);}
            else if(choix == 13)
                generate_quick_sort_defavorable(t,i);
           conteur++;
            double time1 = measureTime(insertion,t,i)*10;
            double time2 = measureTime(bulles,t,i)*10;
            double time3 = measureTime(selection,t,i)*10;
            double time4 = measureTime(merge_sort,t,i)*10;
            double time5 = measureTime(shellSort,t,i)*10;
            double time6 = measureTime(quickSort,t,i)*10;
            tempsMoyenneInsertion+=time1;
            tempsMoyenneBulle+=time2;
            tempsMoyenneSelection+=time3;
            tempsMoyenneFusion+=time4;
            tempsMoyenneShell+=time5;
            tempsMoyenneRapide+=time6;
            moyenneDeDonnees+=i;
           if(conteur%3 == 0){
            fprintf(f,"%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t\n",moyenneDeDonnees/3,tempsMoyenneInsertion/3,tempsMoyenneBulle/3,tempsMoyenneSelection/3,tempsMoyenneFusion/3,tempsMoyenneShell/3,tempsMoyenneRapide/3);   
            printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t\n",moyenneDeDonnees/3,tempsMoyenneInsertion/3,tempsMoyenneBulle/3,tempsMoyenneSelection/3,tempsMoyenneFusion/3,tempsMoyenneShell/3,tempsMoyenneRapide/3);
            tempsMoyenneInsertion =0;
            tempsMoyenneBulle=0;
            tempsMoyenneSelection=0;
            tempsMoyenneFusion=0;
            tempsMoyenneShell=0;
            tempsMoyenneRapide=0;
            moyenneDeDonnees=0;
            
            }

        } }else {printf("ERREUR:vous devez choisir un nombre entre 1 et 13");
        exit(0);
        }
        fclose(f);
        tracer_courbe();
    
    }else
        printf("ouverture du fichier est imposiible !");

    return 0;
}