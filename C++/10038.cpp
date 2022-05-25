// 10038 Jolly Jumpers
// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int a[3001], v[3001];
	while (cin >> n)
	{
		// guardar input en un arreglo
		for (int i = 0; i < n; i++)
			cin >> a[i];
		// guardar valor abs de la secuencia en otro arreglo
		for (int i = 0; i < n - 1; i++)
			v[i] = abs(a[i + 1] - a[i]);
		// sort para despues comparar con la secuencia 1, 2, 3, 4,...
		sort(v, v + n - 1);

		bool b = true;
		for (int i = 0; i < n - 1; i++)
		{
			if (v[i] != i + 1)
			{
				b = false;
				break;
			}
		}
		b ? cout << "Jolly" << endl : cout << "Not jolly" << endl;
	}
	return 0;
}
