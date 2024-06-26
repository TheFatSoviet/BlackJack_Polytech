#include "sabot.cpp"


class Jeu : public sabot
{
public:
    char Nombre_Joueurs_char = 0;
    int Nombre_Joueurs = 0;

    void Afficher_Cartes_Joueur(const Joueur& joueur, size_t numeroDuJoueur)
    {
        std::cout << "Joueur " << numeroDuJoueur << " (" << joueur.nom << ") (" << joueur.type_joueur
                  << ") a les cartes: ";

        if (numeroDuJoueur == 0)
        {
            // Affiche la première carte normalement, les autres en tant que "X"
            bool premiereCarteAffichee = false;
            for (const auto& carte : joueur.cartes)
            {
                if (!premiereCarteAffichee)
                {
                    std::cout << carte << " "; // Affiche la première carte
                    premiereCarteAffichee = true;
                }
                else
                {
                    std::cout << "X "; // Remplace les autres cartes par "X"
                }
            }
        }
        else
        {
            // Pour les autres joueurs, affiche toutes les cartes normalement
            for (const auto& carte : joueur.cartes)
            {
                std::cout << carte << " ";
            }
        }

        std::cout << std::endl;
    }

};
