#include "Ranger_Cartes.h"
#include <fstream>
#include <iostream>


void Ranger_Cartes(std::vector<Joueur>& joueurs)
{
    std::ofstream fileOut("Sabot.txt", std::ios::app); // Ouvre le fichier en mode append

    if (!fileOut.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier pour ajouter." << std::endl;
        return;
    }

    // Vérifie si le fichier est vide pour savoir si on doit ajouter une virgule au début
    fileOut.seekp(0, std::ios::end);
    if(fileOut.tellp() != 0) { // Si le fichier n'est pas vide
        fileOut << ","; // Ajoute une virgule avant de commencer l'ajout des nouvelles cartes
    }

    // Itérer sur tous les joueurs sauf le dealer (joueur[0]) et écrire leurs cartes
    bool isFirstCard = true;
    for (size_t i = 1; i < joueurs.size(); ++i)
    { // Commencer à 1 pour ignorer le dealer
        for (const auto& carte : joueurs[i].cartes)
        {
            if (!isFirstCard)
            {
                fileOut << ","; // Ajoute une virgule avant chaque carte sauf la première
            }
            fileOut << carte;
            isFirstCard = false;
        }
    }

    // Ajouter les cartes du dealer (joueur[0]) en dernier
    for (const auto& carte : joueurs[0].cartes)
    {
        if (!isFirstCard)
        {
            fileOut << ",";
        }
        fileOut << carte;
        isFirstCard = false;
    }

    fileOut.close();
    std::cout << "Cartes ranger avec succes dans le sabot." << std::endl;
}
