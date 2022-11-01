#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 1000

int main() {
    FILE* dico_test = NULL;// create a pointer of type file & initialize it to NULL
    char str[MAX_SIZE]="";

    dico_test = fopen("../dico.txt","r");//open the file

    if (dico_test == NULL) // test if the file is NULL
        printf("Cannot open this file");

    while(fgets(str,MAX_SIZE,dico_test)!=NULL)
    {
        printf("%s",str);
    }
    return 0;
}
