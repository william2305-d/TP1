#include <iostream>
using namespace std;
//agora sim
//criando a classe
class Matriz{
	private:
	public:
		Matriz();
		Matriz(const Matriz &m);
		Matriz(int linhas, int colunas, const double &valor = 0);
		~Matriz();
		
};

Matriz::Matriz(const Matriz &m){

}

Matriz::Matriz(){
}

Matriz::Matriz(int linhas, int colunas, const double &valor){
}

Matriz::~Matriz(){
}
