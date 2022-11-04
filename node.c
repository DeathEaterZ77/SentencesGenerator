//
// Created by Carla Gros-Alcaraz on 01/11/2022.
//

#include "node.h"

pflech_node createNodeFlech(char flech_word, char genre_nbr_tps){
    pflech_node new;
    new->flech_word = flech_word;
    new->attributs = genre_nbr_tps;
    new->next = NULL;
    return new;
}

pbase_node createNode(char val){
    pbase_node new;
    new->letter = val;
    new->next = new->son = NULL;
    new->end = 0;
    new->depth = -1;
    new->flechies = NULL;
    return new;
}
