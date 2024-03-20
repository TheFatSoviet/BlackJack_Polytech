#include "Joueur.h"
#include <cstring> // Pour les fonctions de manipulation de chaînes de caractères comme strcpy et strncpy.
#include <iostream> // Pour l'entrée/sortie, notamment std::cerr.

// Définition du constructeur de la classe Joueur.
Joueur::Joueur() {
    nom[0] = '\0'; // Initialise le nom du joueur avec une chaîne vide.
    type_joueur[0] = '\0'; // Initialise le type du joueur avec une chaîne vide.
    score_in_game = 0; // Initialise le score du joueur à 0 pour le début de la partie.
    nb_partie_joue = 0; // Initialise le nombre de parties jouées à 0.
    jeton_possede = 0; // Initialise le nombre de jetons possédés à 0.
    jeton_mise = 0; // Initialise le nombre de jetons misés à 0.
    std::vector<std::string> cartes; // Crée un vecteur pour stocker les cartes, mais cette ligne ne fait rien et devrait être retirée ou modifiée.
}

// Méthode pour définir le type de joueur.
void Joueur::setTypeJoueur(const char* type)
{
    strncpy(type_joueur, type, sizeof(type_joueur) - 1); // Copie le type en s'assurant de ne pas dépasser la taille du tableau.
    type_joueur[sizeof(type_joueur) - 1] = '\0'; // Assure que la chaîne est bien terminée par un caractère nul.
}

// Méthode pour déterminer si le joueur doit piocher une carte selon la règle du 16.
bool Joueur::pioche_tir16() const
{
    return score_in_game < 17; // Retourne vrai si le score est inférieur à 17, indiquant que le joueur doit piocher.
}

// Méthode pour définir ou changer le nom du joueur.
void Joueur::creation_joueur(const char* nouveau_nom)
{
    size_t longueur_nom = strlen(nouveau_nom); // Calcule la longueur du nouveau nom.
    if (longueur_nom >= sizeof(nom)) // Vérifie si le nouveau nom est trop long pour le tableau 'nom'.
    {
        std::cerr << "Erreur : le nom est trop long." << std::endl; // Affiche une erreur si c'est le cas.
        return; // Quitte la méthode sans changer le nom.
    }
    strcpy(nom, nouveau_nom); // Copie le nouveau nom dans le tableau 'nom' si tout est en ordre.
}
