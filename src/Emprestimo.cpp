
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>

#include "Emprestimo.h"

using namespace std;

// construtor Emprestimo
Emprestimo::Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt): tem_id{id},
		livro{lv}, funcionario{fc}, leitor{lt}, data{std::time(NULL)}{}

// obter Livro de Emprestimo
Livro* Emprestimo::get_livro(){
	return livro;
}

// obter Leitor de Emprestimo
Leitor* Emprestimo::get_leitor(){
	return leitor;
}

// obter data de Emprestimo
time_t Emprestimo::get_data(){
	return data;
}

// obter atraso na entrega de Emprestimo
int Emprestimo::get_atraso(){
	time_t hoje = std::time(NULL);
	double tempo_dias{floor(difftime(hoje,data)/86400)};
	double tempo_extra{min(tempo_dias-7,0.0)};
	return (int) tempo_extra;
}

// obter multa na entraga de Emprestimo
double Emprestimo::get_multa(){
	int tempo_extra=get_atraso();
	int tempo_extra_extra{min(tempo_extra-7,0)};
	double divida{tempo_extra*0.25+tempo_extra_extra*0.5};
	return divida;
}

// imprimir Emprestimo
string Emprestimo::imprime(){
	stringstream out{};
	out << "ID: "<< get_ID() << endl
			<< "ID Livro: " << livro->get_ID() << endl
			<< "ID Funcionario: " << funcionario->get_ID() << endl
			<<"Data: " << data << endl;
	return out.str();
}
