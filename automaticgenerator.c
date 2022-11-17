
#include "automaticgenerator.h"

void generateSentence(int type, int model, nt_tree* cat_trees){
    if(type==1)
    {
        if (model == 1) {
            printf("Your sentence is : %s %s %s %s\n\n", searchForBasicWord(cat_trees, 0, ""),
                   searchForBasicWord(cat_trees, 2, ""), searchForBasicWord(cat_trees, 1, ""),
                   searchForBasicWord(cat_trees, 0, ""));
        } else if (model == 2) {
            printf("Your sentence is : %s qui %s %s %s %s\n\n", searchForBasicWord(cat_trees, 0, ""),
                   searchForBasicWord(cat_trees, 1, ""), searchForBasicWord(cat_trees, 1, ""),
                   searchForBasicWord(cat_trees, 0, ""), searchForBasicWord(cat_trees, 2, ""));
        } else if (model == 3) {
            printf("Your sentence is : %s %s %s %s %s\n\n", searchForBasicWord(cat_trees, 0, ""),
                   searchForBasicWord(cat_trees, 2, ""), searchForBasicWord(cat_trees, 1, ""),
                   searchForBasicWord(cat_trees, 3, ""), searchForBasicWord(cat_trees, 0, ""));
        }
    }else if(type==2){
        char accords[4][2] = {"MS","FS","MP","FP"};
        char* choices = accords[rand()%4];

        printf("Not implemented, but here are some random inflated words\n\tnoun : %s\n\tadjective : %s\n\tadverb : %s\n\n ",
               searchForFlexWord(cat_trees[0], 0, choices),searchForFlexWord(cat_trees[2], 2, choices),
               searchForFlexWord(cat_trees[3], 3, choices));

        return;
        printf("Your sentence is : %s %s %s %s\n\n", searchForFlexWord(cat_trees[0], 0, choices),
               searchForFlexWord(cat_trees[2], 2, choices), searchForFlexWord(cat_trees[1], 1, choices),
               searchForFlexWord(cat_trees[0], 0, choices));
    }
}

char* searchForBasicWord(nt_tree* cat_trees, int cat_val, char* word) {
    char* new_word = (char*)malloc(100*sizeof(char));
    strcpy(new_word, word);

    if(cat_val==4) {
        int k=rand()%4;
        for (int i = 0; i < 4; i++) {
            new_word = searchForBasicWord(cat_trees, k, word);
            if(new_word!=NULL) return new_word;
            k=(k+1)%4;
        }

        return NULL;
    }

    pbase_node pn;
    pn = searchforNode(cat_trees[cat_val], word);
    if (pn == NULL || pn->son == NULL) return NULL;


    while (1) {
        //check if we found a word
        if (pn->end == 1) {
            //chose it or continue by random
            if ((rand() % 6 == 1) || pn->nbsons == 0) return new_word;
        }
        int random = rand()%pn->nbsons;
        pn = pn->son;
        for(int i = 0; i<random; i++) {
            pn = pn->sibling;
        }
        strncat(new_word,&pn->letter, 1);
    }
}

pbase_node searchforNode(nt_tree tree, char* word){
    int i=0, search=0;
    pbase_node here = tree.root;
    pbase_node temp;

    if(word == NULL)return tree.root;
    while(word[i] != '\0'){
        temp = here->son;
        search=0;
        while(search==0){
            if (temp->letter == word[i]) search = 1;
            else if (temp->sibling != NULL) temp = temp->sibling;
            else return NULL;
        }
        here = temp;

        i++;
    }
    return here;
}




char* searchForFlexWord(nt_tree tree, int cat_val, char* form) {
    pbase_node pn = tree.root;
    while (1) {
        //check if we found a word
        if (pn->end == 1) {
            //chose it or continue by random
            if ((rand() % 6 == 1) || pn->nbsons == 0) {

                //find the flexword in the node
                pflech_node flexnode = pn->flechies;
                while(flexnode!=NULL){
                    if(cat_val == 0 || cat_val == 2) {
                        // we need to separate the components
                        char *temp = strtok(flexnode->attributs, "+"); // get the gender
                        if (temp[0] == form[0] || temp[0] == 'I') {//if the gender is the same (or indifferent)
                            temp = strtok(NULL, "+"); // get the number
                            if (temp[0] == form[1] || temp[0] == 'I') { // if the number is the same
                                return flexnode->flech_word;
                            }
                        }
                    }
                    else if(cat_val == 1){
                        // we need to separate the components
                        char *temp = strtok(flexnode->attributs, "+"); // get the conjugation
                        if (temp!=NULL && strcmp(temp,"Inf")!=0) { // if there is a attribut or if it is not infinitive
                            temp = strtok(NULL, "+"); // get the number
                            if(temp != NULL && temp[0]==form[1]) { // if the number is the same
                                temp = strtok(NULL, "+"); // get the person
                                if(temp != NULL && temp[1]=='3') return flexnode->flech_word; // if it is the 3rd person
                            }
                        }
                    }
                    else return flexnode->flech_word;

                    flexnode = flexnode->next;
                }
                // if the flexword isn't found in the node, we search another word
            }
        }
        int random;
        if(pn->nbsons==0) return searchForFlexWord(tree, cat_val, form);
        else {
            random = rand() % pn->nbsons;
            pn = pn->son;
            for (int i = 0; i < random; i++) {
                pn = pn->sibling;
            }
        }
    }
}