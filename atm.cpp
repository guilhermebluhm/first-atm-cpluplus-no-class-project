/*
 * atm.cpp
 *
 *  Created on: Jun 15, 2022
 *      Author: guilhermes
 */
#include <iostream>
#include <string>

using namespace std;

//definição dos metodos
int initial_screen();
void action_atm(int esc);

//variavel global
int saldo_inicial = 0;

int main(){

	int escolha = 0;
	char continuar = 's';

	while(continuar != 'n' ){
		escolha = initial_screen();
		action_atm(escolha);
		cout << "devo continuar[s/n]: ";
		cin >> continuar;
	}
	return 0;
}

int initial_screen(){
	int opcao_tela_inicial = 99;
	while(opcao_tela_inicial < 1 || opcao_tela_inicial > 3){
	cout << "====================" << endl;
	cout << "1 - checar saldo" << endl;
	cout << "2 - fazer deposito" << endl;
	cout << "3 - fazer saque" << endl;
	cout << "====================" << endl;
	cout << "opção: ";
	cin >> opcao_tela_inicial;
	}
	return opcao_tela_inicial;
}

void action_atm(int esc){
	int deposito = 0;
	switch(esc){
	case 1:
		cout << "saldo disponivel na conta = R$ "
		<< saldo_inicial << endl;
		break;
	case 2:
		cout << "valor para deposito: ";
		cin >> deposito;
		while(deposito <= 0){
			cout << "impossivel fazer deposito negativo" << endl;
			cout << "informe uma entrada valida: ";
			cin >> deposito;
		}
		saldo_inicial = deposito;
		break;
	case 3:
		if(saldo_inicial == 0){
			cout << "função indisponivel saldo zerado" << endl;
			break;
		}
		int saque = 0;
		int tentativas_restantes = 2;
		cout << "valor para saque: ";
		cin >> saque;
		while(saque > saldo_inicial){
			if(tentativas_restantes == 0){
				break;
			}
			cout << "informe um valor valido, seu saldo e de R$ "
					<< saldo_inicial
					<< endl;
			cin >> saque;
			if(saque <= saldo_inicial){
				saldo_inicial -= saque;
				break;
			}
			tentativas_restantes-=1;
			cout << "tentativas: " << tentativas_restantes;
		}
	}
}
