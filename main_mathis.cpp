#include "tir16.cpp"
#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;


int main()
{
    vector<Joueur> joueurs(3);

    bool ouii;
    char c1[20]= "tir16";

    for(int i=0;i<3;i++)
    {
      strcpy(joueurs[i].type_joueur,c1);
    }

    for(int i=0;i<3;i++)
    {

      if(strcmp(joueurs[i].type_joueur,"tir16")==0)
      {
        tir16 test;

        ouii=test.pioche_tir16(20);

        cout<<ouii;
      }
    }




    return 0;
}
