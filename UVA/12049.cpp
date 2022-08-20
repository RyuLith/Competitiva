#include <bits/stdc++.h>

using namespace std;

int main(){
  int t,n,m,aux;
  cin >> t;
  while(t--){
    map<int, int> mp;
    cin >> n >> m;
    while (n--) {
      cin >> aux;
      mp[aux]++;
    }
    while (m--) {
      cin >> aux;
      mp[aux]--;
    }
    aux = 0;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
     aux += abs((*it).second);
    cout << aux << endl;
  }
	return 0;
}
