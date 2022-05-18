#include <bits/stdc++.h>

using namespace std;

int main(){
  int set,n,s,q;
  int aux,aux2;
  cin >> set;
  while(set--){
    // escaneo del input
    cin >> n >> s >> q;
    int cargo = 0;
    stack<int> carrier;
    queue<int> b[n];
    for(int i = 0; i < n; i++){
        cin >> aux;
        cargo += aux;
        while(aux--){
            cin >> aux2;
            b[i].push(aux2-1);
        }
    }
    // simulacion
    int min = 0;
    int i = 0;
    while (cargo) {
      // descarga
      while (!carrier.empty()) {
        if (carrier.top() == i ) cargo--; // descarga a A
        else if (b[i].size() < q ) b[i].push(carrier.top()); //descarga a B
        else break; // no descarga;
        carrier.pop();
        min++;
      }
      // carga
      while (carrier.size() < s && !b[i].empty()) {
        carrier.push(b[i].front());
        b[i].pop();
        min++;
      }
      min+=2;
      i++;
      if (i == n) i = 0;
    }
    cout << min-2 << endl;
  }
  return 0;
}
