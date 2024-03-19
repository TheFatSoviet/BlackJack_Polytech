#include <iostream>
#include <stdlib.h>
#include "Joueur.cpp"

using namespace std;


class ret3 : public Joueur
{
public:

bool pioche_ret3()
{
    int n=3;
    int i=0;

    if (i<n)
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
