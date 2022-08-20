// SOLUCION PROPIA
#include <bits/stdc++.h>

using namespace std;

struct team
{
    string name;  // nombre
    int points;   // puntos
    int played;   // partidos jugados
    int scored;   // goles a favor
    int suffered; // goles en contrra
    int dif;      // diferencia de goles
};

bool cmp(team a, team b)
{
    if (a.points != b.points) // criterio 1: puntos
        return a.points > b.points;
    if (a.dif != b.dif) // criterio 2: diferencia de goles
        return a.dif > b.dif;
    if (a.scored != b.scored) // criterio 3: goles a favor
        return a.scored > b.scored;
    // strcasecmp(): comparar string, sin importar mayusculas
    // c_str(): transformar string a string de c, para ocupar la funcion anterior
    if (strcasecmp(a.name.c_str(), b.name.c_str()) < 0) // criterio 4: alfabeticamente
        return true;
    return false;
}

int main()
{
    int n, g;
    int b = 0;
    while (cin >> n >> g)
    {
        if (n == 0 && g == 0) break;
        // endl
        if (b) cout << endl;
        b = 1;
        // creacion e inicializacion de los teams
        vector<team> teams(n);
        for (int i = 0; i < n; i++)
            teams[i].points = teams[i].played = teams[i].scored = teams[i].suffered = teams[i].dif = 0;
        // scan nombre de los equipos
        int g1, g2;
        string t1, t2;
        getchar();
        for (int i = 0; i < n; i++)
            getline(cin, teams[i].name);
        // scan resultados de partidos y añadir los datos
        for (int i = 0; i < g; i++)
        {
            char c; // -
            cin >> t1 >> g1 >> c >> g2 >> t2;
            int tmp = 0; // para no recorrer todo el for, cuando se pueda
            for (int j = 0; j < n; j++)
            {
                if (t1 == teams[j].name)
                {
                    teams[j].scored += g1;
                    teams[j].suffered += (g2);
                    teams[j].dif += (g1 - g2);
                    teams[j].played++;
                    if (g1 > g2)
                        teams[j].points += 3;
                    if (g1 == g2)
                        teams[j].points += 1;
                    tmp++;
                    if (tmp == 2)
                        break;
                }
                if (t2 == teams[j].name)
                {
                    teams[j].scored += g2;
                    teams[j].suffered += (g1);
                    teams[j].dif += (g2 - g1);
                    teams[j].played++;
                    if (g2 > g1)
                        teams[j].points += 3;
                    if (g2 == g1)
                        teams[j].points += 1;
                    tmp++;
                    if (tmp == 2)
                        break;
                }
            }
        }
        sort(teams.begin(), teams.end(), cmp); // sort con una funcion
        // print output, sale mas facil con printf para los decimales y espacios
        // primer team
        printf(" 1. ");
        printf("%15s %3d %3d %3d %3d %3d ", teams[0].name.c_str(), teams[0].points, teams[0].played, teams[0].scored, teams[0].suffered, teams[0].dif);
        if (teams[0].played > 0)
            printf("%6.2f", (100.0 * teams[0].points) / (3.0 * teams[0].played));
        else
            printf("%6s", "N/A");
        printf("\n");
        // teams restantes
        for (int i = 1; i < teams.size(); i++)
        {
            // print posicion, si hay alguna diferencia en estos criterios, hay mas posiciones
            if (teams[i].points != teams[i - 1].points || teams[i].dif != teams[i - 1].dif || teams[i].scored != teams[i - 1].scored)
                printf("%2d. ", i + 1);
            else
                printf("    "); // si no hay diferencias = posicion al anterior
            // print equipo y sus datos
            printf("%15s %3d %3d %3d %3d %3d ", teams[i].name.c_str(), teams[i].points, teams[i].played, teams[i].scored, teams[i].suffered, teams[i].dif);
            // print porcentaje de puntos ganados
            if (teams[i].played)
                printf("%6.2f\n", teams[i].points * 100.0 / (3.0 * teams[i].played));
            else // si no ha jugado, no ha ganado puntos, se imprime N/A
                printf("%6s\n", "N/A");
        }
    }
}