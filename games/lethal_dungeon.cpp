#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>


using namespace std;


const int row = 10;
const int col = 10;
const int hero = 7;
const int enemy1 = 4;
const int enemy2 = 5;
const int block = 6;
const int treasure = 8;
const int numblock = 3;
const int colblock = 2;
const int dannoenemy1 = 2;
const int dannoenemy2 = 3;
const int dannohero = 4;
int lifehero = 10;
int lifeEn1 = 7;
int lifen2 = 8;

int blocks[numblock][colblock];
int posxtrs=0;
int posytrs=0;
int posxhero=0;
int posyhero=0;
int posenemy1;
int posxenemy1, posyenemy1;
int posxenemy2, posyenemy2;
int dungeonRoom[row][col];
int drawRoom[row][col];
bool win = false;
bool death = false;
bool movevalid = false;
bool iswall = false;


void Init() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			dungeonRoom[i][j] = 0;
			drawRoom[i][j] = 0;
		}
	}
	posxhero = rand() % row;
	posyhero = rand() % col;
	dungeonRoom[posxhero][posyhero] = hero;
	drawRoom[posxhero][posyhero] = hero;

	bool enemy1ok = false;
	while (!enemy1ok) {
		posxenemy1 = rand() % row;
		posyenemy1 = rand() % col;
		
		if (dungeonRoom[posxenemy1][posyenemy1] == 0) {
			dungeonRoom[posxenemy1][posyenemy1] = enemy1;
			drawRoom[posxenemy1][posyenemy1] = enemy1;
			enemy1ok = true;
			continue;
		}
	}
	cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;
	bool enemy2ok = false;
	while (!enemy2ok) {
		posxenemy2 = rand() % row;
		posyenemy2 = rand() % col;
		
		if (dungeonRoom[posxenemy2][posyenemy2] == 0) {
			dungeonRoom[posxenemy2][posyenemy2] = enemy2;
			drawRoom[posxenemy2][posyenemy2] = enemy2;
			enemy2ok = true;
			continue;
		}
	}
	cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;
	bool treauseok = false;
	while (!treauseok) {
		posxtrs = rand() % row;
		posytrs = rand() % col;
		
		if (dungeonRoom[posxtrs][posytrs] == 0) {
			dungeonRoom[posxtrs][posytrs] = treasure;
			treauseok = true;
			continue;
		}

	}
	cout << "postrs : " << posxtrs << " " << posytrs << endl;
	bool blockok = false;
	int posxblock, posyblock;
	for (int i = 0; i < numblock; i++) {

		blockok = false;
		while (!blockok) {
			blocks[i][0] = rand() % row;
			blocks[i][1] = rand() % col;
			
			posxblock = blocks[i][0];
			posyblock = blocks[i][1];
			if (dungeonRoom[posxblock][posyblock] == 0) {
				dungeonRoom[posxblock][posyblock] = block;
				drawRoom[posxblock][posyblock] = block;
				blockok = true;
				continue;
			}
		}
	}


}




void Draw() {
	cout << "\n";
	cout << " ";
	
	for (int k = 0; k < row; k++) {

		cout<<" " << '#'<< " ";
	}
	cout << "";
	cout << "" << endl;
	for (int i = 0; i < row; i++) {
		cout << ""  << "#";
		for (int j = 0; j < col; j++) {
			cout << " " << drawRoom[i][j]<< " ";
		}
		cout << "#" << endl;

	}
	cout << " ";
	for (int k = 0; k < row; k++) {

		cout << " " << '#' << " ";
	}
}



bool CheckTreasure(int x, int y) {
	if (posxhero == posxtrs && posyhero== posytrs) {
		cout << "L'eroe ha vinto" << endl;
		return true;
	}

	return false;
}

bool CheckWall(int x, int y) {
	if (dungeonRoom[x][y] == block) {
		cout << "non puoi passare" << endl;
		return true;
	}
	return false;
}

