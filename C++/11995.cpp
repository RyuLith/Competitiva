#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,aux,x;
  while(cin >> n) {
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    int fs=1, fq=1, fpq=1;
    for (int i = 0; i < n; i++) {
      cin >> aux >> x;
      if (aux == 1) {
        s.push(x);
        q.push(x);
        pq.push(x);
      }
      else {
        if (!s.empty() && s.top() == x) s.pop();
        else fs = 0;
        if (!q.empty() && q.front() == x) q.pop();
        else fq = 0;
        if (!pq.empty() && pq.top() == x) pq.pop();
        else fpq = 0;
      }
    }
    if (fs + fq + fpq > 1) cout << "not sure" << endl;
    else if (fs == 1) cout << "stack" << endl;
    else if (fq == 1) cout << "queue" << endl;
    else if (fpq == 1) cout << "priority queue" << endl;
    else cout << "impossible" << endl;
  }
	return 0;
}
