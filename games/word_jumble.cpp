#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>

using namespace std; 

const int Words = 5;
const int col = 2;
const int twist = 50;
string Solution;
string wordjumble;
char tmp;

string EasyDifficult[Words][col];
string MidDifficult[Words][col];
string HardDifficult[Words][col];

void InitEasyDifficult() {
	EasyDifficult[0][0] = "gelato"; EasyDifficult[0][1] = "si mangia in estate";
	EasyDifficult[1][0] = "candela"; EasyDifficult[1][1] = "si accende quando  va via la corrente";
	EasyDifficult[2][0] = "cinema"; EasyDifficult[2][1] = "si vedono i film";
	EasyDifficult[3][0] = "fioraio"; EasyDifficult[3][1] = "fa i soldi il 1 di novembre";
	EasyDifficult[4][0] = "polizia"; EasyDifficult[4][1] = "protegge la gente ";


}

void InitMidDifficult() {
	MidDifficult[0][0] = "orchestra"; MidDifficult[0][1] = "suonano a tempo tanti strumenti";
	MidDifficult[1][0] = "ergastolo"; MidDifficult[1][1] = "hai fatto qualcosa di brutto";
	MidDifficult[2][0] = "canarino"; MidDifficult[2][1] = "cinguetta";
	MidDifficult[3][0] = "gibilterra"; MidDifficult[3][1] = "stato";
	MidDifficult[4][0] = "barbapapa"; MidDifficult[4][1] = "personaggio inventato";

}

void InitHardDifficult() {
	HardDifficult[0][0] = "procrastinare"; HardDifficult[0][1] = "rimandare a tempo futuro";
	HardDifficult[1][0] = "rocambolesco"; HardDifficult[1][1] = "spericolato";
	HardDifficult[2][0] = "psicoterapeuta"; HardDifficult[2][1] = "cura la pazzia";
	HardDifficult[3][0] = "preterintenzionale"; HardDifficult[3][1] = "omicidio";
	HardDifficult[4][0] = "intrigante"; HardDifficult[4][1] = "avvincente";

}





void InitAnagram( string soluzione) {

	wordjumble = soluzione;

	for (int i = 0; i < twist; i++) {
		int x = rand() % wordjumble.size();
		int y = rand() % wordjumble.size();
		tmp = wordjumble[x];
		wordjumble[x] = wordjumble[y];
		wordjumble[y]= tmp;
	}
	cout << "trova la parola : " << wordjumble << endl;
}





int main() {
	srand(time(0));
	int choice;
	string Arrayscelto[Words][col];
	string sol;
	int tentativi = 4;
	char gioco = 'y';
	bool finish = false;
	string ext = "";


	cout << "Benvenuto in jumbleworld!" << endl;
	cout << "\n Devi sapere che al signor jumble piace molto anagrammare ogni parola" << endl;
	cout<<"\n Per fuggire  dal suo mondo devi trovare  la parola giusta dato il suo anagramma" << endl;
	cout << "\n Hai a disposizione 4 tentativi" << endl;
	cout << "\nJumble pero ti concede 2 tipi di aiuti: lo speciale ti rivela le prime 2 lettere ma perdi un tentativo." << endl;
	cout << " \nIl neutro ,invece, ti da un suggerimento attraverso una frase " << endl;
	cout << "\n Bene cominciamo" << endl;


	while (gioco == 'y') {
		cout << "\nscegli il livello di difficolta" << endl;
		cout << "facile(0),medio(1),difficile(2)" << endl;
		cin >> choice;
		if (choice == 0) {
			InitEasyDifficult();
			for (int i = 0; i < Words; i++) {
				for (int j = 0; j < col; j++) {
					Arrayscelto[i][j] = EasyDifficult[i][j];
				}
			}
		}
		else if (choice == 1) {
			InitMidDifficult();
			for (int i = 0; i < Words; i++) {
				for (int j = 0; j < col; j++) {
					Arrayscelto[i][j] = MidDifficult[i][j];
				}
			}

		}
		else {
			InitHardDifficult();
			for (int i = 0; i < Words; i++) {
				for (int j = 0; j < col; j++) {
					Arrayscelto[i][j] = HardDifficult[i][j];
				}
			}
		}


		int numero = rand() % Words;
		Solution = Arrayscelto[numero][0];
		InitAnagram(Solution);

		while (tentativi > 0 && !finish) {

			int scelta;

			cout << "\nvuoi tentare la soluzione (1) , chiedi aiuto(0) o vuoi uscire(2) : ";
			cin >> scelta;
			if (scelta == 1) {
				cout << " \nscrivi soluzione:" << endl;
				cin >> sol;
				if (sol == Solution) {
					cout << "\ncomplimenti" << endl;
					finish = true;
					continue;
				}
				cout << "\nrisposta sbagliata" << endl;
				tentativi--;
				cout << "\n tentativi rimasti : " << tentativi << endl;
			}
			else if (scelta == 0) {
				cout << "quale aiuto vuoi ottenere?: speciale (0), neutro (1):";
				bool aiuto;
				cin >> aiuto;
				if (aiuto) {
					cout << Arrayscelto[numero][1] << endl;
				}
				else {
					cout << "La Prima lettera:" << Solution[0] << endl;
					cout << "La Seconda Lettera:" << Solution[1] << endl;
					tentativi--;
					cout << "\n tentativi rimasti : " << tentativi << endl;
				}
			}
			else if (scelta == 2) {
				cout << "digita quit";
				cin >> ext;
				if (ext == "quit") {

					return 0;
				}
			}

		}

		if (tentativi == 0) {
			cout << "hai perso" << endl;
		}

		cout << "\nvuoi giocare ancora(y/n)?" << endl;
		cin >> gioco;
		if (gioco == 'y') {
			tentativi = 4;
			finish = false;
			sol = "";
			Solution = "";
			wordjumble = "";

		}

	}
}