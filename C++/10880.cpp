#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	long long c,r;
	for (int i = 0; i < n; i++){
		cin >> c >> r;
		vector<long long> v;
		long long q = 0;
		if (c == r) v.push_back(q);
		for (int i = 1; i <= sqrt(c-r); i++) {
			if ((c-r) % i == 0) {
				q = (c-r)/i;
				if (q > r) v.push_back(q);
				if (i != q && i > r) v.push_back(i);
			}
		}
		sort(v.begin(), v.end());
		cout<< "Case #" << i+1 << ":";
		for (int i = 0; i < v.size(); i++) {
			cout<< " " << v[i];
		}
		cout<< '\n';
	}
	return 0;
}
