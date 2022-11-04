//
// Created by Carla Gros-Alcaraz on 01/11/2022.
//

#ifndef SENTENCESGENERATOR_NODE_H
#define SENTENCESGENERATOR_NODE_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>


// data structures of 2 types of nodes

struct flech_node{ // inflected form node collection
    char flech_word; // inflected form
    char attributs; // gender, number, time
    struct flech_node *next;
};
typedef struct flech_node tflech_node, *pflech_node;

struct base_node{ // based forms node collection
    char letter;
    struct base_node *next, *son;
    int end; // if we reach the end of the based word
    int depth;
    pflech_node flechies; // associated inflected forms
};
typedef struct base_node tbase_node, *pbase_node;


// functions implemented
pflech_node createFlechNode(char,char);
pbase_node createNode(char);




#endif //SENTENCESGENERATOR_NODE_H