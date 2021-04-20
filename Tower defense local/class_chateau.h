class Chateau {

private:
	int HP;

public:
	Chateau(int HPChateau) {
		this->HP = HPChateau;
	}

	int Get_HP();
	void Degats(Chateau* Base);

};

int Chateau::Get_HP() {
	return this->HP;
}

void Chateau::Degats(Chateau* Base) {

	if (Base->HP < 1)
	{
		std::cout << "Et bah c'est perdu ..." << std::endl;


		ecran_loose();
	}


	Base->HP--;

}

