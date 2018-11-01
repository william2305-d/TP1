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
	if(((linhaA == linhaB)&&(colunaA == colunaB))){
		Matriz Resultado(linhaA,colunaA,0);
		for(i = 0; i<linhaA; i++){
			for(j = 0; j<colunaA; j++){
				Resultado.p[i][j] = A.p[i][j] + B.p[i][j]; 
			} 
		}
	}
}

int main(){
	int colunas,linhas;
	Matriz M1(2,5,10);
	Matriz M2(2,5,10);
	Matriz M3(2,5,0);
	M3 = M1+M2;
	int coluna = M1.getCols();
	cout << coluna << endl;	  
	return(0);
}
