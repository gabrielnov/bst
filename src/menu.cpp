#include "menu.h"

void menu(ArvoreBST* bst){

	char opt;
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
		std::cout << "\n"
        << "[1] Ler dados\n"	
		<< "[2] Analise de dados A\n"
		<< "[3] Analise de dados B\n"
		<< "[4] Analise de dados C\n"
		<< "[5] Analise de dados D\n"
		<< "[6] Analise de dados E\n"
		<< "[7] Remover funcionario\n"
		<< "[8] Salvar dados\n"
		<< "[9] Encerrar\n"
		<< "[0] Imprimir dados (use com cautela)\n\n"
		<< "Digite a opcao: ";		
}

bool readOption(char opt, ArvoreBST* bst, bool* fileRead){
	std::string nome, cargo1, cargo2, unidade1, unidade2;
	No *resp;
	
	switch(opt){
			case '1':
				readFile(bst);
				*fileRead = true;
				break;
			case '2':
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				break;
			case '3':
				std::cin.ignore();
				std::cout << "cargo1 "; std::getline(std::cin, cargo1);
				std::cout << "cargo2 "; std::getline(std::cin, cargo2);
				bst->auxAnalise1(cargo1, cargo2);
				break;
			case '4':
				std::cin.ignore();
				std::cout << "unidade1 "; std::getline(std::cin, unidade1);
				std::cout << "unidade2 "; std::getline(std::cin, unidade2);
				bst->auxAnalise2(unidade1, unidade2);
				break;
			case '5':
				std::cin.ignore();
				bst->auxAnalise3();
				break;
			case '6':
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)" << std::endl;
					break;
				}
				break;
			case '7':
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

			case '8':
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1) " << std::endl;
					break;
				}
				saveFile(bst);
				break;
			case '9':
				std::cout << "Encerrando programa..."<< std::endl;
				return true;
			case '0':
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
