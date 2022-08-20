// 352 - The Seasonal War
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=288
// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int n, m[25][25], visited[25][25];

void dfs(int i, int j)
{
    if (i - 1 >= 0 && j - 1 >= 0 && m[i - 1][j - 1] && !visited[i - 1][j - 1])
        visited[i - 1][j - 1] = 1, dfs(i - 1, j - 1);
    if (i - 1 >= 0 && m[i - 1][j] && !visited[i - 1][j])
        visited[i - 1][j] = 1, dfs(i - 1, j);
    if (i - 1 >= 0 && j + 1 < n && m[i - 1][j + 1] && !visited[i - 1][j + 1])
        visited[i - 1][j + 1] = 1, dfs(i - 1, j + 1);

    if (j - 1 >= 0 && m[i][j - 1] && !visited[i][j - 1])
        visited[i][j - 1] = 1, dfs(i, j - 1);
    if (j + 1 < n && m[i][j + 1] && !visited[i][j + 1])
        visited[i][j + 1] = 1, dfs(i, j + 1);

    if (i + 1 < n && j - 1 >= 0 && m[i + 1][j - 1] && !visited[i + 1][j - 1])
        visited[i + 1][j - 1] = 1, dfs(i + 1, j - 1);
    if (i + 1 && m[i + 1][j] && !visited[i + 1][j])
        visited[i + 1][j] = 1, dfs(i + 1, j);
    if (i + 1 < n && j + 1 < n && m[i + 1][j + 1] && !visited[i + 1][j + 1])
        visited[i + 1][j + 1] = 1, dfs(i + 1, j + 1);
}

int main()
{
    int caso = 1;
    while (cin >> n)
    {
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                s[j] == '0' ? m[i][j] = 0 : m[i][j] = 1;
                visited[i][j] = 0;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j]) // existe war eagle
                {
                    if (!visited[i][j]) // primera parte del war eagle/war eagle completo (sin vecinos)
                        cnt++;
                    dfs(i, j); // dfs para marcar los vecinos y despues ignorarlos
                }
            }
        }
        cout << "Image number " << caso++ << " contains " << cnt << " war eagles." << endl;
    }
    return 0;
}