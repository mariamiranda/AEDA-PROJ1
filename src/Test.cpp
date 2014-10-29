
#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <fstream>
#include <iostream>
#include "Biblio.h"

using namespace std;

void test_a_criar_livros() {
	//ID, titulo, autores, ISBN, cota, num_paginas, edicao, emprestado, dias_indisponivel
	vector<string> a1{"Saramago, Jose"};
	Livro* l1=new Livro{1,"O Evangelho Segundo Jesus Cristo",a1,9722105248,
		"821.134.3 SARj/EVA 13", 445, 13, false, 0};
	vector<string> a2{"Couto, Mia"};
	Livro* l2=new Livro{2,"A chuva pasmada",a2,9722116541,
		"821.134.3(679) /COUm/CHU", 74, 1, false, 0};
	vector<string> a3{"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* l3=new Livro{3,"Introduction to automata theory, languages, and computation",a3,201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	ASSERT_EQUAL("O Evangelho Segundo Jesus Cristo", l1->get_titulo());
	ASSERT_EQUAL(2, l2->get_ID());
	ASSERT_EQUAL(201441241,l3->get_ISBN());
	ASSERT_EQUAL("519.6 /HOPj/INT 2",l3->get_cota());
	ASSERT_EQUAL(74, l2->get_num_paginas());
	ASSERT_EQUAL(13, l1->get_edicao());
	ASSERT_EQUAL("Motwani, Rajeev", l3->get_autores()[1]);
	ASSERT_EQUAL(false, l2->get_emprestado());
	ASSERT_EQUAL(0,l1->get_dias_indisponivel());
}

void test_b_adicionar_livros() {
	Biblioteca b1{};
	vector<string> a1{"Saramago, Jose"};
	Livro* l1=new Livro{1,"O Evangelho Segundo Jesus Cristo",a1,9722105248,
		"821.134.3 SARj/EVA 13", 445, 13, false, 0};
	vector<string> a2{"Couto, Mia"};
	Livro* l2=new Livro{2,"A chuva pasmada",a2,9722116541,
		"821.134.3(679) /COUm/CHU", 74, 1, false, 0};
	vector<string> a3{"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* l3=new Livro{3,"Introduction to automata theory, languages, and computation",a3,201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	b1.adiciona_livro(l1);
	b1.adiciona_livro(l2);
	b1.adiciona_livro(l3);
	ASSERT_EQUAL(3, b1.num_livros());
}

void test_c_imprimir_livros(){
	vector<string> a3{"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* l3=new Livro{3,"Introduction to automata theory, languages, and computation",a3,201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	stringstream ss{};
	ss << "ID: 3\n"
			<< "Titulo: Introduction to automata theory, languages, and computation\n"
			<< "Autores: Hopcroft, John E.; Motwani, Rajeev; Ullman, Jeffrey D.; \n"
			<< "ISBN: 201441241\n"
			<< "Cota: 519.6 /HOPj/INT 2\n"
			<< "Num. Paginas: 521\n"
			<< "Edicao: 2\n"
			<< "Emprestado: 0\n"
			<< "Dias Indisponibilidade: 0\n";
	cout << l3->imprime();
	ASSERT_EQUAL(ss.str(), l3->imprime());
}

void test_d_criar_funcionarios() {
	//ID, nome
	Funcionario* f1=new Funcionario{1,"Miguel Bacelar"};
	Funcionario* f2=new Funcionario{2,"Jose Oliveira"};
	Funcionario* f3=new Funcionario{3,"Carlos Alvim"};
	Funcionario* f4=new Funcionario{4,"Fatima Bordonhos"};
	ASSERT_EQUAL(1, f1->get_ID());
	ASSERT_EQUAL(2, f2->get_ID());
	ASSERT_EQUAL("Carlos Alvim",f3->get_nome());
	ASSERT_EQUAL("Fatima Bordonhos",f4->get_nome());
}

void test_e_adicionar_funcionarios() {
	Biblioteca b1{};
	Funcionario* f1=new Funcionario{1,"Miguel Bacelar"};
	Funcionario* f2=new Funcionario{2,"Jose Oliveira"};
	Funcionario* f3=new Funcionario{3,"Carlos Alvim"};
	Funcionario* f4=new Funcionario{4,"Fatima Bordonhos"};
	Funcionario* f5=new Funcionario{5,"Margarida Soares"};
	Funcionario* f6=new Funcionario{6,"Joana Rocha"};
	Funcionario* f7=new Funcionario{7,"Alexandra Lameira"};
	Funcionario* f8=new Funcionario{8,"Luis Barros"};
	Funcionario* f9=new Funcionario{9,"Angela Monteiro"};
	b1.adiciona_funcionario(f1);
	b1.adiciona_funcionario(f2);
	b1.adiciona_funcionario(f3);
	b1.adiciona_funcionario(f4);
	b1.adiciona_funcionario(f5);
	b1.adiciona_funcionario(f6);
	b1.adiciona_funcionario(f7);
	b1.adiciona_funcionario(f8);
	b1.adiciona_funcionario(f9);
	ASSERT_EQUAL(9, b1.num_funcionarios());
}

void test_f_imprimir_funcionarios(){
	Funcionario* f8=new Funcionario{8,"Luis Barros"};
	stringstream ss{};
	ss << "ID: 8\n"
			<< "Nome: Luis Barros\n";
	cout << f8->imprime();
	ASSERT_EQUAL(ss.str(), f8->imprime());
}

void test_g_promover_funcionarios() {
	Biblioteca b1{};
	Funcionario* f1=new Funcionario{1,"Miguel Bacelar"};
	Funcionario* f2=new Funcionario{2,"Jose Oliveira"};
	Funcionario* f3=new Funcionario{3,"Carlos Alvim"};
	Funcionario* f4=new Funcionario{4,"Fatima Bordonhos"};
	Funcionario* f5=new Funcionario{5,"Margarida Soares"};
	Funcionario* f6=new Funcionario{6,"Joana Rocha"};
	Funcionario* f7=new Funcionario{7,"Alexandra Lameira"};
	Funcionario* f8=new Funcionario{8,"Luis Barros"};
	Funcionario* f9=new Funcionario{9,"Angela Monteiro"};
	Funcionario* f10=new Funcionario{10,"Andre Martins"};
	Funcionario* f11=new Funcionario{11,"Celia Ferreira"};
	Funcionario* f12=new Funcionario{12,"Hortensia Costa"};
	Funcionario* f13=new Funcionario{13,"Helia Costa"};
	Funcionario* f14=new Funcionario{14,"Maria Sousa"};
	Funcionario* f15=new Funcionario{15,"Sergio Dias"};
	Funcionario* f16=new Funcionario{16,"Isabel Pinto"};
	Funcionario* f17=new Funcionario{17,"Lara Lacerda"};
	b1.adiciona_funcionario(f1);
	b1.adiciona_funcionario(f2);
	b1.adiciona_funcionario(f3);
	b1.adiciona_funcionario(f4);
	b1.adiciona_funcionario(f5);
	b1.adiciona_funcionario(f6);
	b1.adiciona_funcionario(f7);
	b1.adiciona_funcionario(f8);
	b1.adiciona_funcionario(f9);
	b1.adiciona_funcionario(f10);
	b1.adiciona_funcionario(f11);
	b1.adiciona_funcionario(f12);
	b1.adiciona_funcionario(f13);
	b1.adiciona_funcionario(f14);
	b1.adiciona_funcionario(f15);
	b1.adiciona_funcionario(f16);
	b1.adiciona_funcionario(f17);
	ASSERT_EQUAL(b1.promove_funcionario_supervisor(3), true);
	ASSERT_EQUAL(b1.promove_funcionario_supervisor(5), true);
	ASSERT_EQUAL(b1.promove_funcionario_supervisor(10), true);
	ASSERT_EQUAL(b1.promove_funcionario_supervisor(20), false);
	ASSERT_EQUAL(14, b1.num_funcionarios());
	ASSERT_EQUAL(3, b1.num_supervisores());
	ASSERT_EQUAL(5, (b1.get_supervisores()[0])->get_func_sup().size());
	ASSERT_EQUAL(5, (b1.get_supervisores()[1])->get_func_sup().size());
	ASSERT_EQUAL(4, (b1.get_supervisores()[2])->get_func_sup().size());
	stringstream ss{};
	ss << "ID: 5\n"
			<< "Nome: Margarida Soares\n"
			<< "ID Funcionarios: 2; 7; 11; 14; 17; \n";
	ASSERT_EQUAL(ss.str(), b1.get_supervisores()[1]->imprime());
}

void runSuite(){
	cute::suite s{};
	//TODO add your test here
	s.push_back(CUTE(test_a_criar_livros));
	s.push_back(CUTE(test_b_adicionar_livros));
	s.push_back(CUTE(test_c_imprimir_livros));
	s.push_back(CUTE(test_d_criar_funcionarios));
	s.push_back(CUTE(test_e_adicionar_funcionarios));
	s.push_back(CUTE(test_f_imprimir_funcionarios));
	s.push_back(CUTE(test_g_promover_funcionarios));
	cute::ide_listener lis{};
	cute::makeRunner(lis)(s, "AEDA 2014/2015 - Biblioteca");
}

int main(){
    runSuite();
    return 0;
}




