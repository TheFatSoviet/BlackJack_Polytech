#include "Joueur.cpp"
#include "Jeu.cpp"

using namespace std;


int main()
{

    // Vecteur pour conserver les joueurs, y compris le dealer.
    vector<Joueur> joueurs;
    //creation plateau
    Jeu plateau;

    // Boucle pour s'assurer que le nombre de joueurs est dans la plage valide.
    while (plateau.Nombre_Joueurs < 1 || plateau.Nombre_Joueurs > 7)
    {
       cout << "Entrez le nombre de joueurs (entre 1 et 7) : ";
       cin >> plateau.Nombre_Joueurs_char;
       cin.ignore(); // Évite les problèmes de buffer en ignorant le retour à la ligne.

       // Conversion de char à int pour obtenir le nombre réel de joueurs.
       plateau.Nombre_Joueurs = plateau.Nombre_Joueurs_char - '0';

       // Vérification de la validité de l'entrée.
       if (plateau.Nombre_Joueurs < 1 || plateau.Nombre_Joueurs > 7)
       {
           cerr << "Le nombre de joueurs doit etre entre 1 et 7." << std::endl;
          // return 1; // Cette ligne est commentée mais peut être utilisée pour quitter si nécessaire.
       }
    }

    // Appel de la fonction de mélange des cartes.
    plateau.Melange_Cartes(plateau.Nombre_Joueurs_char);

    // Initialisation des joueurs, y compris le dealer.
    joueurs.resize(plateau.Nombre_Joueurs + 1);

    // Définition du nom du dealer.
    strcpy(joueurs[0].nom, "Dealer");
    strcpy(joueurs[0].type_joueur, "croupier");

    // Boucle pour obtenir et définir les noms des joueurs humains.
    for (int i = 1; i <= plateau.Nombre_Joueurs; ++i)
    {
        cout << "Entrez le nom pour le joueur " << i << ": ";
        string nomTemp;
        getline(std::cin, nomTemp);

        // Si le nom est trop long, il est tronqué pour s'adapter.
        if (nomTemp.length() >= sizeof(joueurs[i].nom))
        {
            cerr << "Erreur : le nom est trop long. Il sera tronque." << std::endl;
            nomTemp.resize(sizeof(joueurs[i].nom) - 1);
        }

        // Copie du nom temporaire dans l'objet joueur.
        strcpy(joueurs[i].nom, nomTemp.c_str());
    }

   // Après avoir défini les noms des joueurs
   for (int i = 1; i <= plateau.Nombre_Joueurs; ++i) // Inclure 0 pour inclure le dealer dans la saisie
   {
       string typeTemp;

       cout << "Entrez le type pour le joueur " << i << " : ";
       getline(cin, typeTemp);

       strncpy(joueurs[i].type_joueur, typeTemp.c_str(), sizeof(joueurs[i].type_joueur) - 1);
       joueurs[i].type_joueur[sizeof(joueurs[i].type_joueur) - 1] = '\0'; // Assure que la chaîne est terminée par un '\0'
     }

    // Affichage des noms de tous les joueurs pour confirmation.
    for (size_t i = 0; i < joueurs.size(); ++i)
    {
        cout << "Joueur " << i << " : " << joueurs[i].nom << endl;
    }

    // Distribution des cartes
    plateau.Distribuer_Cartes(joueurs);

    // Affichage des cartes du dealer
    ///Afficher_Cartes_Joueur(joueurs[0], 0);

    // Affichage des cartes de tous les joueurs, y compris le dealer
    for (size_t i = 0; i < joueurs.size(); ++i)
    {
        plateau.Afficher_Cartes_Joueur(joueurs[i], i);
    }



    // vector<Joueur> joueurs(3);
    //
    //
    // bool ouii;
    //
    // strcpy(joueurs[0].type_joueur,"tir16");
    // strcpy(joueurs[1].type_joueur,"ret3");
    // strcpy(joueurs[2].type_joueur,"rand");
    //
    //
    // for(int i=0;i<3;i++)
    // {
    //     if (strcmp(joueurs[i].type_joueur,"tir16")==0)
    //     {
    //       do
    //       {
    //         ouii= joueurs[i].pioche_tir16(20);
    //         cout<<ouii<<endl;
    //       }while (ouii != 0);
    //     }
    //     if (strcmp(joueurs[i].type_joueur,"ret3")==0)
    //     {
    //       do
    //       {
    //         ouii= joueurs[i].pioche_ret3();
    //         cout<<ouii<<endl;
    //       }while (ouii != 0);
    //     }
    //     if (strcmp(joueurs[i].type_joueur,"rand")==0)
    //     {
    //       do
    //       {
    //         ouii= joueurs[i].pioche_rand1();
    //         cout<<ouii<<endl;
    //       }while (ouii != 0);
    //     }
    //
    //
    // }
    //
    //
    //
    // int score_c=21,score_c2=17,score_c3=23;
    // int score_j1=19,score_j2=15,score_j3=21,score_j4=24;
    //
    // int jeton =55;
    // int mise=10;
    //
    // cout<<jeton<<endl;
    // jeton=calcul_gain(score_j1,score_c,jeton,mise);
    // cout<<jeton<<endl;
    // jeton=calcul_gain(score_j3,score_c2,jeton,mise);
    // cout<<jeton<<endl;
    // jeton=calcul_gain(score_j2,score_c3,jeton,mise);
    // cout<<jeton<<endl;
    // jeton=calcul_gain(score_j4,score_c2,jeton,mise);
    // cout<<jeton<<endl;


    return 0;
}
