#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Joueur.h"
#include "Retire_Cartes.h"


void Retire_Cartes(Joueur & joueur) {
  std::ifstream fileIn("Sabot.txt");
  std::string contenu, carte;
  std::vector < std::string > cartes;

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
