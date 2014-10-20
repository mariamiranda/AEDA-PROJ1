#pragma once
#include "Utilities.h"

class Leitor {
	string nome;
	unsigned int numero;
	unsigned int telefone;
	string email;
	vector<unsigned int> emprestimos_leitor;
public:
	Leitor(string nom, unsigned int num, unsigned int tel, string eml, vector<unsigned int> ep_lt);
	string imprime();
	string get_nome();
	void set_nome(string nom);
	unsigned int get_numero();
	void set_numero(unsigned int num);
	unsigned int get_telefone();
	void set_telefone(unsigned int tel);
	string get_email();
	void set_email(string eml);
	void adiciona_emp_leit(unsigned int ep);
	void remove_emp_leit(unsigned int ep);
	vector<unsigned int> get_emp_leit();
};
