#include <iostream>
//modificação
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
		int zeros();
		int getRows();
		int getCols();
		int ones();
		Matriz operator+(const Matriz &A)const;
};
