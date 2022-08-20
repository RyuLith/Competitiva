// 10282 Babelfish
// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, string> mp; // diccionario
    string s, s1, s2;
    while (getline(cin, s) && !s.empty())
    {
        stringstream ss(s);
        ss >> s1 >> s2;
        mp[s2] = s1; // map foreign word with english word (diccionario)
    }
    while (cin >> s)
        mp[s].empty() ? cout << "eh" << endl : cout << mp[s] << endl;
    return 0;
}
