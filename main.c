
#include "N-aryCharTree.h"


int main(){

    nt_tree test = createEmptyTree();
    printf("%c", test.root->letter);
    addNode(test.root, 'a', 0);
    printf("%c", test.root->next->letter);
    addNode(test.root->next, 'b', 1);
    printf("%c", test.root->son->letter);

    return 0;
}
