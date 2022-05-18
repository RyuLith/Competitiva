#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,k,bill;
  while(cin >> n, n) {
    multiset<int> bills;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> k;
      for (int j = 0; j < k; j++) {
        cin >> bill;
        bills.insert(bill);
      }
      multiset<int>::iterator min = bills.begin();
      multiset<int>::iterator max = bills.end();
      max--;
      sum += *max - *min;
      bills.erase(max);
      bills.erase(min);
    }
    cout << sum << endl;
  }
	return 0;
}
