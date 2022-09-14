// E - MagicSubset
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

class MagicSubset
{
public:
    int findBest(vector<int> values)
    {
        int sum1 = values[0], sum2 = 0; // suma incluyendo 0 y sin 0
        for (int i = 1; i < values.size(); i++)
            // si tomo el stone 0, debo tomar los negativos para maximizar
            values[i] < 0 ? sum1 += values[i] : sum2 += values[i];

        return max(-sum1, sum2);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    MagicSubset m;
    cout << m.findBest(v) << endl;
    return 0;
}