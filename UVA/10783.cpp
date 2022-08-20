// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, a, b;
	cin >> t;
    for (int i = 0; i < t; i++){
        cin >> a >> b;

        // primer numero impar a sumar
        int sum = a;
        if (a % 2 == 0) sum = sum + 1;

        for (int j = sum + 2; j <= b; j+=2) // for que suma numeros impares
            sum += j;

        cout << "Case " << i+1 << ": " << sum << endl; 
    }
	return 0;
}
