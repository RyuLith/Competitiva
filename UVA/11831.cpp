// 11831 - Sticker Collector Robot
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2931
// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, s;
    while (cin >> n >> m >> s)
    {
        if (!n && !m && !s)
            break;

        char mat[110][110], ori; // arena y orientacion
        string instr;            // instrucciones
        int x, y;                // posicion del robot

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == 'N' || mat[i][j] == 'S' || mat[i][j] == 'L' || mat[i][j] == 'O')
                    x = i, y = j,
                    ori = mat[i][j];
            }
        }

        cin >> instr;
        int stickers = 0;
        // camino del robot
        for (int i = 0; i < s; i++)
        {
            // turn right
            if (instr[i] == 'D')
            {
                if (ori == 'N')
                    ori = 'L';
                else if (ori == 'L')
                    ori = 'S';
                else if (ori == 'S')
                    ori = 'O';
                else if (ori == 'O')
                    ori = 'N';
            }
            // turn left
            else if (instr[i] == 'E')
            {
                if (ori == 'N')
                    ori = 'O';
                else if (ori == 'L')
                    ori = 'N';
                else if (ori == 'S')
                    ori = 'L';
                else if (ori == 'O')
                    ori = 'S';
            }
            // move forward
            else
            {
                if (ori == 'N')
                    x--;
                else if (ori == 'L')
                    y++;
                else if (ori == 'S')
                    x++;
                else if (ori == 'O')
                    y--;
                // undo
                if (x < 0 || y < 0 || x >= n || y >= m || mat[x][y] == '#')
                {
                    if (ori == 'N')
                        x++;
                    else if (ori == 'L')
                        y--;
                    else if (ori == 'S')
                        x--;
                    else if (ori == 'O')
                        y++;
                }
                else
                {
                    if (mat[x][y] == '*')
                    {
                        stickers++;
                        mat[x][y] = '.';
                    }
                }
            }
        }
        cout << stickers << endl;
    }
    return 0;
}