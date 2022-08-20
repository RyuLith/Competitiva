#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]){
	string linea;

	while(getline(cin, linea)){
		cout << "linea: " << linea << endl;
		stringstream s1(linea);
		int aux;
		int cont = 0;
		while(s1 >> aux){
			cont++;
		}
		cout << cont << " elementos"<< endl;
		int* nums = new int[cont];
		stringstream s2(linea);
		for(int i=0; i<cont; i++){
			s2 >> nums[i];
		}
		cout << endl;
	}
	return 0;
}