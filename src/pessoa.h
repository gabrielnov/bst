#ifndef __PESSOA_H__
#define __PESSOA_H__

#include <string>

class Pessoa{
    private:
        std::string cargoBase;
        std::string cargoComissao;
        std::string unidade;
        float salarioBruto;
    
    public:
        ~Pessoa();
        Pessoa();
        Pessoa(std::string cargoBase, std::string cargoComissao, std::string unidade, float salarioBruto){
            this->cargoBase = cargoBase;
            this->cargoComissao = cargoComissao;
            this->unidade = unidade;
            this->salarioBruto = salarioBruto;
        }
        
        std::string getCargoBase(){return cargoBase;}
        std::string getCargoComissao(){return cargoComissao;}
        std::string getUnidade(){return unidade;}
        float getSalarioBruto(){return salarioBruto;}
        void setCargoBase(std::string cargoBase){this->cargoBase = cargoBase;}
        void setCargoComissao(std::string cargoComissao){this->cargoComissao = cargoComissao;}
        void setUnidade(std::string unidade){this->unidade = unidade;}
        void setSalarioBruto(float salarioBruto){this->salarioBruto = salarioBruto;}
};


struct faixaSalarial {
    int A, B, C, D, E;
};


#endif
