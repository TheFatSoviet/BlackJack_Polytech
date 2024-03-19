


class courpier{
public:
    int score_in_game;
    bool pioche(){
        if (this->score_in_game > 17){
            return 0;
        }
        else{
            return 1;
        }
    }
};
