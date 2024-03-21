#include "Distribuer_Cartes.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Joueur.h"

void Distribuer_Cartes(std::vector<Joueur>& joueurs)
{
    std::ifstream fileIn("Sabot.txt"); // Ouvre le fichier Sabot.txt pour lire les cartes disponibles.
    std::string contenu, carte;
    std::vector<std::string> cartes; // Vecteur pour stocker toutes les cartes lues du fichier.

    if (fileIn.is_open())
    {
        getline(fileIn, contenu); // Lit toute la ligne du fichier, les cartes étant supposées être séparées par des virgules.
        fileIn.close(); // Ferme le fichier après la lecture.

        std::stringstream ss(contenu); // Utilise un flux de chaîne pour traiter les cartes séparées par des virgules.

        // Lire et stocker chaque carte dans le vecteur de cartes.
        while (std::getline(ss, carte, ','))
        {
            if (!carte.empty()) { // Vérifie que la chaîne n'est pas vide pour éviter d'ajouter des cartes vides.
                cartes.push_back(carte);
            }
        }
    }

    // Attribuer deux cartes à chaque joueur et les retirer de la liste des cartes disponibles.
    for (auto& joueur : joueurs)
    {
        if (cartes.size() >= 2)
        {
            joueur.cartes.push_back(cartes[0]);
            joueur.cartes.push_back(cartes[1]);
            cartes.erase(cartes.begin(), cartes.begin() + 2); // Supprime les cartes distribuées du vecteur.
        }
    }

    // Mettre à jour le fichier Sabot.txt avec les cartes restantes.
    std::ofstream fileOut("Sabot.txt");
    if (fileOut.is_open())
    {
        for (size_t i = 0; i < cartes.size(); ++i)
        {
            fileOut << cartes[i];
            if (i != cartes.size() - 1)
            { // Ajoute une virgule entre les cartes, sauf après la dernière.
                fileOut << ",";
            }
        }
        fileOut.close(); // Ferme le fichier après l'écriture.
    }
}
