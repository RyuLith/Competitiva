// https://codeforces.com/problemset/problem/1194/C
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int q;
    cin >> q;
    while (q--)
    {
        string s, t, p;
        cin >> s >> t >> p;
        if (s.size() > t.size())
        {
            cout << "NO" << endl;
            continue;
        }

        // letras disponibles p
        unordered_map<char, int> mp;
        for (int i = 0; i < p.size(); i++)
            mp[p[i]]++;

        int j = 0, flag = 0, ssize = s.size(); // ssize = size del nuevo string a "armar", empieza con size de s, porque no se puede quitar letras a s
        // "armar" el string para que sea igual a t
        for (int i = 0; i < t.size(); i++)
        {
            if (s[j] == t[i] && j < s.size())
                j++;
            else
            {
                if (mp[t[i]] > 0 && ssize <= t.size()) // tengo la letra que me falta en p
                    mp[t[i]]--, ssize++;
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (ssize != t.size()) // "strings" no coinciden
            flag = 1;
        !flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
