#include <bits/stdc++.h>
using namespace std;;

int main() {
  int p,c;
  int casos = 1;
  while (cin >> p >> c, p!=0, c!=0){
    deque<int> dq;
    if (p < c)
      for (int i = 0; i < p; i++)
        dq.push_back(i+1);
    else
      for (int i = 0; i < c; i++)
        dq.push_back(i+1);

    cout << "Case " << casos++ << ":" << endl;
    while (c--){
      char aux; cin >> aux;
      if (aux == 'N') {
        cout << dq.front() << endl;
        dq.push_back(dq.front());
        dq.pop_front();
      } else {
        int n; cin >> n;
        for (deque<int>::iterator it = dq.begin(); it!=dq.end(); it++) {
          if (*it == n) {
            dq.erase(it);
            break;
          }
        }
        dq.push_front(n);
      }
    }
  }
  return 0;
}
