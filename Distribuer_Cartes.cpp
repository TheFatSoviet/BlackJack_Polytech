#include "Distribuer_Cartes.h"
#include <fstream>
#include <sstream>
#include <string>


void Distribuer_Cartes(std::vector<Joueur>& joueurs)
{
    std::ifstream fileIn("Sabot.txt");
    std::string contenu, carte;
    std::vector<std::string> cartes;

    if (fileIn.is_open())
    {
        getline(fileIn, contenu);
        fileIn.close();

        std::stringstream ss(contenu);

        // Lire toutes les cartes dans le vecteur
        while (std::getline(ss, carte, ','))
        {
            if (!carte.empty())
            { // Vérifier que la chaîne n'est pas vide
                cartes.push_back(carte);
            }
        }
    }

    // Attribuer deux cartes à chaque joueur et les retirer de la liste
    for (auto& joueur : joueurs)
    {
        if (cartes.size() >= 2)
        {
            joueur.cartes.push_back(cartes[0]);
            joueur.cartes.push_back(cartes[1]);
            cartes.erase(cartes.begin(), cartes.begin() + 2); // Retirer les deux premières cartes
        }
    }

    // Mettre à jour le fichier avec les cartes restantes
    std::ofstream fileOut("Sabot.txt");
    if (fileOut.is_open())
    {
        for (size_t i = 0; i < cartes.size(); ++i)
        {
            fileOut << cartes[i];
            if (i != cartes.size() - 1)
            {
                fileOut << ",";
            }
        }
        fileOut.close();
    }
}
