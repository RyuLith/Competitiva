// Queries for Number of Palindromes
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

int tam;

void isPalindrome(string s, vector<vector<bool>> &v1, vector<vector<int>> &v2)
{
    // doble for para recorrer todas las palabras posibles
    // hacerlo de esta forma para recorrer algunas palabras antes que otras
    for (int j = 0; j < tam; j++)
        for (int i = j; i >= 0; i--)
        {
            if (i == j)
            {
                v1[i][j] = 1, v2[i][j] = 1;
                continue;
            }
            // si es distinto no es palindromo
            // si no, ver los caracteres de mas adentro
            s[i] != s[j] ? v1[i][j] = 0 : v1[i][j] = v1[i + 1][j - 1];
        }
}

void countPalindromes(vector<vector<bool>> &v1, vector<vector<int>> &v2)
{
    for (int j = 0; j < tam; j++)
        for (int i = j; i >= 0; i--)
        {
            if (v2[i][j])
                continue;

            v2[i][j] += v1[i][j] + v2[i][j - 1] + v2[i + 1][j] - v2[i + 1][j - 1];
        }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // para que se ejecute mas rapido el programa
    string s;
    cin >> s;
    tam = s.size();
    vector<vector<bool>> v1(tam, vector<bool>(tam, 1));
    vector<vector<int>> v2(tam, vector<int>(tam));
    isPalindrome(s, v1, v2);
    countPalindromes(v1, v2);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << v2[l - 1][r - 1] << '\n';
    }
    return 0;
}