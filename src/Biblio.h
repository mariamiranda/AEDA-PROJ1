#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Leitor.h"
#include "Funcionario.h"
#include "Livro.h"
#include "Emprestimo.h"

using namespace std;

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
	string imprime();
	vector<Livro*> getLivros() const;
	vector<Emprestimo*> getEmprestimos() const;
	void setEmprestimos(const vector<Emprestimo*> emprestimos);
	vector<Funcionario*> getFuncionarios() const;
	void setFuncionarios(const vector<Funcionario*> funcionarios);
	vector<Leitor*> getLeitores() const;
	void setLeitores(const vector<Leitor*> leitores);
	vector<Livro*> getLivros() const;
	void setLivros(const vector<Livro*> livros);
};

