
#ifndef SENTENCESGENERATOR_AUTOMATICGENERATOR_H
#define SENTENCESGENERATOR_AUTOMATICGENERATOR_H

#include "N-aryCharTree.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void generateSentence(int type, int model, nt_tree* trees);
char* searchForBasicWord(nt_tree* cat_trees, int cat_val, char* word);
pbase_node searchforNode(nt_tree, char*);
char* searchForFlexWord(nt_tree tree, int cat_val, char* form);


#endif //SENTENCESGENERATOR_AUTOMATICGENERATOR_H



