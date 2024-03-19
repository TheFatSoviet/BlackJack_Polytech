#include <iostream>
#include <stdlib.h>
#include "Type.cpp"

using namespace std;


class tir16 : public type
{
public:

bool pioche(int score)
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
