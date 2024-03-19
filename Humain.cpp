#include <iostream>
#include <stdlib.h>

using namespace std;

class Humain
{
public:

  bool pioche_humain(){
      char oui_non;
      int temp=0;
      while (temp==0){
        cout << "Voulez vous tier une carte ? (o/n)" << endl;
        cin >> oui_non;
        if (oui_non == 'o'){
            return true;
            temp =1;
        }
        else if(oui_non == 'n'){
            return false;
            temp =1;
        }
        else{
          temp =0;
        }
      }
  }

};
