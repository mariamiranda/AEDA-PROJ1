#pragma once
#include "Utilities.h"

class Livro {
	unsigned int numero;
	string titulo;
	vector<string> autores;
	unsigned int ISBN;
	string cota;
	unsigned int num_paginas;
	unsigned int edicao;
	bool emprestado;
	unsigned int dias_indisponivel;
public:
	Livro(unsigned int num, string tit, vector<string> aut, unsigned int isbn, string cot, unsigned int np, unsigned int ed,bool ept, unsigned int di);
	string imprime();
	unsigned int get_numero();
	void set_numero(unsigned int num);
	string get_titulo();
	void set_titulo(string tit);
	vector<string> get_autores();
	void set_autores(vector<string> aut);
	unsigned int get_ISBN();
	void set_ISBN(unsigned int isbn);
	string get_cota();
	void set_cota(string cot);
	unsigned int get_num_paginas();
	void set_num_paginas(unsigned int np);
	unsigned int get_edicao();
	void set_edicao(unsigned int ed);
	bool get_emprestado();
	void set_emprestado(bool ept);
	unsigned int get_dias_indisponivel();
	void set_dias_indisponivel(unsigned int di);
};
