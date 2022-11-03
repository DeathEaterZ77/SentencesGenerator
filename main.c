#include <stdlib.h>
#include <stdio.h>

int affichageMenu(void) /* pas d'entree donc void */
{
    int choixMenu; /* il manquait un point virgule */

    printf("---Menu---\n\n");
    printf("1.Afficher les lignes du dico!\n");
    printf("2.extraction des formes de base\n");
    printf("3.extraction formes flechies\n");
    printf("4.extraction nature du mot\n");
    printf("5.extraction categorie du mot\n");
    printf("\nVotre choix?\n\n");
    scanf("%d", &choixMenu);
    return choixMenu; /* c'est ici qu'on retourne une valeur*/
}
int main(void)
{
    switch (affichageMenu())
    {
        case 1:
            readDico();
            break;
        case 2:
            extracFF();
            break;
        case 3:
            extracFB();
            break;
        case 4:
            extracInfos();
            break;
        case 5:
            extracCat();
            break;
        default:
            printf("Vous ne ferez rien du tout!");
            break;
    }
    return 0;
}



