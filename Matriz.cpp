#include <iostream>
#include <stdexcept>
#include "Matriz.h"
using namespace std;

//Construtor de cópia e atribuição
//Matriz W = C;
//Matriz Z(A);
Matriz::Matriz(const Matriz& m) {
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

//X*=2;
Matriz& Matriz::operator *= (double const& right){
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			p[i][j] *= right;
		}
	}
	return *this;
}

//Extrapolação de X*=2;
//C=X*2;
Matriz Matriz::operator * (double const& right) const{
	Matriz res(l, c);
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			res.p[i][j] = p[i][j] * right;
		}
	}
	return res;
}

//C=A*X;
Matriz Matriz::operator * (const Matriz& right) const{
	if(c !=right.l){
		//Se a coluna da esquerda é diferente da linha da direita, não têm como ser feita a multiplicação e é lançado um erro.
		throw std::invalid_argument( "Matrizes não compativeis para multiplicação" );
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
Matriz& Matriz::operator *= (const Matriz& right){
	if(c != right.l){
		//Se a coluna da esquerda é diferente da linha da direita, não têm como ser feita a multiplicação e é lançado um erro.
		throw invalid_argument( "Matrizes não compativeis para multiplicação" );
	}
	//É criada uma matriz para o resultado, pois se não fosse feito, o resultado seria alterado
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
	return *this;
}

//cout << C << endl;
ostream& operator << (ostream& os, const Matriz& m) {  
	for(int i = 0; i < m.l ; i++){
		for(int j = 0; j < m.c; j++){
			os << m.p[i][j] << " ";
		}
		os << endl;
	}
	return os;
} 

//cin >> Y;
istream& operator >> (istream& os, Matriz& m){ 
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

Matriz& Matriz::operator = (const Matriz &A){
	//Destrói o conteúdo anterior
	for(int i = 0; i < l ; i++){
		delete[] p[i]; 
	}
	delete[] p;
	//Cria uma nova matriz igual a A.
	l = A.l;
	c = A.c;
	p = new double * [l];
	for(int i = 0; i<l; i++){
		p[i] = new double[c];
		for(int j = 0; j<c; j++){
			p[i][j] = A.p[i][j];
		}
	}
	return *this;
}

//if (A == C)
bool Matriz::operator == (const Matriz& A)const{
	//Se as dimensões não são iguais, então não é igual
	if( l!=A.l || c != A.c){
		return false;
	}
	else{
		for(int i = 0; i < l ; i++){
			for(int j = 0; j < c; j++){
				//Se algum elemento não é igual, então não é igual
				if (p[i][j] != A.p[i][j]) return false;
			}
		}
		return true;
	}
}

//if (X != Y)
bool Matriz::operator != (const Matriz& A)const{
	//Se as dimensões são diferentes, então é diferente
	if( l!=A.l || c != A.c){
		return true;
	}
	else{
		for(int i = 0; i < l ; i++){
			for(int j = 0; j < c; j++){
				//Se algum elemento é diferente, então é diferente
				if (p[i][j] != A.p[i][j]) return true;
			}
		}
		return false;
	}
}

//Matriz Y;
Matriz::Matriz(){
	l = 0;
	c = 0;
	p = NULL;
}

//Matriz X(3,1), A(3,3), C(3,3);
Matriz::Matriz(int linhas, int colunas, const double &valor){
	if(0 > linhas || 0 > colunas){
		throw std::invalid_argument("Não podem existir dimensões negativas");
	}
	l = linhas;
	c = colunas;
	p = new double * [l];
	for(int i = 0; i < l; i++){
		p[i] = new double[c];
		for(int j = 0; j < c; j++){
			p[i][j] = valor;
		}
	}
}

//Destrutor
Matriz::~Matriz(){
 	for(int i = 0; i < l ; i++){
		delete[] p[i]; 
	}
	delete[] p;
}

//Y.zeros();
int Matriz::zeros(){
	for(int i = 0; i<l; i++){
		for(int j=0; j<c; j++){
			p[i][j] = 0;
		}
	}
}

//X.ones();
int Matriz::ones(){
	for(int i = 0; i<l; i++){
		for(int j=0; j<c; j++){
			p[i][j] = 1;
		}
	}
}

//int numeroLinhas = A.getRows();
int Matriz::getRows() const{
	return l;
}

//Int numeroColunas = A.getCols();
int Matriz::getCols() const{
	return c;
}

//C=A+A;
Matriz Matriz::operator + (const Matriz& B)const{
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.l;
	int colunaB = B.c;
	if(((linhaA != linhaB)||(colunaA != colunaB))){
		//Se as dimensões são diferentes, não têm como ser feita a adição e é lançado um erro
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

//A+=A;
Matriz& Matriz::operator += (const Matriz& B){
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.l;
	int colunaB = B.c;
	if(((linhaA != linhaB)||(colunaA != colunaB))){
		//Se as dimensões são diferentes, não têm como ser feita a adição e é lançado um erro
		throw std::invalid_argument("Matrizes não compativeis para adição");
	}
	for(int i = 0; i<linhaA; i++){
		for(int j = 0; j<colunaA; j++){
			p[i][j] += B.p[i][j]; 
		} 
	}
	return *this;
}

//A=~C;
Matriz Matriz::operator ~ () const{
	Matriz M(c,l);
	for(int i = 0; i < c; i++){
		for(int j = 0; j < l; j++){
			M.p[i][j] = p[j][i];
		}
	}
	return M;
}

//A=C-A; 
Matriz Matriz::operator - (const Matriz& B)const{
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.l;
	int colunaB = B.c;
	if(((linhaA != linhaB)||(colunaA != colunaB))){
		//Se as dimensões são diferentes, não têm como ser feita a subtração e é lançado um erro
		throw std::invalid_argument("Matrizes não compativeis para subtração");
	}
	Matriz Resultado(linhaA,colunaA,0);
	for(int i = 0; i<linhaA; i++){
		for(int j = 0; j<colunaA; j++){
			Resultado.p[i][j] = p[i][j] - B.p[i][j]; 
		} 
	}
	return Resultado;
}

//C-=A;
Matriz& Matriz::operator -= (const Matriz& B){
	int linhaA = l;
	int colunaA = c;
	int linhaB = B.l;
	int colunaB = B.c;
	if(((linhaA != linhaB)||(colunaA != colunaB))){
		//Se as dimensões são diferentes, não têm como ser feita a subtração e é lançado um erro
		throw std::invalid_argument("Matrizes não compativeis para subtração");
	}
	for(int i = 0; i<linhaA; i++){
		for(int j = 0; j<colunaA; j++){
			p[i][j] -= B.p[i][j]; 
		} 
	}
	return *this;
}

//A(2,1)=10;
double& Matriz::operator () (int const &linhas, int const &colunas){	
	if(l < linhas || 0 >= linhas  || c < colunas || 0 >= colunas){
		throw std::invalid_argument("Elemento fora da matriz");
	}
	return p[linhas-1][colunas-1]; 
}

//Y.unit()
void Matriz::unit(){
	for(int i = 0; i<l; i++){
		for(int j = 0; j<c; j++){
			if(i == j){
				p[i][j] = 1;
			}
			else{
				p[i][j] = 0;
			}
		}
	}
}

int main(){
	Matriz Y;
	Matriz X(3,1),A(3,3),C(3,3);
	Matriz W = C;
	Matriz Z(A);
	int numeroLinhas = A.getRows();
	int numeroColunas = A.getCols();
	Y.unit();
	A(2,1) = 10;
	Y.zeros();
	C=A+A;
	C-=A;
	A=C-A;
	A+= A;
	A=~C;
	X.ones();
	X*=2;
	C=A*X;
	//C*=X; Não funcionaria pois C neste momento tem dimensões (3,1) e X (3,1).
	if(A==C)
	if(X!=Y)
	cout << C << endl;
	cin >> Y;
	return 0;
}
