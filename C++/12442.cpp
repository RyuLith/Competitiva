#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi visited,adj,suma;

int dfs(int u) {
  visited[u] = 1;
  int total = 0; // cuantos martian les llegara el email
  int v = adj[u];
  if (!visited[v] && adj[u] != -1) // si no ha sido visitado y hay una arista entre los 2 nodos
    total += 1 + dfs(v); // dfs con la suma de cuantos martians les llegara email
  visited[u] = 0;
  return suma[u] = total;;
}

int main() {
  int t, n, u, v;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    adj.clear(); adj.resize(n, -1);
    suma.clear(); suma.resize(n, -1);
    visited.clear(); visited.resize(n, 0);

    for (int j = 0; j < n; j++) {
      cin >> u >> v;
      // se usara un vector de 0 hasta n-1 y en el output se imprimira +1
      adj[u-1] = v - 1; // u,v > 0 ; v <= n
    }

    int m = 0, max = 0; // m = el numero del martian
    for (int j = 0; j < n; j++) {
      if (suma[j] == -1) dfs(j); // suma de cuantos martians recibiran email
      if (suma[j] > max) { // si la suma es MAYOR al actual, no puede ser igual, ya que sino, no se imprimira el m menor
        max = suma[j];
        m = j;
      }
    }
    cout << "Case " << i << ": " << m + 1 << endl;
  }
  return 0;
}
