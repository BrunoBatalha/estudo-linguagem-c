#include <iostream> 
using namespace std;

void Aparecer(const char[],const  char[],const  int);
 
int main() {  
	char Programador1[20];
	
	cout << "Digite seu primerio nome: ";
	cin >> Programador1;
	
	Aparecer(Programador1," Batalha",16);
	
	int x = 5;
	
	cout << "\nFora do bloco x = " << x ;
	{
		int x = 3;
		cout << "\nDentro do bloco x = " << x;
	}
	cout << "\nFora do bloco x = " << x ;
	
	cout << "\n\n";
	//testando for de uma maneira diferente
	for(int contador = 1;  contador <= 10;cout <<"\nContador = "<<contador++) ;
	 
return 0; 
}

void Aparecer(const char  Programador1[],const char Programador2[],const int idade){

	cout << "\"Hello, World \nC++ HEHE!\"\n";  

	cout << "\nEis uma multiplicacao: "
			<<"2 * 2 = "
			<< 2 * 2
			<< "\n\n";
			
	cout << "PROGRAMADOR: " << Programador1 << Programador2 << "\n"
			<< "Idade: " << idade;
}


