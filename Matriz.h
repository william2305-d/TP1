#include <iostream>
using namespace std;
//criando a classe
class Matriz{
	private:
		int l,c;
		double **p;
	public:
		Matriz();
		Matriz(const Matriz &m);
		Matriz(int linhas, int colunas, const double &valor = 0);
		~Matriz();
		int zeros();
		int getRows()const;
		int getCols()const;
		int ones();
		Matriz operator+(const Matriz &A)const;
		Matriz operator~()const;
		Matriz& operator+=(const Matriz &A);
		Matriz& operator*=(double const &right);
		Matriz operator*(double const &right)const;
		Matriz operator*(const Matriz &right)const;
		Matriz& operator*=(const Matriz &right);
		friend ostream& operator<< (ostream& os, const Matriz& m);
		Matriz operator-(const Matriz &A)const;
		Matriz& operator-=(const Matriz &A);
		friend istream& operator>>(istream& os, Matriz& m);
		Matriz& operator=(const Matriz &A);
		bool operator==(const Matriz &A)const;
		bool operator!=(const Matriz &A)const;
		double& operator()(int const &linhas, int const &colunas); 
		void unit();		
};