void FindTrs(int x, int y) {
	if ((dungeonRoom[x - 1][y] == dungeonRoom[posxtrs][posytrs]) || (dungeonRoom[x + 1][y] == dungeonRoom[posxtrs][posytrs]) 
		|| (dungeonRoom[x][y - 1] == dungeonRoom[posxtrs][posytrs]) || (dungeonRoom[x][y + 1] == dungeonRoom[posxtrs][posytrs])) {
		cout << "\nfuoco" << endl;
	}
	else if ((dungeonRoom[x - 2][y] == dungeonRoom[posxtrs][posytrs]) || (dungeonRoom[x + 2][y] == dungeonRoom[posxtrs][posytrs])
		|| (dungeonRoom[x][y - 2] == dungeonRoom[posxtrs][posytrs]) || (dungeonRoom[x][y + 2] == dungeonRoom[posxtrs][posytrs])) {
		cout << "\nfuochino" << endl;
	}
	else {
		cout << "\n acqua" << endl;
	}
}


bool  MoveHero(int x, int y) {
	if (x < 0 || x>9 || y < 0 || y>9) {
		cout << "you can't do this here" << endl;
		return false;
	}


	win = CheckTreasure(x, y);
	iswall = CheckWall(x, y);

	if (iswall) { return false; }
	if (death) { return true; }
	if (win) { return true; }

	drawRoom[posxhero][posyhero] = 0;
	dungeonRoom[posxhero][posyhero] = 0;

	posxhero = x;
	posyhero = y;

	drawRoom[x][y] = hero;
	dungeonRoom[x][y] = hero;
	FindTrs(x, y);
	


	return true;
}

