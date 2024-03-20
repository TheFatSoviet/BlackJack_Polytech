#include "Ranger_Cartes.h" // Inclure l'en-tête pour la déclaration de la fonction.
#include <fstream> // Pour les opérations sur les fichiers.
#include <iostream> // Pour std::cerr et std::cout pour les messages d'erreur et de confirmation.

// La fonction prend un vecteur de Joueurs par référence pour accéder et manipuler leurs cartes.
void Ranger_Cartes(std::vector<Joueur>& joueurs)
{
    // Ouvre le fichier Sabot.txt en mode append pour ajouter du contenu à la fin sans supprimer le contenu existant.
    std::ofstream fileOut("Sabot.txt", std::ios::app);

    // Vérifie si le fichier a été correctement ouvert.
    if (!fileOut.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier pour ajouter." << std::endl;
        return; // Sort de la fonction en cas d'échec de l'ouverture du fichier.
    }

    // Détermine si le fichier est vide pour décider de l'ajout d'une virgule initiale.
    fileOut.seekp(0, std::ios::end); // Se déplace à la fin du fichier.
    if(fileOut.tellp() != 0) { // Si le fichier n'est pas vide (tellp renvoie la position actuelle dans le fichier),
        fileOut << ","; // ajoute une virgule pour séparer les nouveaux éléments des précédents.
    }

    bool isFirstCard = true; // Un drapeau pour gérer l'ajout de virgules entre les cartes.
    // Itérer sur tous les joueurs, en commençant par le joueur 1 (en supposant que le joueur 0 est le dealer et est traité en dernier).
    for (size_t i = 1; i < joueurs.size(); ++i)
    {
        for (const auto& carte : joueurs[i].cartes)
        {
            if (!isFirstCard)
            {
                fileOut << ","; // Ajoute une virgule avant d'ajouter la carte, sauf si c'est la première carte.
            }
            fileOut << carte; // Écrit la carte dans le fichier.
            isFirstCard = false; // Après la première carte, ce drapeau est toujours faux.
        }
    }

    // Ajouter les cartes du dealer en dernier pour conserver l'ordre.
    for (const auto& carte : joueurs[0].cartes)
    {
        if (!isFirstCard) // Si ce n'est pas la première carte à être ajoutée,
        {
            fileOut << ","; // insère une virgule avant la carte.
        }
        fileOut << carte; // Ajoute la carte du dealer au fichier.
        isFirstCard = false; // Assure que la première carte a déjà été traitée.
    }

    fileOut.close(); // Ferme le fichier après avoir terminé l'écriture.
    std::cout << "Cartes rangées avec succès dans le sabot." << std::endl; // Confirme que l'opération s'est bien déroulée.
}
