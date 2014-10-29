
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Funcionario.h"

using namespace std;

// construtor Funcionario
Funcionario::Funcionario(long id, string nom): tem_id{id}, nome{nom}{}

// obter nome
string Funcionario::get_nome() {
	return nome;
}

// establecer nome
void Funcionario::set_nome(const string nom) {
	this->nome = nom;
}

// imprimir Funcionario
string Funcionario::imprime(){
	stringstream out{};
	out << "ID: "<< get_ID() << endl
			<< "Nome: " << nome << endl;
	return out.str();
}
