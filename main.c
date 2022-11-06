
#include "N-aryCharTree.h"


int main(){

    nt_tree test = createEmptyTree();
    printf("%c", test.root->letter);
    addNode(test.root, 'a', 1);
    printf("%c", test.root->son->letter);
    addNode(test.root->son, 'b', 0);
    printf("%c", test.root->son->sibling->letter);

    return 0;
}
