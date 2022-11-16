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

    FILE* dico = fopen("../dictionnaire_non_accentue.txt","r"); // open the file
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

        // printf("\n%s %s %d %s",basic_form,flech_form,cat,infos);
        // appeler "addWordToTree" pour ajouter la ligne à l'arbre
        addWordToTree(basic_form, flech_form, gender_nbr_time, &cat_trees[cat]);

    }

    printf("Your data trees have been created ...");
    fclose(dico);

}

void addWordToTree(char* basic_form, char* flech_form, char* gender_nbr_time, nt_tree* cat){
    pbase_node here = cat->root;
    int i=0, search;
    pbase_node temp;
    // on fait une boucle pour parcourir tous les caractères de la forme de base jusqu'a ce qu'il soit == '\0'
    while(basic_form[i] != '\0'){
        // on parcourt tous les frères du noeud où on se trouve pour chercher le caractère
        temp = here->son;
        if(temp==NULL){
            addNode(here, basic_form[i], 1);
            here = here->son;
        }
        else { // sinon on parcours tt les frères jusqu'à trouver
            search = 0;
            while (search == 0) {
                if (temp->letter == basic_form[i]) search = 1;
                else if (temp->sibling != NULL) temp = temp->sibling;
                else search = -1;
            }
            if (search == -1) { // si on a pas trouvé on cré un frère au noeud courant
                // si on ne l'a pas trouvé dans la boucle, on le crée (avec la fonction "addNode")
                addNode(temp, basic_form[i], 0);
                temp=temp->sibling;
            }
            here = temp;
        }
        i++;
    }

   // une fois avoir parcouru tous les caractères, on met le end du noeud courant à 1 (car on est actuellement sur le dernier caractère)
   //on ajoute les formes fléchies dans le noeud courant (donc du dernier caractère) avec la fonction ("addFlechNode")

    addFlechNode(here, basic_form, flech_form, gender_nbr_time);

    //printf("\n%s %s %s", here->basic_form,here->flechies->flech_word,here->flechies->attributs);

}

