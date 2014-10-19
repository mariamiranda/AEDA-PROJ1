#ifndef Funcionario_H
#define Funcionario_H
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
};

#endif
