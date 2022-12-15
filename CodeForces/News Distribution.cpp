// News Distribution
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

// Algoritmo UnionFind en CANVAS
class UnionFind
{
public:
    int size;
    vector<int> sz;

    UnionFind(int tam)
    {
        if (tam <= 0)
            return;
        size = numComponents = tam;
        sz.resize(size);
        id.resize(size);

        for (int i = 0; i < size; i++)
        {
            id[i] = i; 
            sz[i] = 1; 
        }
    }

    int find(int p)
    {
        int root = p;
        while (root != id[root])
            root = id[root];

        while (p != root)
        {
            int next = id[p];
            id[p] = root;
            p = next;
        }

        return root;
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    void unify(int p, int q)
    {
        if (connected(p, q))
            return;

        int root1 = find(p);
        int root2 = find(q);

        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            id[root1] = root2;
            sz[root1] = 0;
        }
        else
        {
            sz[root1] += sz[root2];
            id[root2] = root1;
            sz[root2] = 0;
        }

        numComponents--;
    }

private:
    vector<int> id;
    int numComponents;
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

    int n, m;
    cin >> n >> m;
    UnionFind uf = UnionFind(n);
    while (m--)
    {
        int k;
        cin >> k;
        int nodo;

        for (int i = 0; i < k; i++)
        {
            if (!i)
            {
                cin >> nodo;
                nodo--; // trabajar con 0 a n-1
                continue;
            }
            int aux;
            cin >> aux;
            aux--; // trabajar con 0 a n-1

            uf.unify(aux, nodo);
            nodo = aux;
        }
    }
    for (int i = 0; i < n; i++)
        cout << uf.sz[uf.find(i)] << endl; // buscar el componente al que pertenece y luego obtener el tamaño
    return 0;
}

/*
7 5
3 2 5 4
0
2 1 2
1 1
2 6 7

4 4 1 4 4 2 2 
*/