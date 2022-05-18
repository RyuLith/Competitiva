// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, c;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int c, max = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            // reemplazar el maximo en cada iteracion del ciclo
            if (c > max)
                max = c;
        }

        cout << "Case " << i + 1 << ": " << max << endl;
    }
    return 0;
}
