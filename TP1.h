#include <iostream>
using namespace std;
//criando a classe
class Matriz{
	private:
	public:
		double **p;
		Matriz();
		Matriz(const Matriz &m);
		Matriz(int linhas, int colunas, const double &valor = 0);
		~Matriz();
		void imprimeMatriz(Matriz &m);
		
};

Matriz::Matriz(const Matriz &m){
}

Matriz::Matriz(){
	p = new double * [1];
	p[1] = 0;
}

Matriz::Matriz(int linhas, int colunas, const double &valor){
	p = new double * [colunas];
	for(int i = 0; i<linhas; i++){
		p[i] = new double[linhas];
		for(int j = 0; j<colunas; j++){
			p[i][j] = 0;
		}
	}
}

Matriz::~Matriz(){
}

Matriz::imprimeMatriz(Matriz &m){
}
