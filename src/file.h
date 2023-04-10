#ifndef __FILE_H__
#define __FILE_H__

#include <fstream>
#include "bst.h"
#include "node.h"
#include "pessoa.h"
#define COLUNAS 13

void readFile(ArvoreBST *bst);
void substring(std::string s, std::string* v);
void saveFile(ArvoreBST *bst);
void escreverLinha(No* no, std::fstream *f);

#endif
