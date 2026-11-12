#include "Fonction.h"

void regles()
{
    printf("\n*** Les règles du plus ou moins ***");
    printf("\nDevinez si la carte suivante est plus grand ou plus petite que la précédente.");
    printf("\nPour le sens des cartes, la plus petite c'est l'as et la plus grande c'est le roi.");
}

void regle()
{
    printf("\n*** Les règles du couleur des cartes ***");
    printf("\nDevinez si la carte suivante est de même couleur que la précédente. \nLes coeurs et les carreaux vont ensembles et les piques et les trèfles vont ensemble.");
}

int pioche(int rand, int possibilité)
{
    return (rand % possibilité) + 1;
}

void AffichageCarte(int *possibilite, int carte, int couleur)
{

    if (carte > 0 && couleur == 0)
    {

        switch (carte)
        {
        case 1:
            printf("un As.");
            break;
        case 2:
            printf("un 2.");
            break;
        case 3:
            printf("un 3.");
            break;
        case 4:
            printf("un 4.");
            break;
        case 5:
            printf("un 5.");
            break;
        case 6:
            printf("un 6.");
            break;
        case 7:
            printf("un 7.");
            break;
        case 8:
            printf("un 8.");
            break;
        case 9:
            printf("un 9.");
            break;
        case 10:
            printf("un 10.");
            break;
        case 11:
            printf("un valet.");
            break;
        case 12:
            printf("une dame.");
            break;
        case 13:
            printf("un roi.");
            break;
        default:
            break;
        }
        possibilite[carte - 1] = possibilite[carte - 1] - 1;
    }

    if (couleur > 0 && carte == 0)
    {
        switch (couleur)
        {
        case 1:
            printf("Coeur.");
            break;
        case 2:
            printf("Pique.");
            break;
        case 3:
            printf("Carreau.");
            break;
        case 4:
            printf("Trefle.");
            break;
        default:
            break;
        }
        possibilite[couleur - 1] = possibilite[couleur - 1] - 1;
    }
}
int carteSuivante(int rand, int possibilite)
{
    return pioche(rand, possibilite);
}

int verification(int *t, int carte, int suivante, int rand, char sens)
{

    while (sens != '+' && sens != '-')
    {
        printf("Caractère incorrect !\n");
        printf("La carte suivante est plus grande (+) ou plus petite (-) ? ");
        scanf(" %c", &sens);
    }

    switch (sens)
    {
    case '+':

        if (carte == suivante)
        {
            printf("\nLa carte suivante est ");
            AffichageCarte(t, suivante, 0);
            return 2;
        }

        else if (carte < suivante)
        {
            printf("\nLa carte suivante est ");
            AffichageCarte(t, suivante, 0);
            return 1;
        }
        else
        {

            printf("\nLa carte suivante est ");
            AffichageCarte(t, suivante, 0);
            return 0;
        }
        break;

    case '-':
        if (carte == suivante)
        {
            printf("\nLa carte suivante est ");
            AffichageCarte(t, suivante, 0);
            return 2;
        }

        else if (carte > suivante)
        {
            printf("\nLa carte suivante est ");
            AffichageCarte(t, suivante, 0);
            return 1;
        }
        else
        {
            printf("\nLa carte suivante est ");
            AffichageCarte(t, suivante, 0);
            return 0;
        }
        break;
    }
    return 0;
}

int Correction(int sortie)
{
    if (sortie == 2)
    {
        printf("\nIl ne se passe rien !\n");
    }
    else if (sortie == 1)
    {
        printf("\nBonne réponse !\n");
    }
    else if (sortie == 0)
    {
        printf("\nMauvaise réponse !\n");
    }
    return sortie;
}

void PlusMoins()
{
    int cartesuivante, correction;
    int choix = 13, carte = 0, carteTotal = 52;
    char valeur;

    int disopnibilité[13] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    regles();

    printf("\n\nVous commencez avec ");

    carte = pioche(rand(), choix);
    carteTotal--;
    AffichageCarte(disopnibilité, carte, 0);

    do
    {

        printf("\nLa carte suivante est plus grande (+) ou plus petite (-) ? ");
        scanf(" %c", &valeur);

        cartesuivante = carteSuivante(rand(), choix);

        while (disopnibilité[cartesuivante - 1] == 0)
        {
            cartesuivante = carteSuivante(rand(), choix);
        }

        correction = Correction(verification(disopnibilité, carte, cartesuivante, rand(), valeur));

        carteTotal--;

        carte = cartesuivante;
        cartesuivante = 0;

    } while (correction == 1 || correction == 2);
}

void Couleur()
{
    int cartesuivante;
    int choix = 4, carte = 0, carteTotal = 52, correction = 0;
    char valeur;

    int disopnibilité[4] = {13, 13, 13, 13};

    regle();

    printf("\n\nVous commencez avec ");

    carte = (rand() % choix) + 1;

    AffichageCarte(disopnibilité, 0, carte);

    carteTotal--;

    do
    {

        printf("\nLa carte suivante est de la même couleur (o/n) ? ");
        scanf(" %c", &valeur);

        cartesuivante = (rand() % choix) + 1;

        while (disopnibilité[cartesuivante - 1] == 0)
        {
            cartesuivante = (rand() % choix) + 1;
        }

        printf("\nLa couleur de la carte suivante est ");

        AffichageCarte(disopnibilité, 0, cartesuivante);

        carteTotal--;

        switch (carte)
        {
        case 1:
            if ((cartesuivante == 1 || cartesuivante == 3) && tolower(valeur) == 'o')
            {
                correction = 1;
            }
            else if ((cartesuivante == 2 || cartesuivante == 4) && tolower(valeur) == 'n')
            {
                correction = 1;
            }
            else
            {
                correction = 0;
            }
            break;
        case 2:
            if ((cartesuivante == 2 || cartesuivante == 4) && tolower(valeur) == 'o')
            {
                correction = 1;
            }
            else if ((cartesuivante == 1 || cartesuivante == 3) && tolower(valeur) == 'n')
            {
                correction = 1;
            }
            else
            {
                correction = 0;
            }
            break;
        case 3:
            if ((cartesuivante == 1 || cartesuivante == 3) && tolower(valeur) == 'o')
            {
                correction = 1;
            }
            else if ((cartesuivante == 2 || cartesuivante == 4) && tolower(valeur) == 'n')
            {
                correction = 1;
            }
            else
            {
                correction = 0;
            }
            break;
        case 4:
            if ((cartesuivante == 2 || cartesuivante == 4) && tolower(valeur) == 'o')
            {
                correction = 1;
            }
            else if ((cartesuivante == 1 || cartesuivante == 3) && tolower(valeur) == 'n')
            {
                correction = 1;
            }
            else
            {
                correction = 0;
            }
            break;
        }

        correction = Correction(correction);
        carte = cartesuivante;
        cartesuivante = 0;

    } while (correction == 1);
}