#pragma once
#include "Utilities.h"
#include "Livro.h"
#include "Funcionario.h"
#include "Leitor.h"

class Emprestimo {
	unsigned int numero;
	Livro* livro;
	Funcionario* funcionario
	unsigned int data_entrega;
	Leitor* leitor;

public:
	Emprestimo(unsigned int num, Livro* lv, Funcionario* fc, Leitor* lt, unsigned int dt);
	unsigned int get_numero();
	void set_numero(int num);
	Livro* get_livro();
	void set_livro(Livro* lv);
	Funcionario* get_funcionario();
	void set_funcionario(Funcionario* fc);
	Leitor* get_leitor();
	void set_leitor(Leitor* lt);
	unsigned int get_data();
	void set_data(int dt);
};

