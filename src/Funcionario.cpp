
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Funcionario.h"

using namespace std;

// construtor Funcionario
Funcionario::Funcionario(string nom, long id): nome{nom}, ID{id} {}

// obter ID de Funcionario
const long Funcionario::get_ID(){
	return ID;
}

const string Funcionario::get_nome() {
	return nome;
}

void Funcionario::set_nome(const string nom) {
	this->nome = nom;
}

void Funcionario::set_ID(long id) {
	this->ID = id;
}
