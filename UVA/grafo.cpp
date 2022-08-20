#include <bits/stdc++.h>

using namespace std;

// dfs
typedef vector<int> vi;

vi visited;
vector<vi> adj;

void dfs_recursive(int u) {
  visited[u] = 1;
  for (int v : adj[u])
    if (!visited[v]) dfs_recursive(v);
}

void dfs_iterative(int u) {
  stack<int> st;
  st.push(u);

  while (!st.empty()) {
    int t = st.top();
    st.pop();
    visited[t] = 1;

    for (int v : adj[t])
      if (!visited[v]) st.push(v);
  }
}

/*
for (int i = 0; i < n; i++) cout << vec[i]
for (int i : vec) cout << i
*/
int main() {
  //mat ady. a lista ady.
  int n; cin >> n;
  int mat[n][n];
  //llenar mat
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if(mat[i][j] == 1) adj[i].push_back(j);
  return 0;
}


// bfs
typedef vector<int> vi;

vector<vi> adj;
vi dist; //INT_MAX

void bfs(int s) {
  queue<int> q;
  q.push(s);
  dist[s] = 0;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u])
      if (dist[v] == INT_MAX) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
  }
}


//dijkstra
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
  adj.clear(); adj.resize(V, vii);
  vi.clear();
  dist.resize(V, INT_MAX);

  return 0;
}
