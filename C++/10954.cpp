#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) break;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      int aux;
      cin >> aux;
      pq.push(aux * -1);
    }
    int sum = 0, cost = 0;
    while (pq.size() > 1) {
      cost = pq.top();
      pq.pop();
      cost += pq.top();
      pq.pop();
      sum += cost;
      pq.push(cost);
    }
    cout << sum * -1 << endl;
  }
  return 0;
}
