#include <iostream>
#include <stdlib.h>

using namespace std;

class humain{
public:
    // Méthode pour demander à l'utilisateur s'il souhaite tirer une carte.
    bool pioche_humain(int score) {
        char oui_non; // Variable pour stocker la réponse de l'utilisateur.
            if (score >= 21){
              return false;
            }
            cout << "Voulez-vous tirer une carte ? (o/n)" << endl;
            cin >> oui_non;
            cout << "score in game " << score << endl;
            if (oui_non == 'o') {
                return true; // Retourne vrai si l'utilisateur veut tirer une carte.
            } else if (oui_non == 'n') {
                return false; // Retourne faux si l'utilisateur ne veut pas tirer de carte.
            } else {
                cout << "Entrée invalide. Veuillez répondre par 'o' ou 'n'." << endl;
            }
        }
};
