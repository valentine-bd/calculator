#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

//int get(const char *chaine, int longueurChaine);
double calcul(double *variables, char *operateurs, int *cursor);
char getOperator(const char *chaine, int *cursor);
double getVariable(const char *chaine, int *cursor);
double iteration(const char *chaine, int *cursor);
void give(const char *chaine, int *cursor, char *chaineRes);

#endif //GESTION_H_INCLUDED