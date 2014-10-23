
#ifndef SRC_SUPERVISOR_H_
#define SRC_SUPERVISOR_H_

#include "Funcionario.h"

class Funcionario;

class Supervisor: public Funcionario {
	std::vector<Funcionario*> funcionarios_sup;
public:
	Supervisor(std::string nom, long id, std::vector<Funcionario*> func_sup);
	void adiciona_func_sup(Funcionario* fc);
	void set_func_sup(std::vector<Funcionario*> func_sup);
	std::vector<Funcionario*> get_func_sup();
};

#endif /* SRC_SUPERVISOR_H_ */
