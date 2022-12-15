// Queries https://codeforces.com/gym/100741/problem/A
// SOLUCION PROPIA + arreglo de algunas partes de codigo de https://www.cnblogs.com/mjtcn/p/7327197.html
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL n, m, q;

// Algoritmo Fenwick Tree en CANVAS
class FenwickTreeRangeQueryPointUpdate
{
public:
    FenwickTreeRangeQueryPointUpdate()
    {
        tree.resize(n + 1);
    }
    // Returns the sum of the interval [left, right], O(log(n))
    LL sum(int left, int right)
    {
        if (right < left)
            return -1;
        return prefixSum(right) - prefixSum(left - 1);
    }

    // Add 'v' to index 'i', O(log(n))
    void add(int i, int v)
    {
        while (i <= n)
        {
            tree[i] += v;
            i += lsb(i);
        }
    }

private:
    // This array contains the Fenwick tree ranges
    vector<LL> tree;

    static int lsb(int i)
    {
        // Isolates the lowest one bit value
        return i & -i;
    }

    // Computes the prefix sum from [1, i], O(log(n))
    LL prefixSum(int i)
    {
        LL sum = 0L;
        while (i)
        {
            sum += tree[i];
            i &= ~lsb(i); // Equivalently, i -= lsb(i);
        }
        return sum;
    }
};

int main()
{
    cin >> n >> m;
    vector<LL> a(n + 1);
    // un FT para cada mod
    vector<FenwickTreeRangeQueryPointUpdate> ft(m + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        // añadir cada elemento a su arbol mod (elemento%m) correspondiente
        int mod = a[i] % m;
        ft[mod].add(i, a[i]);
    }

    cin >> q;
    while (q--)
    {
        string s;
        LL l, r;
        cin >> s >> l >> r;
        if (s == "s")
        {
            LL mod;
            cin >> mod;
            cout << ft[mod].sum(l, r) << endl; // encontrar el ft del mod y obtener suma
        }
        else if (s == "+")
        {
            // añadir de esta forma, para que funcione en test 4 en adelante
            ft[a[l] % m].add(l, -a[l]);
            a[l] += r;
            ft[a[l] % m].add(l, a[l]);
            // ft[a[l] % m].add(l, r);
            cout << a[l] << endl;
        }
        else
        {
            if (a[l] < r)
                cout << a[l] << endl;
            else
            {
                // añadir de esta forma, para que funcione en test 4 en adelante
                ft[a[l] % m].add(l, -a[l]);
                a[l] -= r;
                ft[a[l] % m].add(l, a[l]);
                cout << a[l] << endl;
            }
        }
    }
    return 0;
}

/*
3 4
1 2 3
3
s 1 3 2
+ 2 1
- 1 2


2
3
1

*/