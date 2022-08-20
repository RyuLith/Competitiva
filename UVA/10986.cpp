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
  int caso = 1,N;
  cin >> N;
  while (N--) {
    int n,m,s,t; cin >> n >> m >> s >> t;
    adj.clear(); adj.resize(n);
    dist.clear(); dist.resize(n,INT_MAX);
    for (int i = 0; i < m; i++) {
      int u,v,w; cin >> u >> v >> w;
      // grafo sin direccion
      adj[u].push_back(ii(v, w));
      adj[v].push_back(ii(u, w));
    }
    dijkstra(s);
    cout << "Case #" << caso << ": ";
    if (dist[t] != INT_MAX) cout << dist[t] << endl;
    else cout << "unreachable" << endl;
    caso++;
  }
  return 0;
}
