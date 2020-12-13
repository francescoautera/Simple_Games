#include<iostream>
#include<array>
#include<ctime>
#include<cstdlib>

using namespace std;

const int row = 3;
const int col = 3;
bool check1;
bool check2;
bool checkcpu=true;
bool checkInsert;
bool winP1;
bool winP2;
int rounds = 4;

bool firstTurn = true;

char gameTable[row][col];


void  Reset() {
	 check1 = false;
	 check2 = false;
	 checkcpu = true;
	 checkInsert = false;
	 winP1 = false;
	 winP2 = false;
	 rounds = 4;
	 firstTurn = true;
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			gameTable[i][j] = NULL;
		}
	}

}

void Draw() {
	cout << "\n";
	for (int i = 0; i < row; i++) {
		cout << " ";
		for (int j = 0; j < col; j++) {
			cout << " " <<gameTable[i][j] ;
		}
		cout << " " << endl;
	
	}
}


void InsertP1(int x, int y) {
	gameTable[x][y] = 'X';
	Draw();
}

void InsertP2(int x, int y) {

	gameTable[x][y] = 'O';
	Draw();
}

bool CheckP1(int x, int y) {
	bool check;
	if (gameTable[x][y] == NULL) {
		InsertP1(x, y);
		check = true;
	}
	else {
		cout << "valore impossibile da inserire";
		check = false;
	}
	return check;
}

bool CheckP2(int x,int y) {
	bool check;
	if (gameTable[x][y] == NULL) {
		InsertP2(x, y);
		check = true;
	}
	else {
		cout << "valore impossibile da inserire";
		check = false;
	}
	return check;
}

bool WinConditionP1() {
	
	if (gameTable[0][0] == 'X' && gameTable[1][1] == 'X' && gameTable[2][2] == 'X') {
		cout << "Player 1 wins" << endl;
		return	true;
	}

	if (gameTable[0][2] == 'X' && gameTable[1][1] == 'X' && gameTable[2][0] == 'X') {
		cout << "Player 1 wins" << endl;
		return	true;
	}

	int count=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (gameTable[i][j] == 'X') {
				count += 1;;
			}		
			
		}
		
		if (count == 3) {
			cout << "Player 1 wins" << endl;
			return true;
		}
		count = 0;
	}

	int contatore=0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (gameTable[j][i] == 'X') {
				contatore += 1;
			}
		}
	
		if (contatore== 3) {
			cout << "Player 1 wins" << endl;
			return true;
		}
		contatore = 0;
	}

	return false;

}


bool WinConditionP2() {


	if (gameTable[0][0] == 'O' && gameTable[1][1] == 'O' && gameTable[2][2] == 'O') {
		cout << "Player 2 wins" << endl;
		return	true;
	}

	if (gameTable[0][2] == 'O' && gameTable[1][1] == 'O' && gameTable[2][0] == 'O') {
		cout << "Player 2 wins" << endl;
		return	true;
	}

	int count=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (gameTable[i][j] == 'O') {
				count+=1;
			}
		}
	
		if (count == 3) {
			cout << "Player 2 wins" << endl;
			return true;
		}
		count = 0;
	}
	int contatore=0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (gameTable[j][i] == 'O') {
				contatore+=1;
			}
		}
		
		if (contatore == 3) {
			cout << "Player 2 wins" << endl;
			return true;
		}
		contatore = 0;
	}

	return false;
}


bool LastValore() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (gameTable[i][j] == NULL) {
				InsertP1(i, j);
			}
		}
	}
	 bool x= WinConditionP1();
	 return x;
	 
}

// the first move of enemy
void FirstInsert() {
	if (gameTable[1][1] == NULL) {
		InsertP2(1, 1);
		checkInsert = true;
	}
	else {
		InsertP2(2, 0);
		checkInsert = true;
	}


}

bool InsertforVictory() {
	int countrow = 0;
	int countcol = 0;
	int countdiagonal = 0;
	int countdiagonalinv = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (gameTable[i][j] == 'O') {
				countrow += 1;
			}
		}

		if (countrow == 2) {
			for (int j = 0; j < col; j++) {
				if (gameTable[i][j] == NULL) {
					InsertP2(i, j);
					checkInsert = true;
					return true;

				}
			}

		}
		countrow = 0;
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (gameTable[j][i] == 'O') {
				countcol += 1;
			}
		}
		if (countcol == 2) {
			for (int j = 0; j < row; j++) {
				if (gameTable[j][i] == NULL) {
					InsertP2(j, i);
					checkInsert = true;
					return true;

				}
			}

		}
		countcol = 0;
	}

	for (int i = 0; i < row; i++) {
		if (gameTable[i][i] == 'O') {
			countdiagonal += 1;
		}
		if (countrow == 2) {
			for (int j = 0; j < row; j++) {
				if (gameTable[j][j] == NULL) {
					InsertP2(j, j);
					checkInsert = true;
					return true;

				}
			}

		}
		countdiagonal = 0;
	}


	if (gameTable[0][2] == 'O') { countdiagonalinv += 1; }
	if (gameTable[1][1] == 'O') { countdiagonalinv += 1; }
	if (gameTable[2][0] == 'O') { countdiagonalinv += 1; }
	if (countdiagonalinv == 2) {
		if (gameTable[0][2] == NULL) { InsertP2(0, 2); checkInsert = true; return true; }
		if (gameTable[1][1] == NULL) { InsertP2(1, 1); checkInsert = true; return true; }
		if (gameTable[2][0] == NULL) { InsertP2(2, 0); checkInsert = true; return true; }

	}
	countdiagonalinv = 0;
	return false;

}


