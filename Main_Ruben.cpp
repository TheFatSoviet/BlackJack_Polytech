//Ruben SARGSYAN
//commentaires générer en partie par ia

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>

#include "Retire_Cartes.h"
#include "Distribuer_Cartes.cpp"
#include "Calcule_Score.cpp"
#include "Melange_Cartes.cpp"
#include "Ranger_Cartes.cpp"
#include "Joueur.cpp"
#include "Afficher_Cartes_Joueur.cpp"

#include "gain.cpp"
#include "Joueur.h"
#include "Distribuer_Cartes.h"
#include "Ranger_Cartes.h"




void BoucleDeJeu(std::vector < Joueur > & joueurs) {
  bool quelquUnDoitPiocher;

  std::cout << std::endl;
  std::cout << "//////////////////////////////////////////////////" << std::endl;
  std::cout << "/////////////////    PHASE DE PIOCHE    //////////" << std::endl;
  std::cout << "//////////////////////////////////////////////////" << std::endl;

  do {
    quelquUnDoitPiocher = false; // Indicateur pour vérifier si au moins un joueur doit piocher
    for (Joueur & joueur: joueurs) {
      joueur.score_in_game = Calcule_Score(joueur.cartes);

      // Appliquer la logique de pioche en fonction du type de joueur
      if (strcmp(joueur.type_joueur, "croupier") == 0 && joueur.pioche_croupier(joueur.score_in_game)) {
        std::cout << "Le " << joueur.nom << " pioche une carte." << std::endl;
        Retire_Cartes(joueur);
        quelquUnDoitPiocher = true;
      } else if (strcmp(joueur.type_joueur, "ret3") == 0 && joueur.pioche_ret3(joueur.score_in_game)) {
        std::cout << joueur.nom << " pioche une carte." << std::endl;
        Retire_Cartes(joueur);
        quelquUnDoitPiocher = true;
      } else if (strcmp(joueur.type_joueur, "tir16") == 0 && joueur.pioche_tir16(joueur.score_in_game)) //joueurs[0].pioche_tir16(joueurs[0].score_in_game)
      {
        std::cout << joueur.nom << " pioche une carte." << std::endl;
        Retire_Cartes(joueur);
        quelquUnDoitPiocher = true;
      } else if (strcmp(joueur.type_joueur, "humain") == 0 && joueur.pioche_humain(joueur.score_in_game)) {
        std::cout << joueur.nom << " pioche une carte." << std::endl;
        Retire_Cartes(joueur);
        quelquUnDoitPiocher = true;
        Afficher_Cartes_Joueur(joueur);
      } else if (strcmp(joueur.type_joueur, "rand1") == 0 && joueur.pioche_rand1()) {
        std::cout << joueur.nom << " pioche une carte." << std::endl;
        Retire_Cartes(joueur);
        quelquUnDoitPiocher = true; // PROBLEM ON BOCULE SIMULTANEMENT JOUEUR (plusieurs jourus) DANS LKES IF RESPECTIFSD
      }

      joueur.score_in_game = Calcule_Score(joueur.cartes);
    }

    // Si au moins un joueur a pioché, tous les scores sont recalculés et affichés
    if (quelquUnDoitPiocher) {
      for (Joueur & joueur: joueurs) {
        std::cout << ">--------------- Le joueur " << joueur.nom << " a un score de : " << joueur.score_in_game << std::endl;
      }
    }

  }
  while (quelquUnDoitPiocher); // Continuer tant qu'au moins un joueur doit piocher
}

