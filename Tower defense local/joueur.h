//Permet la gestion de l'argent dans le tower defense
class Score {
private:
    int solde;
public:
    Score();
    //permet alors plus préscisement le gain d'argent dû à la mort d'un mob
    void gagner_argent(int nb_pieces) {
        this->solde += nb_pieces;
    }
    //permet alors la vérification du solde disponible
    int get_argent() {
        return this->solde;
    }
    //permet le paiement lors de l'ajout de tours
    void paiement(int nb_coins) {
        this->solde -= nb_coins;
    }
};

Score::Score() {
    this->solde = 200;
}