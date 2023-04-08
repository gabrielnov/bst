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
        // se for menor, entï¿½o insere na sub-ï¿½rvore ï¿½ esquerda
        if(chave < no->getChave())
        {
            // verifica se nï¿½o tem filho a esquerda: achou local de inserï¿½ï¿½o 
            if(no->getEsq() == NULL)
            {
                No *novo_no = new No(chave, p);
                no->setEsq(novo_no); // add o novo_no ï¿½ esquerda do nï¿½ atual
            }
            else
            {
                // senï¿½o, continua percorrendo recursivamente para esquerda
                inserirAux(no->getEsq(), chave, p);
            }
        }
        // se for maior, entï¿½o insere na sub-ï¿½rvore ï¿½ direita
        else if(chave > no->getChave())
        {
            // verifica se nï¿½o tem filho a direita: achou local de inserï¿½ï¿½o
            if(no->getDir() == NULL)
            {
                No *novo_no = new No(chave, p);
                no->setDir(novo_no); // add o novo_no ï¿½ direita do nï¿½ atual
            }
            else
            {
                // senï¿½o, continua percorrendo recursivamente para direita
                inserirAux(no->getDir(), chave, p);
            }
        }
        // se a chave for igual a alguma presente na ï¿½rvore, nï¿½o vamos inserir
        // nï¿½o pode existir 2 chaves iguais na nossa BST
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
        return -1; //ï¿½rvore ou sub-ï¿½rvore vazia: altura = -1
    else
    {
        if(atual->getEsq() == NULL && atual->getDir() == NULL)
            return 0; //ï¿½vore com apenas 1 nï¿½, altura = 0
        else
        {//altura da ï¿½rvore ï¿½ a altura da sub-ï¿½rvore de maior altura
            if (altura(atual->getEsq()) > altura(atual->getDir()))
                return ( 1 + altura(atual->getEsq()) );
            else
                return ( 1 + altura(atual->getDir()) );
        }
    }
}

No* ArvoreBST::excluir(No* t, std::string key){
        
        //Arvore t ï¿½ vazia
        if (t == NULL) 
            return t;
        
        if (key < t->getChave())
            t->setEsq(excluir(t->getEsq(),key));
        else
            if (key > t->getChave())
                t->setDir(excluir(t->getDir(),key));
        
        //encontramos o nï¿½ a ser removido
        else{ 
            //Caso1: o no a ser excluido nao tem filhos
            if (t->getEsq() == NULL and t->getDir() == NULL){
            	delete(t);
                return NULL; //faz o pai apontar para NULL e o nï¿½ nï¿½o faz mais parte da BST	
			}            	
            else 
                //Caso2: tem apenas um filho, a esquerda ou a direita
                if (t->getEsq() == NULL){
                    No* temp = t->getDir();
                    delete(t);
                    return temp; //Faz o pai apontar para o ï¿½nico filho do nï¿½
                }
                else 
                    if  (t->getDir() == NULL){
                        No* temp = t->getEsq();
                        delete(t);
                        return temp; //Faz o pai apontar para o ï¿½nico filho do nï¿½
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
	
	void ArvoreBST::somaAll(std::string procurar, float *soma, int* pessoas, No *no){
		if (no != NULL)
  		{	
  			if(no->getPessoa()->getCargo() == procurar){
  				std::cout << "entramos";
  				std::cout << no->getChave();
  				*soma = *soma + no->getPessoa()->getSalarioBruto();
  				*pessoas += 1;
			}
    		somaAll(procurar, soma, pessoas, no->getDir());
    		somaAll(procurar, soma, pessoas, no->getEsq());
  		}
	}
	
	void ArvoreBST::analise1(std::string cargo1, std::string cargo2){
		float soma = 0, *p = &soma, media1 = 0, media2 = 0;
		int pessoas = 0, *z = &pessoas;
		somaAll(cargo1, p, z, raiz);
		media1 = soma/pessoas;
		std::cout << media1 << " " << pessoas << std::endl;
		*p = 0, *soma = 0;
		somaAll(cargo2, p, z, raiz);
		media2 = soma/pessoas;
		std::cout << media2 << " " << pessoas << std::endl;
		std::cout << "diferenca entre cargo1 e cargo2: " << (media2-media1) << std::endl;
		std::cout << "relação de media entre cargo1 e cargo2 em porcentagem: " << ((media2-media1)/media1)*100 << std::endl;
	}
    
