// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long c, r;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> r;
        vector<long long> v;
        long long q = 0;

        if (c == r)
            v.push_back(0); // nadie comio cookies

        for (int j = 1; j <= sqrt(c - r); j++) // no es necesario probar con todos los numeros
        {
            // si es divisible, es posible que se hayan comido esa cantidad de cookies
            // la idea es quedarse con el divisor y el cociente que son Q
            if ((c - r) % j == 0)
            {
                q = (c - r) / j; // cociente = Q
                if (r < q)
                    v.push_back(q); // R < Q
                if (j != q && r < j) // asegurar de que no se repitan Q, y R < Q (r < j)
                    v.push_back(j); // si es divisible por "j", j tambien es Q
            }
        }
        sort(v.begin(), v.end());

        cout << "Case #" << i + 1 << ":";
        for (int j = 0; j < v.size(); j++)
            cout << " " << v[j];

        cout << '\n';
    }
    return 0;
}