#include "file.h"

void readFile(ArvoreBST *bst){
    // TODO limpar a arvore antes de ler
	std::string nome, cargo, unidade, caminho;
    float salarioBruto;

	std::cout << "Informe o caminho do arquivo a ser lido: ";
	std::cin >> caminho;

	std::fstream f;
    f.open(caminho, std::ios::in); 
    
    std::string line;
	std::string* stringArray = new std::string[13];

    getline(f, line);

    if (f.is_open()){
	    while(getline(f, line) && line != ""){
	    	
	    	substring(line, stringArray);
			
			nome = stringArray[1];
			cargo = stringArray[2];
			salarioBruto = std::stof(stringArray[6]);
			unidade = stringArray[7];

	    	Pessoa * p = new Pessoa(cargo, unidade, salarioBruto);
	    	
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


void saveFile(ArvoreBST *bst){
    std::string caminho;
    std::fstream f;
	
	std::cout << "Informe o caminho do arquivo a ser salvo: ";
	std::cin >> caminho;

	f.open(caminho, std::ofstream::out | std::ofstream::trunc);	
	
	f << "cargo;salario bruto;unidade\n";
	
	// NodeLL *pAnda;
	
    // pAnda = ll->getHead();
    // while (pAnda != nullptr){
    //   	f << pAnda->getId()->getDisciplina() << ";"
    //   		<< pAnda->getId()->getIsbn() << ";"
    //   		<< pAnda->getId()->getTitulo() << ";"
    //   		<< pAnda->getId()->getAutor() << ";"
    //   		<< pAnda->getId()->getEdicao() << ";"
    //   		<< pAnda->getId()->getCidade() << ";"
    //   		<< pAnda->getId()->getEditora() << ";"
    //   		<< pAnda->getId()->getAno() << ";"
    //   		<< pAnda->getId()->getBasica() << std::endl;
    //     pAnda = pAnda->getProx();
	// }	
    
	// delete pAnda;
    // pAnda = nullptr;
    
    f.close();
    
    std::cout << "Dados gravados com sucesso!" << std::endl;
}