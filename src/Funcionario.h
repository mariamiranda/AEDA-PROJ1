
#ifndef SRC_FUNCIONARIO_H_
#define SRC_FUNCIONARIO_H_

class Funcionario {
	std::string nome;
	long ID;
public:
	Funcionario(std::string nom, long id);
	std::string imprime();
	const std::string get_nome();
	void set_nome(std::string nom);
	const long get_ID();
	void set_ID(long id);
};

#endif /* SRC_FUNCIONARIO_H_ */
