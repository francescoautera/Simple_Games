

#include <iostream>
#include <vector>
#include "Pedina.h"

using namespace std;


const int rows = 8;
const int cols = 8;
const int numpedine = 12;
const int player1 = 0;
const int player2 = 1;
const int decr = -1;
int  gameTable[rows][cols];
bool isWin1 = false;
bool isWin2 = false;
Pedina* Player1[numpedine];
Pedina* Player2[numpedine];
bool iseat = false;
bool validMove = false;
bool damaMove = false;



void Draw() {
	cout << "  /     0     1     2     3     4     5     6     7    " << endl;
	cout << " ____ _____ _____ _____ _____ _____ _____ _____ _____  " << endl;
	cout << "  0     " << gameTable[0][0] << "     " << gameTable[0][1] << "    " << gameTable[0][2] << "     " << gameTable[0][3] << "    " << gameTable[0][4] << "     " << gameTable[0][5] << "     " << gameTable[0][6] << "      " << gameTable[0][7] << "     " << endl;
	cout << " ____ _____ _____ _____ _____ _____ _____ _____ _____  " << endl;
	cout << "  1     " << gameTable[1][0] << "     " << gameTable[1][1] << "    " << gameTable[1][2] << "     " << gameTable[1][3] << "    " << gameTable[1][4] << "     " << gameTable[1][5] << "     " << gameTable[1][6] << "      " << gameTable[1][7] << "     " << endl;
	cout << " ____ _____ _____ _____ _____ _____ _____ _____ _____  " << endl;
	cout << "  2     " << gameTable[2][0] << "     " << gameTable[2][1] << "    " << gameTable[2][2] << "     " << gameTable[2][3] << "    " << gameTable[2][4] << "    " << gameTable[2][5] << "     " << gameTable[2][6] << "     " << gameTable[2][7] << "     " << endl;
	cout << " ____ _____ _____ _____ _____ _____ _____ _____ _____  " << endl;
	cout << "  3     " << gameTable[3][0] << "     " << gameTable[3][1] << "    " << gameTable[3][2] << "     " << gameTable[3][3] << "    " << gameTable[3][4] << "     " << gameTable[3][5] << "     " << gameTable[3][6] << "     " << gameTable[3][7] << "     " << endl;
	cout << " ____ _____ _____ _____ _____ _____ _____ _____ _____  " << endl;
	cout << "  4     " << gameTable[4][0] << "     " << gameTable[4][1] << "    " << gameTable[4][2] << "     " << gameTable[4][3] << "    " << gameTable[4][4] << "     " << gameTable[4][5] << "     " << gameTable[4][6] << "     " << gameTable[4][7] << "     " << endl;
	cout << " ____ _____ _____ _____ _____ _____ _____ _____ _____  " << endl;
	cout << "  5     " << gameTable[5][0] << "     " << gameTable[5][1] << "    " << gameTable[5][2] << "     " << gameTable[5][3] << "    " << gameTable[5][4] << "    " << gameTable[5][5] << "    " << gameTable[5][6] << "    " << gameTable[5][7] << "     " << endl;
	cout << " ____ _____ _____ _____ _____ _____ _____ _____ _____  " << endl;
	cout << "  6     " << gameTable[6][0] << "     " << gameTable[6][1] << "    " << gameTable[6][2] << "     " << gameTable[6][3] << "    " << gameTable[6][4] << "    " << gameTable[6][5] << "    " << gameTable[6][6] << "    " << gameTable[6][7] << "     " << endl;
	cout << " ____ _____ _____ _____ _____ _____ _____ _____ _____  " << endl;
	cout << "  7     " << gameTable[7][0] << "     " << gameTable[7][1] << "    " << gameTable[7][2] << "     " << gameTable[7][3] << "    " << gameTable[7][4] << "    " << gameTable[7][5] << "    " << gameTable[7][6] << "    " << gameTable[7][7] << "     " << endl;
	cout << " ____ _____ _____ _____ _____ _____ _____ _____ _____  " << endl;
}


