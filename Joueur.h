#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <vector>
#include <cstddef>  // Pour size_t

class Joueur
{
public:
    char nom[20];
    char type_joueur[20];
    int score_in_game;
    int nb_partie_joue;
    int jeton_possede;
    int jeton_mise;
    std::vector<std::string> cartes;

    Joueur();
    void creation_joueur(const char* nouveau_nom);
    void setTypeJoueur(const char* type);
    bool pioche_tir16() const;
    void AfficherCartesJoueur(const Joueur& joueur, size_t numeroDuJoueur);
    void Afficher_donner_joueur(const Joueur& joueur);
};

#endif
