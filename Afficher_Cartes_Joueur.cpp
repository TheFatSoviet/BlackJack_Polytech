#include "Afficher_Cartes_Joueur.h"
#include <iostream>


void Afficher_Cartes_Joueur(const Joueur& joueur, size_t numeroDuJoueur)
{
    std::cout << "Joueur " << numeroDuJoueur << " (" << joueur.nom << ") a les cartes: ";
    for (const auto& carte : joueur.cartes)
    {
        std::cout << carte << " ";
    }
    std::cout << std::endl;
}
