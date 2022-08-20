// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string youngest, oldest;      // nombre del mas joven y mas viejo
    int agey = 0, ageo = INT_MAX; // edad del mas joven y mas viejo
    while (n--)
    {
        string name;
        int dd, mm, yy;
        cin >> name >> dd >> mm >> yy;
        // pasarlo todo a dias
        dd = dd + mm * 30 + yy * 365;
        // la persona mas joven nacio despues, por lo tanto tiene mayor numero de dias
        if (dd > agey)
        {
            agey = dd;
            youngest = name;
        }
        // la persona mas vieja nacio antes, por lo tanto tiene menor numero de dias
        if (dd < ageo)
        {
            ageo = dd;
            oldest = name;
        }
    }
    cout << youngest << endl;
    cout << oldest << endl;
    return 0;
}