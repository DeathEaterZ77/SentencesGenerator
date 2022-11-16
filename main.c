
#include "automaticgenerator.h"

int main(){

    //tests
    nt_tree test = createEmptyTree();
    printf("%c", test.root->letter);
    addNode(test.root, 'a', 1);
    printf("%c", test.root->son->letter);
    addNode(test.root->son, 'b', 0);
    printf("%c", test.root->son->sibling->letter);


//main

    nt_tree nt_name = createEmptyTree(), nt_verb = createEmptyTree(), nt_adj = createEmptyTree(), nt_adv = createEmptyTree();
    nt_tree cat_trees[4] = {nt_name,nt_verb,nt_adj,nt_adv};

    fill_NTrees(cat_trees);



    return 0;
}