void verifierSabot(int nombreDeJoueurs) {
  std::ifstream fileIn("Sabot.txt");
  std::string contenu;
  std::map < std::string, int > compteurCartes;
  int totalCartes = 0;

  if (fileIn.is_open()) {
    std::getline(fileIn, contenu);
    fileIn.close();

    std::stringstream ss(contenu);
    std::string carte;
    while (std::getline(ss, carte, ',')) {
      compteurCartes[carte]++;
      totalCartes++;
    }
  } else {
    std::cerr << "Erreur : impossible d'ouvrir le fichier Sabot.txt" << std::endl;
    return;
  }

  int totalCartesAttendu = 52 * (nombreDeJoueurs + 1); // Le +1 est pour inclure les cartes du croupier dans le calcul
  std::map < std::string, int > valeursAttendues = {
    {
      "1",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "2",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "3",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "4",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "5",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "6",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "7",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "8",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "9",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "X",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "V",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "D",
      4 * (nombreDeJoueurs + 1)
    },
    {
      "R",
      4 * (nombreDeJoueurs + 1)
    }
  };

  bool validationReussie = true;
  if (totalCartes != totalCartesAttendu) {
    std::cout << "Erreur : le nombre total de cartes dans le sabot (" << totalCartes << ") ne correspond pas au nombre attendu (" << totalCartesAttendu << ")." << std::endl;
    validationReussie = false;
  }

  for (const auto & paire: valeursAttendues) {
    if (compteurCartes[paire.first] != paire.second) {
      std::cout << "Erreur : le nombre de cartes de valeur " << paire.first << " (" << compteurCartes[paire.first] << ") ne correspond pas au nombre attendu (" << paire.second << ")." << std::endl;
      validationReussie = false;
    }
  }

  if (validationReussie) {
    std::cout << "La vérification du sabot est valide." << std::endl;
  }
}

