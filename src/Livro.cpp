#include "Livro.h"

//constructor de Livro
Livro::Livro(unsigned int num, string tit, vector<string> aut, unsigned int isbn, string cot, unsigned int np, unsigned int ed, bool ept, unsigned int di):
numero{num}, titulo{tit}, autores{aut}, ISBN{isbn}, cota{cot}, num_paginas{np}, edicao{ed},
emprestado{ept}, dias_indisponivel{di} {}


//obter numero de livro
unsigned int Livro::get_numero(){
	return numero;
}

//modificar estado emprestado de livro, true/false
void Livro::set_emprestado(bool ept){
	emprestado=ept;
}

// modificar dias de indisponibilidade de Livro
void Livro::set_dias_indisponivel(unsigned int di){
	dias_indisponivel=di;
}

//verifica se livro está ou nao emprestado
bool Livro::get_emprestado(){
	return emprestado;
}


unsigned int Livro::get_dias_indisponivel(){
	return dias_indisponivel;
}
