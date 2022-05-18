// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, coach;
  while (cin >> n)
  {
    if (n == 0)
      break;
    while (1)
    {
      stack<int> s;
      int a = 1; // coches de a

      for (int i = 0; i < n; i++)
      {
        cin >> coach;
        if (coach == 0)
        {
          cout << endl;
          break;
        }

        // for para tener el coche deseado
        // se trata de pushear la secuencia deseada 1,2,3,4,...
        // y comparar con la secuencia de coches leidas en el for de afuera
        for (; a <= n; a++)
        {
          if (!s.empty() && s.top() == coach) // si el coche del stack es == al coche deseado
            break;

          s.push(a); // push de los coches 1,2,3,4,..

          if (a == coach) // si se encuentra el coche deseado
          {
            a++;
            break;
          }
        }
        if (s.top() == coach)
          s.pop();
      }

      if (coach == 0)
        break;
      if (s.empty()) // stack vacio = secuencia sin problemas
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}
