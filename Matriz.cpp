#include <iostream>
#include "Matriz.h"
using namespace std;

Matriz::Matriz(const Matriz &m){
	l = m.l;
	c = m.c;
	//Nova matriz, apenas valores são copiados.
	p = new double * [l];
	for(int i = 0; i<l; i++){
		p[i] = new double[c];
		for(int j = 0; j<c; j++){
			p[i][j] = m.p[i][j];
		}
	}
}

void Matriz::operator *= (double const &right){
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			p[i][j] *= right;
		}
	}
}

Matriz Matriz::operator*(double const &right){
	Matriz res(l, c);
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			res.p[i][j] = p[i][j] * right;
		}
	}
	return res;
}

Matriz Matriz::operator*(const Matriz &right){
	if(c !=right.l){
		cout << "Matrizes não compativeis para multiplicação" << endl;
		//throw std::invalid_argument( "Matrices aren't compatible for multiplication" );
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

void Matriz::operator*=(const Matriz &right){
	if(c !=right.l || c !=right.c){
		cout << "Matrizes não compativeis para multiplicação" << endl;
		//throw invalid_argument( "Matrices aren't compatible for multiplication" );
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

ostream& operator<<(ostream& os, const Matriz& m){  
	for(int i = 0; i < m.l ; i++){
		for(int j = 0; j < m.c; j++){
			os << m.p[i][j] << " ";
		}
		os << endl;
	}
	return os;
} 

istream& operator>>(istream& os, Matriz& m){ 
	cout << "A Matriz possui " << m.l << " Linhas " << m.c << " Colunas"<< endl;
	for(int i = 0; i < m.l ; i++){
		for(int j = 0; j < m.c; j++){
			cout << " A[" << i + 1 << "] [" << j + 1 << "] = " ;
			double valor;
			os >> m.p[i][j];
		}
	}
	return os;
}   
  
void Matriz::operator=(const Matriz &A){
	if( l!=A.l || c != A.c){
		cout << "Matrizes não compativeis para atribuição" << endl;
	}
	else{
		for(int i = 0; i < l ; i++){
			for(int j = 0; j < c; j++){
				p[i][j] = A.p[i][j];
			}
		}
	}	
}

int Matriz::operator==(const Matriz &A)const{
	if( l!=A.l || c != A.c){
		cout << "Matrizes não compativeis para atribuição" << endl;
		return false;
	}
	else{
		for(int i = 0; i < l ; i++){
			for(int j = 0; j < c; j++){
				if (p[i][j] != A.p[i][j]) return false;
			}
		}
		return true;
	}
	
}

int Matriz::operator!=(const Matriz &A)const{
	if( l!=A.l || c != A.c){
		cout << "Matrizes não compativeis para atribuição" << endl;
		return true;
	}
	else{
		for(int i = 0; i < l ; i++){
			for(int j = 0; j < c; j++){
				if (p[i][j] != A.p[i][j]) return true;
			}
		}
		return false;
	}
	
}


Matriz::Matriz(){
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

//Estava vazio, confirmar se precisa desalocar da memoria! 
Matriz::~Matriz(){
 	for(int i = 0; i < l ; i++){
		delete[] p[i]; 
	}
	delete[] p;
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
		cout << "Matrizes não compativeis para adição" << endl;
		//	throw std::invalid_argument("Matrizes não compativeis para adição");
	}
	Matriz Resultado(linhaA,colunaA,0);
	for(int i = 0; i<linhaA; i++){
		for(int j = 0; j<colunaA; j++){
			Resultado.p[i][j] = p[i][j] + B.p[i][j]; 
		} 
	}
	return Resultado;
}

void Matriz::operator+=(const Matriz &B){
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.l;
	int colunaB = B.c;
	if(((linhaA != linhaB)||(colunaA != colunaB))){
		cout << "Matrizes não compativeis para adição" << endl;
		//	throw std::invalid_argument("Matrizes não compativeis para adição");
	}
	for(int i = 0; i<linhaA; i++){
		for(int j = 0; j<colunaA; j++){
			p[i][j] = p[i][j] + B.p[i][j]; 
		} 
	}
}
Matriz Matriz::operator~(){
	Matriz M(c,l,0);
	for(int i = 0; i < c; i++){
		for(int j = 0; j < l; j++){
			M.p[i][j] = p[j][i];
		}
	}
	return M;
}

void Matriz::operator=(const Matriz &A){
	if( l!=A.l || c != A.c){
		cout << "Matrizes nÃ£o compativeis para atribuiÃ§Ã£o" << endl;
	}
	else{
		for(int i = 0; i < l ; i++){
			for(int j = 0; j < c; j++){
				p[i][j] = A.p[i][j];
			}
		}
	}	
}

Matriz Matriz::operator-(const Matriz &B)const{
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.l;
	int colunaB = B.c;
	if(((linhaA != linhaB)||(colunaA != colunaB))){
		cout << "Matrizes não compativeis para subtração" << endl;
		//	throw std::invalid_argument("Matrizes não compativeis para adição");
	}
	Matriz Resultado(linhaA,colunaA,0);
	for(int i = 0; i<linhaA; i++){
		for(int j = 0; j<colunaA; j++){
			Resultado.p[i][j] = p[i][j] - B.p[i][j]; 
		} 
	}
	return Resultado;
}

void Matriz::operator-=(const Matriz &B){
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.l;
	int colunaB = B.c;
	if(((linhaA != linhaB)||(colunaA != colunaB))){
		cout << "Matrizes não compativeis para subtração" << endl;
		//	throw std::invalid_argument("Matrizes não compativeis para adição");
	}
	for(int i = 0; i<linhaA; i++){
		for(int j = 0; j<colunaA; j++){
			p[i][j] = p[i][j] - B.p[i][j]; 
		} 
	}
}

double& Matriz::operator()(int const &linhas, int const &colunas){	
	return p[linhas-1][colunas-1]; 
}
