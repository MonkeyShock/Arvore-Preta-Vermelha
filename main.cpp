#include"Arvore Preta Vermelha.h"
#include <iostream>
using namespace std;

int main() {
	ArvorePV A;
	A.insere(81);
	A.insere(90);
	A.insere(20);
	A.insere(40);
	A.insere(40);
	A.insere(10);
	A.insere(60);
	A.insere(0);
	A.insere(30);
	A.insere(99);
	A.insere(12);
	A.insere(21);
	A.insere(49);
	A.insere(7);
	A.remove(7);
	A.remove(81);
	A.imprimir();
}