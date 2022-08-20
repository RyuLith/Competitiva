#include <bits/stdc++.h>

using namespace std;

int main(){
  int t, doc = 1;
  string line;
  cin >> t;
  while(t--){
    vector<string> words;
    unordered_map<string,int> ump;
    while(getline(cin,line), line != "END"){
      line = regex_replace(line, regex("[^a-z]"), " ");
      istringstream iss(line);
      while(iss >> line) {
        words.push_back(line);
        ump[line] = 0;
      }
    }
    int distintas = ump.size(); // numero de palabras distintas
    int e = 0, s = 0, p = 0, q = 0, cant = 0, rango = 999999999;
    while(e < words.size()) {
      ump[words[e]]++;
      if(ump[words[e]] == 1) cant++; // si es la primera vez que se ve la palabra
      e++;
      while(cant == distintas) { //rango valido
        ump[words[s]]--;
        if(ump[words[s]] == 0) cant--; // salir del while
        s++;
        if(e-s < rango){
          rango = e-s;
          q = e; p = s;
        }
      }
    }
    cout << "Document " << doc++ << ": " << p << " " << q << endl;
  }
  return 0;
}
