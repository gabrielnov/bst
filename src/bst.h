#ifndef __BST_H__
#define __BST_H__

#include <iostream>



class ArvoreBST
{
private:
    No *raiz;

public:
    ArvoreBST()
    {
        raiz = NULL;
    }
    
    void setRaiz(No* root){raiz = root;}
    No* getRaiz() {return raiz;}

    void inserir(int chave, Pessoa p);
    void inserirAux(No *no, int chave, Pessoa p); 
    void emOrdem(No* no);
    void preOrdem(No* no);
    void posOrdem(No* no);
    No *Pesquisar (No* r, int k);
    int contarNos(No* atual);
    int altura(No* atual);
    excluir(No* t, std::string key);
    int folhas(No *atual);
    No* findMin(No* t);
    No* findMax(No* t);
    void infs(No* r);
    void print();
	void print(No *no, int space);
    
};



#endif