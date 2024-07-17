#pragma once
#include <iostream>
using namespace std;

// Cor das arvores
#define verm  1
#define pret  0

	struct No {
		No* esq;
		No* dir;
		int cor;
		int val;
	};

class ArvorePV{
private:
	No* raiz;
	No* balancear(No* H);
	No* Min(No* no);
	void imprimir(No* no);
	/// Cor
	int Cor(No * H);
	void TrocaCor(No* H);
	// Rotações esq e dir
	No* rotesq(No* A);
	No* rotdir(No* A);
	//Rotaçoes Duplas
	No* rot2esq(No* H);
	No* rot2dir(No*H);

public:
	ArvorePV();
	~ArvorePV();
	void insere(int v);
	void remove(int v);
	No* buscar(No* inf, int v);
	void imprimir();
};