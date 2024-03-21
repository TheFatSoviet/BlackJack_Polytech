#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "Humain.cpp"
#include "Joueur.cpp"

using namespace std;

int main(){
  bool temp=0;
  humain h1;
  Joueur j1;
  temp = h1.pioche_humain();
  if (temp){
    cout << "Vous avez choisie de piocher" << endl;
  }
  else{
    cout << "Vous avez choisie de ne pas piocher" << endl;
  }

  j1.Afficher_donner_joueur();

  return 1;
};
