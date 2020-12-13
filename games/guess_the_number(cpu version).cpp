#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

int tentativi=3;
vector <int> numbers;
const int Max_valore=100;


string domanda1 = "\n il numero e' maggiore di";
string domanda2 = "\n  il numero e' pari";
string domanda3 = "\n e' un multiplo di 4";
string domanda4 = "\n e' un multiplo di 3 ";

void Risposta1(char x) {
	if (x == 'y') {
		
			numbers.erase(numbers.begin(), numbers.begin() + Max_valore / 2);
	}
	else {
			
			numbers.erase(numbers.begin() + Max_valore / 2, numbers.begin() + Max_valore);
		
	}
	cout << "numeri rimasti: " << numbers.size() << endl;
	tentativi--;
}

void Risposta2(char x) {
	if (x == 'y') {
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers.at(i) % 2 != 0) {
				numbers.erase(numbers.begin() + i);
			}
		}
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers.at(i) % 2 == 0) {
				numbers.erase(numbers.begin() + i);
			}
		}
		
	}
	cout << "numeri rimasti: " << numbers.size() << endl;
	tentativi--;
}

void Risposta3(char x) {
	if (x == 'y') {
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers.at(i) % 4 != 0) {
				numbers.erase(numbers.begin() + i);
			}
		}
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers.at(i) % 4 == 0) {
				numbers.erase(numbers.begin() + i);
			}
		}
	}
	cout << "numeri rimasti: " << numbers.size() << endl;
	tentativi--;
}

void Risposta4(char x) {
	
	if (x == 'y') {
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers.at(i) % 3 != 0) {
				numbers.erase(numbers.begin() + i);
			}
		}
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers.at(i) % 3 == 0) {
				numbers.erase(numbers.begin() + i);
			}
		}
	}
	cout << "numeri rimasti: " << numbers.size() << endl;
	tentativi--;
}

void Tentativi_Rimasti() {
	if (tentativi == 0) {
		int tmp = rand() % numbers.size();
		int soluzione = numbers.at(tmp);
		cout << " \nla soluzione e': " << soluzione << endl;
		cout << "\n Ho indovinato?" << endl;
		char risposta;
		cin >> risposta;
		if (risposta == 'y') {
			cout << "yeeeeeehhhhh" << endl;
		}
		else {
			cout << "Oh no! Aniway" << endl;
		}
	}
}

int main() { 
	char risposta;
	srand(time(0));
	for (int i = 1; i <= Max_valore; i++) {
		numbers.push_back(i);
	}

	cout << domanda1 << ":" << Max_valore/2 << "(y/n)"<< endl;
	cin >> risposta;
	Risposta1(risposta);
	Tentativi_Rimasti();
	cout << domanda2 << ":" << "(y/n)" << endl;
	cin >> risposta;
	Risposta2(risposta);
	Tentativi_Rimasti();
	if (risposta == 'y') {
		cout << domanda3 << "(y/n)" << endl;
		cin >> risposta;
		Risposta3(risposta);
		Tentativi_Rimasti();
	}
	else {
		cout << domanda4 << "(y/n)" << endl;
		cin >> risposta;
		Risposta4(risposta);
		Tentativi_Rimasti();
	}

	
	system("pause");
}