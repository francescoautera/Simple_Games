#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<string>

using namespace std;

const int words = 5;
string solution;
string EasyWords[words];
string MidWords[words];
string HardWords[words];
int tries = 6;
bool win = false;
bool iscorrect = false;


void DrawHangman(int t)
{
	// Scrivete delle istruzioni COUT per disegnare l'impiccato
	// man mano che aumentano i tentativi
	// da 6 a 0

	if (t == 6) // disegno il primo pezzo
	{
		cout << "//     =======" << endl;
		cout << "//     ||    |" << endl;
		cout << "//     ||     " << endl;
		cout << "//     ||     " << endl;
		cout << "//     ||     " << endl;
		cout << "//   / ||     " << endl;
		cout << "//   ============= " << endl;
	}
	if (t == 5) // disegno i primi 2 pezzi
	{
		cout << "//     =======" << endl;
		cout << "//     ||    |" << endl;
		cout << "//     ||    0" << endl;
		cout << "//     ||    " << endl;
		cout << "//     ||    " << endl;
		cout << "//   / ||    " << endl;
		cout << "//   ============= " << endl;
	}
	if (t == 4) // disegno i primi 3 pezzi
	{
		cout << "//     =======" << endl;
		cout << "//     ||    |" << endl;
		cout << "//     ||    0" << endl;
		cout << "//     ||    |" << endl;
		cout << "//     ||    " << endl;
		cout << "//   / ||    " << endl;
		cout << "//   ============= " << endl;
	}
	if (t == 3) // disegno i primi 4 pezzi
	{
		cout << "//     =======" << endl;
		cout << "//     ||    |" << endl;
		cout << "//     ||    0" << endl;
		cout << "//     ||   /|" << endl;
		cout << "//     ||    " << endl;
		cout << "//   / ||    " << endl;
		cout << "//   ============= " << endl;
	}
	if (t == 2) // disegno i primi 5 pezzi
	{
		cout << "//     =======" << endl;
		cout << "//     ||    |" << endl;
		cout << "//     ||    0" << endl;
		cout << "//     ||   /|\\" << endl;
		cout << "//     ||    " << endl;
		cout << "//   / ||    " << endl;
		cout << "//   ============= " << endl;
	}
	if (t == 1) // disegno i primi 6 pezzi
	{
		cout << "//     =======" << endl;
		cout << "//     ||    |" << endl;
		cout << "//     ||    0" << endl;
		cout << "//     ||   /|\\" << endl;
		cout << "//     ||   /" << endl;
		cout << "//   / ||    " << endl;
		cout << "//   ============= " << endl;
	}
	if (t == 0) // disegno tutti i pezzi
	{
		cout << "//     =======" << endl;
		cout << "//     ||    |" << endl;
		cout << "//     ||    0" << endl;
		cout << "//     ||   /|\\" << endl;
		cout << "//     ||   / \\" << endl;
		cout << "//  \\  ||    " << endl;
		cout << "//   ============= " << endl;
	}
	// ...


	// corda, testa, corpo, braccia, gambe - 7 tentativi
	//     =======
	//     ||    |
	//     ||    0
	//     ||   \|/
	//     ||   / \
    //     ||
	//   ============= 

}

void InitEasy() {
	EasyWords[0] = "gelato";
	EasyWords[1] = "limoni";
	EasyWords[2] = "manina";
	EasyWords[3] = "pulcini";
	EasyWords[4] = "carisma";
	
}


void InitMid() {
	MidWords[0] = "carismatico";
	MidWords[1] = "marmittone";
	MidWords[2] = "carambolina";
	MidWords[3] = "castrazione";
	MidWords[4] = "bontempone";
}

void InitHard() {
	HardWords[0] = "preterintenzionale";
	HardWords[1] = "pleonastico";
	HardWords[2] = "lapalissiano";
	HardWords[3] = "sproloquio";
	HardWords[4] = "peripatetica";

}

void Draw(string word) {
	cout << " ";
	for (int i = 0; i < word.size(); i++) {
		cout<< word[i]<<" " ;
		
	}
	cout << "\n";
}

 bool Checkwin(string word) {
	 if (word == solution) {
		 return true;
	 }
	 return false;
 }

int main() {
	srand(time(0));
	string ArrayScelto[words];
	string Findword;
	char gioco = 'y';

	while (gioco=='y')
	{

	
	cout << "\n scegli il livello di difficolta' : facile(0),medio(1),difficile(2) : ";
	int choice;
	cin >> choice;

	if (choice == 0) {
		InitEasy();
		for (int i = 0; i < words; i++) {
			ArrayScelto[i] = EasyWords[i];
			
		}

	}
	else if (choice == 1) {
		InitMid();
		for (int i = 0; i < words; i++) {
			ArrayScelto[i] = MidWords[i];

		}
	}
	else {
		InitHard();
		for (int i = 0; i < words; i++) {
			ArrayScelto[i] = HardWords[i];
		}
	
	}

	int sol= rand()%words;
	solution = ArrayScelto[sol];
	

	Findword.resize(solution.size());
	for (int i = 0; i < Findword.size(); i++) {
		Findword[i] = '_';
		
	}
	DrawHangman(tries);
	Draw(Findword);

	while (!win && tries > 0) {
		iscorrect = false;

		cout << "\n cosa vuoi fare? : inserisci soluzione(0) chiedi Lettera(1) ";
		int choose;
		cin >> choose;
		if (choose == 0) {
			cout << "\n inserisci soluzione : ";
			string sol;
			cin >> sol;
			win = Checkwin(sol);
			if (!win) {
				tries--;
				DrawHangman(tries);
				//cout << "\Parola sbagliata" << " " << " tentativi rimasti : " << tries << endl;

			}
			else {
				cout << "\n complimenti hai vinto";
				continue;
			}
		}
		else {
			cout << " \n inserire una lettera :";
			char letter;
			cin >> letter;

			for (int i = 0; i < solution.size(); i++) {
				if (solution[i] == letter) {
					Findword[i] = letter;
					iscorrect = true;
					
				}
				
			}
			if (iscorrect) {
				DrawHangman(tries);
				Draw(Findword);
				continue;
			}

			if (!iscorrect) {
				tries--;
				//cout << "\nLettera sbagliata" << " " << " tentativi rimasti : " << tries << endl;
				DrawHangman(tries);
				Draw(Findword);
				continue;
			}


			

		}
		
		}

	if (!win) {
		cout << "\nHai perso" << endl;
	}
	cout << "\nvuoi giocare ancora(y/n)?" << endl;
	cin >> gioco;
	if (gioco == 'y') {
		tries = 6;
		win = false;
		Findword = " ";
		solution = "";
	}

	}

}