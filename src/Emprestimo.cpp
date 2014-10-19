#include "Emprestimo.h"

Emprestimo::Emprestimo(unsigned int num, Livro* lv, Funcionario* fc, Leitor* lt, unsigned int dt):
numero{num}, livro{lv}, funcionario{fc}, leitor{lt}, data_entrega{dt} {}


//retorna o numero do emprestimo
unsigned int Emprestimo::get_numero(){
	return numero;
}

//retorna o livro
Livro* Emprestimo::get_livro(){
	return livro;
}

//obter o leitor de emprestimo
Leitor* Emprestimo::get_leitor(){
	return leitor;
}

