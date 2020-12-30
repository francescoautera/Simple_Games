#include "Ghoul.h"

Ghoul::Ghoul( string n) : Monster( n) {
	fame = 10;
	salute = 10;
	felicit� = 10;
	name = n;
	lvFame = "Pacifico";
	lvFel = "Felice";
	lvSalute = "Forte";
	isdead = false;
	race = "Ghoul";
}

void Ghoul::Eat() {
	Monster::Eat();
}

void Ghoul::Attack(Monster& m) {
	Monster::Attack(m);
}

void Ghoul::Action(Monster& m) {
	cout << name + "  ha spaventato " + m.name << endl;
	m.SetFelicit�(m.felicit� - 2);
	SetFelicit�(felicit� + 1);
}



void Ghoul::Check(int lvFame, int lvSalute, int lvFel) {
	Monster::Check(lvFame, lvSalute, lvFel);
}