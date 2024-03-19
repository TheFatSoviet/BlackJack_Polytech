#include <vector>
#include <string>

int Calcule_Score(const std::vector<std::string>& cartes)
{
    int score = 0;
    int nombreAs = 0;     // Compter le nombre d'As pour ajuster leur valeur à la fin

    // Assigner les valeurs initiales, sans compter les As
    for (const std::string& carte : cartes)
    {
        if (carte == "D" || carte == "R" || carte == "V")
        {
            score += 10;
        }
        else if (carte == "1")
        {
            ++nombreAs; // Compter les As pour les traiter plus tard
        }
        else if (!carte.empty())
        { // Ignorer les cartes vides et traiter les nombres
            score += std::stoi(carte); // Convertir la valeur de la carte en entier et l'ajouter au score
        }
    }

    // Traitement des As
    for (int i = 0; i < nombreAs; ++i)
    {
        // Si l'ajout de 11 dépasse 21, l'As vaut 1. Sinon, il vaut 11.
        if (score + 11 > 21)
        {
            score += 1;
        }
        else
        {
            score += 11;
        }
    }
    return score;
}
