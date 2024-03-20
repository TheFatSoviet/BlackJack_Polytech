
#include "Retire_Cartes.cpp"
#include "Distribuer_Cartes.cpp"
#include "Calcule_Score.cpp"
#include "Joueur.cpp"

#include "Melange_Cartes.cpp"
#include "Ranger_Cartes.cpp"

#include "Joueur.h"
#include "Distribuer_Cartes.h"
#include "Ranger_Cartes.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>


//=============================================
int main()
{
   char Nombre_Joueurs_char = 0;
   int Nombre_Joueurs_humains = 0;
   std::vector<Joueur> joueurs;

while (Nombre_Joueurs_humains < 1 || Nombre_Joueurs_humains > 7)
{
   std::cout << "Entrez le nombre de joueurs humains a creer (entre 1 et 7) : ";
   std::cin >> Nombre_Joueurs_char;
   std::cin.ignore(); // Ignorez le retour à la ligne restant dans le buffer d'entrée

   // Convertissez le char en int
   Nombre_Joueurs_humains = Nombre_Joueurs_char - '0';

   // Vérifiez si le nombre de joueurs est valide
   if (Nombre_Joueurs_humains < 1 || Nombre_Joueurs_humains > 7) {
       std::cerr << "Le nombre de joueurs doit etre entre 1 et 7." << std::endl;
      // return 1;
   }
}

  Melange_Cartes(Nombre_Joueurs_char+1);


   // Initialisez le vecteur de joueurs avec le dealer plus les joueurs humains
   joueurs.resize(Nombre_Joueurs_humains + 1);

   // Définissez le nom du dealer
   strcpy(joueurs[0].nom, "Dealer");

   // Obtenez les noms des joueurs humains
   for (int i = 1; i <= Nombre_Joueurs_humains; ++i) {
       std::cout << "Entrez le nom pour le joueur " << i << ": ";
       std::string nomTemp;
       std::getline(std::cin, nomTemp);

       if (nomTemp.length() >= sizeof(joueurs[i].nom)) {
           std::cerr << "Erreur : le nom est trop long. Il sera tronque." << std::endl;
           nomTemp.resize(sizeof(joueurs[i].nom) - 1);
       }

       strcpy(joueurs[i].nom, nomTemp.c_str());
   }

   // Affichez tous les noms des joueurs
   for (size_t i = 0; i < joueurs.size(); ++i) {
       std::cout << "Joueur " << i << " : " << joueurs[i].nom << std::endl;
   }

 // Distribution des cartes
 Distribuer_Cartes(joueurs);

 // Afficher les cartes de chaque joueur

  for (size_t i = 0; i < joueurs.size(); ++i)
  {
      std::cout << "Joueur " << i << " (" << joueurs[i].nom << ") a les cartes: ";
      for (const auto& carte : joueurs[i].cartes)
      {
          std::cout << carte << " ";
      }
      std::cout << std::endl;
  }


  // Après toutes les manipulations des cartes
      Ranger_Cartes(joueurs);



//  int NB_Cartes_a_retirer;
//    std::cout << "Entrez le nombre de cartes a retirer : ";
//    std::cin >> NB_Cartes_a_retirer;

    // Exemple d'utilisation de la fonction RetireCartes
//    Retire_Cartes(NB_Cartes_a_retirer);


//    std::vector<std::string> cartes_a_ajouter = {"1", "2", "3"};
//    Rajout_Cartes(cartes_a_ajouter);

////////////////////////////////////////////////////////////

  //  std::vector<std::string> cartes = {"1", "5","8"};

    // Calcul du score pour cet ensemble de cartes
//    int score = Calcule_Score(cartes);

    // Affichage du score
  //  std::cout << "Le score est: " << score << std::endl;



    return 0;
}
