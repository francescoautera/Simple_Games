#include "Monster.h"


Monster::Monster(string n) {
	fame = 10;
	salute = 10;
	felicità = 10;
	name = n;
	isdead = false;
	lvFame = "Pacifico";
	lvFel = "Felice";
	lvSalute = "Buona";
	
}

void Monster::Attack(Monster& m) {
	m.SetSalute(m.felicità - 1);
	SetFame(fame - 3);
}



void Monster::Eat() {
	SetFame(fame + 1);
	SetSalute(salute+1);
}

void  Monster::Check(int lvFame, int lvSalute, int lvFel) {
	if (salute <= 0) {
		cout << name + " e' morto" << endl;
		isdead = true;
		
	}
	else {
		if (fame < 0) {
			SetSalute(salute - 1);
		}
		if (fame < lvFame) {
			SetLivello_Fame("Aggressivo");
		}
		else {
			SetLivello_Fame("Pacifico");

		}
		if (salute < lvSalute) {
			SetLivello_Salute("Debole");
		}
		else {
			SetLivello_Salute("Forte");
		}
		if (felicità < lvFel) {
			SetLivello_Fel("Triste");
		}
		else {
			SetLivello_Fel("Felice");
		}
	}
}