#include "gain.cpp"


using namespace std;


int main()
{

    /*
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
    */


    int score_c=21,score_c2=17,score_c3=23;
    int score_j1=19,score_j2=15,score_j3=21,score_j4=24;

    int jeton =55;
    int mise=10;

    cout<<jeton<<endl;
    jeton=calcul_gain(score_j1,score_c,jeton,mise);
    cout<<jeton<<endl;
    jeton=calcul_gain(score_j3,score_c2,jeton,mise);
    cout<<jeton<<endl;
    jeton=calcul_gain(score_j2,score_c3,jeton,mise);
    cout<<jeton<<endl;
    jeton=calcul_gain(score_j4,score_c2,jeton,mise);
    cout<<jeton<<endl;


    return 0;
}
