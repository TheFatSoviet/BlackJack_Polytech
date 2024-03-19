#include "Melange_Cartes.cpp"
#include "Retire_Cartes.cpp"
#include "Rajout_Cartes.cpp"
#include "Calcule_Score.cpp"
#include "Joueur.cpp"

//fhefguy
int main()
{
  char Nombre_Joueurs_char=0;
  int Nombre_Joueurs=0;


  while (Nombre_Joueurs < 1 || Nombre_Joueurs > 8)
  {
    std::cout << "Entrez le nombre de joueurs a creer (entre 1 et 8) : ";
    std::cin >> Nombre_Joueurs_char;
    std::cin.ignore(); // "saut de ligne"

    // Convertir char en int
    Nombre_Joueurs = Nombre_Joueurs_char - '0';

    // Vérification que le nombre est dans la plage [1, 8]
    if (Nombre_Joueurs < 1 || Nombre_Joueurs > 8)
    {
        std::cerr << "Le nombre de joueurs doit etre entre 1 et 8." << std::endl;
    }
  }
//-------------------

  std::vector<Joueur> joueurs(Nombre_Joueurs);

  for (int i = 0; i < Nombre_Joueurs; ++i)
  {
      std::cout << "Entrez le nom pour le joueur " << i + 1 << ": ";
      std::string nomTemp;
      std::getline(std::cin, nomTemp); // Lire le nom complet, y compris les espaces

      // Assurer que le nom n'est pas trop long pour le tableau dans Joueur
      if (nomTemp.length() >= sizeof(joueurs[i].nom))
      {
          std::cerr << "Erreur : le nom est trop long. Il sera tronque." << std::endl;
          nomTemp.resize(sizeof(joueurs[i].nom) - 1); // Réduire la taille pour qu'elle rentre
      }

      // Copier le nom dans la structure du joueur
      strcpy(joueurs[i].nom, nomTemp.c_str()); //copie string vers string(dest , src)
  }

  // Affichage pour vérification
  for (int i = 0; i < Nombre_Joueurs; ++i)
    {
      std::cout << "Nom du joueur " << i + 1 << ": " << joueurs[i].nom << std::endl;
    }

    bool SUCCES___Melange_Cartes = Melange_Cartes(Nombre_Joueurs_char);

    if (SUCCES___Melange_Cartes == 0)   // 0 et -1 erreur
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

////////////////////////////////////////////////////////////

    std::vector<std::string> cartes = {"1", "5","8"};

    // Calcul du score pour cet ensemble de cartes
    int score = Calcule_Score(cartes);

    // Affichage du score
    std::cout << "Le score est: " << score << std::endl;



    return 0;
}
