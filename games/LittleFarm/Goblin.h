#pragma once
#include "Monster.h"
#include<string>
#include<iostream>

class Goblin : public Monster
{
public:
	Goblin(string n);

	void Action(Monster& m) override;
	void Eat();
	void Attack(Monster& m);
	void Check(int lvFame, int lvSalute, int lvFel);
	void SetFame(int f) { fame = f; }
	void SetSalute(int h) { salute = h; }
	void SetFelicità(int happy) { felicità = happy; }
	void SetLivello_Fame(string f) { lvFame = f; }
	void SetLivello_Salute(string s) { lvSalute = s; }
	void SetLivello_Fel(string happy) { lvFel = happy; }
	string GetRace() { return race; }
	int GetPrice() { return price; }
	




	int fame;
	int salute;
	int felicità;
	string name;
	string race;
	string lvFame;
	string lvSalute;
	string lvFel;
	bool isdead;
	const int price = 7;
	
};

