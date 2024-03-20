#include "Afficher_Cartes_Joueur.h" // Inclut l'en-tête nécessaire pour la déclaration de la fonction.
#include <iostream> // Nécessaire pour les opérations d'entrée/sortie, comme std::cout.

// La fonction prend en paramètre une référence constante à un objet Joueur et un size_t représentant le numéro du joueur.
void Afficher_Cartes_Joueur(const Joueur& joueur, size_t numeroDuJoueur)
{
    // Commence par afficher le numéro et le nom du joueur.
    std::cout << "Joueur " << numeroDuJoueur << " (" << joueur.nom << ") a les cartes: ";
    // Itère sur le vecteur de cartes du joueur pour afficher chaque carte.
    for (const auto& carte : joueur.cartes)
    {
        std::cout << carte << " "; // Affiche la carte suivie d'un espace pour séparer les cartes entre elles.
    }
    std::cout << std::endl; // Termine l'affichage par un retour à la ligne pour une meilleure lisibilité.
}
