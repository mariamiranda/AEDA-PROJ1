/*
 * biblio.h
 *
 *  Created on: 14 Oct 2014
 *      Author: Angie
 */

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Leitor.h"
#include "Funcionario.h"
#include "Livro.h"
#include "Emprestimo.h"

class Biblioteca {
	std::vector<Livro*> livros;
	std::vector<Funcionario*> funcionarios;
	std::vector<Leitor*> leitores;
	std::vector<Emprestimo*> emprestimos;
public:
	void adiciona_livro(Livro* lv1);
	void adciona_funcionario(Funcionario* fc);
	void adiciona_leitor(Leitor* lt);
	void adiciona_emprestimo(Emprestimo* ep);
	bool remove_livro(Livro* lv);
	bool remove_funcionario(Funcionario* fc);
	bool remove_leitor(Leitor* lt);
	bool remove_emprestimo(Emprestimo* ep);
	int num_livros();
	int num_funcionarios();
	int num_leitores();
	int num_emprestimos();
	void aloca_supervisor();
	std::string imprime();
};

