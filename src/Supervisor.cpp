
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
