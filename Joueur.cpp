#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <string>

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
    std::vector<std::string> cartes; // Pour stocker les cartes du joueur

    Joueur() {
        nom[0] = '\0'; // Initialise le nom avec une chaîne vide
        type_joueur[0] = '\0'; // Initialise le type de joueur avec une chaîne vide
        score_in_game = 0;
        nb_partie_joue = 0;
        jeton_possede = 0;
        jeton_mise = 0;
    }


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
