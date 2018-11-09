#include <iostream>
#include "Matriz.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	cout << "Cria 3 Matrizes A, B < C"<< endl;
	Matriz A(3,3,1), B(3,3,3), C(3,3,2);
	cout << "A = " << endl << A << "B = " << endl << B << "C = " << endl << C << endl;
 	cout << "C(1,1) = 3"<< endl;
	C(1,1) = 3; 	
 	cout << C<< endl;
	~C;
	cout << "Trasposta de C = " <<endl << C << endl;
	C*= B;
	cout << " C*=B ==>" << endl << C << endl;
	A+=C;
	cout << "A+=C ==>" << endl << A << endl;
	A-=C;
 	cout << "A-=C ==>" << endl << A << endl;
 	A*=2;
 	cout << "A*=2 ==>" << endl << A << endl;
 	A = B*C;
 	cout << "A = B*C ==>" << endl << A << endl << "B =" << B<< endl;
 	
	 if (A!=B) {
 		cout << "A é diferente de B" << endl;
	 }
	 
	 A = B;
	 
	 cout << "A=B" << endl << A << endl;
	 
	 	 if (A==B) {
 		cout << "A é igual a B" << endl;
	 }
}
