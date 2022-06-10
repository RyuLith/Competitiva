#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> v;
	map<int,int> mp;
  int n;
  while(scanf("%d", &n) == 1){
    if (mp.count(n) == 0) {
      mp[n] = 1;
      v.push_back(n);
    }
    else mp[n]++;
  }
  for(int i = 0; i < v.size() ; i++)
		cout << v[i] << " " << mp[v[i]] << endl;
	return 0;
}
