#include <vector>
#include <string> // Inclusion des bibliothèques nécessaires pour utiliser les vecteurs et les chaînes de caractères.

// Fonction pour calculer le score à partir d'un vecteur de chaînes représentant les cartes.
int Calcule_Score(const std::vector<std::string>& cartes)
{
    int score = 0; // Initialisation du score total à 0.
    int nombreAs = 0; // Compteur pour le nombre d'As, car leur valeur peut être 1 ou 11.

    // Parcourir chaque carte dans le vecteur pour assigner les valeurs initiales.
    for (const std::string& carte : cartes)
    {
        if (carte == "D" || carte == "R" || carte == "V") // Si la carte est un roi, une dame, ou un valet,
        {
            score += 10; // leur valeur est 10.
        }
        else if (carte == "1") // Si la carte est un As,
        {
            ++nombreAs; // incrémenter le compteur d'As sans ajouter de score pour l'instant.
        }
        else if (!carte.empty()) // Pour toutes les autres cartes (en ignorant les cartes vides),
        {
            score += std::stoi(carte); // convertir la valeur de la carte en entier et l'ajouter au score.
        }
    }

    // Après avoir assigné les valeurs initiales, traiter les As.
    for (int i = 0; i < nombreAs; ++i)
    {
        // Pour chaque As, décider de sa valeur pour maximiser le score sans dépasser 21.
        if (score + 11 > 21) // Si ajouter 11 dépasse 21,
        {
            score += 1; // l'As vaut 1.
        }
        else
        {
            score += 11; // Sinon, l'As vaut 11.
        }
    }

    return score; // Retourner le score total calculé.
}
