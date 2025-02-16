#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

const string PALSEC = "acido nitrico";
map <char, bool> chutou;
vector<char> churros;

bool letex(char chute) {
	for (char letra : PALSEC) {
		if (chute == letra) {
			return true;
		}
	}
	return false;
}

bool na() {
	for (char letra : PALSEC) {
		if (!chutou[letra]) {
			return true;
		}
	}
	return false;
}
bool nf() {
	return churros.size() < 5;
}

void impra() {
	cout << "*****************" << endl;
	cout << "* Jogo da forca *" << endl;
	cout << "*****************" << endl;
	cout << endl;
}

void oracas(){
    cout << "Chutes errados: ";
		for (char letra : churros) {
		cout << letra << " ";
		}
		cout << endl;
}
void charas(){
    	for (char letra : PALSEC) {
			if (chutou[letra]) {
				cout << letra << " ";
			} else {
				cout << "_ ";
			}
		}
		cout << endl;
}
void maracas(){
    cout << " Seu chute: ";
		char chute;
		cin >> chute;

		chutou[chute] = true;

		if (letex(chute)) {
			cout << "Seu chute esta na palavra." << endl;
		} else {
			cout << "Seu chute nao esta na palavra." << endl;
			churros.push_back(chute);
		}
		cout << endl;
}

int main() {
    impra();

	for (char letra : PALSEC) {
		if (letra == ' ') {
			chutou[letra] = true;
		}
	}

	while (na() && nf()) {
    oracas();
    charas();
    maracas();
	}

	cout << "fim de jogo." << endl;
	cout << "a palavra era " << PALSEC << endl;
	if (!na()) {
		cout << "Parabens, voce venceu a forca!" << endl;
	} else {
		cout << "Voce perdeu, tente novamente." << endl;
	}
}