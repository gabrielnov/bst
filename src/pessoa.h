#ifndef __PESSOA_H__
#define __PESSOA_H__


#include <iostream>

class Pessoa{
    private:
        std::string cargo;
        std::string unidade;
        float salarioBruto;
    
    public:
        ~Pessoa();
        Pessoa(std::string cargo, std::string unidade, float salarioBruto){
            this->cargo = cargo;
            this->unidade = unidade;
            this->salarioBruto = salarioBruto;
        }
        
        std::string getCargo(){return cargo;}
        std::string getUnidade(){return unidade;}
        float getSalarioBruto(){return salarioBruto;}
        void setCargo(std::string cargo){this->cargo = cargo;}
        void setUnidade(std::string unidade){this->unidade = unidade;}
        void setSalarioBruto(float salarioBruto){this->salarioBruto = salarioBruto;}
};

#endif