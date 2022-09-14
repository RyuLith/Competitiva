// I - Palindromize
// SOLUCION PROPIA
// usuario: dazhi
#include <bits/stdc++.h>

using namespace std;

class Palindromize
{
private:
    bool isPalindrome(string s)
    {
        string tmp = s;
        reverse(s.begin(), s.end());
        if (s == tmp)
            return true;
        return false;
    }

public:
    string minAdds(string s)
    {
        if(isPalindrome(s)) return s;
        for (int i = 0; i < s.length(); i++)
        {
            string pal = s;
            for (int j = i; j >= 0; j--)
                pal.push_back(s[j]);
            if(isPalindrome(pal)) return pal;
        }
    }
};

int main()
{
    string s;
    cin >> s;
    Palindromize p;
    cout << p.minAdds(s) << endl;
    return 0;
}