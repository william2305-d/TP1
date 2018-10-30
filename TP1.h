#include <iostream>
using namespace std;
//criando a classe
class Matriz{
	private:
		int l,c;
	public:
		double **p;
		Matriz();
		Matriz(const Matriz &m);
		Matriz(int linhas, int colunas, const double &valor = 0);
		~Matriz();
		void imprimeMatriz();
		
};

Matriz::Matriz(const Matriz &m){
}

Matriz::Matriz(){
	p = new double * [1];
	p[1] = 0;
}

Matriz::Matriz(int linhas, int colunas, const double &valor){
	l = linhas;
	c = c;
	p = new double * [c];
	for(int i = 0; i<l; i++){
		p[i] = new double[l];
		for(int j = 0; j<c; j++){
			p[i][j] = 0;
		}
	}
}

Matriz::~Matriz(){
}

void imprimeMatriz(){
}
