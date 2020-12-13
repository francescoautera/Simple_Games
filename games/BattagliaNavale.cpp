// BattagliaNavale.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include "Windows.h"
#include <ctime>
#include <cstdlib>


using namespace std;

//costanti per matrici
const int col = 10;
const int row = 10;
//costanti grandezza navi
const int little = 2;
const int mid = 3;
const int big = 4;
const int huge = 5;
//variabile player
int player;
//init contatori
int counterLittle = 0;
int counterMid = 0;
int counterBig = 0;
int counterHuge = 0;
int counterLittleEn = 0;
int counterMidEn = 0;
int counterBigEn = 0;
int counterHugeEn = 0;
// inizializzazione navi
char nave_piccolina = 'o';
char littleShip[little] = { 'o','o' };
char midShip[mid] = { 'o','o','o' };
char bigShip[big] = { 'o','o','o','o' };
char cruiser[huge] = { 'o','o','o','o','o' };

char nave_piccolinaEnemy = 'o';
char littleShipEnemy[little] = { 'o','o' };
char midShipEnemy[mid] = { 'o','o','o' };
char bigShipEnemy[big] = { 'o','o','o','o' };
char enemyCruiser[huge] = { 'o','o','o','o','o' };
//posizioni delle navi
int posxnave, posynave;
int positionLittleShip[little][little];
int positionMidShip[mid][little];
int positionBigShip[big][little];
int positionCruiser[huge][little];

int posxnaveEnemy, posynaveEnemy;
int positionLittleShipEnemy[little][little];
int positionMidShipEnemy[mid][little];
int positionBigShipEnemy[big][little];
int positionCruiserEnemy[huge][little];
//tabelloni di gioco
char shipsPosition[row][col];
char battleTable[row][col];
char shipsPositionEn[row][col];
char battleTableEn[row][col];

//controllo vittoria
bool isWin = false;
bool isWinEn = false;

bool hit = false;
bool sinked = false;
bool right = true;
bool left = true;
bool up = true;
bool down = true;
int xLastShot;
int yLastShot;
int incremento=1;

//disegna tabella
void Draw(const char tabella[row][col]) {
	cout << "\n";
	cout << " ";
	cout << " [";
	for (int k = 0; k < row; k++) {

		cout << k << " ";
	}
	cout << "]";
	cout << "" << endl;
	for (int i = 0; i < row; i++) {
		cout << "" << i << "[";
		for (int j = 0; j < col; j++) {
			cout << " " << tabella[i][j];
		}
		cout << "]" << endl;

	}

}

