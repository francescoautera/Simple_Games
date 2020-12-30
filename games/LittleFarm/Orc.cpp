#include "Orc.h"

Orc::Orc( string n) : Monster( n ) {
	fame = 10;
	salute = 10;
	felicit� = 10;
	name = n;
	lvFame = "Pacifico";
	lvFel = "Felice";
	lvSalute = "Forte";
	isdead = false;
	race = "Orc";
}

void Orc::Eat() {
	Monster::Eat();
}

void Orc::Attack(Monster &m) {
	Monster::Attack(m);
}

void Orc::Action(Monster& m) {
	cout << name  + "  ha distrutto un oggetto di  " + m.name << endl;
	m.SetFelicit�(m.felicit� - 2);
	SetFelicit�(felicit� + 1);
}



void Orc::Check(int lvFame, int lvSalute, int lvFel) {
	Monster::Check(lvFame,lvSalute,lvFel);
}
