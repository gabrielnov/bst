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
        std::cout << no->getChave() << std::endl;
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
    		std::cout << no->getChave() << "\n";
//    		std::cout << no->getPessoa()->getSalarioBruto() << "\n";
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
	
	void ArvoreBST::mediaAnalise(std::string procurar, float *soma, int* pessoas, No *no, int choice){
		if (no != NULL)
  		{	
  			if(choice == 3){
  				if(no->getPessoa()->getCargoBase() == procurar || no->getPessoa()->getCargoComissao() == procurar){
//  				std::cout << no->getChave() << std::endl;
  					*soma = *soma + no->getPessoa()->getSalarioBruto();
  					*pessoas += 1;
				}	
			} else if (choice == 4){
				if(no->getPessoa()->getUnidade() == procurar){
//  				std::cout << no->getChave() << std::endl;
  					*soma = *soma + no->getPessoa()->getSalarioBruto();
  					*pessoas += 1;
				}
			} else if (choice == 5){
				*soma = *soma + no->getPessoa()->getSalarioBruto();
  				*pessoas += 1;
			}
    		mediaAnalise(procurar, soma, pessoas, no->getDir(), choice);
    		mediaAnalise(procurar, soma, pessoas, no->getEsq(), choice);
  		}
	}
	
	void ArvoreBST::findMaxAnalise(std::string procurar, float *maximo, No* no, int choice, No* noMaximo){
		if (no != NULL)
  		{	
  			if(choice == 3){
  				if(no->getPessoa()->getCargoBase() == procurar || no->getPessoa()->getCargoComissao() == procurar){
  					if(no->getPessoa()->getSalarioBruto() > *maximo){
  						*maximo = no->getPessoa()->getSalarioBruto();
					}
				}
			} else if (choice == 4) {
				if(no->getPessoa()->getUnidade() == procurar){
  					if(no->getPessoa()->getSalarioBruto() > *maximo){
  						*maximo = no->getPessoa()->getSalarioBruto();
					}
				}
			} else if (choice == 5){
				if(no->getPessoa()->getSalarioBruto() > *maximo){
  					*maximo = no->getPessoa()->getSalarioBruto();
  					noMaximo->getPessoa()->setCargoBase(no->getPessoa()->getCargoBase());
  					noMaximo->getPessoa()->setCargoComissao(no->getPessoa()->getCargoComissao());
  					noMaximo->getPessoa()->setSalarioBruto(no->getPessoa()->getSalarioBruto());
  					noMaximo->getPessoa()->setUnidade(no->getPessoa()->getUnidade());
				}
			}
    		findMaxAnalise(procurar, maximo, no->getDir(), choice, noMaximo);
    		findMaxAnalise(procurar, maximo, no->getEsq(), choice, noMaximo);
  		}
	}
	
	void ArvoreBST::findMinAnalise(std::string procurar, float *minimo, No* no, int choice, No* noMinimo){
		if (no != NULL)
  		{	
  			if(choice == 3){
  				if(no->getPessoa()->getCargoBase() == procurar || no->getPessoa()->getCargoComissao() == procurar){
  					if(no->getPessoa()->getSalarioBruto() < *minimo){
  						*minimo = no->getPessoa()->getSalarioBruto();
					}
				}	
			} else if (choice == 4){
				if(no->getPessoa()->getUnidade() == procurar){
  					if(no->getPessoa()->getSalarioBruto() < *minimo){
  						*minimo = no->getPessoa()->getSalarioBruto();
					}
				}
			} else if (choice == 5){
				if(no->getPessoa()->getSalarioBruto() < *minimo){
  					*minimo = no->getPessoa()->getSalarioBruto();
  					noMinimo->getPessoa()->setCargoBase(no->getPessoa()->getCargoBase());
  					noMinimo->getPessoa()->setCargoComissao(no->getPessoa()->getCargoComissao());
  					noMinimo->getPessoa()->setSalarioBruto(no->getPessoa()->getSalarioBruto());
  					noMinimo->getPessoa()->setUnidade(no->getPessoa()->getUnidade());
				}
			}
    		findMinAnalise(procurar, minimo, no->getDir(), choice, noMinimo);
    		findMinAnalise(procurar, minimo, no->getEsq(), choice, noMinimo);
  		}
	}
	
	void ArvoreBST::auxAnalise1(std::string cargo1, std::string cargo2){
		float soma = 0, *pSoma = &soma, media1 = 0, media2 = 0;
		float maximo1 = 0, *pMaximo1 = &maximo1, minimo1, *pMinimo1 = &minimo1;
		float maximo2 = 0, *pMaximo2 = &maximo2, minimo2, *pMinimo2 = &minimo2;
		int pessoas = 0, *pPessoas = &pessoas;
		
		//media cargo 1
		mediaAnalise(cargo1, pSoma, pPessoas, raiz, 3);
		std::cout << soma << " " << pessoas << std::endl;
		media1 = soma/pessoas; //guarda o valor na variavel 
//		std::cout << media1 << " " << pessoas << std::endl;
		*pPessoas = 0, *pSoma = 0.0; //reseta os valores
		//media cargo 2
		mediaAnalise(cargo2, pSoma, pPessoas, raiz, 3);
//		std::cout << soma << " " << pessoas << std::endl;
		media2 = soma/pessoas; //guarda o valor na varivael
		
		//Max e Min para cargo1
		findMaxAnalise(cargo1, pMaximo1, raiz, 3, nullptr);
		minimo1 = maximo1;
		findMinAnalise(cargo1, pMinimo1, raiz, 3, nullptr);
		 
		//Max e Min para cargo2 
		findMaxAnalise(cargo2, pMaximo2, raiz, 3, nullptr);
		minimo2 = maximo2;
		findMinAnalise(cargo2, pMinimo2, raiz, 3, nullptr);
		
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
    
    void ArvoreBST::auxAnalise2(std::string unidade1, std::string unidade2){
		float soma = 0, *pSoma = &soma, media1 = 0, media2 = 0;
		float maximo1 = 0, *pMaximo1 = &maximo1, minimo1, *pMinimo1 = &minimo1;
		float maximo2 = 0, *pMaximo2 = &maximo2, minimo2, *pMinimo2 = &minimo2;
		int pessoas = 0, *pPessoas = &pessoas;
		
		//media cargo 1
		mediaAnalise(unidade1, pSoma, pPessoas, raiz, 4);
		std::cout << soma << " " << pessoas << std::endl;
		media1 = soma/pessoas; //guarda o valor na variavel 
//		std::cout << media1 << " " << pessoas << std::endl;
		*pPessoas = 0, *pSoma = 0.0; //reseta os valores
		//media cargo 2
		mediaAnalise(unidade2, pSoma, pPessoas, raiz, 4);
//		std::cout << soma << " " << pessoas << std::endl;
		media2 = soma/pessoas; //guarda o valor na varivael
		
		//Max e Min para cargo1
		findMaxAnalise(unidade1, pMaximo1, raiz, 4, nullptr);
		minimo1 = maximo1;
		findMinAnalise(unidade1, pMinimo1, raiz, 4, nullptr);
		 
		//Max e Min para cargo2 
		findMaxAnalise(unidade2, pMaximo2, raiz, 4, nullptr);
		minimo2 = maximo2;
		findMinAnalise(unidade2, pMinimo2, raiz, 4, nullptr);
		
		//print e resultado
		std::cout << "--------- Media ---------\n";
		std::cout << "media unidade 1: " << media1 << " media unidade 2: " << media2 << std::endl;
		std::cout << "diferenca entre unidade1 e unidade2: " << (media2-media1) << std::endl;
		std::cout << "relacao de media entre unidade1 e unidade2 em porcentagem: " << ((media2-media1)/media1)*100 << std::endl;
		std::cout << "--------- MAX ----------\n";
		std::cout << "maximo unidade 1: " << maximo1 << " maximo unidade 2: " << maximo2 << std::endl;
		std::cout << "diferenca entre unidade1 e unidade 2: " << (maximo2-maximo1) << std::endl;
		std::cout << "relacao de maximo entre unidade 1 e unidade 2 em porcentagem: " << ((maximo2-maximo1)/maximo1)*100 << std::endl;
		std::cout << "--------- MIN ----------\n";
		std::cout << "minimo unidade 1: " << minimo1 << " minimo unidade 2: " << minimo2 << std::endl;
		std::cout << "diferenca entre unidade 1 e unidade 2: " << (minimo2-minimo1) << std::endl;
		std::cout << "relacao de maximo entre unidade 1 e unidade 2 em porcentagem: " << ((minimo2-minimo1)/minimo1)*100 << std::endl;
	}
	
	void ArvoreBST::auxAnalise3(){
		float soma = 0, *pSoma = &soma, media1 = 0;
		float maximo1 = 0, *pMaximo1 = &maximo1, minimo1, *pMinimo1 = &minimo1;
		int pessoas = 0, *pPessoas = &pessoas;
		No* noMaximo = new No();
		No* noMinimo = new No();
		
		//media
		mediaAnalise("", pSoma, pPessoas, raiz, 5);
		media1 = soma/pessoas; //guarda o valor na variavel 
		
		//Max e Min
		findMaxAnalise("", pMaximo1, raiz, 5, noMaximo);
		minimo1 = maximo1;
		findMinAnalise("", pMinimo1, raiz, 5, noMinimo);

		//print e resultado
		std::cout << "--------- Media Geral ---------\n";
		std::cout << "soma geral: " << soma << "/ quantidade: " << pessoas << std::endl;
		std::cout << "media geral: " << media1 << std::endl;
		std::cout << "---------- MAX Geral ----------\n";
		std::cout << "maximo da arvore: " << maximo1 << std::endl;
		std::cout << "unidade: " << noMaximo->getPessoa()->getUnidade() << "/ cargo base: " << noMaximo->getPessoa()->getCargoBase() << "/ cargo commisao: " << noMaximo->getPessoa()->getCargoComissao() << std::endl;
		std::cout << "diferenca entre maximo e media: " << (maximo1-media1) << std::endl;
		std::cout << "diferenca entre maximo e media geral em porcentagem: " << ((maximo1-media1)/maximo1)*100 << std::endl;
		std::cout << "---------- MIN Geral ----------\n";
		std::cout << "minimo da arvore: " << minimo1 << std::endl;
		std::cout << "unidade: " << noMinimo->getPessoa()->getUnidade() << "/ cargo base: " << noMinimo->getPessoa()->getCargoBase() << "/ cargo commisao: " << noMinimo->getPessoa()->getCargoComissao() << std::endl;
		std::cout << "diferenca entre minimo e media: " << (media1-minimo1) << std::endl;
		std::cout << "diferenca entre media geral e minimo em porcentagem: " << ((media1-minimo1)/media1)*100 << std::endl;
		std::cout << "----------- MIN/MAX -----------\n";
		std::cout << "diferenca entre maximo e minimo: " << (maximo1-minimo1) << std::endl;
		std::cout << "diferenca entre maximo e minimo em porcentagem: " << ((maximo1-minimo1)/maximo1)*100 << std::endl;
	}
