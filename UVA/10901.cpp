#include <bits/stdc++.h>

using namespace std;

int main(){
  int c,n,t,m;
  cin >> c;
  while(c--){
    cin >> n >> t >> m;
    queue<pair<int, int>> l,r;
    for (int i = 0; i < m; i++) {
      int aux;
      string s;
      cin >> aux >> s;
      if (s[0] == 'l') l.push(pair<int,int>(i,aux));
      else r.push(pair<int,int>(i,aux));
    }
    int sol[m];
    int iod = 0; // izq o der
    int tiempo = 0;
    // simulacion
    while (!l.empty() || !r.empty() ) {
      int cars = 0;
      //tiempo del primer auto, buscando el menor
      int t_auto1;
      if (!l.empty()) t_auto1 = l.front().second;
      else if (!r.empty() && l.empty()) t_auto1 = r.front().second;
      if (!r.empty() && r.front().second < t_auto1) t_auto1 = r.front().second;
      if (tiempo < t_auto1) tiempo = t_auto1; // si el tiempo del primer auto es mayor al tiempo actual, se "espera" hasta ese tiempo

      if (iod == 0) {
        while (!l.empty() && cars < n && l.front().second <= tiempo) {
          sol[l.front().first] = tiempo + t;
          l.pop();
          cars++;
        }
        iod = 1;
      }
      else {
        while (!r.empty() && cars < n && r.front().second <= tiempo) {
          sol[r.front().first] = tiempo + t;
          r.pop();
          cars++;
        }
        iod = 0;
      }
      tiempo += t;
    }
    for (int i = 0; i < m; i++) cout << sol[i] << endl;
    if (c!=0) cout << endl;
  }
  return 0;
}
