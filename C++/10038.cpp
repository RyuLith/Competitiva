#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int a[3001], v[3001];
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n-1; i++)
			v[i] = abs(a[i+1] - a[i]);
		sort(v, v + n-1);
		bool b = true;
		for (int i = 0; i < n-1; i++){
			if(v[i] != i+1) {
				b = false;
				break;
			}
		}
		if (b) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	return 0;
}
