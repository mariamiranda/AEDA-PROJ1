#include "Supervisor.h"

Supervisor::Supervisor(string nom, int num, vector<Funcionario*> func_sup):
		Funcionario{nom,num}
		{
			funcionarios_sup=func_sup;

		}
