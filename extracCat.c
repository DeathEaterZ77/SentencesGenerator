//
// Created by charl on 03/11/2022.
//

#include <stdlib.h>
#include <stdio.h>

char extracCat() {
    FILE* dico_test;
    char str [1000];
    short nb_lignes_lues, nb_val_lues;
    char forme_flechie[400];
    char forme_base[400];
    char nature[200];
    char genre_nbr_tps[200];

    dico_test = fopen("../dico.txt","r");//open the file

    if (dico_test == NULL) {// test if the file is NULL
        printf("Cannot open this file");
        exit(0);
    }

    while(fgets(str,1000,dico_test)!=0 && str[0]=="$"); // read the file while it's not NULL
    nb_lignes_lues = 0;
    while (fgets(str,1000, dico_test) != NULL) {
        nb_lignes_lues++;
        nb_val_lues = sscanf(str, "%s%s%s%s", forme_flechie, forme_base, nature);
        if (nb_val_lues !=3)
            printf(" PROBLEME \n", nb_lignes_lues);
        else
            printf("(Ligne %2hd) %-30.3s \n", nb_lignes_lues, nature);
    }
    fclose(dico_test);
}
