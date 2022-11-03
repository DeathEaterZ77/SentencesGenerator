//
// Created by charl on 03/11/2022.
//

#include <stdlib.h>
#include <stdio.h>

char extracFB() {
    
    //defining the file
    FILE* dico_test;
    
    // this array is needed to memorize the line read by the file
    char str [1000];
    
    // counters for the second test made below
    short nb_lignes_lues, nb_val_lues;
    
    // arrays containing the different categories of words
    char forme_flechie[400];
    char forme_base[400];
    char nature[200];
    char genre_nbr_tps[200];
    
    // open the file
    dico_test = fopen("../dico.txt","r");

    // test if the file is NULL
    if (dico_test == NULL) {
        printf("Cannot open this file");
        exit(0);
    }
    
    // avoid all the lines that starts with $
    while(fgets(str,1000,dico_test)!=0 && str[0]=="$"); 
    
    nb_lignes_lues = 0;
    
    // read the file while it's not NULL
    while (fgets(str,1000, dico_test) != NULL) {
    
        // add 1 each time a line is read
        nb_lignes_lues++;
        
        // analyse the line and keep the 3 categories of words
        // that we want to extract from the file
        nb_val_lues = sscanf(str, "%s%s%s", forme_flechie, forme_base, nature);
        
        // we check if we sscanf function took the 3 categories needed
        if (nb_val_lues !=3)
            printf(" PROBLEME \n", nb_lignes_lues);
        else
            // if so, we display the category of words we want to extract
            // which are in the array of characters named forme_base 
            printf("(Ligne %2hd) %s \n", nb_lignes_lues, forme_base);
    }
    // close the file
    fclose(dico_test);
}


