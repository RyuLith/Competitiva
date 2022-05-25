// 855 Lunch in Grid City
// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t, s, a, f;
  cin >> t;
  while (t--)
  {
    cin >> s >> a >> f;
    int street[f];
    int avenue[f];
    for (int i = 0; i < f; i++)
      cin >> street[i] >> avenue[i];
    sort(street, street + f);
    sort(avenue, avenue + f);
    int mid;
    f % 2 ? mid = (f + 1) / 2 - 1 : mid = f / 2 - 1;
    cout << "(Street: " << street[mid] << ", Avenue: " << avenue[mid] << ")" << endl;
  }
  return 0;
}