#ifndef __GRAFICO_H__
#define __GRAFICO_H__

#include <iostream>
#include <iomanip>
#include "bst.h"
#include "pessoa.h"

void plot(ArvoreBST* bst);
int limit(float total, int div);
float divisor(int total);
std::string repeat(std::string s, int n);

#endif
