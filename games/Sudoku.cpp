#include<iostream>
#include<vector>
#include "Windows.h"
#include<ctime>
#include<cstdlib>

using namespace std;

const int rows = 9;
const int cols = 9;
bool finish = false;
bool correct = false;
bool checkcol = false;
bool checkrow = false;


int Columns[rows][cols];
int Box[rows][cols];
int Rows[rows][cols];

int gameTable[rows][cols];
int Solution[rows][cols];


void DrawGameTable() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << " " << gameTable[i][j];
			if (j == 2 || j == 5) {
				cout << " ";
			}
		}
		if (i == 2 || i == 5) {
			cout << "\n";
		}
		cout << "" << endl;
	}
}

void DrawSolution() {
	cout << "\n" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << " " << Solution[i][j];
			if (j == 2 || j == 5) {
				cout << " ";
			}
		}
		if (i == 2 || i == 5) {
			cout << "\n";
		}
		cout << "" << endl;
	}

}





bool CheckRow(int riga, int valore) {
	for (int j = 0; j < cols; j++) {
		if (Solution[riga][j] == valore) {
			return false;
		}
	}
	return true;
}

bool CheckCol(int colonna, int valore) {
	for (int j = 0; j < rows; j++) {
		if (Solution[j][colonna] == valore) {
			return false;
		}
	}
	return true;
}


void CheckBox(int initx, int finx, int inity, int finy, int posbox) {
	for (int i = initx; i < finx; i++) {
		for (int j = inity; j < finy; j++) {
			for (int num = 1; num <= rows; num++) {
				if (Solution[i][j] == num) {
					Box[posbox][num - 1] = 1;

				}
			}
		}
	}

}


//complete first box with number in random position
void InsertSolution1(int initx, int finx, int inity, int finy, int posbox) {
	bool isok = false;
	int colonna, riga;
	for (int i = initx; i < finx; i++) {
		for (int j = initx; j < finy; j++) {
			isok = false;
			if (Solution[i][j] == 0) {
				while (!isok)
				{
					int num = rand() % 9 + 1;
					if (Box[posbox][num - 1] == 0) {
						colonna = Columns[j][num - 1];
						riga = Rows[i][num - 1];
						if (colonna == 0 && riga == 0) {
							Solution[i][j] = num;
							Box[posbox][num - 1] = 1;
							Columns[j][num - 1] = 1;
							Rows[i][num - 1] = 1;
							isok = true;
							continue;

						}
					}
				}
			}
		}
	}
}
//complete the 2 and 3 box with row shifts
void InsertSolutionX(int inity,int finy, int initx, int finx) {
	
	
	for (int i = initx; i < finx-1; i++ ) {
		for (int j = inity; j < finy; j++) {
			Solution[i+1][j + 3] = Solution[i][j];		
		}
	}
	for (int j = inity; j < finy; j++) {
		Solution[initx][j + 3] = Solution[finx-1][j];
	}

	

}
//complete the other boxes with col shifts
void InsertSolutionY(int inity, int finy, int initx, int finx) {

	for (int j = inity; j < finy - 1; j++) {
		for (int i = initx; i < finx ; i++) {
			Solution[i+3][j + 1] = Solution[i][j];
		}
	}
	for (int i = initx; i < finx; i++) {
		Solution[i+3][inity] = Solution[i][finy-1];
	}



}

void CheckRowLeft() {
	int num;
	for (int i = 0; i < rows; i++) {
		for (num = 1; num <= rows; num++) {
			checkrow = CheckRow(i, num);
			if (!checkrow) {
				Rows[i][num - 1] = 1;

			}

		}
	}
}

void CheckColLeft() {
	int num;
	for (int i = 0; i < cols; i++) {
		for (num = 1; num <= rows; num++) {
			checkcol = CheckCol(i, num);
			if (!checkcol) {
				Columns[i][num - 1] = 1;
			}
		}
	}
}

	
//copy solution into gametable and then add some  zeros in random position	
void CreateGame() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			gameTable[i][j] = Solution[i][j];
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			int x = rand() % 6 + 1;
			if (x % 2 == 0) {
				gameTable[i][j] = 0;
			}
		}
	}

}

bool CheckWin() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (gameTable[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

bool CheckNumber(int value,int posx,int posy) {
	if (Solution[posx][posy] == value) {
		gameTable[posx][posy] = value;
		return true;
	}
	else {
		cout << "posizione non corretta" << endl;
		Sleep(500);
		system("cls");
		DrawGameTable();
	}
	return false;
}

int main() {
	srand(time(0));

	CheckRowLeft();
	CheckColLeft();
	CheckBox(0, 3, 0, 3, 0);
	InsertSolution1(0, 3, 0, 3, 0);
	InsertSolutionX(0,3,0,3);
	InsertSolutionX(3,6,0,3);
	InsertSolutionY(0,9,0,3);
	InsertSolutionY(0,9,3,6);
	CreateGame();
	DrawGameTable();

	while (!finish) {
		int valore;
		int posx, posy;
		correct = false;
		while (!correct)
		{
			cout << "\ninserisci valore:(1,9) " << endl;
			cin >> valore;
			cout << "\ninserisci posizione x(0,8)" << endl;
			cin >> posx;
			cout << "\ninserisci posizione y(0,8)" << endl;
			cin >> posy;
			correct = CheckNumber(valore,posx,posy);
			if (correct) {
				Sleep(500);
				system("cls");
				DrawGameTable();
				finish = CheckWin();
				continue;
			}
			
		}

	}


}