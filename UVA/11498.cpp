#include <bits/stdc++.h>

using namespace std;

int main(){
	int k=1,n,m,x,y;
	while(k!=0){
		cin >> k;
		cin >> n;
		cin >> m;
		for (int i=0; i<k; i++){
			cin >> x;
			cin >> y;
			if (x-n>0 && y-m>0) cout<<"NE" << endl;
			else if (x-n>0 && y-m<0) cout<<"SE" << endl;
			else if (x-n<0 && y-m>0) cout<<"NO" << endl;
			else if (x-n<0 && y-m<0) cout<<"SO" << endl;
			else cout<<"divisa" << endl;
		}
	}
	return 0;
}
