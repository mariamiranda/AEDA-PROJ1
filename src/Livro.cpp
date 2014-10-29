
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Livro.h"

using namespace std;

// construtor Livro
Livro::Livro(long id, string tit, vector<string> aut, long isbn, string cot, int np, int ed, bool ept, int di):
		tem_id{id}, titulo{tit}, autores{aut}, ISBN{isbn}, cota{cot}, num_paginas{np}, edicao{ed},
		emprestado{ept}, dias_indisponivel{di} {}

// modificar estado emprestado de Livro
void Livro::set_emprestado(bool ept){
	emprestado=ept;
}

// modificar dias de indisponibilidade de Livro
void Livro::set_dias_indisponivel(int di){
	dias_indisponivel=di;
}

//obter emprestado de Livro
bool Livro::get_emprestado(){
	return emprestado;
}

//obter emprestado de Livro
int Livro::get_dias_indisponivel(){
	return dias_indisponivel;
}


