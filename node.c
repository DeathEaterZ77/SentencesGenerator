//
// Created by Carla Gros-Alcaraz on 01/11/2022.
//

#include "node.h"

// create the node for one inflected word
pflech_node createFlechNode(char* flech_word, char* gender_nbr_time){
    pflech_node new;
    new = (pflech_node)malloc(sizeof(pflech_node));
    new->flech_word = flech_word;
    new->attributs = gender_nbr_time;
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
    new->flechies = NULL;
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
        prev->nbsons++;
    }
}

// create then add the pflech_node at the end of std list "flechies"
void addFlechNode(pbase_node here, char* flech_word, char* gender_nbr_time){
    here->end = 1;

    pflech_node new = createFlechNode(flech_word,gender_nbr_time);
    if (here->flechies == NULL) here->flechies = new;
    else{
        pflech_node temp = here->flechies->next;
        while ( temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
}

