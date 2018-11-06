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
		int zeros();
		int getRows();
		int getCols();
		int ones();
		Matriz operator+(const Matriz &A)const;
		void operator+=(const Matriz &A); //não sao constante pq altera a primeira Matriz
		void operator~();
		//Caio
		void operator*=(double const &right);
		Matriz operator*(double const &right);
		Matriz operator*(const Matriz &right);
		void operator*=(const Matriz &right);
		friend ostream& operator<< (ostream& os, const Matriz& m); //contante também, apenas leitura
		//Manu
		Matriz operator-(const Matriz &A)const;
		void operator-=(const Matriz &A);
		friend istream& operator>>(istream& os, Matriz& m);
		void operator=(const Matriz &A);
		int operator==(const Matriz &A)const;
		int operator!=(const Matriz &A)const;
		double& operator()(int const &linhas, int const &colunas); 
		
};
