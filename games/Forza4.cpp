#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


const int cols = 7;
const int rows = 6;
const int mid = 5;
const int falsemiddle = 6;
const int victory = 4;
const int insert = 1;

char gameTable[rows][cols];
const char player1 = 'x';
const char player2 = 'o';

bool iswin1 = false;
bool iswin2 = false;
bool fullColumn = false;
int xpos;
int countriga=0;
int countcolonna = 0;
int countdiagsup = 0;
int countdiaginferiore = 0;

void Draw(const char tabella[rows][cols]) {
	cout << "\n";
	cout << " ";
	cout << " [";
	for (int k = 0; k < cols; k++) {

		cout << k << " ";
	}
	cout << "]";
	cout << "" << endl;
	for (int i = 0; i < rows; i++) {
		cout << "" << i << "[";
		for (int j = 0; j < cols; j++) {
			cout << " " << tabella[i][j];
		}
		cout << "]" << endl;

	}

}

bool checkRow(int x, int y,char player) {

	int rcountdx = 0;
	int rcountsx = 0;
	for (int i = 1; i < 4; i++) {
		if (y + i > cols-1) {
			if (gameTable[x][y - i] == player) {
				rcountsx++;
			}
		}
		else if (y - i < 0) {
			if (gameTable[x][y + i] == player) {
				rcountdx++;
			}
		}
		else {
			if (gameTable[x][y - i] == player) {
				rcountsx++;
			}
			if (gameTable[x][y + i] == player) {
				rcountdx++;
			}
		}
	}
		
	countriga = rcountdx + rcountsx+insert;

	if (rcountdx + rcountsx + insert == victory ) {
		if (player == player1) {
			iswin1 = true;
			return iswin1;
		}
		else {
			iswin2 = true;
			return iswin2;
		}
	}
	return false;
}
bool CheckCol(int x, int y, char player) {

	int rcountup = 0;
	int rcountdown = 0;
	
	for (int i = 1; i < 4; i++) {
		if (x + i > rows-1) {
			if (gameTable[x - i][y] == player) {
				rcountup++;
			}
		}
		else if (x - i < 0) {
			if (gameTable[x + i][y] == player) {
				rcountdown++;
			}
		}
		else {
			if (gameTable[x - i][y] == player) {
				rcountup++;
			}
			if (gameTable[x + i][y] == player) {
				rcountdown++;
			}
		}
	}

	countcolonna = rcountup + rcountdown+insert;
	

	if (rcountup + rcountdown + insert == victory ) {
		if (player == player1) {
			iswin1 = true;
			return iswin1;
		}
		else {
			iswin2 = true;
			return iswin2;
		}
	}
	return false;

}

bool CheckDiag(int x, int y, char player) {

	int countdiag = 0;
	int countdiaginf = 0;
	int count = 1;

	while (x + count <= rows - 1 && y + count <= rows - 1 && count != 4) {
		if (gameTable[x+count][y+count] == player) {
			countdiag ++;
		}
		count++;
	}

	count = 1;

	while (x - count >= 0  && y - count >= 0 && count != 4) {
		if (gameTable[x - count][y - count] == player) {
			countdiag ++ ;
		}
		count++;
	}
	count = 1;

	while (x - count >= 0 && y + count <= rows - 1 && count != 4) {
		if (gameTable[x - count][y + count] == player) {
			countdiaginf++;
		}
		count++;
	}
	count = 1;
	while (x + count <= rows-1 && y - count >= 0 && count != 4) {
		if (gameTable[x + count][y - count] == player) {
			countdiaginf++;
		}
		count++;
	}

	countdiagsup = countdiag;
	countdiaginferiore = countdiaginf;

	
	if (countdiag + insert == victory || countdiaginf + insert == victory) {
		if (player == player1) {
			iswin1 = true;
			return iswin1;
		}
		else {
			iswin2 = true;
			return iswin2;
		}
	}

	return false;
}

//controllo solo se con l'ultimo valore inserito player 1 vince la partita
bool Checkwin1(int x, int y) {
	checkRow(x,y,player1);
	if (iswin1) {
		return iswin1;
	}
	CheckCol(x, y, player1);
	if (iswin1) {
		return iswin1;
	}
	CheckDiag(x,y,player1);
	
	return iswin1;

}
bool Checkwin2(int x, int y) {
	checkRow(x, y, player2);
	if (iswin2) {
		return iswin2;
	}
	CheckCol(x, y, player2);
	if (iswin2) {
		return iswin2;
	}
	CheckDiag(x,y,player2);

	return iswin2;

}

bool InsertColumn(char player, int column) {
	bool insert = false;
	int row = rows - 1;
	while (!insert && row > 0) {
		if (gameTable[row][column] == NULL) {
			if (player == player1) {
				gameTable[row][column] = player1;
				xpos = row;
				fullColumn = false;
			}
			else {
				gameTable[row][column] = player2;
				xpos = row;
				fullColumn = false;

			}
			insert = true;
		}
		else {
			row--;
		}
	}
	if (row <= 0) {
		fullColumn = true;
	}
	return fullColumn;
}

