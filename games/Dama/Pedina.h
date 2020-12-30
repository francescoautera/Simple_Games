#pragma once

class Pedina
{
public:
	Pedina(int x,int y, bool d);
	
	~Pedina();

	void SetPosx(int x) { posx = x; }
	void SetPosy(int y) { posy = y; }
	void SetOld() { oldx = posx; oldy = posy; }

	int posx;
	int posy;
	bool isdeath;
	int oldx;
	int oldy;
	bool isDama;
};

