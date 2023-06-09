#ifndef __NODE_H__
#define __NODE_H__

#include <string>
#include "pessoa.h"

class No
{
private:
    No *esq, *dir;
    std::string chave;
    Pessoa *pessoa;

public:
	No(){
		this->chave = " ";
		this->pessoa = new Pessoa();
		esq = NULL;
		dir = NULL;
	}
    No(std::string chave, Pessoa *p)
    {
        this->chave = chave;
        this->pessoa = p;
        esq = NULL;
        dir = NULL;
    }
    Pessoa* getPessoa(){return this->pessoa;}
    std::string getChave(){return chave;}
    No* getEsq(){return esq;}
    No* getDir(){return dir;}
   
    void setEsq(No *no){esq = no;}
    void setDir(No *no){dir = no;}
    void setChave(std::string k){chave = k;}
};

#endif
