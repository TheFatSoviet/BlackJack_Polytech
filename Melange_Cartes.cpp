#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Fonction pour cr�er le fichier .txt avec les cartes m�lang�es
int Melange_Cartes(char value)
{
    if (value < '1' || value > '8')
    return 0; // Si la valeur n'est pas entre 1 et 8, renvoyer 0

    // Cr�ation d'un jeu de cartes
    std::vector<char> Sabot_Type = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '0', 'V', 'D', 'R'};
    std::vector<char> Cartes;

    // Multiplication du jeu de cartes par le nombre de joueurs
    for (int i = 0; i < (value - '0'); ++i)
    {
        Cartes.insert(Cartes.end(), Sabot_Type.begin(), Sabot_Type.end());
    }

    // M�langer les cartes
    std::random_shuffle(Cartes.begin(), Cartes.end());

    // Cr�ation du nom du fichier
    std::string filename = "Sabot.txt";

    // Ouverture du fichier en mode �criture
    std::ofstream file(filename);

    // V�rification que le fichier est bien ouvert
    if (!file.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
        return -1;
    }

    // �criture des cartes dans le fichier
    for (char card : Cartes)
    {
        file << card << ",";
    }

    file.close(); // Fermeture du fichier
    return 1; // Renvoyer 1 si tout est ok
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

    return 0;
}
