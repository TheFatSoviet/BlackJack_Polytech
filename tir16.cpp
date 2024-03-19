#include <iostream>
#include <stdlib.h>
#include "Joueur.cpp"

using namespace std;


class tir16 : public Joueur
{
public:

bool pioche_tir16(int score)
{
    if (score < 17)
    {
        return true;
    }
    else
    {
        return false;
    }
}
};
