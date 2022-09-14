// D - PalindromesCount
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

class PalindromesCount
{
private:
    int cnt = 0;
    bool isPalindrome(string s)
    {
        string tmp = s;
        reverse(s.begin(), s.end());
        if (s == tmp)
            return true;
        return false;
    }

public:
    int count(string A, string B)
    {
        int cnt = 0;
        for (int i = 0; i <= A.length(); i++)
        {
            string s = A;
            s.insert(i, B);
            if (isPalindrome(s))
                cnt++;
        }
        return cnt;
    }
};

int main()
{
    string a, b;
    cin >> a >> b;
    PalindromesCount p;
    int cnt = p.count(a, b);
    cout << cnt << endl;
    return 0;
}