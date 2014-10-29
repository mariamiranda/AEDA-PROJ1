
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Funcionario.h"

using namespace std;

// construtor Funcionario
Funcionario::Funcionario(long id, string nom): tem_id{id}, nome{nom}{}

const string Funcionario::get_nome() {
	return nome;
}

void Funcionario::set_nome(const string nom) {
	this->nome = nom;
}

