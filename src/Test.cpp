
#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <fstream>
#include <iostream>
#include <fstream>
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
	vector<string> a1{"Pacheco, Helder"};
	Livro* l1=new Livro{1,"Porto em Azul e Branco",a1,9789723611199,
		"29.90", 192, 1, false, 0};
	vector<string> a2{"Saramago, Jose"};
	Livro* l2=new Livro{2,"O Evangelho Segundo Jesus Cristo",a2,9722105248,
		"821.134.3 SARj/EVA 13", 445, 13, false, 0};
	vector<string> a3{"Couto, Mia"};
	Livro* l3=new Livro{3,"A chuva pasmada",a3,9722116541,
		"821.134.3(679) /COUm/CHU", 74, 1, false, 0};
	vector<string> a4{"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* l4=new Livro{4,"Introduction to automata theory, languages, and computation",a4,201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	b1.adiciona_livro(l1);
	b1.adiciona_livro(l2);
	b1.adiciona_livro(l3);
	b1.adiciona_livro(l4);
	ASSERT_EQUAL(4, b1.get_livros().size());
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
	ASSERT_EQUAL(9, b1.get_funcionarios().size());
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
	b1.escreve_funcionarios();
	ASSERT_EQUAL(b1.promove_funcionario_supervisor(3), true);
	ASSERT_EQUAL(b1.promove_funcionario_supervisor(5), true);
	ASSERT_EQUAL(b1.promove_funcionario_supervisor(10), true);
	ASSERT_EQUAL(b1.promove_funcionario_supervisor(20), false);
	ASSERT_EQUAL(14, b1.get_funcionarios().size());
	ASSERT_EQUAL(3, b1.get_supervisores().size());
	ASSERT_EQUAL(5, (b1.get_supervisores()[0])->get_func_sup().size());
	ASSERT_EQUAL(5, (b1.get_supervisores()[1])->get_func_sup().size());
	ASSERT_EQUAL(4, (b1.get_supervisores()[2])->get_func_sup().size());
	stringstream ss{};
	ss << "ID: 5\n"
			<< "Nome: Margarida Soares\n"
			<< "ID Funcionarios: 2; 7; 11; 14; 17; \n";
	ASSERT_EQUAL(ss.str(), b1.get_supervisores()[1]->imprime());
	b1.escreve_funcionarios();
	b1.escreve_supervisores();
}

