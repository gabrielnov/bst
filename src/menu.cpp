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
		<< "[5] Analise D - Analise de funcionario\n"
		<< "[6] Analise E - Distribuicao de salarios\n"
		<< "[7] Remover funcionario\n"
		<< "[8] Salvar dados\n"
		<< "[9] Encerrar\n"
		<< "[0] Imprimir dados (use com cautela)\n\n"
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
				std::cout << "Insira o nome do funcionario a ser analisado: ";
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
				std::cout << "Insira o nome do funcionario a ser removido: ";
                std::getline(std::cin, nome);

				resp = bst->excluir(bst->getRaiz(), nome);

				bst->setRaiz(resp);

				if (resp == NULL)
					std::cout << "A arvore esta vazia!" << std::endl;

				break;

			case 8:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1) " << std::endl;
					break;
				}
				saveFile(bst);
				break;
			case 9:
				std::cout << "Encerrando programa..."<< std::endl;
				return true;
			case 10:
				bst->auxLimpar();
				bst->print();
				break;
			case 0:
				std::cout << "!!! Imprimindo dados. Boa sorte !!! " << std::endl;
				bst->print();

				break;
			return true;
			default:
				std::cout << "Opcao invalida. Tenta novamente"<< std::endl;
		}
	return false;
}

// void lerFuncionario(ArvoreBST *bst){
	
// 	std::string nome, cargo, unidade, salarioBruto;
//     float fSalarioBruto;
//     bool salarioValido = false;

// 	std::cout << " -- Informe os dados do novo funcionario -- " << std::endl;
	
//     std::cout << "Nome: ";
//     std::cin >> nome;

//     std::cout << "\nCargo: ";
//     std::cin >> cargo;

//     std::cout << "\nUnidade: ";
//     std::cin >> nome;
    
//     while (!salarioValido){
//         std::cout << "\nSalario bruto: ";
//         std::cin >> salarioBruto;

//         try{
//             fSalarioBruto = std::stof(salarioBruto);
//             salarioValido = true;
//         }catch( ... ){
//             std::cout << "\nSalario invalido, tente novamente!";
//         }
//     }
    
// 	Pessoa* p = new Pessoa(cargo, unidade, fSalarioBruto);
	
//     bst->inserir(nome, p);
	
// }
