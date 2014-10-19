#include "Funcionario.h"

Funcionario::Funcionario()
{
	this->numero=0;
	this->nome="";
}

Funcionario::Funcionario(string nome, int numero)
{
	this->nome = nome;
	this->numero = numero;
}


//retorna o numero do Funcionario
unsigned int Funcionario::get_numero(){
	return numero;
}



