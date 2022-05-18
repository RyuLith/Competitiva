// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n != 0)
    {
        // almacenar todo en un arreglo y ordenarlo
        vector<int> v(n);
        int edad;
        for (int i = 0; i < n; i++)
        {
            cin >> edad;
            v[i] = edad;
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            cout << v[i];
            if (i < n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}