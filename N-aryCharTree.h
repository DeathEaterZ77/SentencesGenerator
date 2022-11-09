//
// Created by Carla Gros-Alcaraz on 05/11/2022.
//

#ifndef SENTENCESGENERATOR_N_ARYCHARTREE_H
#define SENTENCESGENERATOR_N_ARYCHARTREE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

struct n_tree{
    pbase_node root;
};
typedef struct n_tree nt_tree, *np_tree;

//implemented functions
nt_tree createEmptyTree();


// to implement functions
void fill_NTrees(nt_tree*);
void addWordToTree(char*, char*, char*, nt_tree*);




#endif //SENTENCESGENERATOR_N_ARYCHARTREE_H
