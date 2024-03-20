#include "Joueur.cpp" // Assurez-vous que Joueur.cpp définit correctement la classe Joueur

// Définition de la classe courpier qui hérite de Joueur.
class courpier : public Joueur {
public:
    // Déclare la méthode pioche_courpier pour déterminer si le croupier doit piocher une carte.
    bool pioche_courpier(int score_in_game);
};

// Implémentation de la méthode pioche_courpier.
// Note : Cette implémentation devrait être dans le fichier courpier.cpp si vous séparez les déclarations des implémentations.
bool courpier::pioche_courpier(int score_in_game) {
    if (score_in_game <= 17) {
        return true; // Retourne vrai, indiquant que le croupier doit piocher.
    } else {
        return false; // Retourne faux, le croupier ne doit pas piocher.
    }
}
