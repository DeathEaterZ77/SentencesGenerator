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

void fillTrees(nt_tree*,nt_tree*,nt_tree*,nt_tree*){

    // ouvrir le fichier

    // faire une boucle pour lire charque ligne du fichier ouvert
        //découper la ligne en 3 char*

        //verifier dans quel arbre doit aller la ligne

        //appeler "addWordToTree" pour ajouter la ligne à l'arbre


   // fermer le fichier

}

void addWordToTree(char*, char*, char*, int, nt_tree*){

    // on fait une boucle pour parcourir tous les caractères de la forme de base jusqu'a ce qu'il soit == '\0'
        // on parcours tous les frères du noeud où on se trouve pour chercher le caractère

        // si on ne l'a pas trouvé dans la boucle, on le crée (avec la fonction "addNode")

        // on avance dans ce noeuds

   // une fois avoir parcouru tous les caractères, on met le end du noeud courant à 1 (car on est actuellement sur le dernier caractère)

   // pas indispendable pour l'instant, tester d'abord sans:
            //on ajoute les formes fléchies dans le noeud courant (donc du dernier caractère) avec la fonction ("addFlechNode")
}

