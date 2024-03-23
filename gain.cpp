#include <iostream>
#include <stdlib.h>

using namespace std;

class gain{
public:
  int calcul_gain(int score_j,int score_c,int jeton, int mise)
  {

    if (score_j<21)
    {
        if(score_c<score_j || score_c>21)
        {
          jeton=jeton+mise;
        }
        if(score_c>score_j  && score_c<=21)
        {
          jeton=jeton-mise;
        }
    }
    else
    {
      if(score_j==21)
      {
        if(score_c==21)
        {
          jeton=jeton+mise;
        }
        else //jeton_c != 21
        {
          jeton=jeton+(3*mise)/2;
        }
      }
      else //score_j > 21
      {
        jeton=jeton-mise;
      }
    }


    return jeton;
  }

};
