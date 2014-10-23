
#ifndef SRC_EMPRESTIMO_H_
#define SRC_EMPRESTIMO_H_

#include "Livro.h"
#include "Funcionario.h"
#include "Leitor.h"

class Livro;
class Funcionario;
class Leitor;

class Emprestimo {
	long ID;
	Livro* livro;
	Funcionario* funcionario;
	Leitor* leitor;
	std::time_t data; // data em que e feito o emprestimo
public:
	Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt);
	long get_ID();
	void set_ID(int id);
	Livro* get_livro();
	void set_livro(Livro* lv);
	Funcionario* get_funcionario();
	void set_funcionario(Funcionario* fc);
	Leitor* get_leitor();
	void set_leitor(Leitor* lt);
	std::time_t get_data();
	void set_data(std::time_t dt);
	int get_atraso();
	double get_multa();
};

#endif /* SRC_EMPRESTIMO_H_ */
