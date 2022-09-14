// A - DigitPrime
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

class DigitPrime
{
private:
    int cnt = 0;
    vector<int> primos;
    bool isPrime(int n)
    {
        if (n == 1)
            return false;
        if (find(primos.begin(), primos.end(), n) != primos.end())
            return true;

        for (int i = 2; i < sqrt(n) + 1; i++)
            if (n % i == 0)
                return false;
        primos.push_back(n);
        return true;
    }
    bool arrtoint(int a, int b)
    {
        int n = a * 10 + b;
        int m = b * 10 + a;
        if (isPrime(n) || isPrime(m))
        {
            cnt++;
            return true;
        }
        return false;
    }
    void solve(int n)
    {
        // transformar el entero a un vector, para obtener los digitos
        vector<int> v;
        while (n)
        {
            v.push_back(n % 10);
            n /= 10;
        }
        reverse(v.begin(), v.end());

        // busco si hay un primo entre todas las combinaciones posibles de 2 digitos del numero
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (i == j || !v[i] || !v[j])
                    continue;
                if (arrtoint(v[i], v[j]))
                    return;
            }
        }
    }

public:
    int countNumbers(int a, int b)
    {
        for (int i = a; i <= b; i++)
            solve(i);
        return cnt;
    }
};

int main()
{
    int a, b, cnt;
    cin >> a >> b;
    DigitPrime d;
    cnt = d.countNumbers(a, b);
    cout << cnt << endl;
    return 0;
}