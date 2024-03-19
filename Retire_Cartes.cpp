#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>







void Retire_Cartes(int nombre_cartes) {
    std::string filename = "Sabot.txt";
    std::ifstream fileIn(filename);
    std::string contenu, carte;
    std::vector<std::string> cartes;

    if (fileIn.is_open()) {
        getline(fileIn, contenu);
        fileIn.close();

        std::stringstream ss(contenu);

        // Lire toutes les cartes dans le vecteur
        while (std::getline(ss, carte, ',')) {
            if (!carte.empty()) { // Vérifier que la chaîne n'est pas vide
                cartes.push_back(carte);
            }
        }

        // Vérifier qu'il y a suffisamment de cartes à retirer
        if (nombre_cartes <= static_cast<int>(cartes.size())) {
            // Éliminer le nombre spécifié de cartes du début du vecteur
            cartes.erase(cartes.begin(), cartes.begin() + nombre_cartes);

            // Ouvrir le fichier en écriture pour mettre à jour le contenu
            std::ofstream fileOut(filename);
            if (!fileOut.is_open()) {
                std::cerr << "Erreur lors de la réouverture du fichier pour écriture." << std::endl;
                return;
            }

            // Écrire les cartes restantes dans le fichier, séparées par des virgules
            for (size_t i = 0; i < cartes.size(); ++i) {
                fileOut << cartes[i];
                if (i != cartes.size() - 1) {
                    fileOut << ",";
                }
            }

            fileOut.close();
            std::cout << nombre_cartes << " cartes retirées avec succès." << std::endl;
        } else {
            std::cerr << "Pas assez de cartes pour retirer." << std::endl;
        }
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }
}
