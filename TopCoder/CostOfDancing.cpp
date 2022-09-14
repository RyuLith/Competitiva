// H - CostOfDancing
// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

class CostOfDancing
{
public:
    int minimum(int K, vector<int> danceCost)
    {
        sort(danceCost.begin(), danceCost.end());
        int sum = 0;
        for (int i = 0; i < K; i++)
            sum += danceCost[i];
        return sum;
    }
};

int main()
{
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    CostOfDancing c;
    cout << c.minimum(k, v) << endl;
    return 0;
}