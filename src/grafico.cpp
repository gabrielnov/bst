#include "grafico.h"

void plot(ArvoreBST *bst){
    struct faixaSalarial fs;
	// caractere que sera usado para plotar as barras do grafico
	char m = ']';
    int total = 0, space = 6;
	std::string traco;

    fs.A = 0;
	fs.B = 0;
	fs.C = 0;
	fs.D = 0;
	fs.E = 0;

    bst->analise5(bst->getRaiz(), &fs, &total);

    std::cout << "Total de registros: " << total << "\n\n";
    
	// usado para encontrarmos a proporcao correta do grafico
    int div = divisor(total);

	// imprimos cada faixa de acordo com a sua quantidade
	std::cout << std::setw(2) << ' ' << "faixa salarial" << std::endl;	
	std::cout << std::setw(space) << ' ' << " ^ " << std::endl;	
	std::cout << std::setw(space) << ' ' << " | " << std::endl;
	std::cout << "=< 5k  | ";	
	for (int i = 0; i < limit(fs.A, div) ; i++)
		std::cout << m;
	std::cout << " " << fs.A << std::endl;
	
	std::cout << std::setw(space) << ' ' << " | " << std::endl;
	std::cout << "=< 10k | ";		
	for (int i = 0; i < limit(fs.B, div) ; i++)
		std::cout << m;
	std::cout << " " << fs.B << std::endl;
	
	std::cout << std::setw(space) << ' ' << " | " << std::endl;
	std::cout << "=< 15k | ";		
	for (int i = 0; i < limit(fs.C, div) ; i++)
		std::cout << m;
	std::cout  << " " << fs.C << std::endl;
	
	std::cout << std::setw(space) << ' ' << " | " << std::endl;
	std::cout << "=< 20k | ";		
	for (int i = 0; i < limit(fs.D, div) ; i++)
		std::cout << m;
	std::cout << " " << fs.D << std::endl;
	
	std::cout << std::setw(space) << ' ' << " | " << std::endl;
	std::cout << " > 20k | ";	
	for (int i = 0; i < limit(fs.E, div); i++)
		std::cout << m;
	std::cout << " " << fs.E << std::endl;
	
	std::cout << std::setw(space) << ' ' << " | \n ";

	traco = repeat("-", 113);
	std::cout << traco << "> frequencia"<< std::endl;	
	std::cout << std::setw(space) << ' ' << " | ";

	std::cout << std::setw(8) << ' ' << "10k ";
	for (int i = 2; i <= 10; i++){
		std::cout << std::setw(7) << ' ' << i << "0k";
	}
}

std::string repeat(std::string s, int n) {
  std::string repeat;

  for (int i = 0; i < n; i++)
    repeat += s;

  return repeat;
}

int limit(float total, int div){
	float r = total/div;
	
	if (r < 1) return 1;
	else return r;
}

float divisor(int total){
	if (total < 100) return 1;
	if (total < 1000) return 100;
	return 1000;
}
