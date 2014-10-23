
#ifndef SRC_LEITOR_H_
#define SRC_LEITOR_H_

#include "Emprestimo.h"

class Emprestimo;

class Leitor {
	std::string nome;
	long ID;
	long telefone;
	std::string email;
	std::vector<Emprestimo*> emprestimos_leitor;
public:
	Leitor(std::string nom, long id, long tel, std::string eml, std::vector<Emprestimo*> ep_lt);
	std::string imprime();
	std::string get_nome();
	void set_nome(std::string nom);
	long get_ID();
	void set_ID(int id);
	long get_telefone();
	void set_telefone(long tel);
	std::string get_email();
	void set_email(std::string eml);
	void adiciona_emp_leit(Emprestimo* ep);
	void remove_emp_leit(Emprestimo* ep);
	std::vector<Emprestimo*> get_emp_leit();
};

#endif /* SRC_LEITOR_H_ */
