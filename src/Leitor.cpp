#include "Leitor.h"

//contrutor de Leitor
Leitor::Leitor(string nom, unsigned int num, unsigned int tel, string eml, vector<unsigned int> ep_lt):
nome{nom}, numero{num}, telefone{tel}, email{eml}, emprestimos_leitor{ep_lt} {}

//obter o numero de Leitor
unsigned int Leitor::get_numero(){
	return numero;
}

//adiciona emprestimo a leitor
void Leitor::adiciona_emp_leit(unsigned int ep){
	emprestimos_leitor.push_back(ep);
}

//remove o emprestimo ep do vector emprestimos_leitor
void Leitor::remove_emp_leit(unsigned int ep){
	vector<unsigned int> emprestimos_manter;
	unsigned int i=0;
	bool encontrado{false};
	while (i<emprestimos_leitor.size()){
		if (emprestimos_leitor[i] == ep){
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

//retorna o vector de emprestimos de leitos
vector<unsigned int> Leitor::get_emp_leit(){
	return emprestimos_leitor;
}
