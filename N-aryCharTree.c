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

