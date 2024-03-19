
#include "Melange_Cartes.cpp"
#include "Retire_Cartes.cpp"
#include "Rajout_Cartes.cpp"


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
    Retire_Cartes(NB_Cartes_a_retirer);


    std::vector<std::string> cartes_a_ajouter = {"1", "2", "3"};
    Rajout_Cartes(cartes_a_ajouter);



    return 0;
}
