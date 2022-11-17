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
    if (dico == NULL) exit(-1);

    char basic_form[100], flech_form[100], infos[100];

    // do a while loop to read each line of the open file
    while(fscanf(dico," %s %s %s ", flech_form,basic_form, infos) == 3 ) {
        // verify in which tree each line must go
        char catvalue[4];
        for(int i=0; i<3; i++) catvalue[i]=infos[i];
        // '\0' is for the end of the string
        catvalue[3] = '\0';
        // we compare catvalue with the category and then add to the right tree
        if(strcmp(catvalue,"Nom") == 0) addWordToTree(basic_form, flech_form, infos + 4, &cat_trees[0]); 
        else if(strcmp(catvalue,"Ver") == 0) addWordToTree(basic_form, flech_form, infos + 4, &cat_trees[1]);
        else if(strcmp(catvalue,"Adj") == 0) addWordToTree(basic_form, flech_form, infos + 4, &cat_trees[2]);
        else if(strcmp(catvalue,"Adv") == 0) addWordToTree(basic_form, flech_form, infos + 4, &cat_trees[3]);

    }
    printf("Your data trees have been created ...");
    fclose(dico);
}


void addWordToTree(char* basic_form, char* flech_form, char* gender_nbr_time, nt_tree* cat){
    pbase_node here = cat->root;
    int i=0, search;
    pbase_node temp;
    // using a while loop to go further in the tree 
    while(basic_form[i] != '\0'){
        temp = here->son;
        if(temp==NULL){
            // if son is NULL we add the new node in the son
            addNode(here, basic_form[i], 1);
            here->nbsons++;
            here = here->son;
        }
        else {
            // if not we add the new node to the sibling
            search = 0;
            while (search == 0) {
                if (temp->letter == basic_form[i]) search = 1;
                else if (temp->sibling != NULL) temp = temp->sibling;
                else search = -1;
            }
            if (search == -1) {
                addNode(temp, basic_form[i], 0);
                temp=temp->sibling;
                here->nbsons++;
            }
            here = temp;
        }
        i++;
    }

   // une fois avoir parcouru tous les caractères, on met le end du noeud actuel à 1 (car on est actuellement sur le dernier caractère)
   //on ajoute les formes fléchies dans le noeud actuel (donc du dernier caractère) avec la fonction ("addFlechNode")
    here->end=1;
    addFlechNode(here, flech_form, gender_nbr_time);


}



