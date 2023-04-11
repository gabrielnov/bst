#include "menu.h"

void menu(ArvoreBST* bst){

	int opt;
	bool exit = false;
	bool* fileRead = new bool(false);
	
	while (!exit){
		printMenu();
		std::cin >> opt;
		exit = readOption(opt, bst, fileRead);
	}
	
	delete fileRead;
	fileRead = nullptr;
}

void printMenu(){
		std::cout << "\n\n"
        << "[1] Ler dados\n"	
		<< "[2] Analise A - Comparar cargos\n"
		<< "[3] Analise B - Analise de unidades\n"
		<< "[4] Analise C - Estatisticas gerais\n"
		<< "[5] Analise D - Analise de funcionario(a)\n"
		<< "[6] Analise E - Distribuicao de salarios\n"
		<< "[7] Remover funcionario(a)\n"
		<< "[8] Salvar dados\n"
		<< "[9] Limpar a arvore\n"
		<< "[0] Encerrar\n\n"
		<< "Digite a opcao: ";		
}

bool readOption(int opt, ArvoreBST* bst, bool* fileRead){
	std::string nome, cargo1, cargo2, unidade1, unidade2;
	No *resp;
	
	switch(opt){
			case 1:
				readFile(bst);
				*fileRead = true;
				break;
			case 2:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				std::cin.ignore();
				std::cout << "Primeiro cargo: "; std::getline(std::cin, cargo1);
				std::cout << "Segundo cargo: "; std::getline(std::cin, cargo2);
				bst->auxAnalise1(cargo1, cargo2);
				break;
			case 3:
			if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				std::cin.ignore();
				std::cout << "Primeira unidade: "; std::getline(std::cin, unidade1);
				std::cout << "Segunda unidade: "; std::getline(std::cin, unidade2);
				bst->auxAnalise2(unidade1, unidade2);
				break;
			case 4:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				std::cin.ignore();
				bst->auxAnalise3();
				break;
			case 5:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				std::cin.ignore(256, '\n'); 
				std::cout << "Insira o nome do funcionario(a) a ser analisado: ";
                std::getline(std::cin, nome);
				bst->analise4(bst->getRaiz(), nome);
				break;
			case 6:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)" << std::endl;
					break;
				}
				plot(bst);
				break;
			case 7:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)" << std::endl;
					break;
				}
				std::cin.ignore(256, '\n'); 
				std::cout << "Insira o nome do(a) funcionario(a) a ser removido: ";
                std::getline(std::cin, nome);

				resp = bst->excluir(bst->getRaiz(), nome);

				bst->setRaiz(resp);

				if (resp == NULL)
					std::cout << "A arvore esta vazia!" << std::endl;
				else
					std::cout << "funcionario(a) " << nome << " removido(a) com sucesso!" << std::endl;
				break;

			case 8:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1) " << std::endl;
					break;
				}
				saveFile(bst);
				break;
			case 9:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1) " << std::endl;
					break;
				}
				bst->auxLimpar();
				std::cout << "Arvore limpa com sucesso!" << std::endl;
				break;
			case 0:
				std::cout << "Encerrando programa..."<< std::endl;
				return true;
			
			default:
				std::cout << "Opcao invalida. Tenta novamente"<< std::endl;
		}
	return false;
}
