#ifndef __BST_H__
#define __BST_H__

#include <iostream>

class No
{
private:
    No *esq, *dir;
    int chave;

public:
    No(int chave)
    {
        this->chave = chave;
        esq = NULL;
        dir = NULL;
    }
    int getChave(){return chave;}
    No* getEsq(){return esq;}
    No* getDir(){return dir;}
    void setEsq(No *no){esq = no;}
    void setDir(No *no){dir = no;}
    void setChave(int k){chave = k;}
};


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

    void inserir(int chave);
    void inserirAux(No *no, int chave);  
    void emOrdem(No* no);
    void preOrdem(No* no);
    void posOrdem(No* no);
    No *Pesquisar (No* r, int k);
    int contarNos(No* atual);
    int altura(No* atual);
    No *excluir(No* t, int key);
    int folhas(No *atual);
    No* findMin(No* t);
    No* findMax(No* t);
    void infs(No* r);
    void print();
	void print(No *no, int space);
};



#endif