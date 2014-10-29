
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

void runSuite(){
	cute::suite s{};
	//TODO add your test here
	s.push_back(CUTE(test_a_criar_livros));
	s.push_back(CUTE(test_b_adicionar_livros));
	s.push_back(CUTE(test_c_imprimir_livros));
	cute::ide_listener lis{};
	cute::makeRunner(lis)(s, "AEDA 2014/2015 - Biblioteca");
}

int main(){
    runSuite();
    return 0;
}




