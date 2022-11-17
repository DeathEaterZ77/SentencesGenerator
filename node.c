//
// Created by Carla Gros-Alcaraz on 01/11/2022.
//

#include "node.h"
#include <string.h>

// create the node for one inflected word
pflech_node createFlechNode(char* flech_word, char* gender_nbr_time){
    pflech_node new;
    new = (pflech_node)malloc(sizeof(tflech_node));
    new->flech_word = (char*)malloc(50 * sizeof(char));
    new->attributs = (char*)malloc(50 * sizeof(char));
    strcpy(new->attributs, gender_nbr_time);
    strcpy(new->flech_word, flech_word);
    new->next = NULL;
    return new;
}

// create the node for one letter of a based word
pbase_node createNode(char val){
    pbase_node new;
    new = (pbase_node)malloc(sizeof(tbase_node));
    new->letter = val;
    new->sibling = new->son = NULL;
    new->end = 0;
    new->depth = -1;
    new->nbflech = 0;
    new->flechies = NULL;
    new->nbsons=0;
    return new;
}

// create then add the pbase_node at the end of std list "next" or "son"
void addNode(pbase_node prev, char val, int dir){
    pbase_node new = createNode(val);
    if (dir==0){ // add to sibling
        prev->sibling = new;
        prev->sibling->depth = prev->depth;
    }
    else if (dir==1){ // add to son
        prev->son = new;
        prev->son->depth = prev->depth+1;
    }
}

// create then add the pflech_node at the end of std list "flechies"
void addFlechNode(pbase_node here, char* flech_word, char* gender_nbr_time){
    here->end = 1;
    char *temp = strtok(gender_nbr_time, ":");
    if (here->nbflech==0){
        here->flechies = createFlechNode(flech_word, temp);
        temp = strtok(NULL, ":");
        here->nbflech++;
    }
    pflech_node temp_node = here->flechies;
    while (temp_node->next != NULL) {
        temp_node = temp_node->next;
    }

    while (temp != NULL) {
        temp_node->next = createFlechNode(flech_word, temp);
        temp = strtok(NULL, ":");
        here->nbflech++;
        temp_node = temp_node->next;
    }

}

