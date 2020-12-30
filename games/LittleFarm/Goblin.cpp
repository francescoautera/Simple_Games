#include "Goblin.h"

Goblin::Goblin( string n): Monster(n){
	fame = 10;
	salute = 10;
	felicit� =10 ;
	name = n;
	lvFame = "Pacifico";
	lvFel = "Felice";
	lvSalute = "Forte";
	isdead = false;
	race = "Goblin";
}

void Goblin::Eat() {
	Monster::Eat();
}

void Goblin::Attack(Monster& m) {
	Monster::Attack(m);
}

void Goblin::Action(Monster& m) {
	cout << name + "  ha costruito un oggetto e " + m.name + " si e' arrabbiato " << endl;
	m.SetFelicit�(m.felicit� - 1);
	SetFelicit�(felicit� + 1);
	
}



void Goblin::Check(int lvFame, int lvSalute, int lvFel) {
	Monster::Check(lvFame, lvSalute, lvFel);
}