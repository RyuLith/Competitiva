// F - Workshop
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

class Workshop
{
public:
    int pictureFrames(vector<int> pieces)
    {
        int cnt = 0;
        // comparar de a 3, todos los elementos del arreglo
        for (int i = 0; i < pieces.size(); i++)
            for (int j = i + 1; j < pieces.size(); j++)
                for (int k = j + 1; k < pieces.size(); k++)
                    if (pieces[i] + pieces[j] > pieces[k] &&
                        pieces[i] + pieces[k] > pieces[j] &&
                        pieces[j] + pieces[k] > pieces[i])
                        cnt++;
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    Workshop w;
    cout << w.pictureFrames(v) << endl;
    return 0;
}