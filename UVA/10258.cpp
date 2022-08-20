// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

struct submission
{
	// output
	int contestant; // numero del contestant (id)
	int solved;		// problemas resueltos
	int penalty;	// penalty time
	// mapear indices del arreglo con problemas
	int attemps[10];  // numero de attemps de cada problema
	int accepted[10]; // problema aceptado = 1, no aceptado = 0, indice del arreglo = problema
};

// ordenar por problemas resueltos > menor penalty > num del contestant
bool cmp(submission a, submission b)
{
	if (a.solved != b.solved)
		return a.solved > b.solved;
	if (a.penalty != b.penalty)
		return a.penalty < b.penalty;
	return a.contestant < b.contestant;
}

int main()
{
	int t;
	cin >> t;
	getchar();
	getchar();
	while (t--)
	{
		vector<submission> v; // submissions
		// leer con getline y hacer stringstream
		string s;
		while (getline(cin, s) && s.size() != 0)
		{
			stringstream ss;
			int con, pro, tim; // contestant, problem, time
			char l;			   // L
			ss << s;
			ss >> con >> pro >> tim >> l;

			submission sub;
			// ver si es submission nueva
			int i = 0, b = 0; // flag para ver si es una submission nueva o anterior
			for (; i < v.size(); i++)
			{
				// si el contestant ya tiene una submission anterior
				if (v[i].contestant == con)
				{
					sub = v[i];
					b = 1;
					break;
				}
			}
			// inicializacion del submission, si es nueva
			if (!b)
			{
				sub.contestant = con;
				sub.penalty = sub.solved = 0;
				for (int i = 0; i < 10; i++)
					sub.attemps[i] = sub.accepted[i] = 0;
			}
			// resolviendo
			// solo nos importa C o I (y que no haya sido aceptado antes). R, U, E, no importa
			if (l == 'C' && !sub.accepted[pro])
			{
				sub.solved++;
				sub.accepted[pro] = 1; // 1 = aceptado
				sub.penalty += (tim + sub.attemps[pro] * 20);
			}
			else if (l == 'I' && !sub.accepted[pro])
				sub.attemps[pro]++;
			// añadiendo la submission al vector dependiendo del caso
			if (b)
				v[i] = sub;
			else
				v.push_back(sub);
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i++)
			cout << v[i].contestant << " " << v[i].solved << " " << v[i].penalty << endl;
		if (t)
			cout << endl;
	}
	return 0;
}