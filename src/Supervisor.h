#pragma once
#include "Funcionario.h"
#include "Utilities.h"

class Supervisor: public Funcionario {
	vector<Funcionario*> funcionarios_sup;
public:
	Supervisor(string nome, int numero, vector<Funcionario*> func_sup);
	void adiciona_func_sup(Funcionario fc);
};
