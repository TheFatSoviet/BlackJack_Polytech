#include <iostream>
#include <cstdlib>
#include <ctime>

class rand1
{
private:
    int i; // Variable d'état pour suivre le nombre de pioches

public:
    rand1() : i(0) { } // Constructeur pour initialiser i à 0

    bool pioche_rand1()
    {
        // Génère un nombre aléatoire entre 0 et 3, seulement si i est 0
        if (i == 0)
        {
            i = std::rand() % 4; // Le reste de la division par 4
        }

        if (i > 0) // Demande à piocher tant que i > 0
        {
            i--;
            return true;
        }
        else
        {
            return false;
        }
    }
};
