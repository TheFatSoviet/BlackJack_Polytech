//Ruben SARGSYAN
//commentaires générer par ia

#include "Retire_Cartes.cpp"
#include "Distribuer_Cartes.cpp"
#include "Calcule_Score.cpp"


#include "Melange_Cartes.cpp"
#include "Ranger_Cartes.cpp"

#include "Joueur.h"
#include "Joueur.cpp"
#include "Distribuer_Cartes.h"
#include "Ranger_Cartes.h"

#include "Afficher_Cartes_Joueur.cpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>


void Retire_Cartes(Joueur& joueur) {
    std::ifstream fileIn("Sabot.txt");
    std::string contenu, carte;
    std::vector<std::string> cartes;

    if (fileIn.is_open()) {
        getline(fileIn, contenu); // Lit toute la ligne du fichier Sabot.txt.
        fileIn.close();

        std::stringstream ss(contenu);

        // Lire toutes les cartes dans le vecteur.
        while (std::getline(ss, carte, ',')) {
            if (!carte.empty()) { // Vérifier que la chaîne n'est pas vide.
                cartes.push_back(carte);
            }
        }

        if (!cartes.empty()) {
            // Attribuer la première carte au joueur et la retirer du vecteur des cartes.
            joueur.cartes.push_back(cartes[0]);
            cartes.erase(cartes.begin());

            // Mettre à jour le fichier Sabot.txt avec les cartes restantes.
            std::ofstream fileOut("Sabot.txt");
            if (fileOut.is_open()) {
                for (size_t i = 0; i < cartes.size(); ++i) {
                    fileOut << cartes[i];
                    if (i != cartes.size() - 1) {
                        fileOut << ",";
                    }
                }
                fileOut.close();
            } else {
                std::cerr << "Erreur lors de la réouverture du fichier pour écriture." << std::endl;
            }
        } else {
            std::cerr << "Pas de cartes disponibles pour retirer." << std::endl;
        }
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }
}


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
   Melange_Cartes(Nombre_Joueurs_char);

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



  // Après avoir défini les noms des joueurs
  for (int i = 1; i <= Nombre_Joueurs; ++i) // Inclure 0 pour inclure le dealer dans la saisie
  {
      std::string typeTemp;

      std::cout << "Entrez le type pour le joueur " << i << " : ";
      std::getline(std::cin, typeTemp);

      strncpy(joueurs[i].type_joueur, typeTemp.c_str(), sizeof(joueurs[i].type_joueur) - 1);
      joueurs[i].type_joueur[sizeof(joueurs[i].type_joueur) - 1] = '\0'; // Assure que la chaîne est terminée par un '\0'
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




  //joueurs[0].score_in_game = 10 ;

  joueurs[0].score_in_game = Calcule_Score(joueurs[0].cartes);


  if (joueurs[0].pioche_tir16(joueurs[0].score_in_game))
  {
      std::cout << "Le dealer " << joueurs[0].nom << " pioche une carte." << std::endl;
      Retire_Cartes(joueurs[0]);
  }
  else {
      std::cout << "Le dealer " << joueurs[0].nom << " ne pioche pas." << std::endl;
  }



  // Affichage des cartes de tous les joueurs, y compris le dealer
  for (size_t i = 0; i < joueurs.size(); ++i)
  {
      Afficher_Cartes_Joueur(joueurs[i], i);
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
