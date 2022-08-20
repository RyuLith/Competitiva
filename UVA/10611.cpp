#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,q;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> q;
  int v[q];
  for (int i = 0; i < q; i++)
    cin >> v[i];
  int menores[q]; int mayores[q];
  for (int i = 0; i < q; i++) {
    menores[i] = -1;
    mayores[i] = -1;
  }
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i] <= a[j]) break;
      if (v[i] > a[j]) menores[i] = a[j];
    }
  }
  for (int i = 0; i < q; i++) {
    for (int j = n-1; j >= 0; j--) {
      if (v[i] >= a[j]) break;
      if (v[i] < a[j]) mayores[i] = a[j];
    }
  }
  for (int i = 0; i < q; i++) {
    if (menores[i] != -1) cout << menores[i];
    else cout << "X";
    if (mayores[i] != -1) cout << " " << mayores[i] << endl;
    else cout << " X" << endl;
  }
	return 0;
}
