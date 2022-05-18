#include <bits/stdc++.h>

using namespace std;

vector<string> diccionario; // nodos del grafo
map<string, int> dist; // mapa dist que guarda el nodo (string) y la distancia

void bfs(string s, string e) {
  // bfs con la starting word hasta la ending word

  queue<string> q; // = a bfs normal
  q.push(s); dist[s] = 0; // = a bfs normal

  while (!q.empty() && dist.count(e) == 0) { // el ciclo termina cuando se encuentra con la ending word o queue vacia
    string u = q.front(); q.pop(); // = a bfs normal
    for (int i = 0; i < diccionario.size(); i++) { // = a bfs normal, recorre todos los nodos
      string v = diccionario[i]; // = a bfs normal
      if (!dist.count(v) && u.length() == v.length()) { // si no se ha visitado ese nodo, y tienen = length, puede que haya una arista
        // contar letras distintas
        int dif = 0; // diferencia de cantidad letras distintas
        for (int j = 0; j < u.length(); j++)
          if (u[j] != v[j]) ++dif;
        // si solo hay una letra de diferencia, es decir el nodo nos sirve para el cambio en el problema (hay una arista)
        if (dif == 1) {
          dist[v] = dist[u] + 1; // = a bfs normal
          q.push(v); // = a bfs normal
        }
      }
    }
  }
}

int main() {
  int n; cin >> n;
  while(n--) {
    diccionario.clear();
    string palabra;
    while (cin >> palabra, palabra != "*")
      diccionario.push_back(palabra);

    // leer input de manera especial para el par de palabras
    cin.ignore();
    string line;
    while (getline(cin, line) && line != "") {
      stringstream ss(line);
      string start, end;
      ss >> start >> end;


      // BFS
      // los nodos de este problema son strings y no ints, se usara un mapa como "dist" para guardar la distancia y el string
      // los nodos necesarios son: el nodo de partida "start" y el nodo objetivo "end"
      dist.clear();
      bfs(start,end);
      cout << start << " " << end << " " << dist[end] << endl;
    }
    if (n) cout << endl;
  }
  return 0;
}
