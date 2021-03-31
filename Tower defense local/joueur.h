class Score {
private:
    int score;
    int niveau;
    int solde;
public:
    Score();
};

Score::Score() {
    this->score = 0;
    this->niveau = 0;
    this->solde = 200;
}