void Transform(Pedina &pedina,int x) {
	
	gameTable[pedina.posx][pedina.posy] = x ;
}


void InitPlayer1() {
	int pos = 0;
	int x = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < cols; i++) {
			if (j == 1) {
				if ((i % 2) != 0) {
					Pedina* pedina = new Pedina(x, i, false);

					Player1[pos] = pedina;
					pos++;
				}
			}
			else {
				if ((i % 2) == 0) {
					Pedina* pedina = new Pedina(x, i, false);

					Player1[pos] = pedina;
					pos++;
				}
			}
		}
		x++;
	}
	for (int i = 0; i < numpedine; i++) {
		Transform(*Player1[i],i+1);
	}
}

void InitPlayer2() {
	int pos = 0;
	int x = rows-1;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < cols; i++) {
			if (j == 1) {
				if ((i % 2) == 0) {
					Pedina* pedina = new Pedina(x, i, false);

					Player2[pos] = pedina;
					pos++;
				}
			}
			else {
				if ((i % 2) != 0) {
					Pedina* pedina = new Pedina(x, i, false);

					Player2[pos] = pedina;
					pos++;
				}
			}
		}
		x--;
	}
	for (int i = 0; i < numpedine; i++) {
		Transform(*Player2[i],i+numpedine+1);
	}
}
bool MoveDamaP1(int number) {

	char  dir;
	cout << "dove vuoi andare: destra_avanti(d) o sinistra_avanti(s),o destra_indietro(w) o sinistra_indietro(a) ";
	cin >> dir;
	if (dir == 'd') {
		if (Player1[number - 1]->posy + 1 > rows) {
			cout << " \n non puoi andare da quella parte" << endl;

		}
		if (gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy + 1] != 0) {
			cout << "\n non puoi andare da quella parte" << endl;
			return false;
		}
		Player1[number - 1]->SetOld();
		gameTable[Player1[number - 1]->oldx][Player1[number - 1]->oldy] = 0;
		Player1[number - 1]->SetPosx(Player1[number - 1]->posx + 1);
		Player1[number - 1]->SetPosy(Player1[number - 1]->posy + 1);
		Transform(*Player1[number - 1], number);
		return true;
	}
	else if (dir == 's') {
		if (Player1[number - 1]->posy - 1 < 0) {
			cout << " \n non puoi andare da quella parte" << endl;
			return false;
		}
		if (gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy - 1] != 0) {
			cout << " \n non puoi andare da quella parte" << endl;
			return false;
		}
		Player1[number - 1]->SetOld();
		//gameTable[Player1[number - 1]->oldx][pedina.oldy] = NULL;
		gameTable[Player1[number - 1]->oldx][Player1[number - 1]->oldy] = 0;
		Player1[number - 1]->SetPosx(Player1[number - 1]->posx + 1);
		Player1[number - 1]->SetPosy(Player1[number - 1]->posy - 1);
		Transform(*Player1[number - 1], number);
		return true;
	}
	else if (dir == 'w') {
		if (Player1[number - 1]->posy + 1 > rows) {
			cout << " \n non puoi andare da quella parte" << endl;

		}
		if (gameTable[Player1[number - 1]->posx - 1][Player1[number - 1]->posy + 1] != 0) {
			cout << "\n non puoi andare da quella parte" << endl;
			return false;
		}
		Player1[number - 1]->SetOld();
		gameTable[Player1[number - 1]->oldx][Player1[number - 1]->oldy] = 0;
		Player1[number - 1]->SetPosx(Player1[number - 1]->posx - 1);
		Player1[number - 1]->SetPosy(Player1[number - 1]->posy + 1);
		Transform(*Player1[number - 1], number);
		return true;
	}
	else if (dir == 'a') {
		if (Player1[number - 1]->posy - 1 < 0) {
			cout << " \n non puoi andare da quella parte" << endl;
			return false;
		}
		if (gameTable[Player1[number - 1]->posx - 1][Player1[number - 1]->posy - 1] != 0) {
			cout << " \n non puoi andare da quella parte" << endl;
			return false;
		}
		Player1[number - 1]->SetOld();
		//gameTable[Player1[number - 1]->oldx][pedina.oldy] = NULL;
		gameTable[Player1[number - 1]->oldx][Player1[number - 1]->oldy] = 0;
		Player1[number - 1]->SetPosx(Player1[number - 1]->posx - 1);
		Player1[number - 1]->SetPosy(Player1[number - 1]->posy - 1);
		Transform(*Player1[number - 1], number);
		return true;
	}

}
bool MoveDamaP2(int number) {
	char  dir;
	cout << " \n  dove vuoi andare: destra(d) o sinistra(s) o destra_indietro(w) o sinistra_indietro(a) ";
	cin >> dir;
	if (dir == 'd') {
		if (Player2[number - numpedine - 1]->posy + 1 > rows) {
			cout << "\n  non puoi andare da quella parte" << endl;
			return false;
		}
		if (gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy + 1] != 0) {
			cout << "posizione occupata" << endl;
			return false;
		}
		Player2[number - numpedine - 1]->SetOld();
		gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = 0;
		Player2[number - numpedine - 1]->SetPosx(Player2[number - numpedine - 1]->posx - 1);
		Player2[number - numpedine - 1]->SetPosy(Player2[number - numpedine - 1]->posy + 1);
		cout << "\n Posx" << number << " " << Player2[number - numpedine - 1]->posx;
		cout << "\n Posy" << number << " " << Player2[number - numpedine - 1]->posy;
		gameTable[Player2[number - numpedine - 1]->posx][Player2[number - numpedine - 1]->posy] = number;
		//Transform(*Player2[number - numpedine - 1],number);
		return true;
	}
	else if(dir=='s') {
		if (Player2[number - numpedine - 1]->posy - 1 < 0) {
			cout << " \n non puoi andare da quella parte" << endl;
			return false;
		}
		if (gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy - 1] != 0) {
			cout << " \n  posizione occupata " << endl;
			return false;
		}
		Player2[number - numpedine - 1]->SetOld();
		gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = NULL;
		gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = 0;
		Player2[number - numpedine - 1]->SetPosx(Player2[number - numpedine - 1]->posx - 1);
		Player2[number - numpedine - 1]->SetPosy(Player2[number - numpedine - 1]->posy - 1);
		cout << "\n Posx" << number << " " << Player2[number - numpedine - 1]->posx;
		cout << "\n Posy" << number << " " << Player2[number - numpedine - 1]->posy;
		gameTable[Player2[number - numpedine - 1]->posx][Player2[number - numpedine - 1]->posy] = number;
		//Transform(*Player2[number - numpedine - 1],number);
		return true;
	}
	else if (dir == 'w') {
		if (Player2[number - numpedine - 1]->posy + 1 > rows) {
			cout << "\n  non puoi andare da quella parte" << endl;
			return false;
		}
		if (gameTable[Player2[number - numpedine - 1]->posx + 1][Player2[number - numpedine - 1]->posy + 1] != 0) {
			cout << "posizione occupata" << endl;
			return false;
		}
		Player2[number - numpedine - 1]->SetOld();
		gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = 0;
		Player2[number - numpedine - 1]->SetPosx(Player2[number - numpedine - 1]->posx + 1);
		Player2[number - numpedine - 1]->SetPosy(Player2[number - numpedine - 1]->posy + 1);
		cout << "\n Posx" << number << " " << Player2[number - numpedine - 1]->posx;
		cout << "\n Posy" << number << " " << Player2[number - numpedine - 1]->posy;
		gameTable[Player2[number - numpedine - 1]->posx][Player2[number - numpedine - 1]->posy] = number;
		//Transform(*Player2[number - numpedine - 1],number);
		return true;
		
	}
	else if (dir == 'a') {
		if (Player2[number - numpedine - 1]->posy - 1 < 0) {
			cout << " \n non puoi andare da quella parte" << endl;
			return false;
		}
		if (gameTable[Player2[number - numpedine - 1]->posx + 1][Player2[number - numpedine - 1]->posy - 1] != 0) {
			cout << " \n  posizione occupata " << endl;
			return false;
		}
		Player2[number - numpedine - 1]->SetOld();
		gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = NULL;
		gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = 0;
		Player2[number - numpedine - 1]->SetPosx(Player2[number - numpedine - 1]->posx + 1);
		Player2[number - numpedine - 1]->SetPosy(Player2[number - numpedine - 1]->posy - 1);
		cout << "\n Posx" << number << " " << Player2[number - numpedine - 1]->posx;
		cout << "\n Posy" << number << " " << Player2[number - numpedine - 1]->posy;
		gameTable[Player2[number - numpedine - 1]->posx][Player2[number - numpedine - 1]->posy] = number;
	}
}

