
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Supervisor.h"

using namespace std;

// construtor Supervisor
Supervisor::Supervisor(long id, string nom, vector<Funcionario*> func_sup):
		Funcionario{id, nom}, funcionarios_sup{func_sup} {}

// obter funcionarios supervisonados
vector<Funcionario*> Supervisor::get_func_sup(){
	return funcionarios_sup;
}

// establecer funcionarios supervisonados
void Supervisor::set_func_sup(vector<Funcionario*> func_sup){
	funcionarios_sup=func_sup;
}

// adicionar funcionario supervisionado
void Supervisor::adiciona_func_sup(Funcionario* fc){
	funcionarios_sup.push_back(fc);
}

// imprimir Supervisor
string Supervisor::imprime(){
	stringstream out{};
	out << "ID: "<< get_ID() << endl
			<< "Nome: " << get_nome() << endl
			<< "ID Funcionarios: ";
	for (vector<Funcionario*>::const_iterator it=funcionarios_sup.begin(); it!=funcionarios_sup.end(); it++){
		out << (*it)->get_ID() << "; ";
	}
	out << endl;
	return out.str();
}


