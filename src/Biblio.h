
#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_

#include "Supervisor.h"
#include "Emprestimo.h"

class Livro;
class Funcionario;
class Supervisor;
class Leitor;
class Emprestimo;

class Biblioteca {
	std::vector<Livro*> livros;
	std::vector<Funcionario*> funcionarios;
	std::vector<Supervisor*> supervisores; // os supervisores nao estao no vector de funcionarios
	std::vector<Leitor*> leitores;
	std::vector<Emprestimo*> emprestimos;
public:
	void adiciona_livro(Livro* lv1);
	void adciona_funcionario(Funcionario* fc);
	void adiciona_leitor(Leitor* lt);
	void adiciona_emprestimo(Emprestimo* ep);
	bool remove_livro(long id);
	bool remove_funcionario(long id);
	bool remove_leitor(long id);
	bool remove_emprestimo(long id);
	int num_livros();
	int num_funcionarios();
	int num_leitores();
	int num_emprestimos();
	void aloca_funcionario_supervisor(); // nao implementei esta
	void distribui_funcionarios();
	bool promove_funcionorario_supervisor(long ID);
	bool remove_supervisor(long ID);
	bool despromove_supervisor_funcionorario(long id);
	std::string imprime();
	std::vector<Emprestimo*> get_emprestimos_atrasados();
	std::vector<Livro*> get_livros() const;
	std::vector<Emprestimo*> get_emprestimos() const;
	void set_emprestimos(const std::vector<Emprestimo*> emprestimos);
	std::vector<Funcionario*> get_funcionarios() const;
	void set_funcionarios(const std::vector<Funcionario*> funcionarios);
	std::vector<Leitor*> get_leitores() const;
	void set_leitores(const std::vector<Leitor*> leitores);
	void set_livros(const std::vector<Livro*> livros);
};

#endif /* SRC_BIBLIOTECA_H_ */
