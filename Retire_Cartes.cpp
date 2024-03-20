#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// Fonction pour retirer un nombre spécifié de cartes du fichier "Sabot.txt".
void Retire_Cartes(int nombre_cartes)
{
    std::string filename = "Sabot.txt"; // Nom du fichier contenant les cartes.
    std::ifstream fileIn(filename); // Ouvre le fichier en mode lecture.
    std::string contenu, carte; // Variables pour stocker le contenu complet du fichier et les cartes individuelles.
    std::vector<std::string> cartes; // Vecteur pour stocker toutes les cartes lues du fichier.

    // Vérifie si le fichier a été correctement ouvert.
    if (fileIn.is_open())
    {
        getline(fileIn, contenu); // Lit la totalité du contenu du fichier.
        fileIn.close(); // Ferme le fichier après la lecture.

        std::stringstream ss(contenu); // Utilise un flux de chaîne pour traiter le contenu.

        // Lire et stocker chaque carte dans le vecteur.
        while (std::getline(ss, carte, ','))
        {
            if (!carte.empty()) // Assure que la chaîne n'est pas vide pour éviter d'ajouter des cartes vides.
            {
                cartes.push_back(carte);
            }
        }

        // Vérifie si suffisamment de cartes sont disponibles pour être retirées.
        if (nombre_cartes <= static_cast<int>(cartes.size()))
        {
            // Retire le nombre spécifié de cartes du début du vecteur.
            cartes.erase(cartes.begin(), cartes.begin() + nombre_cartes);

            // Réouvre le fichier en mode écriture pour mettre à jour son contenu.
            std::ofstream fileOut(filename);
            if (!fileOut.is_open()) // Vérifie si le fichier a été correctement ouvert.
            {
                std::cerr << "Erreur lors de la réouverture du fichier pour écriture." << std::endl;
                return;
            }

            // Écrit les cartes restantes dans le fichier, séparées par des virgules.
            for (size_t i = 0; i < cartes.size(); ++i)
            {
                fileOut << cartes[i];
                if (i != cartes.size() - 1) // Ne pas ajouter de virgule après la dernière carte.
                {
                    fileOut << ",";
                }
            }

            fileOut.close(); // Ferme le fichier après l'écriture.
            std::cout << nombre_cartes << " cartes retirées avec succès." << std::endl;
        }
        else // Si pas assez de cartes sont disponibles pour être retirées.
        {
            std::cerr << "Pas assez de cartes pour retirer." << std::endl;
        }
    }
    else // Si le fichier n'a pas pu être ouvert.
    {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }
}
