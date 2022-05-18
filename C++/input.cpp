#include<bits/stdc++.h>

using namespace std;

int main(){

	//caso 1
	int t;
	cin>>t; //Casos de prueba
	while(t--){} //Repetir hasta que t sea 0


	//caso 2.1
	//Repetir hasta recibir un 0
	int a;
	while(cin>>a, a != 0){}
	//Otra opción
	while(cin>>a, a){}

	//caso 2.2
	//Repetir hasta que ambos enteros sean 0
	int a, b;
	while(cin>>a>>b, (a && b)){}


	//caso 3
	//No se nos especifica el final
	int a;
	while(scanf("%d",&a) == 1){}
	//otra opción
	while(cin>>a, a != EOF){}
	//otra opción
	while(cin>>a){}


	//caso 4.1
	//Cada output termina con una linea vacía (blank line) al final.
	int a, caso = 1;
	while(cin>>a)
		cout<<"Case "<<caso++<<": "<<a<<endl<<endl;

	//caso 4.2
	//Cada output termina con una blank line, excepto el último.
	int a, caso = 0;
	while(cin>>a){
		if(caso > 0) cout<<endl;
		cout<<"Case "<<++caso<<": "<<a<<endl;
	}


	//caso 5.1
	//Por cada caso (cantidad no específicada) nos dan un valor k, seguido por k cantidad de enteros.
	int k;
	while(cin>>k){
		int num;
		while(k--){
			cin>>num;
			cout<<num<<endl;
		}
	}

	//caso 5.2
	//Mismo caso; no nos entregan un valor k.
	string line;
	while(getline(cin, line))
		cout<<line<<endl;
	//otra opción
	while (1) { // keep looping
    int v;
    char dummy;
    while (scanf("%d%c", &v, &dummy) != EOF) {
			printf("%d\n", v);
      if (dummy == '\n') break; // test EOLN
    }
    if (feof(stdin)) break; // test EOF
  }


	return 0;
}

//cplusplus.com

