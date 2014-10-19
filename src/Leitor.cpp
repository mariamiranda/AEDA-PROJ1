#include "Leitor.h"

//contrutor de Leitor
Leitor::Leitor(string nom, unsigned int num, unsigned int tel, string eml, vector<Emprestimo*> ep_lt):
nome{nom}, numero{num}, telefone{tel}, email{eml}, emprestimos_leitor{ep_lt} {}

//obter o numero de Leitor
unsigned int Leitor::get_numero(){
	return numero;
}

//adiciona emprestimo a leitor
void Leitor::adiciona_emp_leit(Emprestimo* ep){
	emprestimos_leitor.push_back(ep);
}

//remove o emprestimo ep do vector emprestimos_leitor
void Leitor::remove_emp_leit(Emprestimo* ep){
	vector<Emprestimo*> emprestimos_manter;
	unsigned int num_emp=ep->get_numero();
	unsigned int i=0;
	bool encontrado{false};
	while (i<emprestimos_leitor.size()){
		if (emprestimos_leitor[i]->get_numero()==num_emp){
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
vector<Emprestimo*> Leitor::get_emp_leit(){
	return emprestimos_leitor;
}
