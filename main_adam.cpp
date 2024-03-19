#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "Humain.cpp"

using namespace std;

int main(){
  bool temp=0;
  Humain h1;
  temp = h1.pioche_humain();
  if (temp){
    cout << "Vous avez choisie de piocher" << endl;
  }
  else{
    cout << "Vous avez choisie de ne pas piocher" << endl;
  }
  return 1;
};
