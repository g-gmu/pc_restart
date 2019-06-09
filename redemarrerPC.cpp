
#include "redemarrerPC.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

redemarrerPC::redemarrerPC(){
    }

redemarrerPC::~redemarrerPC(){
    }

void redemarrerPC::redemarrageDuPC(){

    char commande [256];
    char nomPC [256];
    int  nCaractere (0);
    int  p (0);

    /**| information |*******************************************************
    Copie le nom du PC("hostname") dans un "fichier.txt"
    *************************************************************************/
    sprintf(commande, "hostname > C:\\nomPC.txt");
    system(commande);

    /**| information |*******************************************************
    Ouvre le "fichier.txt", copie les caracteres dans "nomPC", compte le
    nombre de caracteres.  Ferme ensuite le fichier.
    *************************************************************************/
    FILE *fichier;
    if ((fichier = fopen("C:\\nomPC.txt", "r")) == NULL)
        perror("Ouverture impossible");
    else {
        while((nCaractere = fgetc(fichier)) != EOF){
            nomPC[p] = nCaractere;
            p++;
            }
        }
    fclose(fichier);

    /**| information |*******************************************************
    nCaractere recoit le nombre de caractere compris dans la chaine "nomPC"
    l'avant dernier caractere de la chaine "nomPC" recoit '\0'.  Supprime
    ainsi le caractere "\0".
    *************************************************************************/
    nCaractere = strlen(nomPC);
    nomPC[p -1] = '\0';

    /**| information |*******************************************************
    Supprime le "fichier.txt" de son emplacement.
    *************************************************************************/
    remove("C:\\nomPC.txt");

    /**| information |*******************************************************
    Lance la commande permettant de fermer le PC et y ajoute la recuperation
    du "nomPC".
    *************************************************************************/
    sprintf(commande, "shutdown -f -r -m \\\\%s -t 00 -c \"STOP\"", nomPC);
    system(commande);
    }
