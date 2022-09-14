// G - SmallestOppositeNumber
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

class SmallestOppositeNumber
{
public:
    int construct(int X)
    {
        // transformar el entero a un vector, para obtener los digitos
        vector<int> v, num;
        do
        {
            v.push_back(X % 10);
            X /= 10;
        } while (X);

        // verificar si esta el digito
        for (int i = 0; i < 10; i++)
            if (find(v.begin(), v.end(), i) == v.end() &&
                find(num.begin(), num.end(), i) == num.end())
                num.push_back(i);

        sort(num.begin(), num.end());
        if (!num[0] && num.size() > 1)
            swap(num[0], num[1]);

        int numint = 0, j = num.size() - 1;
        for (int i = 0; i < num.size(); i++)
            numint = numint + num[i] * pow(10, j), j--;
        return numint;
    }
};

int main()
{
    int n;
    cin >> n;
    SmallestOppositeNumber s;
    cout << s.construct(n) << endl;
    return 0;
}