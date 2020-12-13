#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

int sol ;
int tries = 3;
const int Max_valore = 100;
bool choices[11];

string question1=  " \n il numero e' maggiore di ";
string question2 = " \n il numero e' pari";
string question3 = " \n il numero e' un numero primo";
string question4 = " \n il numero e' una potenza di 2";
string question5 = " \n il numero e' una quadrato perfetto";
string question6 = " \n il numero e' un multiplo di 5";
string question7 = " \n il numero e' divisibile per 7 0 3";
string question8 = " \n il numero fa parte della sequenza di fibonacci ";

void Answer_1(int n) {
	if(!choices[n]){
		if (sol > Max_valore / 2) {
			cout << " \n la risposta e' si "<<endl;
		}
		else {
			cout << "\n la risposta e' no " << endl;
		}
		choices[n] = true;
		tries--;
		cout <<"\ntentativi rimasti:" << tries << endl;
	}
	else {
		cout << "\nla domanda e' gia stata posta" << endl;
	}

}
void Answer_2(int n) {
	if (!choices[n]) {
		if ((sol % 2) == 0) {
			cout << " \n la risposta e' si " << endl;
		}
		else {
			cout << "\n la risposta e' no " << endl;
		}
		choices[n] = true;
		tries--;
		cout << "\ntentativi rimasti:" << tries << endl;
	}
	else {
		cout << "\nla domanda e' gia stata posta" << endl;
	}
}
void Answer_3(int n) {
	if (!choices[n]) {
		int primo = 0;
		for (int i = 1; i <=sol; i++) {
			if ((sol % i) == 0) {
				primo++;
			}
		}
		if (primo == 2) {
			cout << " \n la risposta e' si " << endl;
		}
		else {
			cout << "\n la risposta e' no " << endl;
		}
		choices[n] = true;
		tries--;
		cout << "\ntentativi rimasti:" << tries << endl;
	}
	else {
		cout << "\n la domanda e' gia stata posta" << endl;
	}
}
void Answer_4(int n) {
	if (!choices[n]) {
		int find;
		for (int i = 2; i <= sol; i=i*2) {
			if ((sol == i)) {
				find++;
			}
			else {
				find++;
			}
		}
		if (find == 1) {
			cout << " \n la risposta e' si " << endl;
		}
		else {
			cout << "\n la risposta e' no " << endl;
		}
		choices[n] = true;
		tries--;
		cout << "\ntentativi rimasti: " << tries << endl;
	}
	else {
		cout << "\n la domanda e' gia stata posta" << endl;
	}
}
void Answer_5(int n) {
	if (!choices[n]) {
		int x = sqrt(sol);
		if (sol==x*x) {
			cout << " \n la risposta e' si " << endl;
		}
		else {
			cout << "\n la risposta e' no " << endl;
		}
		choices[n] = true;
		tries--;
		cout << "\ntentativi rimasti: " << tries << endl;
	}
	else {
		cout << "\n la domanda e' gia stata posta" << endl;
	}
}

void Answer_6(int n) {
	if (!choices[n]) {
		if ((sol % 5) == 0) {
			cout << " \n la risposta e' si " << endl;
		}
		else {
			cout << "\n la risposta e' no " << endl;
		}
		choices[n] = true;
		tries--;
		cout << "\ntentativi rimasti: " << tries << endl;
	}
	else {
		cout << " \n la domanda e' gia stata posta" << endl;
	}
}


void Answer_7(int n) {
	if (!choices[n]) {
		if ((sol % 3) == 0 || (sol % 7) == 0) {
			cout << " \n la risposta e' si " << endl;
		}
		else
		{
			cout << "\n la risposta e'  no " << endl;
		}
		choices[n] = true;
		tries--;
		cout << "\ntentativi rimasti: " << tries << endl;
	}
	else {
		cout << "la domanda e' gia stata posta" << endl;
	}
}
void Answer_8(int n) {
	if (!choices[n]) {
		int first=1;
		int tmp;
		int second=1;
		while (first + second <= sol) {
			tmp = second;
			second += first;
			first = tmp;
		}
		if (first == sol || second == sol) {
			cout << " \n la risposta e' si " << endl;
		}
		else {
			cout << "\n la risposta e' no " << endl;
		}
		choices[n] = true;
		tries--;
		cout << "\n tentativi rimasti:" << tries << endl;
	}
	else {
		cout << "\n la domanda e' gia stata posta" << endl;
	}
	
}




int main() {
	srand(time(NULL));
	sol = rand() % 100;
	char start;
	cout << "\n Benvenuto a indovina il numero!"<<endl;
	cout << "Le regole sono semplici: devi indovinare un numero";
	cout << " con le domande che ti propone il sistema."<<endl ;
	cout << "Attenzione pero' puoi chiedere solo 3 domande "<<endl;
	cout << " e non puoi chiedere la stessa domanda piu' volte";
	cout << "\n Bene cominciamo! Quando sei pronto premi y per iniziare";
	cin >> start;
	if (start=='y') {
		while (tries != 0) {
			int scelta;


			cout << question1 << Max_valore / 2 << "(0)" << endl;
			cout << question2 << "(1)" << endl;
			cout << question3 << "(2)" << endl;
			cout << question4 << "(3)" << endl;
			cout << question5 << "(4)" << endl;
			cout << question6 << "(5)" << endl;
			cout << question7 << "(6)" << endl;
			cout << question8 << "(7)" << endl;
			cout << "\n quale domanda scegli? :";
			cin >> scelta;
			switch (scelta)
			{
			case 0:
				Answer_1(scelta);
				continue;
			case 1:
				Answer_2(scelta);
				continue;
			case 2:
				Answer_3(scelta);
				continue;
			case 3:
				Answer_4(scelta);
				continue;
			case 4:
				Answer_5(scelta);
				continue;
			case 5:
				Answer_6(scelta);
				continue;
			case 6:
				Answer_7(scelta);
				continue;
			case 7:
				Answer_8(scelta);
				continue;
			default:
				continue;
			}


		}
		int test;
		cout << "Quale e' il numero scelto? :";
		cin >> test;

		if (sol == test) {
			cout << "bravo!" << endl;
		}
		else
		{
			cout << "mi dispiace hai perso" <<" la risposta e' :"<< sol  << endl;
		}
	}
	system("pause");
}