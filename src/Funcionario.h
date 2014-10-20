#pragma once
#include "Utilities.h"
using namespace std;

class Funcionario {
private:
	string nome;
	unsigned int numero;
public:
	Funcionario();
	Funcionario(string nome, int numero);
	string imprime();
	string get_nome();
	void set_nome(string nome);
	unsigned int get_numero();
	void set_numero(int numero);

	const string& getNome() const {
		return nome;
	}

	void setNome(const string& nome) {
		this->nome = nome;
	}

	unsigned int getNumero() const {
		return numero;
	}

	void setNumero(unsigned int numero) {
		this->numero = numero;
	}
};

