
#include "automaticgenerator.h"

int main(){

//main
    srand(time(NULL));
    printf("------ Welcome to the Automatic Sentence Generator program ------\n\n");
    nt_tree nt_name = createEmptyTree(), nt_verb = createEmptyTree(), nt_adj = createEmptyTree(), nt_adv = createEmptyTree();

    nt_tree cat_trees[4] = {nt_name,nt_verb,nt_adj,nt_adv};
    fill_NTrees(cat_trees);


    int choice;
    int loop = 1;
    while(loop==1) {
        do {
            printf("What do you want to do ? Choose an option :\n\t1- Research or extract at random a basic form\n\t2- Generate a random sentence\n\t3- Quit...\n\n");
            scanf("%d", &choice);
        } while (choice<1 || choice>3);

        switch (choice) {
            case 1: { // in order to find a word
                int cat = 0, end = 0;

                do {
                    printf("Which type of word do you want ?\n\t1- a noun\n\t2- a verb\n\t3- an adjective\n\t4- an adverb\n\t5- select at random\n");
                    scanf("%d", &cat);
                } while (cat < 0 || cat > 6);

                do {
                    printf("Do you want : \n\t1- the end of a word ?\n\t2- a random word\n");
                    scanf("%d", &end);
                } while (end < 0 || end > 2);

                if (end == 2)printf("Your word is : %s\n", searchForBasicWord(cat_trees, cat-1, ""));
                else {
                    char *word = (char *) malloc(50 * sizeof(char));
                    printf("Enter the beginning of the word you want to find the end:");
                    scanf("%s", word);
                    printf("The full word is : %s\n\n", searchForBasicWord(cat_trees, cat - 1, word));
                }
                break;
            }

            case 2: { // generate basic forms sentence
                int type,model=1;
                do {
                    printf("Do you want a sentence with :\n\t1- basic forms\n\t2- inflated forms\n");
                    scanf("%d", &type);
                } while (type<1||type>2);


                if(type==1)do {
                    printf("Which model of sentence do you want to generate ?"
                           "\n\t1- noun - adjective - verb - noun\n\t2- noun - qui - verb - verb - noun - adjective\n\t3- noun - adjective - verb - adverb - noun\n");
                    scanf("%d", &model);
                } while (model<1 || model>3);

                generateSentence(type, model,cat_trees);
                break;
            }
            case 3: {
                printf("See you next time !");
                loop = 0;
                break;
            }

            default :
                printf("Error...");
                break;

        }
    }
    return 0;

}
