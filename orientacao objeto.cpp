#include <iostream>
#include <stdlib.h>
using namespace std;

class Cliente{
public:
	int numCliente;
	float saldo;
};


int main(){
	Cliente objCliente;
	
	cout << "Numero do cliente: ";
	cin >> objCliente.numCliente;
	cout << "Saldo: ";
	cin >> objCliente.saldo;
	
	
	cout << "\n\nSaldo do cliente "
			<< objCliente.saldo
			<< " = " 
			<< objCliente.numCliente
			<< "\n";
	
	system("pause");
return 0;
}