// Le point d'entrée principal du programme.
int main() {
  // Variables pour stocker le nombre de joueurs sous différentes formes.
  char Nombre_Joueurs_char = 0;
  int Nombre_Joueurs = 0;
  int N_Manche_Actuelle = 0;
  int N_Manche_Total = 0;
  // Vecteur pour conserver les joueurs, y compris le dealer.
  std::vector < Joueur > joueurs;

  setlocale(LC_ALL, "");

  // Boucle pour s'assurer que le nombre de joueurs est dans la plage valide.
  while (Nombre_Joueurs < 1 || Nombre_Joueurs > 7) {
    std::cout << "Entrez le nombre de joueurs (entre 1 et 7) : ";
    std::cin >> Nombre_Joueurs_char;
    std::cin.ignore(); // Évite les problèmes de buffer en ignorant le retour à la ligne.

    // Conversion de char à int pour obtenir le nombre réel de joueurs.
    Nombre_Joueurs = Nombre_Joueurs_char - '0';

    // Vérification de la validité de l'entrée.
    if (Nombre_Joueurs < 1 || Nombre_Joueurs > 7) {
      std::cerr << "Le nombre de joueurs doit etre entre 1 et 7." << std::endl;
      // return 1; // Cette ligne est commentée mais peut être utilisée pour quitter si nécessaire.
    }
  }

  // Appel de la fonction de mélange des cartes.
  Melange_Cartes(Nombre_Joueurs_char);

  // Initialisation des joueurs, y compris le dealer.
  joueurs.resize(Nombre_Joueurs + 1);

  // Définition du nom du Croupier.
  strcpy(joueurs[0].nom, "Croupier");
  strcpy(joueurs[0].type_joueur, "croupier");

  // Boucle pour obtenir et définir les noms des joueurs.
  for (int i = 1; i <= Nombre_Joueurs; ++i) {
    std::string nomTemp;
    bool nomUnique;

    do {
      nomUnique = true; // On suppose initialement que le nom est unique

      std::cout << "Entrez le nom pour le joueur " << i << ": ";
      std::getline(std::cin, nomTemp);

      // Vérifier si le nom est trop long et le tronquer si nécessaire
      if (nomTemp.length() >= sizeof(joueurs[i].nom)) {
        std::cerr << "Erreur : le nom est trop long. Il sera tronque." << std::endl;
        nomTemp.resize(sizeof(joueurs[i].nom) - 1);
      }

      // Vérifier si le nom est unique par rapport à tous les noms déjà entrés
      for (int j = 1; j < i; ++j) {
        if (nomTemp == joueurs[j].nom) {
          std::cerr << "Erreur : ce nom est déjà pris. Veuillez en choisir un autre." << std::endl;
          nomUnique = false; // Le nom n'est pas unique, demande un autre nom
          break; // Pas besoin de continuer à vérifier les autres noms
        }
      }
    } while (!nomUnique); // Répéter tant que le nom n'est pas unique

    // Une fois un nom unique obtenu, l'assigner au joueur
    strcpy(joueurs[i].nom, nomTemp.c_str());
  }

  // Après avoir défini les types des joueurs
  for (int i = 1; i <= Nombre_Joueurs; ++i) { // Exclure le croupier de la saisie
    std::string typeTemp;
    bool typeValide;

    do {
      std::cout << "Entrez le type pour le joueur " << i << " (humain, ret3, rand1, tir16, magic): ";
      std::getline(std::cin, typeTemp);

      // Vérifier si le type saisi est valide
      typeValide = typeTemp == "humain" || typeTemp == "ret3" || typeTemp == "rand1" || typeTemp == "tir16" || typeTemp == "magic";

      if (!typeValide) {
        std::cout << "Type invalide. Veuillez réessayer." << std::endl;
      } else {
        // Copier le type valide dans l'attribut type_joueur du joueur
        strncpy(joueurs[i].type_joueur, typeTemp.c_str(), sizeof(joueurs[i].type_joueur) - 1);
        joueurs[i].type_joueur[sizeof(joueurs[i].type_joueur) - 1] = '\0'; // Assure que la chaîne est terminée par un '\0'
      }

    } while (!typeValide); // Répéter jusqu'à obtenir un type valide
  }

  // Affichage des noms de tous les joueurs pour confirmation.
  // for (size_t i = 0; i < joueurs.size(); ++i)
  // {
  //     std::cout << "Joueur " << i << " : " << joueurs[i].nom << std::endl;
  // }

  // Initialiser les jetons pour tous les joueurs
  for (int i = 0; i <= Nombre_Joueurs; ++i) { // Commence à 0 pour inclure le croupier
    if (i == 0) { // Le croupier est le joueur à l'indice 0
      joueurs[i].jeton_possede = 100000000; // 100 millions pour le croupier
    } else {
      joueurs[i].jeton_possede = 1000; // 1000 jetons pour les joueurs
    }
  }

  std::cout << "Combien de manche voulez-vous jouer ? : ";
  std::cin >> N_Manche_Total;

  //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  while (N_Manche_Actuelle < N_Manche_Total) {
    N_Manche_Actuelle++;

    std::cout << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << "/////////////////    DEBUT ROUND " << N_Manche_Actuelle << "    ////////////" << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << std::endl;

    verifierSabot(Nombre_Joueurs);

    std::cout << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << "/////////////////    PHASE DE MISE    ////////////" << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << std::endl;

    for (size_t i = 1; i < joueurs.size(); ++i) {
      const auto & joueur = joueurs[i];
      std::cout << "Joueur " << joueur.nom << " possède " << joueur.jeton_possede << " jetons." << std::endl;
    }

    std::cout << std::endl;

    srand(static_cast < unsigned int > (time(nullptr)));

    for (size_t i = 1; i < joueurs.size(); ++i) { // Commence à 1 pour exclure le croupier
      if (strcmp(joueurs[i].type_joueur, "humain") != 0) { // Si le joueur n'est pas humain
        // Assigner une mise aléatoire entre 10 et 100
        joueurs[i].jeton_mise = rand() % 91 + 10; // % 91 assure une plage de 0-90, + 10 décale à 10-100
      } else {
        // Demander la mise pour les joueurs humains
        do {
          std::cout << "Joueur " << joueurs[i].nom << ", entrez votre mise (entre 10 et 100 jetons) : ";
          std::cin >> joueurs[i].jeton_mise;
          if (joueurs[i].jeton_mise < 10 || joueurs[i].jeton_mise > 100) {
            std::cout << "Mise non valide. Veuillez miser entre 10 et 100 jetons." << std::endl;
          }
        } while (joueurs[i].jeton_mise < 10 || joueurs[i].jeton_mise > 100);
      }
    }

    // Afficher la mise de tous les joueurs (sauf le croupier)
    for (size_t i = 1; i < joueurs.size(); ++i) {
      std::cout << "Joueur " << joueurs[i].nom << " a misé " << joueurs[i].jeton_mise << " jetons." << std::endl;
    }

    // Distribution des cartes
    Distribuer_Cartes(joueurs);

    // Affichage des cartes du dealer
    ///Afficher_Cartes_Joueur(joueurs[0], 0);

    // Affichage des cartes de tous les joueurs, y compris le dealer
    for (size_t i = 0; i < joueurs.size(); ++i) {
      Afficher_Cartes_Joueur(joueurs[i], i);
    }

    //joueurs[0].score_in_game = 10 ;
    //----------------------------------------------------------------------------------------------------------------------------
    // joueurs[0].score_in_game = Calcule_Score(joueurs[0].cartes);
    //
    //
    // if (joueurs[0].pioche_tir16(joueurs[0].score_in_game))
    // {
    //     std::cout << "Le dealer " << joueurs[0].nom << " pioche une carte." << std::endl;
    //     Retire_Cartes(joueurs[0]);
    // }
    // else {
    //     std::cout << "Le dealer " << joueurs[0].nom << " ne pioche pas." << std::endl;
    // }
    //
    //
    //
    // // Affichage des cartes de tous les joueurs, y compris le dealer
    // for (size_t i = 0; i < joueurs.size(); ++i)
    // {
    //     Afficher_Cartes_Joueur(joueurs[i], i);
    // }
    //----------------------------------------------------------------------------------------------------------------------------

    BoucleDeJeu(joueurs);

    //ici faut :
    // une boucle pour : calculer score
    // mais en mm temps si ya une pioche faut encore calculer le score du joeur qui pioche
    // en plus mettre en place les types

    // for (size_t i = 0; i < joueurs.size(); ++i)
    // {
    //       joueurs[i].score_in_game = Calcule_Score(joueurs[i].cartes);
    //
    //
    //
    //       if (joueurs[0].pioche_croupier(joueurs[0].score_in_game))
    //       {
    //           std::cout << "Le dealer " << joueurs[0].nom << " pioche une carte." << std::endl;
    //           Retire_Cartes(joueurs[0]);
    //           joueurs[0].score_in_game = Calcule_Score(joueurs[0].cartes);
    //
    //       }
    //       else {
    //           std::cout << "Le dealer " << joueurs[0].nom << " ne pioche pas." << std::endl;
    //       }
    //
    //
    //       //std::cout << "Le joueur " << joueurs[i].nom << "a :" << joueurs[i].score_in_game << std::endl;
    // }

    std::cout << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << "/////////////////    SCORE FINALE     ////////////" << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << std::endl;

    //score
    for (size_t i = 0; i < joueurs.size(); ++i) {
      std::cout << "Le joueur " << joueurs[i].nom << " a :" << joueurs[i].score_in_game << std::endl;
    }

    std::cout << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << "/////////////////    PHASE DE GAIN    ////////////" << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << std::endl;

    gain calculateurDeGain; // Créez une instance de votre classe gain

    for (size_t i = 1; i < joueurs.size(); ++i) {
      int nouveauTotalJetons = calculateurDeGain.calcul_gain(joueurs[i].score_in_game, joueurs[0].score_in_game, joueurs[i].jeton_possede, joueurs[i].jeton_mise);

      // Imprimez le résultat et mettez à jour les jetons du joueur
      if (nouveauTotalJetons > joueurs[i].jeton_possede) {
        std::cout << "Joueur " << joueurs[i].nom << " gagne " << (nouveauTotalJetons - joueurs[i].jeton_possede) << " jetons." << std::endl;
      } else if (nouveauTotalJetons < joueurs[i].jeton_possede) {
        std::cout << "Joueur " << joueurs[i].nom << " perd " << (joueurs[i].jeton_possede - nouveauTotalJetons) << " jetons." << std::endl;
      } else {
        std::cout << "Joueur " << joueurs[i].nom << " ne gagne ni ne perd des jetons." << std::endl;
      }

      joueurs[i].jeton_possede = nouveauTotalJetons; // Mettre à jour les jetons du joueur
    }

    std::cout << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << "/////////////////    INFO JETONS      ////////////" << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << std::endl;

    for (size_t i = 1; i < joueurs.size(); ++i) {
      const auto & joueur = joueurs[i];
      std::cout << "Joueur " << joueur.nom << " possède " << joueur.jeton_possede << " jetons." << std::endl;
    }

    // Après toutes les manipulations des cartes

    std::cout << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << "/////////////////    FIN DE ROUND " << N_Manche_Actuelle << "    ////////////" << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << std::endl;

    // Reset le choix de l'humain de ne plus piocher de carte
    for (auto & joueur: joueurs) {
      if (auto h = dynamic_cast < humain * > ( & joueur)) {
        h -> flag_repondu_non = 0; // Réinitialiser le flag pour le joueur humain
      }
    }

    Ranger_Cartes(joueurs);

  }
  return 0;
}
