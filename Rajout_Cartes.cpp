#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void Rajout_Cartes(const std::vector<std::string>& cartes_a_ajouter)
{
    std::string filename = "Sabot.txt";
    std::ofstream fileOut(filename, std::ios::app); // Ouvre le fichier en mode append

    if (!fileOut.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier pour l'ajout." << std::endl;
        return;
    }

    if (!cartes_a_ajouter.empty())
    {
        fileOut << ","; // Ajoute une virgule avant de commencer l'ajout des nouvelles cartes
    }

    for (size_t i = 0; i < cartes_a_ajouter.size(); ++i)
    {
        fileOut << cartes_a_ajouter[i];
        if (i != cartes_a_ajouter.size() - 1)
        {
            fileOut << ","; // Ajoute une virgule entre les cartes, sauf après la dernière
        }
    }

    fileOut.close(); // Ferme le fichier après l'ajout
    std::cout << cartes_a_ajouter.size() << " cartes ajoutees avec succes à la fin du fichie." << std::endl;
}
