#include "file.h"

void readFile(ArvoreBST *bst){
    // TODO limpar a arvore antes de ler

    f.open("dados.csv", std::ios::in); 
    
    std::string line;
	std::string* stringArray = new std::string[13];

    getline(f, line);

    if (f.is_open()){
	    while(getline(f, line) && line != ""){
	    	
	    	substring(line, stringArray);

	    	Book * b = new Book(stringArray);
	    	bool nacional = b->verificaNacional(stringArray[5]);
	    	b->setNacional(nacional);
	    	
	    	ll->insertTail(b);		
	    }
	f.close();
	}
	
	delete[] stringArray;
	stringArray = nullptr;
	
	std::cout << "Dados lidos com sucesso!" << std::endl;
}