bool Move(int player,int number) {
		damaMove = false;
		if (player == 0) {
			if (!Player1[number - 1]->isdeath) {
				if (Player1[number - 1]->isDama) {
					damaMove= MoveDamaP1(number);
					if (damaMove) {
						return true;
						}
				}
				else
				{
					char  dir;
					cout << "dove vuoi andare: destra(d) o sinistra(s) ";
					cin >> dir;
					if (dir == 'd') {
						if (Player1[number - 1]->posy + 1 > rows) {
							cout << " \n non puoi andare da quella parte" << endl;
							return false;
						}
						if (gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy + 1] != 0) {
							cout << "\n non puoi andare da quella parte" << endl;
							return false;
						}
						Player1[number - 1]->SetOld();
						gameTable[Player1[number - 1]->oldx][Player1[number - 1]->oldy] = 0;
						Player1[number - 1]->SetPosx(Player1[number - 1]->posx + 1);
						Player1[number - 1]->SetPosy(Player1[number - 1]->posy + 1);
						Transform(*Player1[number - 1], number);
						return true;
					}
					else {
						if (Player1[number - 1]->posy - 1 < 0) {
							cout << " \n non puoi andare da quella parte" << endl;
							return false;
						}
						if (gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy - 1] != 0) {
							cout << " \n non puoi andare da quella parte" << endl;
							return false;
						}
						Player1[number - 1]->SetOld();
						//gameTable[Player1[number - 1]->oldx][pedina.oldy] = NULL;
						gameTable[Player1[number - 1]->oldx][Player1[number - 1]->oldy] = 0;
						Player1[number - 1]->SetPosx(Player1[number - 1]->posx + 1);
						Player1[number - 1]->SetPosy(Player1[number - 1]->posy - 1);
						Transform(*Player1[number - 1], number);
						return true;
					}
				}
			}
			else {
				cout << "\n  la pedina e' morta" << endl;
				return false;
			}
		}
	
		else {
			if (!Player2[number - numpedine - 1]->isdeath) {
				if (Player2[number - numpedine - 1]->isDama) {
					damaMove=MoveDamaP2(number);
					if (damaMove) {
						return true;
					}
				}
				else {
					char  dir;
					cout << " \n  dove vuoi andare: destra(d) o sinistra(s) ";
					cin >> dir;
					if (dir == 'd') {
						if (Player2[number - numpedine - 1]->posy + 1 > rows) {
							cout << "\n  non puoi andare da quella parte" << endl;
							return false;
						}
						if (gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy + 1] != 0) {
							cout << "posizione occupata" << endl;
							return false;
						}
						Player2[number - numpedine - 1]->SetOld();
						gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = 0;
						Player2[number - numpedine - 1]->SetPosx(Player2[number - numpedine - 1]->posx - 1);
						Player2[number - numpedine - 1]->SetPosy(Player2[number - numpedine - 1]->posy + 1);
						cout << "\n Posx" << number << " " << Player2[number - numpedine - 1]->posx;
						cout << "\n Posy" << number << " " << Player2[number - numpedine - 1]->posy;
						gameTable[Player2[number - numpedine - 1]->posx][Player2[number - numpedine - 1]->posy] = number;
						//Transform(*Player2[number - numpedine - 1],number);
						return true;
					}
					else {
						if (Player2[number - numpedine - 1]->posy - 1 < 0) {
							cout << " \n non puoi andare da quella parte" << endl;
							return false;
						}
						if (gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy - 1] != 0) {
							cout << " \n  posizione occupata " << endl;
							return false;
						}
						Player2[number - numpedine - 1]->SetOld();
						gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = NULL;
						gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = 0;
						Player2[number - numpedine - 1]->SetPosx(Player2[number - numpedine - 1]->posx - 1);
						Player2[number - numpedine - 1]->SetPosy(Player2[number - numpedine - 1]->posy - 1);
						cout << "\n Posx" << number << " " << Player2[number - numpedine - 1]->posx;
						cout << "\n Posy" << number << " " << Player2[number - numpedine - 1]->posy;
						gameTable[Player2[number - numpedine - 1]->posx][Player2[number - numpedine - 1]->posy] = number;
						//Transform(*Player2[number - numpedine - 1],number);
						return true;
					}
				}
			}
			else {
				cout << "\n  la pedina e' morta" << endl;
				return false;
			
			}
		}


	
}



