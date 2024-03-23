#include "Afficher_Cartes_Joueur.h" // Inclut l'en-tête nécessaire pour la déclaration de la fonction.
#include <iostream> // Nécessaire pour les opérations d'entrée/sortie, comme std::cout.

void Afficher_Cartes_Joueur(const Joueur& joueur, size_t numeroDuJoueur)
{
    std::cout << "Joueur " << numeroDuJoueur << " (" << joueur.nom << ") (" << joueur.type_joueur
              << ") a les cartes: ";

    if (numeroDuJoueur == 0)
    {
        // Affiche la première carte normalement, les autres en tant que "X"
        bool premiereCarteAffichee = false;
        for (const auto& carte : joueur.cartes)
        {
            if (!premiereCarteAffichee)
            {
                std::cout << carte << " "; // Affiche la première carte
                premiereCarteAffichee = true;
            }
            else
            {
                std::cout << "X "; // Remplace les autres cartes par "X"
            }
        }
    }
    else
    {
        // Pour les autres joueurs, affiche toutes les cartes normalement
        for (const auto& carte : joueur.cartes)
        {
            std::cout << carte << " ";
        }
    }

    std::cout << std::endl;
}







//Pour debug : permet de voir TOUTE les cartes, meme celui du dealer
//
// // La fonction prend en paramètre une référence constante à un objet Joueur et un size_t représentant le numéro du joueur.
// void Afficher_Cartes_Joueur(const Joueur& joueur, size_t numeroDuJoueur)
// {
//     // Commence par afficher le numéro et le nom du joueur.
//     std::cout << "Joueur " << numeroDuJoueur << " (" << joueur.nom << ") (" << joueur.type_joueur
//   << ") a les cartes: ";
//     // Itère sur le vecteur de cartes du joueur pour afficher chaque carte.
//     for (const auto& carte : joueur.cartes)
//     {
//         std::cout << carte << " "; // Affiche la carte suivie d'un espace pour séparer les cartes entre elles.
//     }
//     std::cout << std::endl; // Termine l'affichage par un retour à la ligne pour une meilleure lisibilité.
// }
