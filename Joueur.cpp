#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Joueur
{
public:
    char nom[20];
    char type_joueur[20];
    int score_in_game;
    int nb_partie_joue;
    int jeton_possede;
    int jeton_mise;


    void creation_joueur(const char* nouveau_nom)
    {
        size_t longueur_nom = strlen(nouveau_nom);
        if (longueur_nom >= sizeof(nom)) // sizeof(nom) donne la taille du tableau `nom`
        {
            std::cerr << "Erreur : le nom est trop long." << std::endl;
            return;
        }

        strcpy(nom, nouveau_nom);
    }

};
