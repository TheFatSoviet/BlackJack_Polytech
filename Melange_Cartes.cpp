#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Melange_Cartes.h"

int Melange_Cartes(char value)
{
    value++;
    if (value < '1' || value > '8')
        return 0; // Si la valeur n'est pas entre 1 et 8, renvoyer 0

    // Création d'un jeu de cartes
    std::vector<char> Sabot_Type = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'V', 'D', 'R'};
    std::vector<char> Cartes;

    // Multiplication du jeu de cartes par le nombre de joueurs
    for (int i = 0; i < (value - '0'); ++i)
    {
        Cartes.insert(Cartes.end(), Sabot_Type.begin(), Sabot_Type.end());
    }

    // Utiliser srand pour initialiser le générateur de nombres aléatoires avec le temps actuel
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::random_shuffle(Cartes.begin(), Cartes.end());

    // Création du nom du fichier
    std::string filename = "Sabot.txt";

    // Ouverture du fichier en mode écriture
    std::ofstream file(filename);

    // Vérification que le fichier est bien ouvert
    if (!file.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
        return -1;
    }

    // Écriture des cartes dans le fichier
    for (char card : Cartes)
    {
        file << card << ",";
    }

    file.close(); // Fermeture du fichier
    return 1; // Renvoyer 1 si tout est ok
}
