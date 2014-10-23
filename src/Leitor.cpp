
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Leitor.h"

using namespace std;

// construtor Leitor
Leitor::Leitor(string nom, long id, long tel, string eml, vector<Emprestimo*> ep_lt):
		nome{nom}, ID{id}, telefone{tel}, email{eml}, emprestimos_leitor{ep_lt} {}

// obter ID de Leitor
long Leitor::get_ID(){
	return ID;
}

// adicionar Emprestimo a Leitor
void Leitor::adiciona_emp_leit(Emprestimo* ep){
	emprestimos_leitor.push_back(ep);
}

// remover Emprestimo de Leitor
void Leitor::remove_emp_leit(Emprestimo* ep){
	vector<Emprestimo*> emprestimos_manter{};
	long id_emp=ep->get_ID();
	unsigned int i{0};
	bool encontrado{false};
	while (i<emprestimos_leitor.size()){
		if (emprestimos_leitor[i]->get_ID()==id_emp){
			encontrado=true;
		}
		else{
			emprestimos_manter.push_back(emprestimos_leitor[i]);
		}
		i++;
	}
	if (encontrado) {
		emprestimos_leitor=emprestimos_manter;
	}
}

// obter Emprestimos de Leitor
vector<Emprestimo*> Leitor::get_emp_leit(){
	return emprestimos_leitor;
}

