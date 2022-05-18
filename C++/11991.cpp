#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k, v, tmp;
  while (scanf("%d %d", &n, &m) != EOF) {
    // se usara un vector de vectores para almacenar las posiciones en las que aparecio cierto entero del array
    vector<vector<int>> vec(1000001);
    // cada indice del vector de vectores representa un entero del array del input
    // el vector de cada indice guarda las posiciones en las que aparecio ese indice en el arreglo del input
    for (int i = 0; i < n; i++) {
      cin >> tmp; // entero del array
      vec[tmp].push_back(i+1); // el indice del vector de vectores representa ese entero y guarda las posiciones en las que aparece
    }
    while(m--) {
      cin >> k >> v;
      if (k > vec[v].size()) cout << "0" << endl;
      else cout << vec[v][k-1] << endl;
    }
  }
	return 0;
}
