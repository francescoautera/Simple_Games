
#include <iostream>
#include<vector>
#include"Monster.h"
#include"Goblin.h"
#include"Ghoul.h"
#include"Orc.h"
#include<cstdlib>
#include<ctime>
#include"Windows.h"
#include<random>
#include<chrono>


using namespace std;

const int LivelloFame = 5;
const int LivelloSalute = 5;
const int LivelloFelicità = 5;
int oro = 20;
int cibo = 10;
const int MaxEvents = 4;
const int prezzo_cibo = 3;
const int prezzo_oggetti = 3;
int oggetti = 2;
bool playerTurn = false;
bool isFinish = false;

vector<Monster*> monster;
vector<Monster*> marketPlace;


void Init() {
    
    Monster* en1 = new Orc("Franco");
    Monster* en2 = new Goblin("Gianni");
    Monster* en3 = new Ghoul("Giovanni");
    monster.push_back(en1);
    monster.push_back(en2);
    monster.push_back(en3);
    Monster* slv1 = new Orc("Graham");
    Monster* slv2 = new Goblin("Gonzalez");
    Monster* slv3 = new Ghoul("n'acthoul");
    Monster* slv4 = new Orc("Adalberto");
    Monster* slv5 = new Goblin("Julia");
    Monster* slv6 = new Ghoul("in t'hu ");
    marketPlace.push_back(slv1);
    marketPlace.push_back(slv2);
    marketPlace.push_back(slv3);
    marketPlace.push_back(slv4);
    marketPlace.push_back(slv5);
    marketPlace.push_back(slv6);
}


void DisplayMarket() {

    for (int i = 0; i < marketPlace.size(); i++) {
        cout << i << " " << marketPlace[i]->name + " " + marketPlace[i]->GetRace() << "  " << marketPlace[i]->GetPrice() << endl;
        cout << "\n";
    }
}

void DisplayMonster() {

    for (int i = 0; i < monster.size(); i++) {
        cout << monster[i]->name << "  " << monster[i]->GetRace() << "  " << monster[i]->lvFame << "  " << monster[i]->lvFel <<  "  " << monster[i]->lvSalute << endl;
    }
}


bool BuyMonster() {
    if (marketPlace.size() == 0) {
        cout << "hai comprato tutti i mostri" << endl;
        return false;
    }
    else {
        DisplayMarket();

        int choice;
        cout << "\n Quale mostro vuoi acquistare: indica il numero"<<endl;
        cin >> choice;
        if (choice > marketPlace.size() || choice < 0) {
            cout << "\n numero errato"<<endl;
            return false;
        }
        else if (marketPlace[choice]->GetPrice() > oro) {
            cout << "\n quantita' oro insufficiente" << endl;
            return false;
        }
        else {
            oro = oro- marketPlace[choice]->GetPrice();
            monster.push_back(marketPlace[choice]);
            marketPlace.erase(marketPlace.begin() + choice);
            cout << " \n oro rimasto " << oro << endl;
            return true;
        }
    }
}

bool BuyFood() {
    int x;
    cout << "quanto cibo vuoi acquistare";
    cin >> x;
    if (oro == 0 || oro < (prezzo_cibo * x)) {
        cout << "\n non puoi permetterti tutto questo cibo" << endl;
        return false;
    }
    cibo += x;
    oro = oro - (prezzo_oggetti * x);
    return true;
}

bool SellObject() {
    int x;
    cout << "quanti oggetti vuoi vendere";
    cin >> x;
    if (oggetti == 0 || oggetti < x) {
        cout << "\n non puoi vendere cio che non hai" << endl;
        return false;
    }
    oggetti -= x;
    oro = oro + (prezzo_oggetti * x);
    return true;
}

void DisplayRisorse() {
    cout << "\n oro rimasto : " << oro << endl;
    cout << "\ncibo rimasto : " << cibo << endl;
    cout << "\noggetti rimasti : " << oggetti << endl;
}

void DestroyAll() {
    for (int i = 0; i < marketPlace.size(); i++) {
        delete marketPlace[i];
    }
    for (int i = 0; i < monster.size(); i++) {
        delete monster[i];
       
    }

}

