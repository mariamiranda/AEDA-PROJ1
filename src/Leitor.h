#include "Utilities.h"

class Leitor {
	string nome;
	unsigned int numero;
	unsigned int telefone;
	string email;
	vector<Emprestimo*> emprestimos_leitor;
public:
	Leitor(string nom, unsigned int num, unsigned int tel, string eml, vector<Emprestimo*> ep_lt);
	string imprime();
	string get_nome();
	void set_nome(string nom);
	unsigned int get_numero();
	void set_numero(unsigned int num);
	unsigned int get_telefone();
	void set_telefone(unsigned int tel);
	string get_email();
	void set_email(string eml);
	void adiciona_emp_leit(Emprestimo* ep);
	void remove_emp_leit(Emprestimo* ep);
	vector<Emprestimo*> get_emp_leit();
};
