//gestion du chateau
class Chateau {

private:
	//vie du chateau
	int HP;

public:
	//setter
	Chateau(int HPChateau) {	
		this->HP = HPChateau;
	}
	//getter
	int Get_HP();
	//setter
	void Degats(Chateau* Base);

};

int Chateau::Get_HP() {
	return this->HP;
}

void Chateau::Degats(Chateau* Base) {
	//quand le chateau n'a plus de vie, on a perdu
	if (Base->HP < 1)
	{
		std::cout << "Et bah c'est perdu ..." << std::endl;


		ecran_loose();
	}


	Base->HP--;

}

