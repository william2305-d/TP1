#include <iostream>
#include "Matriz.h"
//uhuuuuuuuul
using namespace std;
//Construtor de cópia e atribuição
//Matriz W = C;
//Matriz Z(A);
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

//X*=2;
Matriz::Void operator *= (double const &right){
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			p[i][j] *= right;
		}
	}
}

//Extrapolação de X*=2;
//C=X*2;
Matriz::Void operator * (double const &right){
	Matriz res(l, c);
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			res.p[i][j] = p[i][j] * right;
		}
	}
	return res;
}

//C=A*X
Matriz::Matriz operator * (const Matriz &right){
	if(c !=right.l){
		throw std::invalid_argument( "Matrices aren't compatible for multiplication" );
	}
	Matriz res(l, right.c);
	for (int i = 0; i < res.l; i++){
		for (int j = 0; j < res.c; j++){
			double acc = 0;
			for (int k = 0; k < c; k++){
				acc+= p[i][k] * right.p[k][j];
			}
			res.p[i][j] = acc;
		}
	}
	return res;
}

//C*=X;
Matriz::Void operator *= (const Matriz &right){
	if(c !=right.l || c !=right.c){
		throw std::invalid_argument( "Matrices aren't compatible for multiplication" );
	}
	Matriz res(l, right.c);
	for (int i = 0; i < res.l; i++){
		for (int j = 0; j < res.c; j++){
			double acc = 0;
			for (int k = 0; k < c; k++){
				acc+= p[i][k] * right.p[k][j];
			}
			res.p[i][j] = acc;
		}
	}
	*this = res;
}

Matriz::Void operator *= (const Matriz &right){
	if(c !=right.l || c !=right.c){
		throw std::invalid_argument( "Matrices aren't compatible for multiplication" );
	}
	Matriz res(l, right.c);
	for (int i = 0; i < res.l; i++){
		for (int j = 0; j < res.c; j++){
			double acc = 0;
			for (int k = 0; k < c; k++){
				acc+= p[i][k] * right.p[k][j];
			}
			res.p[i][j] = acc;
		}
	}
	*this = res;
}

//cout << C << endl;
Matriz::ostream& operator<< (ostream& os, const Matriz& m)  
{  
	for(int i = 0; i < m.l ; i++){
		for(int j = 0; j < m.c; j++){
			os << m.p[i][j] << " ";
		}
		os << endl;
	}
	return os;
}  
  












//algumas correções
Matriz::Matriz(){
	l = 0;
	c = 0;
	p = NULL;
}
//algumas correções
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
