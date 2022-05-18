// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
    string s;
	cin >> t;
	while (t--) {
        cin >> s;

        if (s.length() == 5) cout << "3" << endl;
        else {
            if (s[0] == 'o') cout << "1" << endl;
            else if (s[0] == 't') cout << "2" << endl;
            else if (s[1] == 'n') cout << "1" << endl;
            else if (s[1] == 'w') cout << "2" << endl;
            else if (s[2] == 'e') cout << "1" << endl;
            else if (s[2] == 'o') cout << "2" << endl;
        }
    }
	return 0;
}