bool Insertvalue() {
	int countrighe = 0;
	int countcolonne = 0;
	int countdiagonale = 0;
	

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (gameTable[i][j] == 'X') {
				countrighe += 1;
			}	
		}
		
		if (countrighe == 2) {
			for (int j = 0; j < col; j++) {
				if (gameTable[i][j] == NULL) {
					InsertP2(i, j);
					checkInsert = true;
					return true;

				}
			}

		}
		countrighe = 0;
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (gameTable[j][i] == 'X') {
				countcolonne += 1;
			}
		}
		if (countcolonne == 2) {
			for (int j = 0; j < row; j++) {
				if (gameTable[j][i] == NULL) {
					InsertP2(j, i);
					checkInsert = true;
					return true;

				}
			}

		}
		countcolonne = 0;
	}


	if (gameTable[0][0] == 'X') { countdiagonale += 1; }
	if (gameTable[1][1] == 'X') { countdiagonale += 1; }
	if (gameTable[2][2] == 'X') { countdiagonale += 1; }
	if (countdiagonale == 2) {
		if (gameTable[0][0] == NULL) { InsertP2(0, 0); checkInsert = true; return true; }
		if (gameTable[1][1] == NULL) { InsertP2(1, 1); checkInsert = true; return true; }
		if (gameTable[2][2] == NULL) { InsertP2(2, 2); checkInsert = true; return true; }

	}

	return false;
}




void InsertRandomValue() {
	bool isOk = false;
	while (!isOk)
	{
		int posx = rand() % row;
		int posy = rand() % col;
		if (gameTable[posx][posy] == NULL) {
			InsertP2(posx, posy);
			isOk = true;
		}
	}

}

void VersusCpu() {
	while (!winP1 && !winP2 && rounds > 0) {
		int posx, posy;
		while (!check1) {
			cout << "\n Turno player 1:" << endl;
			cout << "\ninserire coordinata x(0,1,2):";
			cin >> posx;
			cout << "\ninserire coordinata y(0,1,2):";
			cin >> posy;
			check1 = CheckP1(posx, posy);
		}
		winP1 = WinConditionP1();
		if (winP1) {continue;}
		
		if (firstTurn) {
			FirstInsert();
			firstTurn = false;
			continue;
		}
			checkcpu = InsertforVictory();
			if (!checkcpu) { checkcpu = Insertvalue(); }

			if (!checkInsert && !checkcpu ) {
				InsertRandomValue();
			}
			winP2 = WinConditionP2();
			if (winP2) { continue; }

		check1 = false;
		checkInsert = false;
		rounds--;
	}
	

	if (rounds == 0 && !winP2 && !winP1) { 
		winP1 = LastValore();
		if (!winP1) {
			cout << "\n Pareggio" << endl;
		}

	}
	
}

void VersusPlayer2() {
	while (!winP1 && !winP2 && rounds > 0) {
		int posx, posy;
		while (!check1) {
			cout << "\n Turno player 1:" << endl;
			cout << "\ninserire coordinata x(0,1,2):";
			cin >> posx;
			cout << "\ninserire coordinata y(0,1,2):";
			cin >> posy;
			check1 = CheckP1(posx, posy);
		}
		winP1 = WinConditionP1();
		if (winP1) {
			continue;
		}

		while (!check2) {
			cout << "\n Turno player 2:" << endl;
			cout << "\ninserire coordinata x(0,1,2):";
			cin >> posx;
			cout << "\ninserire coordinata y(0,1,2):";
			cin >> posy;
			check2 = CheckP2(posx, posy);
		}
		rounds--;
		winP2 = WinConditionP2();
		if (winP2) {
			continue;
		}
		check1 = false;
		check2 = false;

	}
	if (rounds == 0 && !winP2 && !winP1) { winP1 = LastValore(); }
	if(!winP1){
		cout << "\n Pareggio" << endl;

	}

}


int main() {
	srand(time(0));
	char gioca = 'y';
	while (gioca == 'y') {
		int scelta;
		cout << "Contro chi vuoi giocare?: Cpu(0) Player2(1):";
		cin >> scelta;
		Draw();
		if (scelta == 0) {
			VersusCpu();
		}
		else {
			VersusPlayer2();
		}

		cout << "\n vuoi giocare ancora?(y/n):";
		cin >> gioca;
		if (gioca == 'y') {
			Reset();
			
		}
		else {
			system("pause");
		}
	}
	}
