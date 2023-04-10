#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <limits>
#include "pessoa.h"
#include "node.h"

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

    void inserir(std::string chave, Pessoa *p);
    void inserirAux(No *no, std::string chave, Pessoa *p); 
    void emOrdem(No* no);
    void preOrdem(No* no);
    void posOrdem(No* no);
    No *Pesquisar (No* r, std::string k);
    int contarNos(No* atual);
    int altura(No* atual);
    No *excluir(No* t, std::string key);
    int folhas(No *atual);
    No* findMin(No* t);
    No* findMax(No* t);
    void infs(No* r);
    void print();
  	void print(No *no, int space);
    void mediaAnalise(std::string procurar, float *soma, int* pessoas, No *no, int choice);
    void findMaxAnalise(std::string procurar, float *maximo, No* no, int choice, No* noMaximo);
    void findMinAnalise(std::string procurar, float *minimo, No* no, int choice, No* noMinimo);
    void auxAnalise1(std::string cargo1, std::string cargo2);
    void auxAnalise2(std::string unidade1, std::string unidade2);
    void auxAnalise3();
    void analise4(No *no, struct faixaSalarial *fs, int *total);
    void analise5(No* no, std::string nome);
    void LimparArvore (No* no);
    void auxLimpar();
};



#endif
