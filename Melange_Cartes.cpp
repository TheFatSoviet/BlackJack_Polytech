#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <random>
#include <algorithm>
#include <deque>
//ok2

// Fonction pour cr�er le fichier .txt avec les cartes m�lang�es
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

int Melange_Cartes(char value) {
    if (value < '1' || value > '8')
        return 0; // Si la valeur n'est pas entre 1 et 8, renvoyer 0

    // Création d'un jeu de cartes
    std::vector<char> Sabot_Type = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '0', 'V', 'D', 'R'};
    std::vector<char> Cartes;

    // Multiplication du jeu de cartes par le nombre de joueurs
    for (int i = 0; i < (value - '0'); ++i) {
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
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
        return -1;
    }

    // Écriture des cartes dans le fichier
    for (char card : Cartes) {
        file << card << ",";
    }

    file.close(); // Fermeture du fichier
    return 1; // Renvoyer 1 si tout est ok
}















void RetireCartes(int nombre_cartes) {
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





int main()
{
    char Nombre_Joueurs;

    std::cout << "Entrez le nombre de joueurs (entre 1 et 8) : ";
    std::cin >> Nombre_Joueurs;

    bool SUCCES___Melange_Cartes = Melange_Cartes(Nombre_Joueurs);

    if (SUCCES___Melange_Cartes == 0)
    {
        std::cout << "La valeur n'est pas entre 1 et 8." << std::endl;
    }
    else if (SUCCES___Melange_Cartes == 1)
    {
        std::cout << "Fichier sabot.txt cree avec succes." << std::endl;
    }






    int NB_Cartes_a_retirer;
    std::cout << "Entrez le nombre de cartes a retirer : ";
    std::cin >> NB_Cartes_a_retirer;

    // Exemple d'utilisation de la fonction RetireCartes
    RetireCartes(NB_Cartes_a_retirer);

    return 0;
}
