#include "bst.h"
#include <iostream>

void ArvoreBST::inserir(std::string chave, Pessoa *p){
        if(raiz == NULL) 
            raiz = new No(chave, p); 
        else
            inserirAux(raiz, chave, p);
}

 void ArvoreBST::inserirAux(No *no, std::string chave, Pessoa *p)
    {
        // se for menor, ent�o insere na sub-�rvore � esquerda
        if(chave < no->getChave())
        {
            // verifica se n�o tem filho a esquerda: achou local de inser��o 
            if(no->getEsq() == NULL)
            {
                No *novo_no = new No(chave, p);
                no->setEsq(novo_no); // add o novo_no � esquerda do n� atual
            }
            else
            {
                // sen�o, continua percorrendo recursivamente para esquerda
                inserirAux(no->getEsq(), chave, p);
            }
        }
        // se for maior, ent�o insere na sub-�rvore � direita
        else if(chave > no->getChave())
        {
            // verifica se n�o tem filho a direita: achou local de inser��o
            if(no->getDir() == NULL)
            {
                No *novo_no = new No(chave, p);
                no->setDir(novo_no); // add o novo_no � direita do n� atual
            }
            else
            {
                // sen�o, continua percorrendo recursivamente para direita
                inserirAux(no->getDir(), chave, p);
            }
        }
        // se a chave for igual a alguma presente na �rvore, n�o vamos inserir
        // n�o pode existir 2 chaves iguais na nossa BST
    }

void ArvoreBST::emOrdem(No* no)
{
    if(no != NULL)
    {
        emOrdem(no->getEsq());
        std::cout << no->getPessoa()->getSalarioBruto() << std::endl;
        emOrdem(no->getDir());
    }
}

