#include <bits/stdc++.h>
using namespace std;;

int main() {
  int p, q;
  cin >> p >> q;
  map<string, double> mp;
	while (p--) {
    string s;
    double tmp;
    cin >> s >> tmp;
    mp[s] = tmp;
  }
  for (int i = 0; i < q; i++) {
    string s;
    double sum = 0;
    cin >> s; // scan palabra
    sum += mp[s];
    cin >> s; // scan operador
    while (s == "+") { // si es el operador "+"
      cin >> s; // scan palabra
      sum += mp[s];
      cin >> s; // scan operador
    }
    double tmp; cin >> tmp;
    cout << "Guess #" << i+1 << " was ";
    
    if ("<" == s) {
      if (sum+0.001 < tmp) cout << "correct." << endl;
      else cout << "incorrect." << endl;
    }
    else if (">" == s) {
      if (sum-0.001 > tmp) cout << "correct." << endl;
      else cout << "incorrect." << endl;
    }
    else if ("<=" == s) {
      if (sum-0.001 <= tmp) cout << "correct." << endl;
      else cout << "incorrect." << endl;
    }
    else if (">=" == s) {
      if (sum+0.001 >= tmp) cout << "correct." << endl;
      else cout << "incorrect." << endl;
    }
    else if ("=" == s) {
      if (fabs(sum - tmp) < 0.01) cout << "correct." << endl;
      else cout << "incorrect." << endl;
    }
  }
  return 0;
}
