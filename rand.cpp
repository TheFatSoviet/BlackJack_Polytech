#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


class rand1
{
public:

  bool pioche_rand1()
  {
      static int i=0;

      // Initialisation de la graine du générateur pseudo-aléatoire
      srand(time(NULL));

      // Génère un nombre aléatoire entre 0 et 3
      int n = rand() % 4; // Le reste de la division par 4

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