void test_h_criar_adicionar_imprimir_escrever_leitor() {
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
	b1.escreve_funcionarios();
	b1.promove_funcionario_supervisor(3);
	b1.promove_funcionario_supervisor(5);
	b1.promove_funcionario_supervisor(10);
	vector<string> a1{"Pacheco, Helder"};
	Livro* lv1=new Livro{1,"Porto em Azul e Branco",a1,9789723611199,
		"29.90", 192, 1, false, 0};
	vector<string> a2{"Saramago, Jose"};
	Livro* lv2=new Livro{2,"O Evangelho Segundo Jesus Cristo",a2,9722105248,
		"821.134.3 SARj/EVA 13", 445, 13, false, 0};
	vector<string> a3{"Couto, Mia"};
	Livro* lv3=new Livro{3,"A chuva pasmada",a3,9722116541,
		"821.134.3(679) /COUm/CHU", 74, 1, false, 0};
	vector<string> a4{"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* lv4=new Livro{4,"Introduction to automata theory, languages, and computation",a4,201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	b1.adiciona_livro(lv1);
	b1.adiciona_livro(lv2);
	b1.adiciona_livro(lv3);
	b1.adiciona_livro(lv4);
	vector<Emprestimo*> emp{};
	Leitor* l1=new Leitor{1,"Ines Cunha", 912233444, "inescunha@fe.up.pt",emp};
	Leitor* l2=new Leitor{2,"Maria Fonseca", 962345444, "mariafonseca@fe.up.pt",emp};
	Leitor* l3=new Leitor{3,"Ana Moura", 912231234, "anamoura@fe.up.pt",emp};
	Leitor* l4=new Leitor{4,"Davide Azevedo", 962234244, "davideazevedo@fe.up.pt",emp};
	Leitor* l5=new Leitor{5,"Pedro Nunes", 912212324, "pedronunes@fe.up.pt",emp};
	Leitor* l6=new Leitor{6,"Joao Meireles", 962232354, "joaomeireles@fe.up.pt",emp};
	Leitor* l7=new Leitor{7,"Alexandre Cunha", 963453442, "alexandrecunha@fe.up.pt",emp};
	Leitor* l8=new Leitor{8,"Andreia Teixeira", 9135634553, "andreiateixeira@fe.up.pt",emp};
	Leitor* l9=new Leitor{9,"Margarida Carvalho", 912234242, "margaridacarvalho@fe.up.pt",emp};
	Leitor* l10=new Leitor{10,"Daniel Pereira", 932233244, "danielpereira@fe.up.pt",emp};
	Leitor* l11=new Leitor{11,"Susana Costa", 912932342, "susanacosta@fe.up.pt",emp};
	Leitor* l12=new Leitor{12,"Jose Leal", 918475657, "joseleal@fe.up.pt",emp};
	Leitor* l13=new Leitor{13,"Roberto Silva", 928374644, "robertosilva@fe.up.pt",emp};
	Leitor* l14=new Leitor{14,"Patricia Ribeiro", 932345994, "patriciaribeiro@fe.up.pt",emp};
	Leitor* l15=new Leitor{15,"Diana Goncalves", 922989898, "dianagoncalves@fe.up.pt",emp};
	Leitor* l16=new Leitor{16,"Vanessa Oliveira", 962233434, "vanessaoliveira@fe.up.pt",emp};
	Leitor* l17=new Leitor{17,"Pedro Almeida", 962253574, "pedroalmeida@fe.up.pt",emp};
	Leitor* l18=new Leitor{18,"Lino Amorim", 912865432, "linoamorim@fe.up.pt",emp};
	Leitor* l19=new Leitor{19,"Jorge Almeida", 912678990, "jorgealmeida@fe.up.pt",emp};
	Leitor* l20=new Leitor{20,"Antonio Vieira", 962256989, "antoniovieira@fe.up.pt",emp};
	Leitor* l21=new Leitor{21,"Sandra Vieira", 962254354, "sandravieira@fe.up.pt",emp};
	Leitor* l22=new Leitor{22,"Bruno Rocha", 937654324, "brunorocha@fe.up.pt",emp};
	Leitor* l23=new Leitor{23,"Viriato Sousa", 928534982, "viriatosousa@fe.up.pt",emp};
	Leitor* l24=new Leitor{24,"Alzira Pinto", 910934899, "alzirapinto@fe.up.pt",emp};
	Leitor* l25=new Leitor{25,"Edmundo Santos", 910998768, "edmundosantos@fe.up.pt",emp};
	Leitor* l26=new Leitor{26,"Maria Mendes", 968748347, "mariamendes@fe.up.pt",emp};
	Leitor* l27=new Leitor{27,"Catarina Pereira", 939838488, "catarinapereira@fe.up.pt",emp};
	Leitor* l28=new Leitor{28,"Luisa Pereira", 928787879, "luisapereira@fe.up.pt",emp};
	Leitor* l29=new Leitor{29,"Nuno Cardoso", 969898239, "nunocardoso@fe.up.pt",emp};
	Leitor* l30=new Leitor{30,"Rita Rio", 919888388, "ritario@fe.up.pt",emp};
	Leitor* l31=new Leitor{31,"Mario Almeida", 932309922, "marioalmeida@fe.up.pt",emp};
	Leitor* l32=new Leitor{32,"Rogerio Cunha", 939999982, "rogeriocunha@fe.up.pt",emp};
	Leitor* l33=new Leitor{33,"Leonor Moreira", 932233444, "leonormoreira@fe.up.pt",emp};
	Leitor* l34=new Leitor{34,"Barbara Furtado", 962233444, "barbarafurtado@fe.up.pt",emp};
	Leitor* l35=new Leitor{35,"Gil Sousa", 962237744, "gilsousa@fe.up.pt",emp};
	Leitor* l36=new Leitor{36,"Manuela Azevedo", 912987689, "manuelaazevedo@fe.up.pt",emp};
	Leitor* l37=new Leitor{37,"Joana Franco", 912382999, "joanafranco@fe.up.pt",emp};
	Leitor* l38=new Leitor{38,"Marco Marques", 968264009, "marcomarques@fe.up.pt",emp};
	Leitor* l39=new Leitor{39,"Filipe Pedro", 938899989, "filipepedro@fe.up.pt",emp};
	b1.adiciona_leitor(l1);
	b1.adiciona_leitor(l2);
	b1.adiciona_leitor(l3);
	b1.adiciona_leitor(l4);
	b1.adiciona_leitor(l5);
	b1.adiciona_leitor(l6);
	b1.adiciona_leitor(l7);
	b1.adiciona_leitor(l8);
	b1.adiciona_leitor(l9);
	b1.adiciona_leitor(l10);
	b1.adiciona_leitor(l11);
	b1.adiciona_leitor(l12);
	b1.adiciona_leitor(l13);
	b1.adiciona_leitor(l14);
	b1.adiciona_leitor(l15);
	b1.adiciona_leitor(l16);
	b1.adiciona_leitor(l17);
	b1.adiciona_leitor(l18);
	b1.adiciona_leitor(l19);
	b1.adiciona_leitor(l20);
	b1.adiciona_leitor(l21);
	b1.adiciona_leitor(l22);
	b1.adiciona_leitor(l23);
	b1.adiciona_leitor(l24);
	b1.adiciona_leitor(l25);
	b1.adiciona_leitor(l26);
	b1.adiciona_leitor(l27);
	b1.adiciona_leitor(l28);
	b1.adiciona_leitor(l29);
	b1.adiciona_leitor(l30);
	b1.adiciona_leitor(l31);
	b1.adiciona_leitor(l32);
	b1.adiciona_leitor(l33);
	b1.adiciona_leitor(l34);
	b1.adiciona_leitor(l35);
	b1.adiciona_leitor(l36);
	b1.adiciona_leitor(l37);
	b1.adiciona_leitor(l38);
	b1.adiciona_leitor(l39);
	ASSERT_EQUAL(39, b1.get_leitores().size());
	cout << b1.imprime();
	b1.escreve();
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
	s.push_back(CUTE(test_h_criar_adicionar_imprimir_escrever_leitor));
	cute::ide_listener lis{};
	cute::makeRunner(lis)(s, "AEDA 2014/2015 - Biblioteca");
}

int main(){
    runSuite();
    return 0;
}




