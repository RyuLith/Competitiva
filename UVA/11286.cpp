// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        map<vector<int>, int> m; // map de courses, popularidad

        for (int i = 0; i < n; i++)
        {
            vector<int> courses(5); // vector temporal, para no usar iterador (map)
            for (int j = 0; j < 5; j++)
            {
                int tmp;
                cin >> tmp;
                courses[j] = tmp;
            }

            sort(courses.begin(), courses.end()); // ordenar courses (para ver si son iguales)
            m[courses]++;                         // +1 de popularidad para el course
        }

        // iterar el mapa para ver el mas popular
        int popularidad = 0;
        for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); it++)
            if (popularidad < it->second)
                popularidad = it->second;

        int distintos = 0; // en caso de que haya mas de un course popular
        for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); it++)
            if (it->second == popularidad)
                distintos++;

        cout << popularidad * distintos << endl;
    }
    return 0;
}