void MoveEnemy1() {
	
	
	double distancex = abs(posxenemy1 - posxhero);
	double distancey = abs(posyenemy1 - posyhero);
	if (lifeEn1 > 0) {
		if (distancex > distancey) {
			if (posyenemy1 > posyhero) {
				iswall = CheckWall(posxenemy1, posyenemy1 - 1);
				if (iswall) {
					if (posxenemy1 >= posxhero) {

						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1 - 1][posyenemy1] = enemy1;
						drawRoom[posxenemy1 - 1][posyenemy1] = enemy1;

						posxenemy1 = posxenemy1 - 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
					else {

						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1 + 1][posyenemy1] = enemy1;
						drawRoom[posxenemy1 + 1][posyenemy1] = enemy1;
						posxenemy1 = posxenemy1 + 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
				}
				else {
					dungeonRoom[posxenemy1][posyenemy1] = 0;
					drawRoom[posxenemy1][posyenemy1] = 0;

					dungeonRoom[posxenemy1][posyenemy1 - 1] = enemy1;
					drawRoom[posxenemy1][posyenemy1 - 1] = enemy1;
					posyenemy1 = posyenemy1 - 1;
					cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;


				}

			}
			else if (posyenemy1 < posyhero) {
				iswall = CheckWall(posxenemy1, posyenemy1 + 1);
				if (iswall) {
					if (posxenemy1 >= posxhero) {

						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1 - 1][posyenemy1] = enemy1;
						drawRoom[posxenemy1 - 1][posyenemy1] = enemy1;
						posxenemy1 -= 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
					else {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1 + 1][posyenemy1] = enemy1;
						drawRoom[posxenemy1 + 1][posyenemy1] = enemy1;
						posxenemy1 += 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
				}
				else {

					dungeonRoom[posxenemy1][posyenemy1] = 0;
					drawRoom[posxenemy1][posyenemy1] = 0;

					dungeonRoom[posxenemy1][posyenemy1 + 1] = enemy1;
					drawRoom[posxenemy1][posyenemy1 + 1] = enemy1;
					posyenemy1 += 1;
					cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;


				}
			}
			else if (posyenemy1 == posyhero) {
				if (posxenemy1 > posxhero) {

					iswall = CheckWall(posxenemy1 - 1, posyenemy1);
					if (iswall) {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						drawRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						posyenemy1 += 1;

					}
					else {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1 - 1][posyenemy1] = enemy1;
						drawRoom[posxenemy1 - 1][posyenemy1] = enemy1;
						posxenemy1 -= 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}

				}
				else {
					iswall = CheckWall(posxenemy1 + 1, posyenemy1);
					if (iswall) {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						drawRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						posyenemy1 += 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
					else {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1 + 1][posyenemy1] = enemy1;
						drawRoom[posxenemy1 + 1][posyenemy1] = enemy1;
						posxenemy1 += 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
				}

			}

		}
		else {
			if (posxenemy1 > posxhero) {
				iswall = CheckWall(posxenemy1 - 1, posyenemy1);
				if (iswall) {
					if (posyenemy1 > posyhero) {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1][posyenemy1 - 1] = enemy1;
						drawRoom[posxenemy1][posyenemy1 - 1] = enemy1;
						posyenemy1 -= 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
					else {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						drawRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						posyenemy1 += 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
				}
				else {
					dungeonRoom[posxenemy1][posyenemy1] = 0;
					drawRoom[posxenemy1][posyenemy1] = 0;

					dungeonRoom[posxenemy1 - 1][posyenemy1] = enemy1;
					drawRoom[posxenemy1 - 1][posyenemy1] = enemy1;
					posxenemy1 -= 1;
					cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

				}

			}
			else if (posxenemy1 < posxhero) {
				iswall = CheckWall(posxenemy1 + 1, posyenemy1);
				if (iswall) {
					if (posyenemy1 > posyhero) {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1][posyenemy1 - 1] = enemy1;
						drawRoom[posxenemy1][posyenemy1 - 1] = enemy1;
						posyenemy1 -= 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
					else {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						drawRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						posyenemy1 += 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
				}
				else {
					dungeonRoom[posxenemy1][posyenemy1] = 0;
					drawRoom[posxenemy1][posyenemy1] = 0;

					dungeonRoom[posxenemy1 + 1][posyenemy1] = enemy1;
					drawRoom[posxenemy1 + 1][posyenemy1] = enemy1;
					posxenemy1 += 1;
					cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

				}

			}
			else if (posxenemy1 == posxhero) {
				if (posyenemy1 > posyhero) {
					iswall = CheckWall(posxenemy1, posyenemy1 - 1);
					if (iswall) {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1 + 1][posyenemy1] = enemy1;
						drawRoom[posyenemy1 + 1][posyenemy1] = enemy1;
						posxenemy1 += 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
					else {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1][posyenemy1 - 1] = enemy1;
						drawRoom[posxenemy1][posyenemy1 - 1] = enemy1;
						posyenemy1 -= 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
				}
				else {
					iswall = CheckWall(posxenemy1, posyenemy1 + 1);
					if (iswall) {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1 + 1][posyenemy1] = enemy1;
						drawRoom[posyenemy1 + 1][posyenemy1] = enemy1;
						posxenemy1 += 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
					else {
						dungeonRoom[posxenemy1][posyenemy1] = 0;
						drawRoom[posxenemy1][posyenemy1] = 0;

						dungeonRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						drawRoom[posxenemy1][posyenemy1 + 1] = enemy1;
						posyenemy1 += 1;
						cout << "pos enemy : " << posxenemy1 << " " << posyenemy1 << endl;

					}
				}

			}

		}
	}
	}
	
	
void MoveEnemy2() {

	double distancex = abs(posxenemy2 - posxhero);
	double distancey = abs(posyenemy2 - posyhero);
	if (lifen2 > 0) {
		if (distancex > distancey) {
			if (posyenemy2 > posyhero) {
				iswall = CheckWall(posxenemy2, posyenemy2 - 1);
				
				if (iswall) {
					if (posxenemy2 >= posxhero) {

						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2 - 1][posyenemy2] = enemy2;
						drawRoom[posxenemy2 - 1][posyenemy2] = enemy2;

						posxenemy2 = posxenemy2 - 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
					else {

						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						drawRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						posxenemy2 = posxenemy2 + 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
				}
				else {
					dungeonRoom[posxenemy2][posyenemy2] = 0;
					drawRoom[posxenemy2][posyenemy2] = 0;

					dungeonRoom[posxenemy2][posyenemy2 - 1] = enemy2;
					drawRoom[posxenemy2][posyenemy2 - 1] = enemy2;
					posyenemy2 = posyenemy2 - 1;
					cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;


				}

			}
			else if (posyenemy2 < posyhero) {
				iswall = CheckWall(posxenemy2, posyenemy2 + 1);
				if (iswall) {
					if (posxenemy2 >= posxhero) {

						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2 - 1][posyenemy2] = enemy2;
						drawRoom[posxenemy2 - 1][posyenemy2] = enemy2;
						posxenemy2 -= 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
					else {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						drawRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						posxenemy2 += 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
				}
				else {

					dungeonRoom[posxenemy2][posyenemy2] = 0;
					drawRoom[posxenemy2][posyenemy2] = 0;

					dungeonRoom[posxenemy2][posyenemy2 + 1] = enemy2;
					drawRoom[posxenemy2][posyenemy2 + 1] = enemy2;
					posyenemy2 += 1;
					cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;


				}
			}
			else if (posyenemy2 == posyhero) {
				if (posxenemy2 > posxhero) {

					iswall = CheckWall(posxenemy2 - 1, posyenemy2);
					if (iswall) {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						drawRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						posyenemy2 += 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
					else {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2 - 1][posyenemy2] = enemy2;
						drawRoom[posxenemy2 - 1][posyenemy2] = enemy2;
						posxenemy2 -= 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}

				}
				else {
					iswall = CheckWall(posxenemy2 + 1, posyenemy2);
					if (iswall) {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						drawRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						posyenemy2 += 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
					else {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						drawRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						posxenemy2 += 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
				}

			}
		}


		else {
			if (posxenemy2 > posxhero) {
				iswall = CheckWall(posxenemy2 - 1, posyenemy2);
				if (iswall) {
					if (posyenemy2 > posyhero) {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2][posyenemy2 - 1] = enemy2;
						drawRoom[posxenemy2][posyenemy2 - 1] = enemy2;
						posyenemy2 -= 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
					else {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						drawRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						posyenemy2 += 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
				}
				else {
					dungeonRoom[posxenemy2][posyenemy2] = 0;
					drawRoom[posxenemy2][posyenemy2] = 0;

					dungeonRoom[posxenemy2 - 1][posyenemy2] = enemy2;
					drawRoom[posxenemy2 - 1][posyenemy2] = enemy2;
					posxenemy2 -= 1;
					cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

				}

			}
			else if (posxenemy2 < posxhero) {
				iswall = CheckWall(posxenemy2 + 1, posyenemy2);
				if (iswall) {
					if (posyenemy2 > posyhero) {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2][posyenemy2 - 1] = enemy2;
						drawRoom[posxenemy2][posyenemy2 - 1] = enemy2;
						posyenemy2 -= 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
					else {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						drawRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						posyenemy2 += 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
				}
				else {
					dungeonRoom[posxenemy2][posyenemy2] = 0;
					drawRoom[posxenemy2][posyenemy2] = 0;

					dungeonRoom[posxenemy2 + 1][posyenemy2] = enemy2;
					drawRoom[posxenemy2 + 1][posyenemy2] = enemy2;
					posxenemy2 += 1;
					cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

				}

			}
			else if (posxenemy2 == posxhero) {
				if (posyenemy2 > posyhero) {
					iswall = CheckWall(posxenemy2, posyenemy2 - 1);
					if (iswall) {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						drawRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						posxenemy2 += 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
					else {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2][posyenemy2 - 1] = enemy2;
						drawRoom[posxenemy2][posyenemy2 - 1] = enemy2;
						posyenemy2 -= 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
				}
				else {
					iswall = CheckWall(posxenemy2, posyenemy2 + 1);
					if (iswall) {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						drawRoom[posxenemy2 + 1][posyenemy2] = enemy2;
						posxenemy2 += 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
					else {
						dungeonRoom[posxenemy2][posyenemy2] = 0;
						drawRoom[posxenemy2][posyenemy2] = 0;

						dungeonRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						drawRoom[posxenemy2][posyenemy2 + 1] = enemy2;
						posyenemy2 += 1;
						cout << "posenemy2 : " << posxenemy2 << " " << posyenemy2 << endl;

					}
				}

			}

		}
	}
}

void BattleEn1() {
	double distancex = abs(posxenemy1 - posxhero);
	double distancey = abs(posyenemy1 - posyhero);
	if ((dungeonRoom[posxhero + 1][posyhero] == enemy1) || (dungeonRoom[posxhero - 1][posyhero] == enemy1)
		|| (dungeonRoom[posxhero][posyhero + 1] == enemy1) || (dungeonRoom[posxhero][posyhero - 1] == enemy1)) {
	while(lifeEn1>0 && lifehero>0 ){
			lifeEn1 -= dannohero + rand() % 3;
			if (lifeEn1 <= 0) {
				cout << "nemico sconfitto" << endl;
				dungeonRoom[posxenemy1][posyenemy1] = 0;
				drawRoom[posxenemy1][posyenemy1] = 0;
				posxenemy1 = col;
				posyenemy1 = row;
				Draw();
				continue;
			}
			cout << "\n vita nemica rimasta : " << lifeEn1<<endl;
			lifehero -= dannoenemy1 + rand() % 3;
			if (lifehero <= 0) {
				cout << "\nsei morto" << endl;
				death = true;
				continue;
			}
			cout << "\n vita hero rimasta : " << lifehero << endl;
		}
	}


}

void BattleEn2() {
	double distancex = abs(posxenemy2 - posxhero);
	double distancey = abs(posyenemy2 - posyhero);
	if ((dungeonRoom[posxhero+1][posyhero]==enemy2)||(dungeonRoom[posxhero-1][posyhero]==enemy2)
		||(dungeonRoom[posxhero][posyhero+1]==enemy2)||(dungeonRoom[posxhero][posyhero-1]==enemy2)) {
		while (lifen2 > 0 && lifehero > 0) {
			lifen2 -= dannohero + rand() % 3;
			if (lifen2 <= 0) {
				cout << "nemico sconfitto" << endl;
				dungeonRoom[posxenemy2][posyenemy2] = 0;
				drawRoom[posxenemy2][posyenemy2] = 0;
				posxenemy2 = row;
				posyenemy2 = col;
				Draw();
				continue;
			}
			cout << "\n vita nemica rimasta : " << lifen2 << endl;
			lifehero -= dannoenemy2 + rand() % 3;
			if (lifehero <= 0) {
				cout << "\nsei morto" << endl;
				death = true;
				continue;
			}
			cout << "\n vita hero rimasta : " << lifehero << endl;
		}
	}
}

int main() {
	srand(time(0));

	char gioco = 'y';

	while (gioco == 'y') {
		Init();
		Draw();
		while (!win && !death) {
			while (!movevalid &&!death ) {
				BattleEn1();
				BattleEn2();
			
				cout << "\n scegli dove andare : up(w),down(s), right(d) , left(a) ";
				char choice;
				cin >> choice;
				switch (choice)
				{
				case 'a':
					movevalid = MoveHero(posxhero, posyhero - 1);
					iswall = false;
					BattleEn1();
					MoveEnemy1();
					BattleEn2();
					MoveEnemy2();
					
					Draw();

					break;
				case 'd':
					movevalid = MoveHero(posxhero, posyhero + 1);
					iswall = false;
					BattleEn1();
					MoveEnemy1();
					BattleEn2();
					MoveEnemy2();
					
					Draw();
					break;
				case 'w':
					movevalid = MoveHero(posxhero - 1, posyhero);
					iswall = false;
					BattleEn1();
					MoveEnemy1();
					BattleEn2();
					MoveEnemy2();
					Draw();
					break;
				case 's':
					movevalid = MoveHero(posxhero + 1, posyhero);
					iswall = false;
					BattleEn1();
					MoveEnemy1();
					BattleEn2();
					MoveEnemy2();
					Draw();
					break;
				}
			}

			movevalid = false;
		}

		cout << "vuoi giocare ancora?(y/n)" << endl;
		cin >> gioco;
		if (gioco == 'y') {
			win = false;
			death = false;
			movevalid = false;
			lifehero = 10;
			lifeEn1 = 7;
		    lifen2 = 8;
		}
	}

	system("pause");

}