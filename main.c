#include <stdlib.h>
#include <stdio.h>

FILE* fopen(const char* dico_10_lignes, const char* r);
int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    fichier = fopen("dico_10_lignes.txt", "r");

    return 0;
}
