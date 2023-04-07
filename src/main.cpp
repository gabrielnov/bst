#include "main.h"

int main(){
   ArvoreBST *bst = new ArvoreBST();

 	menu(bst);
	
    delete bst;
	bst = NULL;
    return 0;
}
