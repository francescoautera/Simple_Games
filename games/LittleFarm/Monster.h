#pragma once
#include<iostream>
#include<string>
using namespace std;

class Monster
{
public:
	 Monster(string n);
	 virtual void Action(Monster&m ) = 0;
	 void Eat() ;
	 void Attack(Monster& m);
	 

	 void SetFame(int f) { fame = f; }
	 void SetSalute(int h) { salute = h; }
	 void SetFelicità(int happy) { felicità = happy; }
	 void Check(int lvFame,int lvSalute, int lvFel);
	 void SetLivello_Fame(string f) { lvFame = f; }
	 void SetLivello_Salute(string s) { lvSalute = s;}
	 void SetLivello_Fel(string happy) { lvFel = happy; }
	 virtual string GetRace() = 0;
	 virtual int GetPrice() = 0;
	 

	int fame;
	int salute;
	int felicità;
	string name;
	string lvFame;
	string lvSalute;
	string lvFel;
	bool isdead;
	string race ;
	const int price=0;
};


