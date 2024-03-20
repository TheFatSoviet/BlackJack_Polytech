#include "Joueur.h"
#include <cstring>
#include <iostream>
// Assurez-vous d'inclure les autres dépendances nécessaires pour votre classe

Joueur::Joueur() {
    nom[0] = '\0';
    type_joueur[0] = '\0';
    score_in_game = 0;
    nb_partie_joue = 0;
    jeton_possede = 0;
    jeton_mise = 0;
}

void Joueur::creation_joueur(const char* nouveau_nom) {
    size_t longueur_nom = strlen(nouveau_nom);
    if (longueur_nom >= sizeof(nom)) {
        std::cerr << "Erreur : le nom est trop long." << std::endl;
        return;
    }
    strcpy(nom, nouveau_nom);
}
