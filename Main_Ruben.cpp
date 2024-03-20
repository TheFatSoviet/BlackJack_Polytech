//Ruben SARGSYAN
//commentaires générer par ia

#include "Retire_Cartes.cpp"
#include "Distribuer_Cartes.cpp"
#include "Calcule_Score.cpp"
#include "Joueur.cpp"

#include "Melange_Cartes.cpp"
#include "Ranger_Cartes.cpp"

#include "Joueur.h"
#include "Distribuer_Cartes.h"
#include "Ranger_Cartes.h"

#include "Afficher_Cartes_Joueur.cpp"
#include "tir16.cpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

// Le point d'entrée principal du programme.
int main()
{
   // Variables pour stocker le nombre de joueurs sous différentes formes.
   char Nombre_Joueurs_char = 0;
   int Nombre_Joueurs = 0;
   // Vecteur pour conserver les joueurs, y compris le dealer.
   std::vector<Joueur> joueurs;

   // Boucle pour s'assurer que le nombre de joueurs est dans la plage valide.
   while (Nombre_Joueurs < 1 || Nombre_Joueurs > 7)
   {
      std::cout << "Entrez le nombre de joueurs (entre 1 et 7) : ";
      std::cin >> Nombre_Joueurs_char;
      std::cin.ignore(); // Évite les problèmes de buffer en ignorant le retour à la ligne.

      // Conversion de char à int pour obtenir le nombre réel de joueurs.
      Nombre_Joueurs = Nombre_Joueurs_char - '0';

      // Vérification de la validité de l'entrée.
      if (Nombre_Joueurs < 1 || Nombre_Joueurs > 7)
      {
          std::cerr << "Le nombre de joueurs doit etre entre 1 et 7." << std::endl;
         // return 1; // Cette ligne est commentée mais peut être utilisée pour quitter si nécessaire.
      }
   }

   // Appel de la fonction de mélange des cartes.
   Melange_Cartes(Nombre_Joueurs_char+1);

   // Initialisation des joueurs, y compris le dealer.
   joueurs.resize(Nombre_Joueurs + 1);

   // Définition du nom du dealer.
   strcpy(joueurs[0].nom, "Dealer");

   // Boucle pour obtenir et définir les noms des joueurs humains.
   for (int i = 1; i <= Nombre_Joueurs; ++i)
   {
       std::cout << "Entrez le nom pour le joueur " << i << ": ";
       std::string nomTemp;
       std::getline(std::cin, nomTemp);

       // Si le nom est trop long, il est tronqué pour s'adapter.
       if (nomTemp.length() >= sizeof(joueurs[i].nom))
       {
           std::cerr << "Erreur : le nom est trop long. Il sera tronque." << std::endl;
           nomTemp.resize(sizeof(joueurs[i].nom) - 1);
       }

       // Copie du nom temporaire dans l'objet joueur.
       strcpy(joueurs[i].nom, nomTemp.c_str());
   }

   // Affichage des noms de tous les joueurs pour confirmation.
   for (size_t i = 0; i < joueurs.size(); ++i)
   {
       std::cout << "Joueur " << i << " : " << joueurs[i].nom << std::endl;
   }


 // Distribution des cartes
    Distribuer_Cartes(joueurs);

 // Affichage des cartes du dealer
 ///Afficher_Cartes_Joueur(joueurs[0], 0);

 // Affichage des cartes de tous les joueurs, y compris le dealer
 for (size_t i = 0; i < joueurs.size(); ++i)
 {
     Afficher_Cartes_Joueur(joueurs[i], i);
 }










  // joueurs[0].score_in_game = 10 ;
  // if (joueurs[0].pioche_tir16())
  // {
  //     std::cout << "Le dealer " << joueurs[0].nom << " doit piocher une carte." << std::endl;
  //     // Logique pour piocher une carte pour le dealer
  // }
  // else {
  //     std::cout << "Le dealer " << joueurs[0].nom << " ne pioche pas." << std::endl;
  // }










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
