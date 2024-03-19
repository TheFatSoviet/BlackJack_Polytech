#include <iostream>
#include <stdlib.h>
#include <random>
#include "Joueur.cpp"

using namespace std;


class rand : public Joueur
{
public:

  bool pioche_rand()
  {
      // Crée un générateur de nombres aléatoires
      random_device rd;
      mt19937 gen(rd());

      // Définit la plage de valeurs (de 0 à 3)
      uniform_int_distribution<int> distribution(0, 3);

      // Génère un nombre aléatoire
      int n = distribution(gen);

      // Affiche le nombre aléatoire
      cout << "Nombre aléatoire entre 0 et 3 : " << n << endl;

      return n > 0;
  }
};
