#include "Ghoul.h"

Ghoul::Ghoul( string n) : Monster( n) {
	fame = 10;
	salute = 10;
	felicità = 10;
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
	m.SetFelicità(m.felicità - 2);
	SetFelicità(felicità + 1);
}



void Ghoul::Check(int lvFame, int lvSalute, int lvFel) {
	Monster::Check(lvFame, lvSalute, lvFel);
}