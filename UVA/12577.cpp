// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
    int i = 1;
    while (1) {
        cin >> s; 
        if (s[0] == '*') break;
        if (s[0] == 'H') cout << "Case " << i << ": " << "Hajj-e-Akbar" << endl; 
        if (s[0] == 'U') cout << "Case " << i << ": " << "Hajj-e-Asghar" << endl;
        i++;       
    }
	return 0;
}