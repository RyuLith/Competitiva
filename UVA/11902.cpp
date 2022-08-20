#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi visited;
vector<vi> adj;

void dfs(int u, int quitado) {
  if (u == quitado) return; // skip n quitado
  visited[u] = 1;
  for (int v : adj[u])
    if (!visited[v]) dfs(v, quitado);
}


int main() {
  int t, caso = 0;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    adj.clear(); adj.resize(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int tmp; cin >> tmp;
        if (tmp) adj[i].push_back(j); // transformar de matriz a lista
      }
    }

    int mat[n][n];
    visited.clear(); visited.resize(n);

    // copiar resultados de dfs a un arreglo
    dfs(0, -1);
    int arr[n];
    for (int i = 0; i < n; i++)
      arr[i] = visited[i];

    // comparacion del dfs original vs dfs skipeando los distintos numeros
    for (int i = 0; i < n; i++) {
      visited.clear(); visited.resize(n);
      dfs(0, i); // dfs sin 0,en sig iter sin 1,2,etc.
      // comparando los 2 arreglos
      for (int j = 0; j < n; j++)
        if (arr[j] != visited[j]) mat[i][j] = 1;
        else mat[i][j] = 0;
    }

    // imprimir
    caso++;
    cout << "Case " << caso << ":" << endl;

    cout << "+";
    for (int i = 0; i < n*2-1; i++) cout << "-";
    cout << "+" << endl;

    for (int i = 0; i < n; i++) {
      cout << "|";
      for (int j = 0; j < n; j++)
        if (mat[i][j]) cout << "Y|";
        else cout << "N|";
      cout << endl;

      cout << "+";
      for (int i = 0; i < n*2-1; i++) cout << "-";
      cout << "+" << endl;
    }
  }
  return 0;
}
