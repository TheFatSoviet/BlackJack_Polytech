#include <iostream>
#include <stdlib.h>

using namespace std;

class Humain {
public:
    // Méthode pour demander à l'utilisateur s'il souhaite tirer une carte.
    bool pioche_humain() {
        char oui_non; // Variable pour stocker la réponse de l'utilisateur.
        while (true) { // Boucle jusqu'à ce que l'utilisateur entre une réponse valide.
            cout << "Voulez-vous tirer une carte ? (o/n)" << endl;
            cin >> oui_non;
            if (oui_non == 'o') {
                return true; // Retourne vrai si l'utilisateur veut tirer une carte.
            } else if (oui_non == 'n') {
                return false; // Retourne faux si l'utilisateur ne veut pas tirer de carte.
            } else {
                cout << "Entrée invalide. Veuillez répondre par 'o' ou 'n'." << endl;
                // Aucun changement de temp ou autre variable nécessaire, la boucle continue.
            }
        }
    }
};
