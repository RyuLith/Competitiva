// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        // A debe estar en la mitad de la secuencia ordenada de numeros
        // nos interesan los numeros que estan al medio, ya que los numeros del extremo generan posibleores mas grandes
        sort(v.begin(), v.end());
        int mid = v[n / 2], mid2 = mid;
        if (n % 2 == 0)          // mediana, si hay un numero par de numeros
            mid2 = v[n / 2 - 1]; // 2 medianas
        // contar los numeros que satisfacen la propiedad
        int count = 0;
        for (int i = 0; i < n; i++)
            if (v[i] == mid || v[i] == mid2)
                count++;
                
        int posible = mid - mid2 + 1;
        cout << mid2 << " " << count << " " << posible << endl;
    }
    return 0;
}