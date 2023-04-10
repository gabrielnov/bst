#include "grafico.h"

void plot(ArvoreBST *bst){
    struct faixaSalarial fs;
	char m = ']';
    int total = 0;
	std::string traco;

    fs.A = 0;
	fs.B = 0;
	fs.C = 0;
	fs.D = 0;
	fs.E = 0;

    bst->analise4(bst->getRaiz(), &fs, &total);

    std::cout << "Total de registros: " << total << "\n\n";
    
    int div = divisor(total);

	std::cout << std::setw(4) << ' ' << "faixa salarial" << std::endl;	
	std::cout << std::setw(8) << ' ' << " ^ " << std::endl;	
	std::cout << std::setw(8) << ' ' << " | " << std::endl;
	std::cout << "=< 5000  | ";	
	for (int i = 0; i < limit(fs.A, div) ; i++)
		std::cout << m;
	std::cout << " " << fs.A << std::endl;
	
	std::cout << std::setw(8) << ' ' << " | " << std::endl;
	std::cout << "=< 10000 | ";		
	for (int i = 0; i < limit(fs.B, div) ; i++)
		std::cout << m;
	std::cout << " " << fs.B << std::endl;
	
	std::cout << std::setw(8) << ' ' << " | " << std::endl;
	std::cout << "=< 15000 | ";		
	for (int i = 0; i < limit(fs.C, div) ; i++)
		std::cout << m;
	std::cout  << " " << fs.C << std::endl;
	
	std::cout << std::setw(8) << ' ' << " | " << std::endl;
	std::cout << "=< 20000 | ";		
	for (int i = 0; i < limit(fs.D, div) ; i++)
		std::cout << m;
	std::cout << " " << fs.D << std::endl;
	
	std::cout << std::setw(8) << ' ' << " | " << std::endl;
	std::cout << " > 20000 | ";	
	for (int i = 0; i < limit(fs.E, div); i++)
		std::cout << m;
	std::cout << " " << fs.E << std::endl;
	
	std::cout << std::setw(8) << ' ' << " | \n ";

	traco = repeat("-", 120);
	std::cout << traco << "> frequencia"<< std::endl;	
	std::cout << std::setw(8) << ' ' << " | ";

	for (int i = 1; i <= 10; i++){
		std::cout << std::setw(8) << ' ' << i << "0";
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
