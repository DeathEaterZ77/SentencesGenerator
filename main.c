
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

    printf("------ Welcome to the Automatic Sentence Generator program ------\n\n)";
    nt_tree nt_name = createEmptyTree(), nt_verb = createEmptyTree(), nt_adj = createEmptyTree(), nt_adv = createEmptyTree();
    nt_tree cat_trees[4] = {nt_name,nt_verb,nt_adj,nt_adv};

    fill_NTrees(cat_trees);

    int choice;
    do{
    printf("What do you want to do ? Choose an option :\n\t1- Research or extract at random a basic form\n\t2- Generate a random sentence\n\n");
    scanf("%d",&choice);} while(choice!=1 && choice!=2);

    switch(choice){
        case 1:{
            int cat;
            do{
            printf("Which type of word do you want ?\n\t1- a noun\n\t2- a verb\n\t3- an adjective\n\t4- an adverb\n\t5- select at random\n");
            scanf("%d",&cat);} while(cat>0 && cat<6);

            char* word = (char*)malloc(sizeof(char)*100);
            printf("Enter the beginning of the word you want to find the end : ");
            scanf("%s",word);

            //find random word
            //find end of word

            break;
        }
        case 2:{
            int type;
            do{
                printf("Which model of sentence do you want to generate ?"
                       "\n\t1- noun - adjective - verb - noun\n\t2- noun - qui - verb - verb - noun - adjective\n");
                scanf("%d", &type);} while(type!=1 && type!=2);

            // generate basic forms sentence

            break;
        }


        default : printf("Error..."); break;


    return 0;
    }
}