void ArvoreBST::preOrdem(No* no)
    {
    if(no != NULL)
    {
        std::cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void ArvoreBST::posOrdem(No* no)
{
    if(no != NULL)
    {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        std::cout << no->getChave() << " ";
    }
}

No* ArvoreBST::Pesquisar (No* r, std::string k)
{
    if (r == NULL || r->getChave() == k)
        return r;
    if (r->getChave() > k)
        return Pesquisar(r->getEsq(), k);
    else
        return Pesquisar(r->getDir(), k);
}

int ArvoreBST::contarNos(No* atual)
{
    if(atual == NULL)  return 0;
    else return ( 1 + contarNos(atual->getEsq()) + contarNos(atual->getDir()));
}

 int ArvoreBST::altura(No* atual)
{
    if(atual == NULL)
        return -1; //�rvore ou sub-�rvore vazia: altura = -1
    else
    {
        if(atual->getEsq() == NULL && atual->getDir() == NULL)
            return 0; //�vore com apenas 1 n�, altura = 0
        else
        {//altura da �rvore � a altura da sub-�rvore de maior altura
            if (altura(atual->getEsq()) > altura(atual->getDir()))
                return ( 1 + altura(atual->getEsq()) );
            else
                return ( 1 + altura(atual->getDir()) );
        }
    }
}

No* ArvoreBST::excluir(No* t, std::string key){
        
        //Arvore t � vazia
        if (t == NULL) 
            return t;
        
        if (key < t->getChave())
            t->setEsq(excluir(t->getEsq(),key));
        else
            if (key > t->getChave())
                t->setDir(excluir(t->getDir(),key));
        
        //encontramos o n� a ser removido
        else{ 
            //Caso1: o no a ser excluido nao tem filhos
            if (t->getEsq() == NULL and t->getDir() == NULL){
            	delete(t);
                return NULL; //faz o pai apontar para NULL e o n� n�o faz mais parte da BST	
			}            	
            else 
                //Caso2: tem apenas um filho, a esquerda ou a direita
                if (t->getEsq() == NULL){
                    No* temp = t->getDir();
                    delete(t);
                    return temp; //Faz o pai apontar para o �nico filho do n�
                }
                else 
                    if  (t->getDir() == NULL){
                        No* temp = t->getEsq();
                        delete(t);
                        return temp; //Faz o pai apontar para o �nico filho do n�
                    }
            
            //Caso3: o no a ser excluido tem 2 filhos. Vamos escolher o menor dos maiores
            //para substituir o no que sera removido. Sucessor = menor no na sub-arvore da direita
            
            No* temp = findMin(t->getDir()); 
            
            //Copia a chave do sucessor para o no que esta sendo removido
            t->setChave(temp->getChave());
            
            //Remove da arvore o sucessor!
            t->setDir(excluir(t->getDir(),temp->getChave()));
        }
        
        //retorna a raiz da arvore
        return t;
        
}

  int ArvoreBST::folhas(No *atual)
    {
        if(atual == NULL) return 0;
        if(atual->getEsq() == NULL && atual->getDir() == NULL) return 1;
        return folhas(atual->getEsq()) + folhas(atual->getDir());
    }

 No* ArvoreBST::findMin(No* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->getEsq() == NULL)
            return t;
        else
            return findMin(t->getEsq());
    }

	//recursivo
    No* ArvoreBST::findMax(No* t) {
        if(t == NULL)
            return NULL;
        else if(t->getDir() == NULL)
            return t;
        else
            return findMax(t->getDir());
    }

  
    void ArvoreBST::infs(No* r)
    {
        No* aux;
        std::cout << "\nInformacoes gerais da arvore: \n";
        std::cout << "\n Altura da arvore: " << altura(raiz);
        std::cout << "\n Quantidade de folhas: " << folhas(raiz);
        std::cout << "\n Quantidade de Nos: " << contarNos(raiz);
        if (raiz != NULL )    // se arvore nao esta vazia
        {           
            aux = findMin(r);
            std::cout << "\n Valor minimo: " << aux->getChave();            
            aux = findMax(r);
            std::cout << "\n Valor maximo: " << aux->getChave();
        }
    }

    void ArvoreBST::print()
	{
  		emOrdem(raiz);
	}

	void ArvoreBST::print(No *no, int space)
	{
  		if (no != NULL)
  		{	
    		print(no->getDir(), space + 5);
    		for (int k = 0; k < space; ++k) 
				std::cout << " ";
//    		std::cout << no->getChave() << "\n";
    		std::cout << no->getPessoa()->getSalarioBruto() << "\n";
    		print(no->getEsq(), space + 5);
  		}
	}
	
//	void ArvoreBST::mediaSalario(float *soma, int* pessoas, No *no){
//		if (no != NULL)
//  		{	
//  			*soma = *soma + no->getPessoa()->getSalarioBruto();
//  			*pessoas += 1;
//    		mediaSalario(procurar, soma, pessoas, no->getDir());
//    		mediaSalario(procurar, soma, pessoas, no->getEsq());
//  		}
//	}
//	
//	void ArvoreBST::auxMediaSalario(){
//		float soma = 0, *p = &soma, media1 = 0, media2 = 0;
//		int pessoas = 0, *z = &pessoas;
//		mediaSalario(p, z, raiz);
//	}
	
	//Analise 1
	void ArvoreBST::analise1(std::string procurar, float *soma, int* pessoas, No *no){
		if (no != NULL)
  		{	
  			if(no->getPessoa()->getCargoBase() == procurar || no->getPessoa()->getCargoComissao() == procurar){
//  				std::cout << no->getChave() << std::endl;
  				*soma = *soma + no->getPessoa()->getSalarioBruto();
  				*pessoas += 1;
			}
    		analise1(procurar, soma, pessoas, no->getDir());
    		analise1(procurar, soma, pessoas, no->getEsq());
  		}
	}
	
	void ArvoreBST::findMaxAnalise1(std::string procurar, float *maximo, No* no){
		if (no != NULL)
  		{	
  			if(no->getPessoa()->getCargoBase() == procurar || no->getPessoa()->getCargoComissao() == procurar){
  				if(no->getPessoa()->getSalarioBruto() > *maximo){
  					*maximo = no->getPessoa()->getSalarioBruto();
				}
			}
    		findMaxAnalise1(procurar, maximo, no->getDir());
    		findMaxAnalise1(procurar, maximo, no->getEsq());
  		}
	}
	
	void ArvoreBST::findMinAnalise1(std::string procurar, float *minimo, No* no){
		if (no != NULL)
  		{	
  			if(no->getPessoa()->getCargoBase() == procurar || no->getPessoa()->getCargoComissao() == procurar){
  				if(no->getPessoa()->getSalarioBruto() < *minimo){
  					*minimo = no->getPessoa()->getSalarioBruto();
				}
			}
    		findMinAnalise1(procurar, minimo, no->getDir());
    		findMinAnalise1(procurar, minimo, no->getEsq());
  		}
	}
	
	void ArvoreBST::auxAnalise1(std::string cargo1, std::string cargo2){
		float soma = 0, *pSoma = &soma, media1 = 0, media2 = 0;
		float maximo1 = 0, *pMaximo1 = &maximo1, minimo1, *pMinimo1 = &minimo1;
		float maximo2 = 0, *pMaximo2 = &maximo2, minimo2, *pMinimo2 = &minimo2;
		int pessoas = 0, *pPessoas = &pessoas;
		
		//media cargo 1
		analise1(cargo1, pSoma, pPessoas, raiz);
		std::cout << soma << " " << pessoas << std::endl;
		media1 = soma/pessoas; //guarda o valor na variavel 
//		std::cout << media1 << " " << pessoas << std::endl;
		*pPessoas = 0, *pSoma = 0.0; //reseta os valores
		//media cargo 2
		analise1(cargo2, pSoma, pPessoas, raiz);
//		std::cout << soma << " " << pessoas << std::endl;
		media2 = soma/pessoas; //guarda o valor na varivael
		
		//Max e Min para cargo1
		findMaxAnalise1(cargo1, pMaximo1, raiz);
		minimo1 = maximo1;
		findMinAnalise1(cargo1, pMinimo1, raiz);
		 
		//Max e Min para cargo2 
		findMaxAnalise1(cargo2, pMaximo2, raiz);
		minimo2 = maximo2;
		findMinAnalise1(cargo2, pMinimo2, raiz);
		
		//print e resultado
		std::cout << "--------- Media ---------\n";
		std::cout << "media cargo 1: " << media1 << " media cargo2: " << media2 << std::endl;
		std::cout << "diferenca entre cargo1 e cargo2: " << (media2-media1) << std::endl;
		std::cout << "relacao de media entre cargo1 e cargo2 em porcentagem: " << ((media2-media1)/media1)*100 << std::endl;
		std::cout << "--------- MAX ----------\n";
		std::cout << "maximo cargo 1: " << maximo1 << " maximo cargo2: " << maximo2 << std::endl;
		std::cout << "diferenca entre cargo1 e cargo2: " << (maximo2-maximo1) << std::endl;
		std::cout << "relacao de maximo entre cargo1 e cargo2 em porcentagem: " << ((maximo2-maximo1)/maximo1)*100 << std::endl;
		std::cout << "--------- MIN ----------\n";
		std::cout << "minimo cargo 1: " << minimo1 << " minimo cargo2: " << minimo2 << std::endl;
		std::cout << "diferenca entre cargo1 e cargo2: " << (minimo2-minimo1) << std::endl;
		std::cout << "relacao de maximo entre cargo1 e cargo2 em porcentagem: " << ((minimo2-minimo1)/minimo1)*100 << std::endl;
	}
    
