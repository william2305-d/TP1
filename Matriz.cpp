#include <iostream>
#include "Matriz.h"
//uhuuuuuuuul
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
	cout << "teste" << endl;
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.zeros();
	int colunaB = B.ones();
	if((linhaA == linhaB)&&(colunaA == colunaB)){
		cout << l << endl;
	}
}

int main(){
	int colunas,linhas;
	Matriz M1(2,5,10);
	Matriz M2(2,5,10);
	Matriz M3(2,5,0);
	M3 = M1+M2;	  
	return(0);
}
