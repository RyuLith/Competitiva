// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s; // input
    vector<string> ignore;
    multimap<string, string> words; // asocia palabra mayuscula (la que se usa para ordenar), el titulo y orden de lectura
    // palabras a ignorar
    while (cin >> s)
    {
        if (s == "::")
            break;
        ignore.push_back(s);
    }
    // comparacion de las palabras
    while (getline(cin, s)) // escaneo de los titulos con getline
    {
        // todo el titulo a minuscula, para comparar
        for (int i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);
        // comparar las palabras de los titulos con las palabras ignore
        for (int i = 0; i < s.size(); i++)
        {
            // ignorar espacios
            if (!isalpha(s[i]))
                continue;
            string pal; // palabra
            int j;
            for (j = i; isalpha(s[j]) != 0; j++)
                pal += s[j];
            // ver si la palabra se debe ignorar
            int b = 0;
            for (int k = 0; k < ignore.size(); k++)
            {
                if (ignore[k] == pal)
                {
                    b = 1;
                    break;
                }
            }
            // si la palabra no se debe ignorar, b==0
            if (!b)
            {
                // palabra mayuscula
                for (int k = 0; k < pal.size(); k++)
                    pal[k] = toupper(pal[k]);
                // reemplazar palabra mayuscula en el titulo
                string tmp = s;
                for (int k = 0; k < pal.size(); k++)
                {
                    tmp[i] = pal[k];
                    i++;
                }
                words.insert(make_pair(pal, tmp));
            }
            i = j; // siguiente palabra del titulo
        }
    }
    for (map<string, string>::iterator i = words.begin(); i != words.end(); i++)
        cout << i->second << endl;
    return 0;
}
