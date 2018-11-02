#include <iostream>
#include "Matriz.h"
using namespace std;
Matriz::Matriz(const Matriz &m){

}

Matriz::Matriz(){
	p = NULL;
}

Matriz::Matriz(int linhas, int colunas, const double &valor){
	l = linhas;
	c = colunas;
	p = new double * [l];
	for(int i = 0; i<l; i++){
		p[i] = new double[c];
		for(int j = 0; j<c; j++){
			p[i][j] = valor;
		}
	}
}

Matriz::~Matriz(){

}

void Matriz::imprimeMatriz(){
	for(int i = 0; i<l ; i++){
		for(int j = 0; j<c; j++){
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Matriz::zeros(){
	for(int i = 0; i<l; i++){
		for(int j=0; j<c; j++){
			p[i][j] = 0;
		}
	}
}

int Matriz::ones(){
	for(int i = 0; i<l; i++){
		for(int j=0; j<c; j++){
			p[i][j] = 1;
		}
	}
}

int Matriz::getRows(){
	return l;
}

int Matriz::getCols(){
	return c;
}

Matriz Matriz::operator+(const Matriz &B)const{
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.l;
	int colunaB = B.c;
	if(((linhaA != linhaB)||(colunaA != colunaB))){
		throw std::invalid_argument("Matrizes não compativeis para adição");
	}
	Matriz Resultado(linhaA,colunaA,0);
	for(int i = 0; i<linhaA; i++){
		for(int j = 0; j<colunaA; j++){
			Resultado.p[i][j] = p[i][j] + B.p[i][j]; 
		} 
	}
	return Resultado;
}

void Matriz::operator+=(const Matriz &B)const{
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.l;
	int colunaB = B.c;
	if(((linhaA != linhaB)||(colunaA != colunaB))){
		throw std::invalid_argument("Matrizes não compativeis para adição");
	}
	for(int i = 0; i<linhaA; i++){
		for(int j = 0; j<colunaA; j++){
			p[i][j] = p[i][j] + B.p[i][j]; 
		} 
	}
}

void Matriz::operator~(){
	double m[c][l];
	int auxColunas;
	
	//atribuição de valores da matriz local para uma matriz auxiliar
	for(int i = 0; i < c; i++){
		for(int j = 0; j < l; j++){
			m[i][j] = p[j][i];
		}
	}

	//Desalocação da matriz
	for(int i = 0; i < l; i++){
		delete[] p[i]; 
	}
	delete[] p;
	
	//atribuição de novos valores de linhas e colunas
	auxColunas = c;
	c = l;
	l = auxColunas;
	
	//Alocação de memoria para nova matriz
	p = new double * [c];

	for(int i = 0; i<l; i++){
		p[i] = new double[l];
		for(int j = 0; j<c; j++){
			p[i][j] = 0 ;
		}
	}

	//atribuição de valores da nova matriz
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			p[i][j] = m[i][j];
		}
	}
}


int main(){
	int colunas,linhas;
	Matriz M1(5,2,7);
	Matriz M2(5,2,12);
	M1.imprimeMatriz();
	~M1;
	M1.imprimeMatriz();
	return(0);
}
