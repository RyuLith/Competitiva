#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  while (n--) {
    int min = INT_MAX;
    int p; cin >> p;
    getchar(); //clear buffer
    p++; // 1 hasta P
    vector<int> v(p);

    for (int i = 1; i < p; i++) {
      int vecinos = 1; // siempre tiene al menos 1 vecino

      // leer entrada como string, para contar espacios vacios (n espacios vacios = n-1 vecinos)
      string s;
      getline(cin, s);
      for (int j = 0; j < s.length(); j++) {
        if (s[j] == ' ') vecinos++;
      }

      v[i] = vecinos; // numero de vecinos en cada place
      if (vecinos < min) min = vecinos;
    }

    bool first = true;
    for (int i = 1; i < p; i++) {
      if (v[i] == min) {
        if (!first) cout << " ";
        cout << i;
        first = false;
      }
    }
    cout << endl;
  }
  return 0;
}
