#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n,coach;
  stack<int> s;
  while (cin >> n) {
    if (n == 0) break;
    while (true) {
      while (!s.empty()) s.pop(); // resetear el stack
      int a = 1; // coches de a
      for (int i = 0; i < n; i++) {
        cin >> coach;
        if (coach == 0) {
          cout << endl;
          break;
        }

        for ( a ; a <= n; a++) {
          if (!s.empty() && s.top() == coach) break; // si el coche del stack es == al coche deseado
          s.push(a); // push de los coches 1,2,3,4,..
          if (a == coach) { // si se encuentra el coche deseado
            a++;
            break;
          }
        }
        if(s.top() == coach) s.pop();
      }
      if (coach == 0) break;
      if (s.empty()) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}
