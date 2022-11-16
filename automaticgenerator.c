
#include "automaticgenerator.h"

char searchforBasicWord(nt_tree* cat_trees, int cat_val, char* word){

    pbase_node search;
    search = searchforNode(cat_trees[cat_val], word);
    if(search == NULL) return '~';
    char* full_word = word;


    // on cherche le début du word dans l'arbre
    /*p_node pn;
    found = (goToNode(trees[num_tree-1], begin_str, &pn));
    if(found == -1) return "";

    // on cherche la suite
    char* fullStr = (char*)malloc(sizeof(char));
    strcpy(fullStr, begin_str);

    int x;
    while(found == 0) {
        if((pn->kid == NULL && pn->end == 1) || (pn->end == 1 && rand()%5 == 0)) found = 1;
        else {
            x=rand()%pn->nb_kids;
            pn = pn->kid;
            for(i=0; i < x; i++){
                pn = pn->sibling;
            }
            strncat(fullStr,&pn->value, 1);
        }
    }
    return fullStr;*/
}

pbase_node searchforNode(nt_tree tree, char* word){
    int i=0, search=0;
    pbase_node here = tree.root;
    pbase_node temp;

    while(word[i] != '\0'){
        temp = here->son;
        if(temp==NULL){
            return NULL;
        }
        else{
            while(search==0){
                if (temp->letter == word[i]) search = 1;
                else if (temp->sibling != NULL) temp = temp->sibling;
                else return NULL;
            }
            here = temp;
        }
        i++;
    }
    return here;
}