void PlayerTurn() {
    int choice;
    playerTurn = false;
    DisplayRisorse();
    while (!playerTurn) {
        cout << "\n cosa vuoi fare: compra cibo(0), compra mostri(1), vendi oggetti(2), vedi i tuoi mostri(3)";
        cin >> choice;
        switch (choice)
        {
        case 0:
            playerTurn = BuyFood();
            continue;
        case 1:
            playerTurn = BuyMonster();
            continue;
        case 2:
            playerTurn = SellObject();
            continue;
        case 3:
             DisplayMonster();
             continue;
        default:
            DisplayMonster();
            continue;
        }

    }

    DisplayRisorse();
    cout << "\n" << endl;
    DisplayMonster();
}


void MonsterTurn() {
    for (int i = 0; i < monster.size(); i++) {
        Sleep(500);
        if (monster[i]->isdead) {
            monster.erase(monster.begin() + i);
            
        }
        if (monster[i]->lvFame == "Aggressivo" || monster[i]->lvSalute == "Debole") {
            cout << monster[i]->name + "sta mangiando" << endl;
            monster[i]->Eat();
        }
        else if (monster[i]->lvFame == "Aggressivo" || (monster[i]->lvSalute == "Forte" && monster[i]->lvFel == "Attivo")) {
            cout << monster[i]->name + "sta per attaccare" << endl;
            int en = rand() % monster.size();
            cout << monster[i]->name + "sta per attaccare " + monster[en]->name  << endl;
            monster[i]->Attack(*monster[en]);
        }
        else if (monster[i]->lvFel == "Attivo" && monster[i]->lvSalute == "Forte" && monster[i]->lvFame == "Pacifico") {
            
            bool done = false;
            while (!done) {
                int y = rand() % monster.size();
                if (i != y) {
                    if (monster[i]->GetRace() == monster[y]->GetRace()) {
                        int x = rand() % 2;
                        if (x == 1) {
                            if (monster[i]->GetRace() == "Orc") { Monster* figlio = new Orc("franchino"); }
                            else if (monster[i]->GetRace() == "Goblin") { Monster* figlio = new Goblin("pe'conoscessi"); }
                            else if (monster[i]->GetRace() == "Ghoul") { Monster* figlio = new Ghoul("giorno_Giovanna"); }
                        }
                        else { cout << "\n putroppo non e' andata bene "; }
                    }
                    else {
                        int x = rand() % 100;
                        if (x == 42) {
                            if (monster[i]->GetRace() == "Orc") { Monster* figlio = new Orc("Belzebu"); }
                            else if (monster[i]->GetRace() == "Goblin") { Monster* figlio = new Goblin("Artorias"); }
                            else if (monster[i]->GetRace() == "Ghoul") { Monster* figlio = new Ghoul("Tokyo"); }
                        }
                        else { cout << "\n putroppo non e' andata bene "; }
                    }
                    done = true;
                    continue;
                }
                else {
                    done = false;
                    continue;
                }
            }

        }
        int move = rand() % MaxEvents;
        if (move < MaxEvents ) {

            if (monster[i]->GetRace() == "Orc") {
                int en = rand() % monster.size();
                monster[i]->Action(*monster[en]);
                if (oggetti > 0) { oggetti--; }
            }
            else if (monster[i]->GetRace() == "Goblin") {
                int j = 0;
                while (monster[j]->GetRace() != "Ghoul" && j < monster.size()) {
                    j++;
                }
                monster[i]->Action(*monster[j]);
                oggetti++;
            }
            else if (monster[i]->GetRace() == "Ghoul") {
                int en = rand() % monster.size();
                monster[i]->Action(*monster[en]);

            }
        }
        monster[i]->Check(LivelloFame,LivelloSalute,LivelloFelicità);
    }
           
    }

void Shuffle() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(monster.begin(), monster.end(), default_random_engine(seed));
}

int main(){

    srand(time(0));
    Init();
    while (!isFinish) {
        if (oro == 0 && monster.size() == 0 && oggetti == 0) {
            isFinish = true;
            continue;
        }
        cout << "vuoi uscire dalla partita? : press (y/n)";
        char finish;
        cin >> finish;
        
        if (finish == 'y') {
            isFinish = true;
            continue;
        }
        else {
            PlayerTurn();
            cout << "\n Monster_turn" << endl;
            Shuffle();
            MonsterTurn();
        }
    }
    
    DestroyAll();
    
}
