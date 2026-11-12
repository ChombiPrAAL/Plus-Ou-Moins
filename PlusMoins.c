#include <stdio.h>  // printf, scanf
#include <locale.h> // setlocale
#include <conio.h>  // getch

#include "Fonction.h"

void main()
{
    char jeu, continuer;

    setlocale(LC_ALL, "fr_FR.UTF-8");

    srand(time(NULL));

    do
    {

        printf("\nVous voulez jouez au plus ou moins (p) ou au couleur des cartes (c) ? ");
        scanf(" %c", &jeu);

        while (tolower(jeu) != 'p' && tolower(jeu) != 'c')
        {
            printf("Caractère incorrect !\n");
            printf("Vous voulez jouez au plus ou moins (p) ou au couleur des cartes (c) ? ");
            scanf(" %c", &jeu);
        }

        switch (jeu)
        {
        case 'p':
            PlusMoins();
            break;

        case 'c':
            Couleur();
            break;
        }

        printf("Voulez vous refaire une partie/changer de jeu (o/n) ? ");
        scanf(" %c", &continuer);

        while (tolower(continuer) != 'o' && tolower(continuer) != 'n')
        {
            printf("Caractère inccorect !\n");
            printf("Voulez vous refaire une partie/changer de jeu (o/n) ? ");
            scanf(" %c", &continuer);
        }

    } while (continuer == 'o');
}