void InsertValue(int x, int y) {
	if (countriga == victory - 1) {
		if (x == rows - 1) {
			if (gameTable[x][y - 1] == NULL) {
				InsertColumn(x, y - 1);
				Checkwin2(x, y - 1);
			}
			else if (gameTable[x][y + 1] == NULL) {

				InsertColumn(player2, y + 1);
				Checkwin2(x, y + 1);
			}
				else if (gameTable[x][y - 2] == NULL) {
						InsertColumn(player2, y - 2);
						Checkwin2(x, y - 2);
					
				}
				else if (gameTable[x][y + 2] == NULL) {
					
						InsertColumn(player2, y + 2);
						Checkwin2(x, y + 2);
					
				}
		}
		if (gameTable[x][y - 1] == NULL) {
			if (gameTable[x + 1][y - 1] != NULL) {
				InsertColumn(player2, y - 1);
				Checkwin2(x,y-1);
			}
		}
		else if (gameTable[x][y + 1] == NULL) {
			if (gameTable[x + 1][y + 1] != NULL) {
				InsertColumn(player2, y + 1);
				Checkwin2(x, y + 1);
			}
			else if (gameTable[x][y - 2] == NULL) {
				if (gameTable[x + 1][y - 2] != NULL) {
					InsertColumn(player2, y - 2);
					Checkwin2(x, y - 2);
				}
			}
			else if (gameTable[x][y + 2] == NULL) {
				if (gameTable[x + 1][y + 2] != NULL) {
					InsertColumn(player2, y + 2);
					Checkwin2(x, y +2);
				}
			}
			else {
				int x = rand() % rows;
				InsertColumn(player2, x);
				Checkwin2(xpos, y - 1);
			}
		}
	}

	else if (countcolonna == victory - 1 ) {
			InsertColumn(player2, y);
	}

	else if (countdiagsup == victory-1 && gameTable[x][y-1]!=NULL) {
			InsertColumn(player2,y-1);
	}
	else if (countdiagsup == victory - 1 && gameTable[x][y + 1] != NULL) {
			InsertColumn(player2, y + 1);
	}
	else
	{
		int x = rand() % rows;
		InsertColumn(player2, x);
	}
}
void Reset() {
	int countriga = 0;
	int countcolonna = 0;
	int countdiagsup = 0;
	int countdiaginferiore = 0;
}
void Multiplayer() {
	int p1;
	int p2;
	while (!iswin1 && !iswin2) {
		cout << " \n turno player 1" << endl;
		cout << " \n scegli la colonna (0,6) ";
		cin >> p1;
		InsertColumn(player1, p1);
		if (fullColumn) {
			cout << " \n scegli la colonna (0,6) ";
			cin >> p1;
			InsertColumn(player1, p1);
		}
		fullColumn = false;
		Draw(gameTable);
		Checkwin1(xpos, p1);
		if (iswin1) {
			cout << "\n player 1 wins" << endl;
			continue;
		}
		Reset();
		cout << " \n turno player 2" << endl;

		cout << " \n scegli la colonna (0,6) ";
		cin >> p2;
		InsertColumn(player2, p2);
		if (fullColumn) {
			cout << " \n scegli la colonna (0,6) ";
			cin >> p2;
			InsertColumn(player2, p2);
		}
		fullColumn = false;
		Draw(gameTable);
		Checkwin2(xpos, p2);
		if (iswin2) {
			cout << "\n player 2 wins" << endl;
		}

	}
}
void VsCpu() {

	int p1;
	int p2;
	while (!iswin1 && !iswin2) {
		cout << " \n turno player 1" << endl;
		cout << " \n scegli la colonna (0,6) ";
		cin >> p1;
		InsertColumn(player1, p1);
		if (fullColumn) {
			cout << " \n scegli la colonna (0,6) ";
			cin >> p1;
			InsertColumn(player1, p1);
		}
		fullColumn = false;
		Draw(gameTable);
		Checkwin1(xpos, p1);
		if (iswin1) {
			cout << "\n player 1 wins" << endl;
			continue;
		}
		
		cout << " \n turno player 2" << endl;
		InsertValue(xpos, p1);
		Draw(gameTable);
		if (iswin2) {
			cout << "\n player 2 wins" << endl;
		}
		Reset();
	}

}

int  main() {

	srand(time(0));
	int choice;

	
	Draw(gameTable);
	cout << "scegli un avversario : Player2(0), Cpu(1)";
	cin >> choice;
	switch (choice)
	{
	case 0:
		Multiplayer();
	case 1:
		VsCpu();
		
	}
}
