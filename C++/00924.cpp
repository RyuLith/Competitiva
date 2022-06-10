#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi dist; //INT_MAX
map<int, int> mp;

void bfs(int s) {
  queue<int> q;
  q.push(s); dist[s] = 0;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u])
      if (dist[v] == INT_MAX) {
        dist[v] = dist[u] + 1;
        mp[dist[v]]++;
        q.push(v);
      }
  }
}



int main() {
  int e,n,t,tmp;
  cin >> e;
  adj.clear(); adj.resize(e);
  for (int i = 0; i < e; i++) {
    cin >> n;
    while (n--) {
      cin >> tmp;
      adj[i].push_back(tmp);
    }
  }

  cin >> t;
  while (t--) {
    dist.clear(); dist.resize(e,INT_MAX);
    mp.clear();
    cin >> tmp;
    bfs(tmp);

    int m = 0, d;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
      if (it->second > m) {
        m = it->second;
        d = it->first;
      }
    }
    if (m) cout << m << " " << d << endl;
    else cout << "0" << endl;
  }
  return 0;
}
