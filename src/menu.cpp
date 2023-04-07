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
		<< "[9] Encerrar\n\n"
		<< "Digite a opcao: ";		
}

bool readOption(char opt, ArvoreBST* bst, bool* fileRead){
	std::string nome;

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
				ll->print();
				break;
			case '3':
				
			case '4':
				
				
				break;
			case '5':
				
			case '6':
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				analysisA(ll);
				break;
			case '7':
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				std::cin.ignore(256, '\n'); 
				std::cout << "Insira o nome do funcionario a ser removido: ";
                std::cin >> nome;
                
				No *n = bst->excluir(nome);
			case '8':
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				saveFile(bst);
				break;
			case '9':
				std::cout << "Encerrando programa...";
				return true;
			default:
				std::cout << "Opcao invalida. Tenta novamente";
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
