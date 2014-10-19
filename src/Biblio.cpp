#include "Biblio.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Emprestimo.h"
using namespace std;


// adicionar Livro a Biblioteca
void Biblioteca::adiciona_livro(Livro* lv){
	livros.push_back(lv);
}

// adicionar Funcionario a Biblioteca
void Biblioteca::adciona_funcionario(Funcionario* fc){
	funcionarios.push_back(fc);
}

// adicionar Leitor a Biblioteca
void Biblioteca::adiciona_leitor(Leitor* lt){
	leitores.push_back(lt);
}

// obter Livro de Emprestimo


// obter Leitor de Emprestimo




// remover Livro da Biblioteca
bool Biblioteca::remove_livro(Livro* lv){
	vector<Livro*> livros_manter{};
	long num_liv=lv->get_numero();
	unsigned int i{0};
	bool encontrado{false};
	while (i<livros.size()){
		if (livros[i]->get_numero()==num_liv){
			encontrado=true;
		}
		else{
			livros_manter.push_back(livros[i]);
		}
		i++;
	}
	if (encontrado) {
		livros=livros_manter;
		return true;
	}
	return false;
}

// remover Funcionario da Biblioteca
bool Biblioteca::remove_funcionario(Funcionario* fc){
	vector<Funcionario*> funcionarios_manter{};
	long num_func=fc->get_numero();
	unsigned int i{0};
	bool encontrado{false};
	while (i<funcionarios.size()){
		if (funcionarios[i]->get_numero()==num_func){
			encontrado=true;
		}
		else{
			funcionarios_manter.push_back(funcionarios[i]);
		}
		i++;
	}
	if (encontrado) {
		funcionarios=funcionarios_manter;
		return true;
	}
	return false;
}

// remover Leitor da Biblioteca
bool Biblioteca::remove_leitor(Leitor* lt){
	vector<Leitor*> leitores_manter{};
	long num_leit=lt->get_numero();
	unsigned int i{0};
	bool encontrado{false};
	while (i<leitores.size()){
		if (leitores[i]->get_numero()==num_leit){
			encontrado=true;
		}
		else{
			leitores_manter.push_back(leitores[i]);
		}
		i++;
	}
	if (encontrado) {
		leitores=leitores_manter;
		return true;
	}
	return false;
}

// numero de livros na Biblioteca
int Biblioteca::num_livros(){
	return livros.size();
}

// numero de funcionarios na Biblioteca
int Biblioteca::num_funcionarios(){
	return funcionarios.size();
}

// numero de leitores na Biblioteca
int Biblioteca::num_leitores(){
	return leitores.size();
}

// numero de emprestimos na Biblioteca
int Biblioteca::num_emprestimos(){
	return emprestimos.size();
}




// adicionar Emprestimo a Biblioteca
void Biblioteca::adiciona_emprestimo(Emprestimo* ep){
	Livro* lv=ep->get_livro();
	Leitor* lt=ep->get_leitor();
	vector<Emprestimo*> ep_lt=lt->get_emp_leit();
	int di=lv->get_dias_indisponivel();
	if (lv->get_emprestado()==false){
		if (ep_lt.size()<3){
			lv->set_emprestado(true);
			lv->set_dias_indisponivel(7);
			lt->adiciona_emp_leit(ep);
			emprestimos.push_back(ep);
		}
		else {
			cout << "Leitor ja tem 3 emprestimos feitos.";
		}
	}
	else {
		cout << "Este livro nao esta disponivel para emprestar. Regressa dentro de " << di << "dias.";
	}
}

// remover Emprestimo da Biblioteca
bool Biblioteca::remove_emprestimo(Emprestimo* ep){
	vector<Emprestimo*> emprestimos_manter{};
	long num_emp=ep->get_numero();
	Livro* lv=ep->get_livro();
	Leitor* lt=ep->get_leitor();
	unsigned int i{0};
	bool encontrado{false};
	while (i<emprestimos.size()){
		if (emprestimos[i]->get_numero()==num_emp){
			encontrado=true;
		}
		else{
			emprestimos_manter.push_back(emprestimos[i]);
		}
		i++;
	}
	if (encontrado) {
		lv->set_emprestado(false);
		lv->set_dias_indisponivel(0);
		lt->remove_emp_leit(ep);
		emprestimos=emprestimos_manter;
		return true;
	}
	return false;
}


