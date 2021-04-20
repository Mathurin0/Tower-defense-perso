class Score {
private:
    int score;
    int niveau;
    int solde;
public:
    Score();
    void gagner_argent(int nb_pieces) {
        this->solde += nb_pieces;
    }
    int get_argent() {
        return this->solde;
    }
    void paiement(int nb_coins) {
        this->solde -= nb_coins;
    }
};

Score::Score() {
    this->score = 0;
    this->niveau = 0;
    this->solde = 200;
}
