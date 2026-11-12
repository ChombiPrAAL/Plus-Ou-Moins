#include <conio.h>   // getch()
#include <locale.h>  // setlocal()
#include <stdbool.h> // bool,false,true
#include <stdio.h>   // printf(), scanf()
#include <stdlib.h>  // srand(), rand()
#include <time.h>    // time()
#include <ctype.h>   // tolower(), toupper()

void Couleur();

void PlusMoins();

void regles();

void regle();

int pioche(int rand,int possibilite);

void AffichageCarte(int *possibilite, int carte,int couleur);

int carteSuivante(int rand,int possibilite);

int verification(int *t,int carte, int suivante, int rand, char sens);

int Correction(int sortie);