#include <iostream>
#include "Matriz.h"
//uhuuuuuuuul
using namespace std;
//Construtor de cópia e atribuição?
Matriz::Matriz(const Matriz &m){
	l = m.l;
	c = m.c;
	//nova matriz, apena valores são copiados.
	p = new double * [l];
	for(int i = 0; i<l; i++){
		p[i] = new double[c];
		for(int j = 0; j<c; j++){
			p[i][j] = m.p[i][j];
		}
	}
}

Matriz::Matriz operator * (const Matriz &right){
	if(c !=right.l){
		throw std::invalid_argument( "Matrices aren't compatible for multiplication" );
	}
	Matriz res(l, right.l);
	for (int i = 0; i < res.l; i++){
		for (int j = 0; j < res.l; j++){
			double acc = 0;
			for (int k = 0; k < c; k++){
				acc+= p[i][k] * right.p[k][j];
			}
			res.p[i][j] = acc;
		}
	}
	return res;
}


Matriz::Void operator *= (const Matriz &right){
	if(c !=right.l || c !=right.c){
		throw std::invalid_argument( "Matrices aren't compatible for multiplication" );
	}
	Matriz res(l, right.l);
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			double acc = 0;
			for (int k = 0; k < c; k++){
				acc+= p[i][k] * right.p[k][j];
			}
			res.p[i][j] = acc;
		}
	}
	*this = res;
}


Matriz::Void operator *= (double const &right){
	if(c == 0 || l == 0 ){
	return;
	}
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			p[i][j] *= right;
		}
	}
}













Matriz::Matriz(){
	l = 0;
	c = 0;
	p = NULL;
}

Matriz::Matriz(int linhas, int colunas, const double &valor = 0){
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

int main(){
	int colunas,linhas;
	Matriz M(2,5,10);
	linhas = M.getRows();
	colunas  = M.getCols();
	cout << "colunas: " << colunas << " " << "linhas: " << linhas << endl;  
	return(0);
}
