// 318 - Domino Effect
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=254
// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
vi dist;

void dijkstra(int s)
{
    priority_queue<ii, vii, greater<ii>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u_dist = pq.top().first;
        int u_vertex = pq.top().second;
        pq.pop();

        if (u_dist > dist[u_vertex])
            continue; // lazy deletion

        for (ii it : adj[u_vertex])
        {
            int v_vertex = it.first;
            int v_dist = it.second;

            // relajacion, si peso de camino actual es mejor al anterior
            if (u_dist + v_dist >= dist[v_vertex])
                continue;
            dist[v_vertex] = u_dist + v_dist;
            pq.push({dist[v_vertex], v_vertex});
        }
    }
}

int main()
{
    int n, m, caso = 1;
    while (cin >> n >> m && n)
    {
        // Inicializacion
        adj.clear(), dist.clear();
        adj.resize(n);           // n nodos, pares {nodo, distancia}
        dist.resize(n, INT_MAX); // dist min

        // Input
        int a, b, l; // nodo a,b y dist
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> l;
            adj[a - 1].push_back({b - 1, l}); // distancia del nodo a-1 a b-1 es l
            adj[b - 1].push_back({a - 1, l}); // distancia del nodo b-1 a a-1 es l
        }

        // Obtener distancia minima con dijkstra
        dijkstra(0);
        // Obtener el domino (nodo) que cae ultimo y su valor
        int last_ind = max_element(dist.begin(), dist.end()) - dist.begin();
        double last_val = dist[last_ind];

        // Si el domino cae en la mitad.
        // El vector adj tiene almacenado para cada nodo i, las distancias con los otros nodos.
        int ini, fin, f = 0;
        // Recorrer todos los nodos.
        for (int i = 0; i < n; i++) // nodo i
        {
            for (int j = 0; j < adj[i].size(); j++) // demas nodos aparte de i
            {
                ii nodoj = adj[i][j]; // {nodo distinto de i (j), distancia de i}
                // tiempo maximo entre 2 dominos
                double between = (dist[i] + dist[nodoj.first] + nodoj.second) / 2.0;
                if (adj[i][j].second && last_val < between)
                {
                    last_val = between, ini = i, fin = nodoj.first,
                    f = 1;
                    break;
                }
            }
        }

        cout << "System #" << caso++ << endl;
        f ? cout << "The last domino falls after " << fixed << setprecision(1) << last_val
                 << " seconds, between key dominoes " << ini + 1 << " and " << fin + 1 << "."
          : cout << "The last domino falls after " << fixed << setprecision(1) << last_val
                 << " seconds, at key domino " << last_ind + 1 << ".";
        cout << "\n\n";
    }
    return 0;
}