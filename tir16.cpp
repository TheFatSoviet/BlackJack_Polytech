using namespace std;

class tir16 {
public:
    // La méthode pioche_tir16 détermine si une nouvelle carte doit être tirée en fonction du score actuel.
    bool pioche_tir16(int score) {
        // Si le score est inférieur à 17, la méthode retourne vrai, indiquant qu'une carte doit être tirée.
        // Sinon, elle retourne faux, indiquant qu'aucune carte supplémentaire ne doit être tirée.
        return score < 17;
    }
};