bool Eat(int number,int player ) {
	if (player == 0) {
		if (Player1[number - 1]->posy + 1 <= rows - 1 && Player1[number - 1]->posy + 2 <= rows - 1) {
			if (gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy + 1] > numpedine 
				&& gameTable[Player1[number - 1]->posx + 2][Player1[number - 1]->posy + 2] == 0) {
				Player1[number - 1]->SetOld();
				gameTable[Player1[number - 1]->oldx][Player1[number - 1]->oldy] = 0;
				int x = gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy + 1];
				gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy + 1] = 0;
				Player2[x - numpedine - 1]->isdeath = true;
				Player1[number - 1]->SetPosx(Player1[number - 1]->posx + 2);
				Player1[number - 1]->SetPosy(Player1[number - 1]->posy + 2);
				Transform(*Player1[number - 1], number);
				iseat = true;
				return iseat;

			}
		}
		if (Player1[number - 1]->posy - 1 >= 0 && Player1[number - 1]->posy - 2 >=0) {
			if (gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy - 1] > numpedine
				&& gameTable[Player1[number - 1]->posx + 2][Player1[number - 1]->posy - 2] == 0) {
				Player1[number - 1]->SetOld();
				gameTable[Player1[number - 1]->oldx][Player1[number - 1]->oldy] = 0;
				int x = gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy - 1];
				gameTable[Player1[number - 1]->posx + 1][Player1[number - 1]->posy - 1] = 0;
				Player2[x - numpedine - 1]->isdeath = true;
				Player1[number - 1]->SetPosx(Player1[number - 1]->posx + 2);
				Player1[number - 1]->SetPosy(Player1[number - 1]->posy - 2);
				Transform(*Player1[number - 1], number);
				iseat = true;
				return iseat;
			}
		}
	}
	 else if (player == 1) {
		if (Player2[number - numpedine - 1]->posy + 1 <= rows - 1 && Player2[number - numpedine - 1]->posy + 2 <=rows-1) {
			if (gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy + 1] < numpedine + 1
				&& gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy + 1] >0
				&& gameTable[Player2[number - numpedine - 1]->posx - 2][Player2[number - numpedine - 1]->posy + 2] == 0) {
				Player2[number - numpedine - 1]->SetOld();
				gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = 0;
				int x = gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy + 1];
				gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy + 1] = 0;
				Player1[ x-1 ]->isdeath = true;
				Player2[number - numpedine - 1]->SetPosx(Player2[number - numpedine - 1]->posx - 2);
				Player2[number - numpedine - 1]->SetPosy(Player2[number - numpedine - 1]->posy + 2);
				gameTable[Player2[number - numpedine - 1]->posx][Player2[number - numpedine - 1]->posy] = number;
				//Transform(*Player2[number-numpedine-1], number);
				iseat = true;
				return iseat;

			}
		}
		if (Player2[number - numpedine - 1]->posy - 1 >= 0 && Player2[number - numpedine - 1]->posy -2  >=0) {
			if (gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy - 1] < numpedine + 1
			    && gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy - 1] >0 
				&& gameTable[Player2[number - numpedine - 1]->posx - 2][Player2[number - numpedine - 1]->posy - 2] == 0) {
				Player2[number - numpedine - 1]->SetOld();
				gameTable[Player2[number - numpedine - 1]->oldx][Player2[number - numpedine - 1]->oldy] = 0;
				int x = gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy - 1];
				gameTable[Player2[number - numpedine - 1]->posx - 1][Player2[number - numpedine - 1]->posy - 1] = 0;
				Player1[ x-1 ]->isdeath = true;
				Player2[number - numpedine - 1]->SetPosx(Player2[number - numpedine - 1]->posx - 2);
				Player2[number - numpedine - 1]->SetPosy(Player2[number - numpedine - 1]->posy - 2);
				gameTable[Player2[number - numpedine - 1]->posx][Player2[number - numpedine - 1]->posy] = number;
				//Transform(*Player2[number - numpedine - 1], number);
				iseat = true;
				return iseat;

			}
		}
	}
	iseat = false;
	return iseat;
}

