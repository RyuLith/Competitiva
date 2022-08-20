// 12582 - Wedding of Sultan
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4027
// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main()
{
    int t, caso = 1;
    cin >> t;
    while (t--)
    {
        vi visited(26), cnt(26), adj(26);
        string s;
        cin >> s;

        // Camino de u a v
        int u, v;
        // Inicializacion del primer nodo
        u = s[0] - 'A', visited[u] = 1;
        // Recorrer secuencia (string)
        for (int i = 1; i < s.size(); i++)
        {

            v = s[i] - 'A';  // camino a v
            if (!visited[v]) // nuevo camino
            {
                visited[v] = 1;
                adj[v] = u;         // existe un camino de u a v, u como padre de v
                cnt[v]++, cnt[u]++; // como existe un camino, aumenta el contador
                u = v;              // v sera el padre del proximo nodo
            }
            else // si ya ha pasado por ese nodo (letra repetida)
                u = adj[v];
        }

        cout << "Case " << caso++ << endl;
        for (int i = 0; i < 26; i++)
            if (cnt[i])
            {
                char c = i + 'A';
                cout << c << " = " << cnt[i] << endl;
            }
    }
    return 0;
}