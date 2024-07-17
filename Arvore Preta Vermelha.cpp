#include <iostream>
#include "Arvore Preta Vermelha.h"
using namespace std;

No* ArvorePV::balancear(No* H)
{
	if (Cor(H->dir) == verm)
	{
		H = rotesq(H);
	}
	if (H->esq !=NULL && Cor(H->dir) ==verm && Cor(H->esq->esq) == verm)
	{
		H = rotdir(H);
	}
	if (Cor(H->esq) == verm && Cor(H->dir) == verm)
	{
		TrocaCor(H);
	}

	if (Cor(H->esq) == verm && Cor(H->esq->esq) == verm) {
		H = rot2dir(H);
	}
	if (Cor(H->dir) == verm && Cor(H->dir->dir) == verm) {
		H = rot2esq(H);
	}
	return(H);
}

No* ArvorePV::Min(No* no)
{
	No* atual = no;
	while (atual && atual->esq != nullptr) {
		atual = atual->esq;
	}
	return atual;
}

ArvorePV::ArvorePV()
{
	this->raiz = NULL;
}

ArvorePV::~ArvorePV()
{
}

void ArvorePV::insere(int v)
{
	No* novoNo = new No;
	// Criando um Nó
	novoNo->val = v;
	novoNo->dir = nullptr; // nullptr é mais preferível do que NULL em código C++
	novoNo->esq = nullptr;
	novoNo->cor = verm; // Vermelho
	
	// Colocando o Nó
	if (this->raiz == nullptr) {
		novoNo->cor = pret; // Preto
		this->raiz = novoNo;
	}
	else {
		No* temp = this->raiz; 
		while (temp != nullptr) {
			if (temp->val == v) {
				cout << "Valor Ingual " << endl;
				break;
			}
			if (v < temp->val) {
				if (temp->esq == nullptr) {
					temp->esq = novoNo;
					break;
				}
				else {
					temp = temp->esq;
				}
			}
			else {
				if (temp->dir == nullptr) {
					temp->dir = novoNo;
					break;
				}
				else {
					temp = temp->dir;
				}
			}
		}
	}
	this->raiz = balancear(this->raiz);
 
}

void ArvorePV::remove(int v)
{
	// Busca pelo nó a ser removido
	No* atual = buscar(this->raiz, v);
	if (atual == nullptr) {
		cout << "Valor " << v << " nao encontrado na arvore." << endl;
		return;
	}

	No* pai = nullptr; // Nó pai do nó a ser removido

	// Encontra o pai do nó atual
	if (atual != this->raiz) {
		pai = this->raiz;
		while (pai->esq != atual && pai->dir != atual) {
			if (v < pai->val) {
				pai = pai->esq;
			}
			else {
				pai = pai->dir;
			}
		}
	}

	// Se o nó a ser removido é uma folha
	if (atual->esq == nullptr && atual->dir == nullptr) {
		if (atual == this->raiz) {
			delete atual;
			this->raiz = nullptr;
		}
		else if (atual->val < pai->val) {
			delete atual;
			pai->esq = nullptr;
		}
		else {
			delete atual;
			pai->dir = nullptr;
		}
	}
	// Se o nó a ser removido tem apenas um filho
	else if (atual->esq == nullptr || atual->dir == nullptr) {
		No* filho = (atual->esq != nullptr) ? atual->esq : atual->dir;
		if (atual == this->raiz) {
			delete atual;
			this->raiz = filho;
		}
		else if (atual->val < pai->val) {
			delete atual;
			pai->esq = filho;
		}
		else {
			delete atual;
			pai->dir = filho;
		}
	}
	// Se o nó a ser removido tem dois filhos
	else {
		No* substituto = Min(atual->dir);
		atual->val = substituto->val;

		// Removendo o nó substituto
		if (atual->dir == substituto) {
			atual->dir = substituto->dir;
		}
		else {
			remove(substituto->val);
		}
		delete substituto;
	}
	this->raiz = balancear(this->raiz);
}





No* ArvorePV::buscar(No* inf, int v)
{
	// Se chegarmos a um nó nulo ou encontrarmos o valor, retornamos o nó
	if (inf == nullptr || inf->val == v) {
		if (inf == nullptr)
			cout << "Valor não encontrado" << endl;
		return inf;
	}

	// Se o valor for menor que o valor do nó atual, continuamos a busca na subárvore esquerda
	if (v < inf->val) {
		return buscar(inf->esq, v);
	}
	else {
		// Caso contrário, continuamos a busca na subárvore direita
		return buscar(inf->dir, v);
	}
}

void ArvorePV::imprimir(No* no)
{
	if (no != nullptr) {
		imprimir(no->esq); // Visita o filho esquerdo
		cout << no->val << " "; // Imprime o valor do nó
		imprimir(no->dir); // Visita o filho direito
	}
}
int ArvorePV::Cor(No*H)
{
	if (H == NULL)
		return pret;
	else
		return verm;
}
void ArvorePV::TrocaCor(No* H)
{
	H->cor = ~H->cor;
	if (H->esq != NULL)
		H->esq->cor = ~H->esq->cor;
	if (H->dir != NULL)
		H->dir->cor = ~H->dir->cor;
}
No* ArvorePV::rotesq(No* A)
{
	No* B = A->dir;
	A->dir = B->esq;
	B->esq = A;
	B->cor = A->cor;
	this->raiz->cor = verm;
	return B;
}
No* ArvorePV::rotdir(No* A)
{
	No* B = A->esq;
	A->esq = B->dir;
	B->dir = A;
	B->cor = A->cor;
	A->cor = verm;
	return B;
}
No* ArvorePV::rot2esq(No* H)
{
	TrocaCor(H);
	if (Cor(H->dir->esq) == verm)
	{
		H->dir = rotesq(H->dir);
		H = rotesq(H);
		TrocaCor(H);
	}
	return H;
}
No* ArvorePV::rot2dir(No * H)
{
	TrocaCor(H);
	if (Cor(H->esq->esq) == verm)
	{
		H = rotdir(H);
		TrocaCor(H);
	}
	return H;
}
void ArvorePV::imprimir()
{
	imprimir(this->raiz); // Chama o método recursivo para iniciar a impressão a partir da raiz
}