bool CheckWin1() {
	int count = 0;
	for (int i = 0; i < numpedine; i++) {
		if (Player2[i]->isdeath) {
			count++;
		}
	}
	if (count == numpedine) {
		isWin1 = true;
		return isWin1;
	}
	return isWin1;
}

bool CheckWin2() {
	int count = 0;
	for (int i = 0; i < numpedine; i++) {
		if (Player1[i]->isdeath) {
			count++;
		}
	}
	if (count == numpedine) {
		isWin2 = true;
		return isWin2;
	}
	return isWin2;
}

void  CheckDama(int player) {
	if (player == 0) {
		for (int i=0; i<numpedine; i++){
			if (Player1[i]->posx == rows - 1) {
				cout << " il numero : " << i + 1 << " e' dama " << endl;
				Player1[i]->isDama = true;
			}
		}
	}
	else if (player == 1) {
		for (int i = 0; i < numpedine; i++) {
			if (Player2[i]->posx == 0) {
				cout << " il numero : " << numpedine+i+1 << " e' dama " << endl;
				Player2[i]->isDama = true;
			}
		}
	}
}

int main() {
	InitPlayer1();
	InitPlayer2();
	Draw();
	int numb;
	int choice;
	
	while (!isWin1 && !isWin2) {
		cout << "\n turno player 1" << endl;
		cout << "vuoi mangiare(0) o muovere(1):";
		cin >> choice;
		if (choice == 1) {
			while (!validMove) {
				cout << "\n scegli quale pedina muove: (1-12)";
				cin >> numb;
				validMove = Move(player1, numb);
			}
		}
		else if (choice == 0) {
			cout << "\n scegli con quale pedina vuoi mangiare: (1-12)";
			cin >> numb;
			Eat(numb, player1);
			while (iseat) {
				Eat(numb, player1);
			}
			CheckWin1();
			if (isWin1) {
				cout << "\n Player 1 vince" << endl;
				continue;
			}
		}
		CheckDama(0);
		cout << "\n" << endl;
		Draw();
		
		validMove = false;
		cout << "\n turno player 2" << endl;
		cout << "vuoi mangiare(0) o muovere(1):";
		cin >> choice;
		if (choice == 1) {
			while (!validMove) {
				cout << "\n scegli quale pedina muove: (13-24)";
				cin >> numb;
				validMove = Move(player2, numb);
			}
		}
		else if (choice == 0) {
			cout << "\n scegli con quale pedina vuoi mangiare: (13-24)";
			cin >> numb;
			Eat(numb, player2);
			while (iseat) {
				Eat(numb, player2);
			}
			CheckWin2();
			if (isWin2) {
				cout << "\n Player 2 vince" << endl;
				continue;
			}
		}
		CheckDama(1);
		cout << "\n" << endl;
		Draw();
		validMove = false;
	}
	
	
	

	
	
	

	
	

	
}


