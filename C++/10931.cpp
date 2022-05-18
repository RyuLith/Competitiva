// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
    while (1) {
        cin >> t; if (t == 0) break;

        int a[20];
        int n = t, p = 0, i = 0;

        for (; 0 < n; i++) {// decimal a binario
            a[i] = n % 2; // resto = 0 o 1
            n /= 2;
            if (a[i] == 1) p++;
        }

        cout << "The parity of ";
        for ( i -= 1 ; i >= 0; i--) cout << a[i];
        cout << " is " << p << " (mod 2)." << endl;        
    }
	return 0;
}
