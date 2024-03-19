#include "Joueur.cpp"


using namespace std;


int main()
{
    vector<Joueur> joueurs(3);


    bool ouii;

    strcpy(joueurs[0].type_joueur,"tir16");
    strcpy(joueurs[1].type_joueur,"ret3");
    strcpy(joueurs[1].type_joueur,"rand");


    for(int i=0;i<3;i++)
    {
        if (strcmp(joueurs[i].type_joueur,"tir16")==0)
        {
          ouii= joueurs[i].pioche_tir16(20);
        }
        if (strcmp(joueurs[i].type_joueur,"ret3")==0)
        {
          ouii= joueurs[i].pioche_ret3();
        }
        if (strcmp(joueurs[i].type_joueur,"rand")==0)
        {
          ouii= joueurs[i].pioche_rand1();
        }
      cout<<ouii<<endl;

    }




    return 0;
}