//inizializzazione posizioni delle navi e scrittura nella tabella di gioco
void InitLittleShip(char tabella[row][col], int posizione[little][little]) {
	bool iscorrect = false;
	while (!iscorrect) {

		int x, y;
		cout << "\ninserisci coordianata x nave2x2(0,9) :";
		cin >> x;
		cout << "\ninserisci coordinata y nave2x2(0,9) : ";
		cin >> y;
		if (0 > x || x > 9 || 0 > y || y > 9) {
			continue;
		}

		int orientation;
		cout << "\ncome la vuoi posizionare:orizzontale(0) o verticale(1): ";
		cin >> orientation;
		if (orientation == 0) {
			if (tabella[x][y] == NULL) {
				if (y == 9) {
					if (tabella[x][y - 1] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						iscorrect = true;
						continue;
					}
				}
				else if (y > 0) {
					if (tabella[x][y + 1] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y - 1] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						iscorrect = true;
						continue;

					}
				}
				else if (y == 0) {
					if (tabella[x][y + 1] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						iscorrect = true;
						continue;
					}
				}
			}
		}
		else {
			if (tabella[x][y] == NULL) {
				if (x == 9) {
					if (tabella[x - 1][y] == NULL) {
						tabella[x][y] = 'o';
						tabella[x - 1][y] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x - 1;
						posizione[1][1] = y;
						iscorrect = true;
						continue;
					}
				}
				else if (x > 0) {
					if (tabella[x + 1][y] == NULL) {
						tabella[x][y] = 'o';
						tabella[x + 1][y] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x + 1;
						posizione[1][1] = y;
						iscorrect = true;
						continue;
					}
					else if (tabella[x - 1][y] == NULL) {
						tabella[x][y] = 'o';
						tabella[x - 1][y] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x - 1;
						posizione[1][1] = y;
						iscorrect = true;
						continue;

					}
				}
				else if (x == 0) {
					if (tabella[x + 1][y] == NULL) {
						tabella[x][y] = 'o';
						tabella[x + 1][y] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x + 1;
						posizione[1][1] = y;
						iscorrect = true;
						continue;
					}
				}
			}
		}
	}
}
void InitMidShip(char tabella[row][col], int posizione[mid][little]) {
	bool iscorrect = false;
	while (!iscorrect) {

		int x, y;
		cout << "\ninserisci coordianata x nave3x3(0,9) :";
		cin >> x;
		cout << "\ninserisci coordinata y nave3x3(0,9) : ";
		cin >> y;
		if (0 > x || x > 9 || 0 > y || y > 9) {
			continue;
		}

		int orientation;
		cout << "\ncome la vuoi posizionare:orizzontale(0) o verticale(1): ";
		cin >> orientation;
		if (orientation == 0) {
			if (tabella[x][y] == NULL) {
				if (y > mid) {
					if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL && y < 8) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						iscorrect = true;
						continue;

					}

				}
				else {
					if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && y >= 2) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						iscorrect = true;
						continue;

					}

				}

			}
		}
		else {
			if (x > mid) {
				if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					iscorrect = true;
					continue;
				}
				else if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL && x < 8) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					iscorrect = true;
					continue;

				}

			}
			else {
				if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					iscorrect = true;
					continue;
				}
				else if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && x < 2) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					iscorrect = true;
					continue;

				}

			}
		}
	}
}
void InitBigShip(char tabella[row][col], int posizione[big][little]) {
	bool iscorrect = false;
	while (!iscorrect) {

		int x, y;
		cout << "\ninserisci coordianata x nave4x4(0,9) :";
		cin >> x;
		cout << "\ninserisci coordinata y nave4x4(0,9) : ";
		cin >> y;
		if (0 > x || x > 9 || 0 > y || y > 9) {
			continue;
		}

		int orientation;
		cout << "\ncome la vuoi posizionare:orizzontale(0) o verticale(1): ";
		cin >> orientation;
		if (orientation == 0) {
			if (tabella[x][y] == NULL) {
				if (y > big) {
					if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && tabella[x][y - 3] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						tabella[x][y - 3] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						posizione[3][0] = x;
						posizione[3][1] = y - 3;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL && tabella[x][y + 3] == NULL && y < 7) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						tabella[x][y + 3] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						posizione[3][0] = x;
						posizione[3][1] = y + 3;
						iscorrect = true;
						continue;

					}

				}
				else {
					if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL && tabella[x][y + 3] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						tabella[x][y + 3] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						posizione[3][0] = x;
						posizione[3][1] = y + 3;
						iscorrect = true;
						continue;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && tabella[x][y - 3] == NULL && y >= mid) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						tabella[x][y - 3] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						posizione[3][0] = x;
						posizione[3][1] = y - 3;
						iscorrect = true;
						continue;

					}

				}

			}
		}
		else {
			if (x > big) {
				if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && tabella[x - 3][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					tabella[x - 3][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					posizione[3][0] = x - 3;
					posizione[3][1] = y;
					iscorrect = true;
					continue;
				}
				else if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL && tabella[x + 3][y] == NULL && x < 7) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					tabella[x + 3][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					posizione[3][0] = x + 3;
					posizione[3][1] = y;

					iscorrect = true;
					continue;

				}

			}
			else {
				if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL && tabella[x + 3][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					tabella[x + 3][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					posizione[3][0] = x + 3;
					posizione[3][1] = y;

					iscorrect = true;
					continue;
				}
				else if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && tabella[x - 3][y] == NULL && x >= mid) {
					tabella[x][y] = 'o';
					tabella[x][y - 1] = 'o';
					tabella[x][y - 2] = 'o';
					tabella[x][y - 3] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					posizione[3][0] = x - 3;
					posizione[3][1] = y;
					iscorrect = true;
					continue;
				}

			}
		}
	}
}
void initCruiser(char tabella[row][col], int posizione[huge][little]) {
	bool iscorrect = false;
	while (!iscorrect) {

		int x, y;
		cout << "\ninserisci coordianata x nave5x5(0,9) :";
		cin >> x;
		cout << "\ninserisci coordinata y nave5x5(0,9) : ";
		cin >> y;
		if (0 > x || x > 9 || 0 > y || y > 9) {
			continue;
		}

		int orientation;
		cout << "\ncome la vuoi posizionare:orizzontale(0) o verticale(1): ";
		cin >> orientation;
		if (orientation == 0) {
			if (tabella[x][y] == NULL) {
				if (y > huge) { // controllo se y maggiore di 5 e inserisco valore a sinistra
					if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && tabella[x][y - 3] == NULL && tabella[x][y - 4] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						tabella[x][y - 3] = 'o';
						tabella[x][y - 4] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						posizione[3][0] = x;
						posizione[3][1] = y - 3;
						posizione[4][0] = x;
						posizione[4][1] = y - 4;
						iscorrect = true;
						continue;
					}

				}
				else {
					if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL && tabella[x][y + 3] == NULL && tabella[x][y + 4] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						tabella[x][y + 3] = 'o';
						tabella[x][y + 4] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						posizione[3][0] = x;
						posizione[3][1] = y + 3;
						posizione[4][0] = x;
						posizione[4][1] = y + 4;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && tabella[x][y - 3] == NULL && tabella[x][y - 4] == NULL && y == huge) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						tabella[x][y - 3] = 'o';
						tabella[x][y - 4] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						posizione[3][0] = x;
						posizione[3][1] = y - 3;
						posizione[4][0] = x;
						posizione[4][1] = y - 4;
						iscorrect = true;
						continue;

					}

				}

			}
		}
		else {
			if (x > huge) {
				if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && tabella[x - 3][y] == NULL && tabella[x - 4][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					tabella[x - 3][y] = 'o';
					tabella[x - 4][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					posizione[3][0] = x - 3;
					posizione[3][1] = y;
					posizione[4][0] = x - 4;
					posizione[4][1] = y;
					iscorrect = true;
					continue;
				}


			}
			else {
				if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL && tabella[x + 3][y] == NULL && tabella[x + 4][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					tabella[x + 3][y] = 'o';
					tabella[x + 4][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					posizione[3][0] = x + 3;
					posizione[3][1] = y;
					posizione[4][0] = x + 4;
					posizione[4][1] = y;

					iscorrect = true;
					continue;
				}
				else if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && tabella[x - 3][y] == NULL && tabella[x - 4][y] == NULL && x == huge) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					tabella[x - 3][y] = 'o';
					tabella[x - 4][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					posizione[3][0] = x - 3;
					posizione[3][1] = y;
					posizione[4][0] = x - 4;
					posizione[4][1] = y;
					iscorrect = true;
					continue;
				}

			}
		}
	}
}

