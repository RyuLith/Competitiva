#include <bits/stdc++.h>

using namespace std;

int main(){
	long long sz,p;
	while(scanf("%lld %lld",&sz,&p ),(sz||p)){
		long long centro=(sz+1)/2;
		long long i=centro,j=centro;
		long long k=1; //contador 1,9,25...

		//buscando el cuadrado impar mayor a p
		while (k<sz) {
			if ((k*k)%2!=0) {
				if ((k*k)>=p) break;
				i--; j++;
			}
			k++;
		}

		int orilla=k;
		k*=k;
		for (int lado = 1; lado <= 4; lado++) { //lados del cuadrado: der,abajo,iz,arriba
			for (long long cell = 0; cell < orilla-1; cell++) {
				if (k==p) break;
				if (lado==1) i++; //mov abajo
				if (lado==2) j--; //mov izq
				if (lado==3) i--; //mov arriba
				if (lado==4) j++; //mov der
				k--;
			}
		}
		cout<<"Line = "<<sz-(i-1)<<", column = "<<j<< "." << endl;
	}
	return 0;
}
