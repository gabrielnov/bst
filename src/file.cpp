#include "file.h"

void readFile(ArvoreBST *bst){
    // TODO limpar a arvore antes de ler
	std::string nome, cargoBase, cargoComissao, unidade, caminho;
    float salarioBruto;

	std::cout << "Informe o caminho do arquivo a ser lido: ";
	std::cin >> caminho;

	std::cout << "abrindo arquivo " << caminho << "... " << std::endl;

	std::fstream f;
    f.open(caminho, std::ios::in); 
    
	// verificamos se o arquivo realmente existe
	if (!f){
		std::cout << "!!! O arquivo informado nao existe. Tente novamente. !!!" << std::endl;
		readFile(bst);
	}

    std::string line;
	std::string* stringArray = new std::string[13];

	std::cout << "lendo linhas do arquivo " << caminho << "... " << std::endl;

    getline(f, line);

    if (f.is_open()){
	    while(getline(f, line) && line != ""){
	    	
	    	substring(line, stringArray);
			
			nome = stringArray[1];
			cargoBase = stringArray[2];
			cargoComissao = stringArray[2];
			
			if (cargoBase == " "){
				cargoBase = "sem cargo base";
			}
			if (cargoComissao == " "){
				cargoComissao = "sem cargo base";
			}

			//algumas linhas possuem o valor em branco ou inválido, isso causa exceção na conversão
			try{
				salarioBruto = std::stof(stringArray[6]);
			} 
			catch( ... ){
				salarioBruto = 0.0;
			}
			
			unidade = stringArray[7];

	    	Pessoa * p = new Pessoa(cargoBase, cargoComissao, unidade, salarioBruto);
	    	
			bst->inserir(nome, p);
	    }
	f.close();
	}
	
	delete[] stringArray;
	stringArray = nullptr;
	
	std::cout << "Dados lidos com sucesso!" << std::endl;
}

// substring inclui os campos do csv em um de string que será usado para construir uma instancia de Pessoa
void substring(std::string s, std::string* v){
	int j = 0;
	std::string aux;
	
	for(int i = 0; i < COLUNAS; i++){

		while (s[j] != ';' && j < s.size()){
			aux.push_back(s[j]);
			j++;
		}
		
		v[i] = aux;
		aux = "";
		j++;
	}
}

void escreverLinha(No* no, std::fstream *f)
{
    if(no != NULL)
    {
        escreverLinha(no->getEsq(), f);
        
		*f << no->getChave() << ";"
		<< no->getPessoa()->getCargoBase() << ";"
		<< no->getPessoa()->getCargoComissao() << ";"
		<< no->getPessoa()->getSalarioBruto() << ";"
		<< no->getPessoa()->getUnidade() << "\n";
		
        escreverLinha(no->getDir(), f);
    }
}

void saveFile(ArvoreBST *bst){
    std::string caminho;
    std::fstream f;
	
	std::cout << "Informe o caminho do arquivo a ser salvo: ";
	std::cin >> caminho;

	f.open(caminho, std::ofstream::out | std::ofstream::trunc);	
	
	f << "cargo base;salario bruto;unidade\n";
	
	std::cout << "escrevendo linhas no arquivo " << caminho << "..." << std::endl;
	escreverLinha(bst->getRaiz(), &f);
    
    f.close();
    
    std::cout << "Dados gravados com sucesso!" << std::endl;
}
