#include "file.h"

void readFile(ArvoreBST *bst){
    // TODO limpar a arvore antes de ler
	std::string nome, cargo, unidade;
    float salarioBruto;

	std::fstream f;
    f.open("dados.csv", std::ios::in); 
    
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

}