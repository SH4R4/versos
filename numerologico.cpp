#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	cout<<"************************************"<< endl;
	cout<<"* Bem vindo ao jogo da advinhação! *"<< endl;
	cout<<"************************************"<< endl;

	cout << "Defina a dificuldade do jogo: "<< endl;
	cout << "Facil (F), Medio (M) ou Dificil (D)"<< endl;

	char diff;
	cin >> diff;

	int nmax;
	if(diff == 'F') {
		nmax = 15;
	} else if (diff == 'M') {
		nmax = 10;
	} else {
		nmax = 5;
	}

	srand(time(NULL));
	const int NUM_SEC = rand() % 100;

	bool nacertou = true;
	int tentativas;

	double pontos = 1000.0;

	for(tentativas = 1; tentativas <= nmax; tentativas++) {
		cout << "Tentativa " << tentativas << endl;
		int chute;
		cout << "Qual seu chute? ";
		cin >> chute;

		double pperdidos = abs(chute - NUM_SEC)/2.0;
		pontos -= pperdidos;

		cout << "Seu chute foi: " << chute << endl;

		bool acertou = (chute == NUM_SEC);
		bool maior = (chute > NUM_SEC);

		if(acertou) {
			cout << "Parabens, voce acertou o numero secreto!" << endl;
			nacertou = false;
			break;
		} else if(maior) {
			cout << "Seu chute foi maior que o numero a ser descoberto." << endl;
		} else {
			cout << "Seu chute foi menor que o numero a ser descoberto." << endl;
		}
	}

	cout << "Jogo finalizado."<< endl;
	if(nacertou) {
		cout << "Você perdeu, tente novamente."<< endl;
		cout << "O numero secreto era " << NUM_SEC << endl;
	} else {
		cout << "Você precisou de " << tentativas << " tentativas para acertar o numero secreto." << endl;
		cout << "Vejamos..." << endl;
		/*cout.precision(2);
		cout << fixed;*/
		cout << pontos << " bilhões de pontos pra você!" << endl;
	}
}
