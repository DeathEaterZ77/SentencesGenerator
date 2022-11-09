//
// Created by Carla Gros-Alcaraz on 04/11/2022.
//

#include "N-aryCharTree.h"

nt_tree createEmptyTree(){
    nt_tree new;
    new.root = createNode('~');
    new.root->depth = -1;
    return new;
}

void fill_NTrees( nt_tree* cat_trees ){

    FILE* dico = fopen("../dico_10_lignes.txt",'r'); // open the file
    if (dico == NULL) { // verify if the file is not empty
        printf("Cannot open this file");
        exit(0);
    }

    char basic_form[100], flech_form[100], infos[100];

    // faire une boucle pour lire chaque ligne du fichier ouvert
    while(fscanf(dico," %s %s %s ", basic_form, flech_form, infos) == 3 ) {
        int cat = 0;

        //verifier dans quel arbre doit aller la ligne
        char catvalue[4];
        for(int i=0; i<3; i++) catvalue[i]=infos[i];
        catvalue[3] = '\0';
        char *gender_nbr_time = infos + 4;


        if(strcmp(catvalue,"Nom") == 0) cat = 0;
        else if(strcmp(catvalue,"Adj") == 0) cat = 1;
        else if(strcmp(catvalue,"Ver") == 0) cat = 2;
        else if(strcmp(catvalue,"Adv") == 0) cat = 3;

        //appeler "addWordToTree" pour ajouter la ligne à l'arbre
        addWordToTree(basic_form, flech_form, gender_nbr_time, &cat_trees[cat]);

    }

    printf("Your data trees have been created ...");
    fclose(dico);

}

void addWordToTree(char* basic_form, char* flech_form, char* gender_nbr_time, nt_tree* cat){

    // on fait une boucle pour parcourir tous les caractères de la forme de base jusqu'a ce qu'il soit == '\0'


        // on parcours tous les frères du noeud où on se trouve pour chercher le caractère

        // si on ne l'a pas trouvé dans la boucle, on le crée (avec la fonction "addNode")

        // on avance dans ce noeuds

   // une fois avoir parcouru tous les caractères, on met le end du noeud courant à 1 (car on est actuellement sur le dernier caractère)

   // pas indispendable pour l'instant, tester d'abord sans:
            //on ajoute les formes fléchies dans le noeud courant (donc du dernier caractère) avec la fonction ("addFlechNode")
}

