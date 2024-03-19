#include "Joueur.cpp"

class Huamin{
public:
    bool pioche_humain();
};


using namespace std;

bool pioche_h(){
    char oui_non;
    cout << "Voulez vous tier une carte ? (o/n)" << endl;
    cin >> oui_non;
    if (oui_non == 'o'){
        return 0;
    }
    else{
        return 1;
    }
}
