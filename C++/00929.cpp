#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
vi dist;

void dijkstra(int s) {
  priority_queue<ii, vii, greater<ii>> pq;
  dist[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    int u_dist = pq.top().first;
    int u_vertex = pq.top().second;
    pq.pop();

    if (u_dist > dist[u_vertex]) continue; //lazy deletion

    for (ii it : adj[u_vertex]) {
      int v_vertex = it.first;
      int v_dist = it.second;

      //relajacion, si peso de camino actual es mejor al anterior
      if (u_dist + v_dist >= dist[v_vertex]) continue;
      dist[v_vertex] = u_dist + v_dist;
      pq.push({dist[v_vertex], v_vertex});
    }
  }
}


int main() {
  int casos, n, m;
  cin >> casos;
  while (casos--) {
    cin >> n >> m;
    adj.clear(); adj.resize(n*m);
    dist.clear(); dist.resize(n*m, INT_MAX);

    int maze[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> maze[i][j];

    int contador = 0; //etiqueta del nodo: 0, 1, 2,..., n*m-1
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // mapear el nodo "contador" con sus vecinos (arriba, abajo, derecha, izquierda)
        int x = i-1, y = j-1;
        if (x > -1) adj[contador].push_back(ii(contador-m, maze[x][j]));
        if (y > -1) adj[contador].push_back(ii(contador-1, maze[i][y]));
        x = i+1, y = j+1;
        if (x < n) adj[contador].push_back(ii(contador+m, maze[x][j]));
        if (y < m) adj[contador].push_back(ii(contador+1, maze[i][y]));
        contador++;
      }
    }
    dijkstra(0); //nodo inicial = 0, nodo final = n*m-1
    cout << dist[contador-1] + maze[0][0] << endl; // el nodo origen tiene un peso
  }
  return 0;
}
