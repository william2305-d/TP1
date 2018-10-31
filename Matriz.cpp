#include <iostream>
#include "Matriz.h"

using namespace std;
Matriz::Matriz(const Matriz &m){

}

Matriz::Matriz(){
	p = new double *[1];
	p[1] = 0;
}

Matriz::Matriz(int linhas, int colunas, const double &valor){
	l = linhas;
	c = colunas;
	p = new double * [l];
	for(int i = 0; i<l; i++){
		p[i] = new double[c];
		for(int j = 0; j<c; j++){
			p[i][j] = 0;
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
}

int main(){
	Matriz M(5,3,0);
	M.imprimeMatriz();
	return(0);
}
