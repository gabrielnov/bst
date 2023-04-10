#ifndef __MENU_H__
#define __MENU_H__

#include "bst.h"
#include "file.h"
#include "grafico.h"

void menu(ArvoreBST* bst);
void printMenu();
bool readOption(int opt, ArvoreBST* bst, bool* fileRead);

#endif

