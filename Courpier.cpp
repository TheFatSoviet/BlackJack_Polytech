
#include "Joueur.cpp"

class courpier:public Joueur{
public:
    bool pioche_courpier(int score_in_game);
};





bool pioche_courpier(int score_in_game){
    if (score_in_game > 17){
        return 0;
    }
    else{
        return 1;
    }
}
