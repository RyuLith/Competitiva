// J - CheatingAfterTests
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

class CheatingAfterTests
{
public:
    int cheat(vector<int> report)
    {
        sort(report.begin(), report.end());
        int sum = 0, num = -1;
        for (int i = 0; i < report.size(); i++)
        {
            sum += report[i];
            if (num == -1 && report[i] >= 10)
                num = report[i];
        }

        if (num != -1 && num < 90)
            return sum + (9 - num / 10) * 10;
        if (num != -1 && num >= 90)
            return sum + max(99 - num, 9 - report[0]);
        return sum + 9 - report[0];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    CheatingAfterTests c;
    cout << c.cheat(v) << endl;
    return 0;
}