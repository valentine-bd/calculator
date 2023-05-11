#include<stdio.h>
#include<gtk/gtk.h>

#include<mainWindow.h>
#include<gestion.h>

#define N 100  // N : taille de la chaine d'entrée en attente de l'allocation dynamique

/*
CALCULATRICE
 _________________________________________________________________________________________________________________
| La version actuelle prend en charge les opération standards  /, *, - et +.                                      |
| Elle prend en paramettre un nombre NON DEFINI de doubles (dans la limite de N caractères) et renvoie UN double. |
| Il est possible d'utiliser les parenthèses '(' et ')'.                                                          |
|_________________________________________________________________________________________________________________|

SESSION 1-----------------------------------------------------------------------------------------------29/03/2023
-> Modifier getOperator() pour renvoyer un tableau d'opérations à effectuer                                     OK 
-> Créer une fonction getVariable() qui prend la chaine d'entrée et renvoie un tableau de valeurs               OK
-> Adapter la fonction calcul() pour prendre en compte les modification ci dessus                               OK

SESSION 2-----------------------------------------------------------------------------------------------30/03/2023
-> Gérer la priorité de calcul (sans parenthèses) avec la fonction calcul()                                     OK
-> Gérer la priorité de calcul (avec parenthèses) avec la fonction iteration()                                  OK

SESSION 3-----------------------------------------------------------------------------------------------31/03/2023
-> Simplifier le programme pour limiter le nombre de boucles (actuellement 1(2))                                OK

SESSION 4-----------------------------------------------------------------------------------------------26/04/2023
-> Ajouter l' erreur de la division par 0                                                                       OK

SESSION 5-----------------------------------------------------------------------------------------------??/??/2023
-> Ajouter un historique de la dernière opération réalisée (Doit gérer la récursivité)                     A FAIRE
-> Ecrire une fonction type "strtod" fait maison pour "le beau jeu"                                        A FAIRE                      
*/

/*int main(int argc, char *argv[])
{
    char entree[N];
    printf("\nEntrez une opération à effectuer : ");
    get(entree,N);
    give(entree);
    return 0;
}*/

int main(int argc, char *argv[])
{
  GtkApplication* app;
  int stat;

  app = gtk_application_new(NULL, G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app,"activate",G_CALLBACK(app_activate), NULL);
  stat = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return stat;
}