void InitLittleShip_Cpu(char tabella[row][col], int posizione[little][little]) {
	bool iscorrect = false;
	while (!iscorrect) {
		int x = rand() % 10;
		int y = rand() % 10;
		int orientation = rand() % 2 + 1;

		if (orientation == 1) {
			if (tabella[x][y] == NULL) {
				if (y == 9) {
					if (tabella[x][y - 1] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						iscorrect = true;
						continue;
					}
				}
				else if (y > 0) {
					if (tabella[x][y + 1] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y - 1] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						iscorrect = true;
						continue;

					}
				}
				else if (y == 0) {
					if (tabella[x][y + 1] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						iscorrect = true;
						continue;
					}
				}
			}
		}
		else {
			if (tabella[x][y] == NULL) {
				if (x == 9) {
					if (tabella[x - 1][y] == NULL) {
						tabella[x][y] = 'o';
						tabella[x - 1][y] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x - 1;
						posizione[1][1] = y;
						iscorrect = true;
						continue;
					}
				}
				else if (x > 0) {
					if (tabella[x + 1][y] == NULL) {
						tabella[x][y] = 'o';
						tabella[x + 1][y] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x + 1;
						posizione[1][1] = y;
						iscorrect = true;
						continue;
					}
					else if (tabella[x - 1][y] == NULL) {
						tabella[x][y] = 'o';
						tabella[x - 1][y] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x - 1;
						posizione[1][1] = y;
						iscorrect = true;
						continue;

					}
				}
				else if (x == 0) {
					if (tabella[x + 1][y] == NULL) {
						tabella[x][y] = 'o';
						tabella[x + 1][y] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x + 1;
						posizione[1][1] = y;
						iscorrect = true;
						continue;
					}
				}
			}
		}
	}

}
void InitMidShip_Cpu(char tabella[row][col], int posizione[mid][little]) {
	bool iscorrect = false;
	while (!iscorrect) {

		int x, y;
		x = rand() % 10;
		y = rand() % 10;


		int orientation = rand() % 2 + 1;

		if (orientation == 1) {
			if (tabella[x][y] == NULL) {
				if (y > mid) {
					if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL && y < 8) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						iscorrect = true;
						continue;

					}

				}
				else {
					if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && y >= 2) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						iscorrect = true;
						continue;

					}

				}

			}
		}
		else {
			if (x > mid) {
				if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					iscorrect = true;
					continue;
				}
				else if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL && x < 8) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					iscorrect = true;
					continue;

				}

			}
			else {
				if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					iscorrect = true;
					continue;
				}
				else if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && x < 2) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					iscorrect = true;
					continue;

				}

			}
		}
	}

}
void InitBigShip_Cpu(char tabella[row][col], int posizione[big][little]) {
	bool iscorrect = false;
	while (!iscorrect) {

		int x, y;
		x = rand() % 10;
		y = rand() % 10;
		int orientation = rand() % 2 + 1;
		if (orientation == 1) {
			if (tabella[x][y] == NULL) {
				if (y > big) {
					if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && tabella[x][y - 3] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						tabella[x][y - 3] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						posizione[3][0] = x;
						posizione[3][1] = y - 3;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL && tabella[x][y + 3] == NULL && y < 7) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						tabella[x][y + 3] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						posizione[3][0] = x;
						posizione[3][1] = y + 3;
						iscorrect = true;
						continue;

					}

				}
				else {
					if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL && tabella[x][y + 3] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						tabella[x][y + 3] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						posizione[3][0] = x;
						posizione[3][1] = y + 3;
						iscorrect = true;
						continue;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && tabella[x][y - 3] == NULL && y >= mid) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						tabella[x][y - 3] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						posizione[3][0] = x;
						posizione[3][1] = y - 3;
						iscorrect = true;
						continue;

					}

				}

			}
		}
		else {
			if (x > big) {
				if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && tabella[x - 3][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					tabella[x - 3][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					posizione[3][0] = x - 3;
					posizione[3][1] = y;
					iscorrect = true;
					continue;
				}
				else if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL && tabella[x + 3][y] == NULL && x < 7) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					tabella[x + 3][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					posizione[3][0] = x + 3;
					posizione[3][1] = y;

					iscorrect = true;
					continue;

				}

			}
			else {
				if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL && tabella[x + 3][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					tabella[x + 3][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					posizione[3][0] = x + 3;
					posizione[3][1] = y;

					iscorrect = true;
					continue;
				}
				else if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && tabella[x - 3][y] == NULL && x >= mid) {
					tabella[x][y] = 'o';
					tabella[x][y - 1] = 'o';
					tabella[x][y - 2] = 'o';
					tabella[x][y - 3] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					posizione[3][0] = x - 3;
					posizione[3][1] = y;
					iscorrect = true;
					continue;
				}

			}
		}
	}

}
void InitCruiser_Cpu(char tabella[row][col], int posizione[huge][little]) {
	bool iscorrect = false;
	while (!iscorrect) {

		int x, y;
		x = rand() % 10;
		y = rand() % 10;
		int orientation = rand() % 2 + 1;

		if (orientation == 1) {
			if (tabella[x][y] == NULL) {
				if (y > huge) { // controllo se y maggiore di 5 e inserisco valore a sinistra
					if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && tabella[x][y - 3] == NULL && tabella[x][y - 4] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						tabella[x][y - 3] = 'o';
						tabella[x][y - 4] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						posizione[3][0] = x;
						posizione[3][1] = y - 3;
						posizione[4][0] = x;
						posizione[4][1] = y - 4;
						iscorrect = true;
						continue;
					}

				}
				else {
					if (tabella[x][y + 1] == NULL && tabella[x][y + 2] == NULL && tabella[x][y + 3] == NULL && tabella[x][y + 4] == NULL) {
						tabella[x][y] = 'o';
						tabella[x][y + 1] = 'o';
						tabella[x][y + 2] = 'o';
						tabella[x][y + 3] = 'o';
						tabella[x][y + 4] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y + 1;
						posizione[2][0] = x;
						posizione[2][1] = y + 2;
						posizione[3][0] = x;
						posizione[3][1] = y + 3;
						posizione[4][0] = x;
						posizione[4][1] = y + 4;
						iscorrect = true;
						continue;
					}
					else if (tabella[x][y - 1] == NULL && tabella[x][y - 2] == NULL && tabella[x][y - 3] == NULL && tabella[x][y - 4] == NULL && y == huge) {
						tabella[x][y] = 'o';
						tabella[x][y - 1] = 'o';
						tabella[x][y - 2] = 'o';
						tabella[x][y - 3] = 'o';
						tabella[x][y - 4] = 'o';
						posizione[0][0] = x;
						posizione[0][1] = y;
						posizione[1][0] = x;
						posizione[1][1] = y - 1;
						posizione[2][0] = x;
						posizione[2][1] = y - 2;
						posizione[3][0] = x;
						posizione[3][1] = y - 3;
						posizione[4][0] = x;
						posizione[4][1] = y - 4;
						iscorrect = true;
						continue;

					}

				}

			}
		}
		else {
			if (x > huge) {
				if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && tabella[x - 3][y] == NULL && tabella[x - 4][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					tabella[x - 3][y] = 'o';
					tabella[x - 4][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					posizione[3][0] = x - 3;
					posizione[3][1] = y;
					posizione[4][0] = x - 4;
					posizione[4][1] = y;
					iscorrect = true;
					continue;
				}


			}
			else {
				if (tabella[x + 1][y] == NULL && tabella[x + 2][y] == NULL && tabella[x + 3][y] == NULL && tabella[x + 4][y] == NULL) {
					tabella[x][y] = 'o';
					tabella[x + 1][y] = 'o';
					tabella[x + 2][y] = 'o';
					tabella[x + 3][y] = 'o';
					tabella[x + 4][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x + 1;
					posizione[1][1] = y;
					posizione[2][0] = x + 2;
					posizione[2][1] = y;
					posizione[3][0] = x + 3;
					posizione[3][1] = y;
					posizione[4][0] = x + 4;
					posizione[4][1] = y;

					iscorrect = true;
					continue;
				}
				else if (tabella[x - 1][y] == NULL && tabella[x - 2][y] == NULL && tabella[x - 3][y] == NULL && tabella[x - 4][y] == NULL && x == huge) {
					tabella[x][y] = 'o';
					tabella[x - 1][y] = 'o';
					tabella[x - 2][y] = 'o';
					tabella[x - 3][y] = 'o';
					tabella[x - 4][y] = 'o';
					posizione[0][0] = x;
					posizione[0][1] = y;
					posizione[1][0] = x - 1;
					posizione[1][1] = y;
					posizione[2][0] = x - 2;
					posizione[2][1] = y;
					posizione[3][0] = x - 3;
					posizione[3][1] = y;
					posizione[4][0] = x - 4;
					posizione[4][1] = y;
					iscorrect = true;
					continue;
				}

			}
		}
	}
}
// scelta= 0 per player 1, 1 per player 2 , 2 per cpu
void InitPlayer(int scelta) {
	if (scelta == 0) {

		initCruiser(shipsPosition, positionCruiser);
		InitBigShip(shipsPosition, positionBigShip);
		InitMidShip(shipsPosition, positionMidShip);
		InitLittleShip(shipsPosition, positionLittleShip);


		bool iscorrect = false;
		while (!iscorrect) {
			cout << "\ninserisci coordianata x nave1x1(0,9) :";
			cin >> posxnave;
			cout << "\ninserisci coordinata y nave 1x1(0,9) : ";
			cin >> posynave;
			if (0 <= posxnave && posxnave <= 9 && 0 <= posynave && posynave <= 9 && shipsPosition[posxnave][posynave] == NULL) {
				shipsPosition[posxnave][posynave] = 'o';
				iscorrect = true;

			}
			else {
				cout << "\n coordinate sbagliate!" << endl;
			}
		}

	}
	else if (scelta == 1) {

		initCruiser(shipsPositionEn, positionCruiserEnemy);
		InitBigShip(shipsPositionEn, positionBigShipEnemy);
		InitMidShip(shipsPositionEn, positionMidShipEnemy);
		InitLittleShip(shipsPositionEn, positionLittleShipEnemy);


		bool iscorrect = false;
		while (!iscorrect) {
			cout << "\ninserisci coordianata x nave1x1(0,9) :";
			cin >> posxnaveEnemy;
			cout << "\ninserisci coordinata y nave 1x1(0,9) : ";
			cin >> posynaveEnemy;
			if (0 <= posxnaveEnemy && posxnaveEnemy <= 9 && 0 <= posynaveEnemy && posynaveEnemy <= 9 && shipsPositionEn[posxnaveEnemy][posynaveEnemy] == NULL) {
				shipsPositionEn[posxnaveEnemy][posynaveEnemy] = 'o';
				iscorrect = true;
			}
			else {
				cout << "\n coordinate sbagliate!" << endl;
			}
		}
	}
	else if (scelta == 2) {
		InitCruiser_Cpu(shipsPositionEn, positionCruiserEnemy);
		InitBigShip_Cpu(shipsPositionEn, positionBigShipEnemy);
		InitMidShip_Cpu(shipsPositionEn, positionMidShipEnemy);
		InitLittleShip_Cpu(shipsPositionEn, positionLittleShipEnemy);

		bool iscorrect = false;
		while (!iscorrect) {

			posxnaveEnemy = rand() % 10;
			posynaveEnemy = rand() % 10;

			if (shipsPositionEn[posxnaveEnemy][posynaveEnemy] == NULL) {
				shipsPositionEn[posxnaveEnemy][posynaveEnemy] = 'o';
				iscorrect = true;
			}
			else {
				cout << "\n coordinate sbagliate!" << endl;
			}
		}


	}

}

//check which  ship is hit
void CheckHit(int x, int y) {
	bool isColpito = false;
	while (!isColpito) {
		if (counterHuge != huge) {
			for (int i = 0; i < huge; i++) {
				if (positionCruiser[i][0] == x && positionCruiser[i][1] == y) {
					cruiser[i] = 'x';
					counterHuge++;
					if (counterHuge == huge) { 
					cout << "\n incrociatore distrutto" << endl; 
					sinked = true;
					}
					isColpito = true;
					continue;
				}
			}
		}
		if (counterBig != big) {
			for (int i = 0; i < big; i++) {
				if (positionBigShip[i][0] == x && positionBigShip[i][1] == y) {
					bigShip[i] = 'x';
					counterBig++;
					if (counterBig == big) {
						cout << "\n naveGrande distrutto" << endl;
						sinked = true;
						}
					isColpito = true;
					continue;
				}
			}
		}
		if (counterMid != mid) {
			for (int i = 0; i < mid; i++) {
				if (positionMidShip[i][0] == x && positionMidShip[i][1] == y) {
					midShip[i] = 'x';
					counterMid++;
					if (counterMid == mid) { 
						cout << "\n naveMedia distrutto" << endl;
						sinked = true;
					}
					isColpito = true;
					continue;
				}
			}
		}
		if (counterLittle != little) {
			for (int i = 0; i < little; i++) {
				if (positionLittleShip[i][0] == x && positionLittleShip[i][1] == y) {
					littleShip[i] = 'x';
					counterLittle++;
					if (counterLittle == little) {
						cout << "\n navePiccola distrutta" << endl; 
						sinked = true;
					}
					isColpito = true;
					continue;
				}
			}
		}
		if (nave_piccolina != 'x') {
			if (posxnave == x && posynave == y) {
				nave_piccolina = 'x';
				cout << "\n nave piccolina distrutta" << endl;
				sinked = true;
				isColpito = true;
				continue;
			}
		}
	}
}

//check which enemy ship is hit 
void CheckHitEnemy(int x, int y) {
	bool isColpito = false;
	while (!isColpito) {
		if (counterHugeEn != huge) {
			for (int i = 0; i < huge; i++) {
				if (positionCruiserEnemy[i][0] == x && positionCruiserEnemy[i][1] == y) {
					enemyCruiser[i] = 'x';
					counterHugeEn++;
					if (counterHugeEn == huge) { cout << "\n incrociatore distrutto" << endl; }
					isColpito = true;
					continue;
				}
			}
		}
		if (counterBigEn != big) {
			for (int i = 0; i < big; i++) {
				if (positionBigShipEnemy[i][0] == x && positionBigShipEnemy[i][1] == y) {
					bigShipEnemy[i] = 'x';
					counterBigEn++;
					if (counterBigEn == big) { cout << "\n naveGrande distrutto" << endl; }
					isColpito = true;
					continue;
				}
			}
		}
		if (counterMidEn != mid) {
			for (int i = 0; i < mid; i++) {
				if (positionMidShipEnemy[i][0] == x && positionMidShipEnemy[i][1] == y) {
					midShipEnemy[i] = 'x';
					counterMidEn++;
					if (counterMidEn == mid) { cout << "\n naveMedia distrutto" << endl; }
					isColpito = true;
					continue;
				}
			}
		}
		if (counterLittleEn != little) {
			for (int i = 0; i < little; i++) {
				if (positionLittleShipEnemy[i][0] == x && positionLittleShipEnemy[i][1] == y) {
					littleShipEnemy[i] = 'x';
					counterLittleEn++;
					if (counterLittleEn == little) { cout << "\n navePiccola distrutta" << endl; }
					isColpito = true;
					continue;
				}
			}
		}
		if (nave_piccolinaEnemy != 'x') {
			if (posxnaveEnemy == x && posynaveEnemy == y) {
				nave_piccolinaEnemy = 'x';
				cout << "\n nave piccolina distrutta" << endl;
				isColpito = true;
				continue;
			}
		}
	}
}

//check victory
bool checkWin1() {
	if (counterLittleEn == little && counterMidEn == mid
		&& counterBigEn == big && counterHugeEn == huge && nave_piccolinaEnemy == 'x') {
		cout << "\n complimenti hai vinto Player 1!" << endl;
		isWin = true;
		return isWin;
	}
	return isWin;
}
bool checkWin2() {
	if (counterLittle == little && counterMid == mid
		&& counterBig == big && counterHuge == huge && nave_piccolina == 'x') {
		cout << "\n complimenti hai vinto Player 2!" << endl;
		isWinEn = true;
		return isWinEn;
	}
	return isWinEn;
}

void Shoot(int x, int y, char tabella[row][col], char battle[row][col], int player) {
	if (tabella[x][y] == NULL || battle[x][y] == 'A') {
		cout << "\n colpo a vuoto " << endl;
		battle[x][y] = 'A';
	}
	else if (tabella[x][y] == 'o') {

		if (player == 0) {

			CheckHitEnemy(x, y);
			checkWin1();

		}
		else if (player == 1) {
			CheckHit(x, y);
			checkWin2();
		}
		cout << "\n nave colpita" << endl;
		battle[x][y] = 'X';

	}
}

//is hit a ship then will hit the adiacent cells until the ship isn't sinked
void ShootCpu() {
	bool isvalid = false;
	int x, y;
	if (!hit) {
		while (!isvalid) {
			x = rand() % 10;
			y = rand() % 10;
			cout << "\n posizione x sparo  :  " << x << " posizione y sparo:  " << y;
			if (battleTableEn[x][y] == 'A' || battleTableEn[x][y] == 'X') {
				continue;
			}
			else {
				isvalid = true;
			}
		}
		if (shipsPosition[x][y] == NULL) {
			battleTableEn[x][y] = 'A';
		}
		else {
			
			xLastShot = x;
			yLastShot = y;
			CheckHit(x,y);
			battleTableEn[x][y] = 'X';
			if (sinked) {
				hit = false;
				sinked = false;
			}
			else {
				hit = true;
			}
		}
		
	}
	else {
		if (right) {
			if (shipsPosition[xLastShot][yLastShot + incremento] == 'o') {
				cout << "\n posizione x sparo  :  " << xLastShot << " posizione y sparo:  " << yLastShot+incremento;
				CheckHit(xLastShot, yLastShot + incremento);
				battleTableEn[xLastShot][yLastShot + incremento] = 'X';
				if (sinked) {
					hit = false;
					sinked = false;
					incremento = 1;
				}

				else
				{
					incremento++;
				}
			}
			
			else {
				right = false;
				incremento = 1;	
				if (battleTableEn[xLastShot][yLastShot + incremento] == NULL) {
					battleTableEn[xLastShot][yLastShot + incremento] = 'A';
				
				}
			}

		}
		else if (!right && left) {
			if (shipsPosition[xLastShot][yLastShot - incremento] == 'o') {
				cout << "\n posizione x sparo  :  " << xLastShot << " posizione y sparo:  " << yLastShot - incremento;
				CheckHit(xLastShot, yLastShot - incremento);
				battleTableEn[xLastShot][yLastShot - incremento] = 'X';
				if (sinked) {
					hit = false;
					sinked = false;
					incremento = 1;
					right = true;
				}

				else
				{
					incremento++;
				}
			}

			else {
				left = false;
				incremento = 1;
				if (battleTableEn[xLastShot][yLastShot - incremento] == NULL) {
					battleTableEn[xLastShot][yLastShot - incremento] = 'A';

				}
			}
		}
		else if (!right && !left && up) {
			if (shipsPosition[xLastShot-incremento][yLastShot] == 'o') {
				cout << "\n posizione x sparo  :  " << xLastShot - incremento  << " posizione y sparo:  " << yLastShot;
				CheckHit(xLastShot-incremento, yLastShot);
				battleTableEn[xLastShot-incremento][yLastShot] = 'X';
				if (sinked) {
					hit = false;
					sinked = false;
					incremento = 1;
					right = true; 
					left = true;
				}

				else
				{
					incremento++;
				}
			}
			
			else {
				up = false;
				incremento = 1;	
				if (battleTableEn[xLastShot-incremento][yLastShot ] == NULL) {
					battleTableEn[xLastShot-incremento][yLastShot] = 'A';
				
				}
			}
		
		}
		else if (!right && !left && !up && down) {
			if (shipsPosition[xLastShot + incremento][yLastShot] == 'o') {
				cout << "\n posizione x sparo  :  " << xLastShot + incremento  << " posizione y sparo:  " << yLastShot ;
				CheckHit(xLastShot + incremento, yLastShot);
				battleTableEn[xLastShot + incremento][yLastShot] = 'X';
				if (sinked) {
					hit = false;
					sinked = false;
					incremento = 1;
					right = true;
					left = true;
					up = true;
				}

				else
				{
					incremento++;
				}
			}

			else {
				up = false;
				incremento = 1;
				if (battleTableEn[xLastShot + incremento][yLastShot] == NULL) {
					battleTableEn[xLastShot + incremento][yLastShot] = 'A';

				}
			}
		
		}
		
	}
}

//gameloop player1 vs player2
void Multiplayer() {
	InitPlayer(0);
	Draw(shipsPosition);
	bool iscorrect = false;
	InitPlayer(1);
	Draw(shipsPositionEn);
	system("pause");
	while (!isWin && !isWinEn) {
		Sleep(500);
		system("cls");
		cout << "\n turno player 1" << endl;
		Draw(battleTable);
		int posy;
		int posx;
		iscorrect = false;

		while (!iscorrect) {

			cout << "\nindica posizione x(0,9): ";
			cin >> posx;
			cout << "\n indica posizione y(0,9)";
			cin >> posy;

			if (0 <= posx && posx <= 9 && 0 <= posy && posy <= 9) {
				iscorrect = true;
				continue;
			}
		}
		Shoot(posx, posy, shipsPositionEn, battleTable, 0);
		if (isWin) {
			continue;
		}

		iscorrect = false;
		Sleep(500);
		system("cls");
		cout << "\turno player 2" << endl;
		Draw(battleTableEn);
		int posy2;
		int posx2;
		while (!iscorrect) {

			cout << "\nindica posizione x(0,9): ";

			cin >> posx2;
			cout << "\n indica posizione y(0,9)";
			cin >> posy2;
			if (0 <= posx2 && posx2 <= 9 && 0 <= posy2 && posy2 <= 9) {
				iscorrect = true;
				continue;
			}
		}
		Shoot(posx2, posy2, shipsPosition, battleTableEn, 1);
		if (isWinEn) {
			continue;
		}
	}
}

//gameloop player1 vs cpu
void VsCpu() {
	InitPlayer(0);
	Draw(shipsPosition);
	bool iscorrect = false;
	InitPlayer(2);
	Draw(shipsPositionEn);
	while (!isWin && !isWinEn) {
		Sleep(500);
		system("cls");
		cout << "\n turno player 1" << endl;
		Draw(battleTable);
		int posy;
		int posx;
		iscorrect = false;

		while (!iscorrect) {

			cout << "\nindica posizione x(0,9): ";
			cin >> posx;
			cout << "\n indica posizione y(0,9)";
			cin >> posy;

			if (0 <= posx && posx <= 9 && 0 <= posy && posy <= 9) {
				iscorrect = true;
				continue;
			}
		}
		Shoot(posx, posy, shipsPositionEn, battleTable, 0);
		if (isWin) {
			continue;
		}

		iscorrect = false;
		Sleep(500);
		system("cls");
		cout << "\turno player 2" << endl;
		Draw(battleTableEn);
		ShootCpu();
		if (isWinEn) {
			continue;
		}
	}

}

int main()
{
	srand(time(0));
	int choice;
	cout << "\n Scegli contro chi vuoi giocare: VsPlayer(0) , VsCpu(1) : " << endl;
	cin >> choice;
	if (choice == 0) {
		Multiplayer();
	}
	else {
		VsCpu();
	}
}

