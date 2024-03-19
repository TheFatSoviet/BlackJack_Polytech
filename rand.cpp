#include "random"

using namespace std;


class rand1
{
public:

  bool pioche_rand1()
  {
      int i=0;
      // Crée un générateur de nombres aléatoires
      random_device rd;
      mt19937 gen(rd());

      // Définit la plage de valeurs (de 0 à 3)
      uniform_int_distribution<int> distribution(0, 3);

      // Génère un nombre aléatoire
      int n = distribution(gen);

      if (i<n)//demande a piocher tant que i<n
      {
        i=i+1;
        return true;
      }
      else
      {
        i=0;
        return false;
      }
  }
};
